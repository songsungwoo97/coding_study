SELECT 
    i1.ITEM_ID, 
    i1.ITEM_NAME
FROM 
    ITEM_INFO i1 join ITEM_TREE i2 on i1.ITEM_ID = i2.ITEM_ID
where 
    i2.PARENT_ITEM_ID is null
ORDER BY 
    i1.ITEM_ID ASC;