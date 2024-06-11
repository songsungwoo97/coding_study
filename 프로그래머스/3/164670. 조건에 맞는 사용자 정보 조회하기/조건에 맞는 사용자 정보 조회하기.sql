-- 코드를 입력하세요
SELECT ugu.USER_ID, ugu.NICKNAME, concat(CITY, ' ',STREET_ADDRESS1, ' ', STREET_ADDRESS2) as '전체주소', concat(substring(TLNO, 1, 3), '-', substring(TLNO, 4, 4), '-',substring(TLNO, 8)) as '전화번호'
    from USED_GOODS_BOARD ugb 
join USED_GOODS_USER ugu on ugb.WRITER_ID = ugu.USER_ID
group by ugb.WRITER_ID
having count(ugb.TITLE) >= 3
order by 1 desc