SELECT MEMBER_ID, MEMBER_NAME, GENDER, date_format(DATE_OF_BIRTH, '%Y-%m-%d') as DATE_OF_BIRTH
from MEMBER_PROFILE 
where TLNO is not null and GENDER = 'W' and date_format(DATE_OF_BIRTH, '%m') = '03'
order by MEMBER_ID ASC