# Write your MySQL query statement below
select (select distinct salary
from employee
order by salary DESC
limit 1 offset 1) as SecondHighestSalary;
