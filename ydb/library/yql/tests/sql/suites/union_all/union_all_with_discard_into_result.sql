/* syntax version 1 */
/* postgres can not */

use plato;
pragma DisableAnsiOrderByLimitInUnionAll;

select * from Input
union all
select * from Input into result aaa;

discard
select * from Input
union all
select * from Input;
