# mlock

MlockFileMappings подгружает и лочит в память все страницы исполняемого файла.

В отличии от вызова mlockall, функция не лочит другие страницы процесса.
mlockall явно выделяет физическую память под все vma. Типичный процесс сначала
стартует и инициализирует аллокатор, а потом уже вызывает функцию для mlock страниц.
Аллокатор при старте выделяет большие диапазоны через mmap, но реально их не использует.
Поэтому mlockall приводит в повышенному потреблению памяти.

Также, в отличии от mlockall, функция может подгрузить страницы в память сразу. 
