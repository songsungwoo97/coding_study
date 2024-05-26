select ed.ID, ed.GENOTYPE, ed2.GENOTYPE as PARENT_GENOTYPE
from ECOLI_DATA ed join ECOLI_DATA ed2 on ed2.ID = ed.PARENT_ID
where ed.GENOTYPE & ed2.GENOTYPE = ed2.GENOTYPE
order by 1 asc