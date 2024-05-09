select count(*) as FISH_COUNT, MONTH(TIME) as MONTH
from FISH_INFO
group by MONTH
having FISH_COUNT > 0
order by MONTH
