SELECT CONCAT('/home/grep/src/', ugb.BOARD_ID, '/', ugf.FILE_ID, ugf.FILE_NAME, ugf.FILE_EXT) AS FILE_PATH
from USED_GOODS_BOARD ugb join USED_GOODS_FILE ugf on ugb.BOARD_ID = ugf.BOARD_ID
where ugb.VIEWS = (select max(VIEWS) from USED_GOODS_BOARD)
order by ugf.FILE_ID DESC