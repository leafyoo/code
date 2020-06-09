/* 
176. 第二高的薪水
https://leetcode-cn.com/problems/second-highest-salary/

编写一个 SQL 查询，获取 Employee 表中第二高的薪水（Salary） 。

+----+--------+
| Id | Salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+
例如上述 Employee 表，SQL查询应该返回 200 作为第二高的薪水。如果不存在第二高的薪水，那么查询应返回 null。

+---------------------+
| SecondHighestSalary |
+---------------------+
| 200                 |
+---------------------+

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/second-highest-salary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

https://leetcode-cn.com/problems/second-highest-salary/solution/qiu-di-er-gao-de-xin-shui-zhi-yun-yong-fen-ye-si-x/
 */

/* 
思路1：
使用子查询找出语文成绩查询最大的成绩记为a，然后再找出小于a的最大值就是课程成绩的第二高值。
max(列名) 可以返回该列的最大值
可以用下面的sql语句得到语文课的最大值

select max(distinct 成绩) 
from 成绩表
where 课程='语文';
然后再找出小于a的最大值就是课程成绩的第二高值。

select max(distinct 成绩) 
from 成绩表
where 课程='语文' and
      成绩 < (select max(distinct 成绩) 
              from 成绩表 
              where 课程='语文');

作者：houziAI
链接：https://leetcode-cn.com/problems/second-highest-salary/solution/tu-jie-sqlmian-shi-ti-ru-he-cha-zhao-di-ngao-de-sh/
 */
/* 
错误：limit 1,1 ，这里的1表示第二个元素
 */
select IFNULL( 
    (select distinct Salary
    from Employee
    order by Salary desc limit 1,1), 
    null) as SecondHighestSalary
;


/* 本表可能只有一项记录。为了克服这个问题，我们可以将其作为临时表。 */
select
    (select distinct Salary
    from Employee
    ORDER BY Salary DESC limit 1,1) 
as SecondHighestSalary;


/*性能低：
 执行用时 :213 ms, 在所有 MySQL 提交中击败了
9.75%的用户 */
select max(Salary) as SecondHighestSalary
from Employee
where Salary <> (select max(Salary)
from Employee);


select FirstName, LastName, City, State
from Person
    left join Address
    on Person.PersonId = Address.PersonId;


/* 
175. 组合两个表
写一个 SQL 查询，满足条件：无论 person 是否有地址信息，都需要基于上述两表提供 person 的以下信息：
https://leetcode-cn.com/problems/combine-two-tables/submissions/

注意：left join
 */
select FirstName, LastName, City, State
from Person
    left join Address
    on Person.PersonId = Address.PersonId;

/* 
178. 分数排名
https://leetcode-cn.com/problems/rank-scores/submissions/
编写一个 SQL 查询来实现分数排名。如果两个分数相同，则两个分数排名（Rank）相同。请注意，平分后的下一个名次应该是下一个连续的整数值。换句话说，名次之间不应该有“间隔”。

注意：用表的别名

知识点：关联子查询

 */

select a.Score,
    (select count(distinct Score)
    from Scores as b
    where b.Score >= a.Score ) 
as Rank
from Scores as a
order by a.Score desc;


/* 
185. 部门工资前三高的所有员工
https://leetcode-cn.com/problems/department-top-three-salaries/
Employee 表包含所有员工信息，每个员工有其对应的工号 Id，姓名 Name，工资 Salary 和部门编号 DepartmentId 。

题解：
https://leetcode-cn.com/problems/department-top-three-salaries/solution/185-bu-men-gong-zi-qian-san-gao-de-yuan-gong-by-li/

https://leetcode-cn.com/problems/department-top-three-salaries/solution/bu-men-gong-zi-qian-san-de-suo-you-yuan-gong-by-wo/

1.员工表自连求前三的工资，
因为是求前三 所以 (select count(distinct e2.salary) from employee e2 where e2.salary>e1.salary) <3 ,
因为是同部门的，比较工资大小的时候需要加条件 e1.departmentid=e2.departmentid

2.1的结果连接（join）部门表，查出所有字段

 */

SELECT
    d.name as Department,
    e1. NAME as Employee,
    e1.salary as Salary
FROM
    employee e1 JOIN department d ON d.id=e1.departmentid
WHERE
	(
		SELECT
    COUNT(DISTINCT e2.salary)
FROM
    employee e2
WHERE
                    e2.salary > e1.salary
    AND e1.departmentid = e2.departmentid
	) < 3
ORDER BY Department, Salary DESC;

/* 
fish
181. 超过经理收入的员工
https://leetcode-cn.com/problems/employees-earning-more-than-their-managers/submissions/

可以在leet执行一下：
select *
from Employee e1
    join Employee e2 
    on e1.ManagerId = e2.Id;
看看结果

 */

select e1.Name Employee
from Employee e1
    join Employee e2
    on e1.ManagerId = e2.Id
where e1.Salary > e2.Salary;


/* fish
https://leetcode-cn.com/problems/duplicate-emails/
182. 查找重复的电子邮箱


 */
select Email
from Person
group by Email
having count(Email) >=2

select Email
from
    (
    select Email, count(Email) as num
    from Person
    group by Email
) e
where num >= 2

select Email
from
    (
    select Email, count(Email) as num
    from Person
    group by Email
    having num >= 2
) e


/* fish
596. 超过5名学生的课
https://leetcode-cn.com/problems/classes-more-than-5-students/submissions/

 */
select class
from courses
group by class
having count(distinct student) >= 5


SELECT
    class
FROM
    (SELECT
        class, COUNT(DISTINCT student) AS num
    FROM
        courses
    GROUP BY class) AS temp_table
WHERE
    num >= 5;


/* 
177. 第N高的薪水
https://leetcode-cn.com/problems/nth-highest-salary/submissions/

注意：
1、分号；
2、end if
 */
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    if N < 1 then
    RETURN (select min(Salary)
    from Employee );
    else
    set N
    = N - 1;
RETURN 
        (
            select ifnull((select distinct Salary
    from Employee
    order by Salary desc limit N, 1), 
            null)
        );

    end if;
END


/* 
184. 部门工资最高的员工
https://leetcode-cn.com/problems/department-highest-salary/solution/bu-men-gong-zi-zui-gao-de-yuan-gong-by-leetcode/

 */
SELECT
    Department.name AS 'Department',
    Employee.name AS 'Employee',
    Salary
FROM
    Employee
    JOIN
    Department ON Employee.DepartmentId = Department.Id
WHERE
    (Employee.DepartmentId , Salary) IN
    (   SELECT
    DepartmentId, MAX(Salary)
FROM
    Employee
GROUP BY DepartmentId
	)
;

SELECT
    Department.NAME AS Department,
    Employee.NAME AS Employee,
    Salary
FROM
    Employee,
    Department
WHERE
	Employee.DepartmentId = Department.Id
    AND ( Employee.DepartmentId, Salary ) 
    IN (SELECT DepartmentId, max( Salary )
    FROM Employee
    GROUP BY DepartmentId )


/* 
1179. 重新格式化部门表
https://leetcode-cn.com/problems/reformat-department-table/submissions/
 */
SELECT id,
    SUM(CASE `month` WHEN 'Jan' THEN revenue END) Jan_Revenue,
    SUM(CASE `month` WHEN 'Feb' THEN revenue END) Feb_Revenue,
    SUM(CASE `month` WHEN 'Mar' THEN revenue END) Mar_Revenue,
    SUM(CASE `month` WHEN 'Apr' THEN revenue END) Apr_Revenue,
    SUM(CASE `month` WHEN 'May' THEN revenue END) May_Revenue,
    SUM(CASE `month` WHEN 'Jun' THEN revenue END) Jun_Revenue,
    SUM(CASE `month` WHEN 'Jul' THEN revenue END) Jul_Revenue,
    SUM(CASE `month` WHEN 'Aug' THEN revenue END) Aug_Revenue,
    SUM(CASE `month` WHEN 'Sep' THEN revenue END) Sep_Revenue,
    SUM(CASE `month` WHEN 'Oct' THEN revenue END) Oct_Revenue,
    SUM(CASE `month` WHEN 'Nov' THEN revenue END) Nov_Revenue,
    SUM(CASE `month` WHEN 'Dec' THEN revenue END) Dec_Revenue
FROM Department
GROUP BY id;



/* 
mysql的排名函数：rank, dense_rank, row_number
https://leetcode-cn.com/problems/rank-scores/solution/tu-jie-sqlmian-shi-ti-jing-dian-pai-ming-wen-ti-by/

 */

select *,
    rank() over (order by 成绩 desc) as ranking,
    dense_rank() over (order by 成绩 desc) as dese_rank,
    row_number() over (order by 成绩 desc) as row_num
from 班级



/* 
180. 连续出现的数字
https://leetcode-cn.com/problems/consecutive-numbers/
https://leetcode-cn.com/problems/consecutive-numbers/solution/lian-xu-chu-xian-de-shu-zi-by-leetcode/

 */
select distinct l1.num ConsecutiveNums
from
    Logs l1,
    Logs l2,
    Logs l3
where l1.Id = l2.Id -1
    and l2.Id = l3.Id -1
    and l1.num = l2.num
    and l2.num = l3.num

/* 错误case： 不要少了 distinct

select l1.num ConsecutiveNums  
from  
Logs l1, 
Logs l2, 
Logs l3 
where l1.Id = l2.Id -1
and l2.Id = l3.Id -1
and l1.num = l2.num
and l2.num = l3.num


输入:
{"headers": {"Logs": ["Id", "Num"]}, "rows": {"Logs": [[1, 3], [2, 3], [3, 3], [4, 3]]}}
输出
{"headers": ["ConsecutiveNums"], "values": [[3], [3]]}
预期结果
{"headers":["ConsecutiveNums"],"values":[[3]]}

 */

/*实验 1
结论：
1、同时从两个表select，得到的结果会是将连个表的行拼接成一行，行宽翻倍；
2、会有row * row种组合（行）
*/
select *
from Logs l1, Logs l2

/*
+----+-----+
| Id | Num |
+----+-----+
| 1  |  1  |
| 2  |  1  |
| 3  |  1  |
| 4  |  2  |
| 5  |  1  |
| 6  |  2  |
| 7  |  2  |
+----+-----+

执行结果： （n * n种组合，7*7种）

{"headers": ["Id", "Num", "Id", "Num"], "values": [[1, 1, 1, 1], [2, 1, 1, 1], [3, 1, 1, 1], [4, 2, 1, 1], [5, 1, 1, 1], [6, 2, 1, 1], [7, 2, 1, 1], [1, 1, 2, 1], [2, 1, 2, 1], [3, 1, 2, 1], [4, 2, 2, 1], [5, 1, 2, 1], [6, 2, 2, 1], [7, 2, 2, 1], [1, 1, 3, 1], [2, 1, 3, 1], [3, 1, 3, 1], [4, 2, 3, 1], [5, 1, 3, 1], [6, 2, 3, 1], [7, 2, 3, 1], [1, 1, 4, 2], [2, 1, 4, 2], [3, 1, 4, 2], [4, 2, 4, 2], [5, 1, 4, 2], [6, 2, 4, 2], [7, 2, 4, 2], [1, 1, 5, 1], [2, 1, 5, 1], [3, 1, 5, 1], [4, 2, 5, 1], [5, 1, 5, 1], [6, 2, 5, 1], [7, 2, 5, 1], [1, 1, 6, 2], [2, 1, 6, 2], [3, 1, 6, 2], [4, 2, 6, 2], [5, 1, 6, 2], [6, 2, 6, 2], [7, 2, 6, 2], [1, 1, 7, 2], [2, 1, 7, 2], [3, 1, 7, 2], [4, 2, 7, 2], [5, 1, 7, 2], [6, 2, 7, 2], [7, 2, 7, 2]]}
*/


/*实验 2
结论：
1、同时从两个表select，得到的结果会是将连个表的行拼接成一行，行宽翻倍；
2、会有row * row种组合（行），然后再按照where过滤
*/

select *
from Logs l1, Logs l2
where l1.Id = 1
/*
+----+-----+
| Id | Num |
+----+-----+
| 1  |  1  |
| 2  |  1  |
| 3  |  1  |
| 4  |  2  |
| 5  |  1  |
| 6  |  2  |
| 7  |  2  |
+----+-----+

执行结果： 

{"headers": ["Id", "Num", "Id", "Num"], "values": [[1, 1, 1, 1], [1, 1, 2, 1], [1, 1, 3, 1], [1, 1, 4, 2], [1, 1, 5, 1], [1, 1, 6, 2], [1, 1, 7, 2]]}

*/


/* 实验3
注意： Id 前面必须指定table名字
多个table之间要有，号
 */
select l1.Id
from Logs l1, Logs l2
where l1.Id = 1

/*
+----+-----+
| Id | Num |
+----+-----+
| 1  |  1  |
| 2  |  1  |
| 3  |  1  |
| 4  |  2  |
| 5  |  1  |
| 6  |  2  |
| 7  |  2  |
+----+-----+

执行结果： 

{"headers": ["Id"], "values": [[1], [1], [1], [1], [1], [1], [1]]}
*/



/* 
183. 从不订购的客户
https://leetcode-cn.com/problems/customers-who-never-order/

 */
select c1.Name as Customers
from Customers c1
where c1.Id not in (select c.Id
from Customers c right join Orders o
    on c.Id = o.CustomerId )
/* 
错误case： 不能根据姓名过滤，因为姓名相同的人有多个，只可以根据id来过滤

select c1.Name as Customers 
from Customers c1 where c1.Name not in (select c.Name from Customers c right join Orders o
    on c.Id = o.CustomerId )
输入:
{"headers": {"Customers": ["Id", "Name"], "Orders": ["Id", "CustomerId"]}, "rows": {"Customers": [[1, "James"], [2, "James"]], "Orders": [[1, 1]]}}
输出
{"headers": ["Customers"], "values": []}
预期结果
{"headers":["Customers"],"values":[["James"]]}
 */




/* 
196. 删除重复的电子邮箱
https://leetcode-cn.com/problems/delete-duplicate-emails/

 */
DELETE p1 FROM Person p1,
    Person p2
WHERE
    p1.Email = p2.Email AND p1.Id > p2.Id



DELETE FROM Person
WHERE Id NOT IN (   -- 删除不在查询结果中的值
    SELECT id
FROM
    (
       SELECT MIN(Id) AS Id
    -- 排除Email相同时中Id较大的行
    FROM Person
    GROUP BY Email
   ) AS temp    -- 此处需使用临时表，否则会发生报错
)


/* 
197. 上升的温度
https://leetcode-cn.com/problems/rising-temperature/
*/
select w1.Id
from
    Weather w1,
    Weather w2
where w1.Temperature > w2.Temperature
    and datediff(w1.RecordDate, w2.RecordDate ) = 1


/* 
595. 大的国家
https://leetcode-cn.com/problems/big-countries/
 */
select name, population, area
from World
where 
population > 25000000
    or
    area > 3000000

/* 
比上面这个方法 运行速度更快
 */
    SELECT
        name, population, area
    FROM
        world
    WHERE
    area > 3000000

UNION

    SELECT
        name, population, area
    FROM
        world
    WHERE
    population > 25000000


/* 
620. 有趣的电影
https://leetcode-cn.com/problems/not-boring-movies/
 */
select * from cinema 
where description not like '%boring%'
and mod(id, 2) = 1
order by rating desc


select * from cinema 
where description <> 'boring'
and mod(id, 2) = 1
order by rating desc

/* 
627. 交换工资
https://leetcode-cn.com/problems/swap-salary/
 */

update salary set sex =
if(sex = 'f', 'm', 'f')


/* 
511. 游戏玩法分析 I
https://blog.csdn.net/Hello_JavaScript/article/details/102967865


 */

select player_id, min(event_date) as first_login
from Activity
group by player_id;


/* 
LeetCode-512. 游戏玩法分析 II
https://blog.csdn.net/qq_43618030/article/details/104187459

 */
select a.player_id, a.device_id
from
    Activity a
    right join (
    select player_id, min(event_date) as latest_date
    from
        Activity
    group by player_id) b on a.event_date = b.latest_date
where a.player_id = b.player_id


select a.player_id , a.device_id
from Activity a
where (a.player_id ,a.event_date
) in
(select player_id, min(event_date) as first_login
from Activity
group by player_id)


/* 
577. Employee Bonus 员工奖金
https://blog.csdn.net/weixin_30402343/article/details/97515186
 */

SELECT name, bonus
FROM Employee LEFT JOIN Bonus
on e.empId = b.empId
where bonus < 1000 or bonus is null

SELECT name, bonus
FROM Employee LEFT JOIN Bonus
on e.empId = b.empId
WHERE IFNULL(bonus, 0) < 1000　　


/* 
584 寻找用户推荐人
https://blog.csdn.net/qq_32424059/article/details/90413782
 */
select name
from customer
where referee_id != 2 or referee_id is NULL

/*  待验证*/
select name
from customer
where referee_id <> 2


/* 
586.订单最多的客户
https://blog.csdn.net/weixin_41723227/article/details/99317337

 */
 SELECT
	customer_number
FROM
	orders
GROUP BY customer_number
ORDER BY COUNT(*) DESC
LIMIT 1

/* 
597	 好友申请 I ：总体通过率
https://blog.csdn.net/weixin_43329319/article/details/96378865

fish：
round()把数值字段舍入为指定的小数位数
 */
select round(
            ifnull(count(distinct requester_id,accepter_id) 
                / count(distinct sender_id,send_to_id), 
            0),
        2) as accept_rate
from friend_request,request_accepted


/* 
603. 连续空余座位
https://blog.csdn.net/Hello_JavaScript/article/details/103388520
| seat_id | free |
|---------|------|
| 1       | 1    |
| 2       | 0    |
| 3       | 1    |
| 4       | 1    |
| 5       | 1    |
 */

 /* fish: join on里的on后面跟的条件很灵活 */
select A1.seat_id as id1,A2.seat_id as id2
from cinema as A1 
join cinema as A2 on(A1.seat_id+1 = A2.seat_id and A1.free = 1 and A2.free = 1)


