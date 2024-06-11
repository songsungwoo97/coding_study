-- 코드를 입력하세요
SELECT APNT_NO, PT_NAME, app.PT_NO, app.MCDP_CD, DR_NAME, APNT_YMD
from APPOINTMENT app inner join PATIENT pa on app.PT_NO = pa.PT_NO
inner join DOCTOR doc on app.MDDR_ID = doc.DR_ID
where app.APNT_CNCL_YN = 'N' and app.MCDP_CD = 'CS' and DATE_FORMAT(app.APNT_YMD, '%Y-%m-%d') = '2022-04-13'
order by app.APNT_YMD asc