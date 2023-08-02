# NYT::NProfiling

yt/yt/library/profiling - это библиотека для мониторинга, которая используется
в кодовой базе YT.

Основные фичи:
* Локальное вычисление агрегатов позволяет удобно работать с многомерными счётчиками.
* Lockfree регистрация счётчиков позволяет создавать новые счётчики во время работы 
  процесса и не беспокоиться о лишних локах.
* Внутренний буффер точек позволяет сохранять значения с высоким разрешением.
  YT использует шаг сетки в 5c, при интервале сбора метрик 30с.
* Sparse счётчики и де-регистрация старых счётчиков позволяет использовать
  теги большой кардинальности, вроде `user` или `table_path`.
* Опциональный глобальный registry позволяет добавлять счётчики в код,
  без необходимости пробрасывать параметр через конструкторы.
* Разделение на интерфейс и реализацию позволяет использовать интерфейс 
  в других core библиотеках, не создавая dependency hell.
* Встроенная debug страница для отладки переполнения числа сенсоров
  и мониторинга сбора метрик.
* Умеет помечать сенсоры, для которых имеет смысл вычислять агрегат на стороне Соломона.
  Эта опция спасает от безумных графиков "суммы максимумов по кластеру".

## Несовместимости с yt/yt/core/profiling

* Метрики, значением которых является интервал времени,
  всегда экспортируются в секундах. `core/profiling` не имел такого понятия,
  и в некоторых случаях требовал конвертации на стороне пользователя.
  Дефолтная функция конвертации использовала микросекунды.

## Сравнение от monlib

|                           | YT  | monlib |
| ------------------------- | --- | ------ |
| Spack                     | Yes | Yes    |
| Debug Page                | Yes | Yes    |
| 5s Grid Step              | Yes | No     |
| Local Projections         | Yes | No     |
| Sparse Sensors            | Yes | No     |
| Sensor Deregistration     | Yes | No     |

## Разделение на интерфейс и реализацию

`yt/yt/library/profiling` содержит минимальный интерфейс для добавления сенсоров в код.
От этой библиотеки зависят другие `core` библиотеки.

Реализация интерфейса находится в `yt/yt/library/profiling/solomon`. Интерфейс
находит реализацию через `weak` символ `GetGlobalRegistry`. Если реализация не
прилинкована, вся библиотека превращается в no-op.

## Sparse сенсоры

По умолчанию все сенсоры являются dense. Значение счётчика будет экспортироваться в Соломон,
даже если этот сенсор не менялся или равен нулю. Это верно даже для сенсоров, которые
создаются через `ISensorProducer`.

В некоторых ситуациях такое поведение создаёт слишком большую нагрузку на Соломон. Например, 
среди сенсоров `request_count` пользователей мастера Хана, в каждый момент времени
не равны нулю только несколько сотен из 10 тысяч. В таких случаях сенсор можно переключить
в sparse режим.

Sparse сенсоры не экспортируются, пока их значение равно нулю. После того, как значение сенсора
становится не равно нулю, сенсор экспортируется в течении LingerTimeout (по умолчанию 5 минут).
Это сделано для того, чтобы уменьшить число дырок в графиках.

## Global сенсоры

По умолчанию сенсор относится к текущему процессу. При экспорте к нему будет привязан тег `host=`,
или другой идентификатор текущего процесса.

Сенсор можно сделать "глобальным". Тогда при экспорте к нему не будут добавляться теги процесса. Но
клиент должен гарантировать, что такой сенсор в один момент времени активен только на одном процессе
кластера.

## Теги и проекции

Перед экспортом сенсоров в Соломон, YT вычисляет локальные агрегаты.

Все сенсоры с одинаковым именем должны быть проаннотированы тегами с
одинаковыми ключами. Нарушать это правило можно, но крайне не рекомендуется.

```
# Неверно. Одинаковое имя, но разные ключи тегов.
request_count{user=foo} 1
request_count{command=get} 1

# Правильно
request_count_by_user{user=foo} 1
request_count_by_command{command=get} 1

# Правильно
request_count{user=foo;command=get} 1
```

По дефолту, агрегация считается по всем подмножествам множества ключей.
Экспортируются только агрегаты, а не сами сенсоры.

В некоторых ситуациях такое поведение приводит к комбинаторному взрыву
или бесполезной работе.

Например:

```
# Исходный сенсор
request_count{bundle=sys;table_path=//sys/operations}

# Значение агрегата с тегом table_path всегда будет равно
# исходному сенсору. Такая проекция увеличивает нагрузку на Соломон
# в 2 раза и не добавляет никакой новой информации.
request_count{table_path=//sys/operations}

# Агрегат по всем таблицам бандла очень полезен, и его нужно оставить.
request_count{bundle=sys}
```

Чтобы избежать этой проблемы, можно исключать некоторые множества ключей
из агрегации.

- `Required` тег обязан присутствовать в множестве ключей для агрегации.
- `Excluded` тег исключает все множества ключей, в которых он присутствует.
- `Alternative(other)` тег исключает все подмножества ключей, где присутствуют одновременно
  тег и его альтернативный тег.
- Тег, для которого определён `Parent`, исключает все подмножества, в которых
  присутствует тег, но не присутствует его родитель.

Пример: Допустим у нас есть счётчик с тегами `a` и `b`.
Таблица показывает подмножества агрегатов, которые будут экспортироваться,
в зависимости от настроек тегов.

| Aggregate       | A is required | B is excluded | A is parent of B | A is alternative to B |
|-----------------|---------------|---------------|------------------|-----------------------|
| `{}`            | -             | +             | +                | +                     |
| `{a=foo}`       | +             | +             | +                | +                     |
| `{b=bar}`       | -             | -             | -                | +                     |
| `{a=foo;b=bar}` | +             | -             | +                | -                     |

## Агрегаты Соломона

Текущие агрегаты Соломона умеют считать сумму метрик при записи.

Сумма имеет смысл не для всех типов сенсоров. Чтобы не создавать в Соломоне
бесполезные графики, библиотека помечает все значения, для которых имеет смысл вычислять
агрегаты, тегом `yt_aggr=1`.

В настройках шарда должено быть включено единственное правило `host=*, yt_aggr=1 -> host=Aggr, yt_aggr=1`.