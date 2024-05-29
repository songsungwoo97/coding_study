select ec1.ID, COUNT(ec2.ID) AS CHILD_COUNT
from ECOLI_DATA ec1 left join ECOLI_DATA ec2 on ec1.ID = ec2.PARENT_ID
group by 1
order by 1