# Write your MySQL query statement below
select unique_id,name 
from Employees AS e 
LEFT JOIN EmployeeUNI AS em  
on e.id = em.id;