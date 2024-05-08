SELECT 
    INGREDIENT_TYPE, 
    SUM(TOTAL_ORDER) AS TOTAL_ORDER
FROM 
    (
        SELECT 
            i.FLAVOR, 
            i.INGREDIENT_TYPE, 
            f.TOTAL_ORDER
        FROM 
            ICECREAM_INFO i
            JOIN FIRST_HALF f ON i.FLAVOR = f.FLAVOR
    ) t
GROUP BY 
    INGREDIENT_TYPE
ORDER BY 
    TOTAL_ORDER ASC;