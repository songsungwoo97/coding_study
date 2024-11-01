SELECT 
    c.CAR_ID,
    c.CAR_TYPE,
    FLOOR(c.DAILY_FEE * (1 - p.DISCOUNT_RATE/100) * 30) AS FEE
FROM 
    CAR_RENTAL_COMPANY_CAR c
JOIN 
    CAR_RENTAL_COMPANY_DISCOUNT_PLAN p ON c.CAR_TYPE = p.CAR_TYPE
WHERE 
    -- 세단 또는 SUV만 선택
    c.CAR_TYPE IN ('세단', 'SUV')
    -- 30일 이상 대여 할인율 적용
    AND p.DURATION_TYPE = '30일 이상'
    -- 해당 기간에 대여 중이지 않은 차량 선택
    AND c.CAR_ID NOT IN (
        SELECT CAR_ID 
        FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY 
        WHERE START_DATE <= '2022-11-30' 
        AND END_DATE >= '2022-11-01'
    )
    -- 대여 금액이 50만원 이상 200만원 미만
    AND (c.DAILY_FEE * (1 - p.DISCOUNT_RATE/100) * 30) >= 500000
    AND (c.DAILY_FEE * (1 - p.DISCOUNT_RATE/100) * 30) < 2000000
ORDER BY 
    FEE DESC,
    c.CAR_TYPE ASC,
    c.CAR_ID DESC;