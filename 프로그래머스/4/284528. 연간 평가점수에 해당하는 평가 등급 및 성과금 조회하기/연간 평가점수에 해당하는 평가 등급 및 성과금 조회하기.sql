SELECT 
    E.EMP_NO,
    E.EMP_NAME,
    CASE
        WHEN avg(G.SCORE) >= 96 THEN 'S'
        WHEN avg(G.SCORE) >= 90 THEN 'A'
        WHEN avg(G.SCORE) >= 80 THEN 'B'
        ELSE 'C'
    END AS GRADE,
    CASE
        WHEN avg(G.SCORE) >= 96 THEN E.SAL * 0.2
        WHEN avg(G.SCORE) >= 90 THEN E.SAL * 0.15
        WHEN avg(G.SCORE) >= 80 THEN E.SAL * 0.1
        ELSE 0
    END AS BONUS
FROM 
    HR_EMPLOYEES E JOIN HR_GRADE G ON E.EMP_NO = G.EMP_NO
group by EMP_NO
ORDER BY 1 asc;