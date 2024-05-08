SELECT 
    i.ITEM_ID, 
    i.ITEM_NAME
FROM 
    ITEM_INFO i
WHERE 
    i.ITEM_ID IN (
        SELECT 
            DISTINCT ITEM_ID
        FROM 
            ITEM_TREE
        WHERE 
            PARENT_ITEM_ID IS NULL
    )
ORDER BY 
    i.ITEM_ID ASC;