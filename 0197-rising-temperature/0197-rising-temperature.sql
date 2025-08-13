# Write your MySQL query statement below
select today.id from 
Weather as yesterday  
cross join Weather as today
where DateDIFF(today.recordDate,yesterday.recordDate)=1
and today.temperature > yesterday.temperature;