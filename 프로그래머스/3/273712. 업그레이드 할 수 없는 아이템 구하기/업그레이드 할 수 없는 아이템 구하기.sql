select ii.ITEM_ID, ii.ITEM_NAME, ii.RARITY
from ITEM_INFO ii join ITEM_TREE it on ii.ITEM_ID = it.ITEM_ID
where it.ITEM_ID not in (select PARENT_ITEM_ID 
                         from ITEM_TREE 
                         where PARENT_ITEM_ID is not null)
order by ITEM_ID DESC