/* 
176. 第二高的薪水
https://leetcode-cn.com/problems/second-highest-salary/

https://leetcode-cn.com/problems/second-highest-salary/solution/qiu-di-er-gao-de-xin-shui-zhi-yun-yong-fen-ye-si-x/
 */

/* 
错误：limit 1,1 ，这里的1表示第二个元素
 */
select IFNULL( 
    (select distinct Salary from Employee order by Salary desc limit 1,1), 
    null) as SecondHighestSalary ;


/* 本表可能只有一项记录。为了克服这个问题，我们可以将其作为临时表。 */
select  
(select distinct Salary from Employee ORDER BY Salary DESC limit 1,1) 
as SecondHighestSalary;


/*性能低：
 执行用时 :213 ms, 在所有 MySQL 提交中击败了
9.75%的用户 */
select max(Salary) as SecondHighestSalary from Employee 
    where Salary <> (select max(Salary) from Employee);

