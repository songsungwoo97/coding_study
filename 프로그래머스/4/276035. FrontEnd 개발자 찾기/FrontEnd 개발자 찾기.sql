select distinct ID, EMAIL, FIRST_NAME, LAST_NAME
from DEVELOPERS d join SKILLCODES s on s.CODE & d.SKILL_CODE in (select code from SKILLCODES where CATEGORY = "Front End")
order by 1 asc