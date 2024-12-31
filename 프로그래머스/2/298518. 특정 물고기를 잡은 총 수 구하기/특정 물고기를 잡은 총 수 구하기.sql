select count(*) as FISH_COUNT
from FISH_INFO fi, FISH_NAME_INFO fni
where fi.FISH_TYPE = fni.FISH_TYPE and (fni.FISH_NAME = 'BASS' or fni.FISH_NAME = 'SNAPPER')