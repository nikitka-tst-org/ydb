--!syntax_pg
select 
array['a','b'],
array[array['a','b']],
array[array['a','b'],array['c','d']],
array['a',null],
array[null],
array[1],
array[1,2],
array[null::int4,2],
array[array[1,2]],
array[array[1,2],array[3,4]],
array_out(array[1,2]),
array_out(array[null,'NULL','',',','{}'])
