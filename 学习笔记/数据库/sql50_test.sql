-- 表结构
-- fy_student(sno,sname,sage,ssex) 学生表
-- course(cno,cname,tno) 课程表
-- sc(sno,cno,score) 成绩表
-- fy_teacher(tno,tname) 教师表


--1、查询课程1的成绩 比 课程2的成绩 高 的所有学生的学号.
select  a.sno from 
(select c1.sno,c1.score from sc c1 where c1.cno=1) a ,
(select c2.sno,c2.score from sc c2 where c2.cno=2) b 
where a.score>b.score and a.sno=b.sno;

--2、查询平均成绩大于60分的同学的学号和平均成绩；
select sno,avg(score) from sc 
group by sno 
having avg(score)>60 
order by avg(score) desc;

--3、查询所有同学的学号、姓名、选课数、总成绩
select s1.sno,s2.sname,count(*),sum(s1.score) from
sc s1 inner join fy_student s2 on s1.sno=s2.sno
group by s2.sname,s1.sno
order by sum(s1.score) desc;

--4、查询姓“李”的老师的个数；
select count(*) from fy_teacher where tname like '李%';

--5、查询没学过“叶平”老师课的同学的学号、姓名；
select sno,sname from fy_student
where sno not in (
select distinct(s1.sno) 
from sc s1,course c1,fy_teacher t1
where s1.cno=c1.cno and c1.tno=t1.tno and t1.tname='叶平');

--6、查询同时学过课程1和课程2的同学的学号、姓名
select sno,sname from fy_student
where sno in (
select sno from sc where sc.cno=1) and
sno in (select sno from sc where sc.cno=2);

--7、查询学过“叶平”老师所教所有课程的所有同学的学号、姓名
select sno,sname from fy_student
where sno  in (
select s1.sno 
from sc s1,course c1,fy_teacher t1
where s1.cno=c1.cno and c1.tno=t1.tno and t1.tname='叶平');

--8、查询 课程编号1的成绩 比 课程编号2的成绩 高的所有同学的学号、姓名
select sno,sname from fy_student
where sno in (
select a.sno from
(select sno ,score from sc where cno=1) a,
(select sno ,score from sc where cno=2) b
where a.sno=b.sno and a.score>b.score
);

--9、查询所有课程成绩小于60分的同学的学号、姓名
select sno,sname from fy_student
where sno not in (
select distinct sno from sc where score>60
);

--10、查询所有课程成绩大于60分的同学的学号、姓名
select sno,sname from fy_student
where sno not in (
select distinct sno from sc where score<60
);

--11、查询没有学全所有课的同学的学号、姓名
select sno,sname from fy_student
where sno not in (
select distinct sno from sc 
group by sno 
having count(*) =(select count(distinct cno) from sc)
);

--12、查询至少有一门课程 与 学号为1的同学所学课程 相同的同学的学号和姓名
select sno ,sname from fy_student
where sno<>1 and sno  in(
	select sno from sc where cno  in (
		select distinct cno from sc where sno=1
	)
);

--13、把“sc”表中“叶平”所教课的成绩都更改为此课程的平均成绩
update sc set score=(select avg(sc_2.score) from sc sc_2 where sc_2.cno=sc.cno)
where sc.cno in (select course.cno from fy_teacher,course where fy_teacher.tno=course.tno  and fy_teacher.tname='叶平');

--14、查询和2号同学学习的课程完全相同的其他同学学号和姓名
select sno,sname from fy_student
where sno in (select sno from sc 
where sno <>2
group by sno
having sum(cno)=(select sum(cno) from sc where sno=2));

--15、删除学习“叶平”老师课的sc表记录
delete from sc where cno in (
	select a.cno from course a,fy_teacher b where a.tno=b.tno and b.tname='叶平' 
);

--16、向sc表中插入一些记录，这些记录要求符合以下条件：
--将没有课程3成绩同学的该成绩补齐, 其成绩取所有学生的课程2的平均成绩
insert into sc select sno,3,(select avg(score) from sc where cno=2) 
	from fy_student where sno not in
	(select sno from sc where cno =3);

--17、按平平均分从高到低显示所有学生的如下统计报表：
-- 学号,企业管理,马克思,UML,数据库,物理,课程数, 平均分

select sno as 学号,
max(case when cno=1 then score end) as 企业管理,
max(case when cno=2 then score end) as 马克思,
max(case when cno=3 then score end) as UML,
max(case when cno=4 then score end) as 数据库,
max(case when cno=5 then score end) as 物理,
count(*) as 课程数,
avg(score) as 平均分
from sc 
group by sno
order by 平均分;

--18、查询各科成绩最高分和最低分：以如下形式显示：课程号，最高分，最低分
select cno as 课程号,
max(score) as 最高分,
min(score) as 最低分
from sc
group by cno;

--19、按各科平均成绩从低到高和及格率的百分数从高到低顺序
select t.cno as 课程号,
max(course.cname)as 课程名,
nvl(avg(score),0) as 平均成绩,
100 * sum(case when nvl(score,0)>=60 then 1 else 0 end)/count(1) as 及格率
from sc t, course
where t.cno = course.cno
group by t.cno
group by 平均成绩 asc,及格率;

--20、查询如下课程平均成绩和及格率的百分数(用"1行"显示): 企业管理（001），马克思（002），UML （003），数据库（004） 
select avg (case when cno=1 then score end) as 平均分1,
avg (case when cno=2 then score end) as 平均分2,
avg (case when cno=3 then score end) as 平均分3,
avg (case when cno=4 then score end) as 平均分4,
100*sum(case when nvl(score,0)>=60 and cno=1 then 1 else 0 end)/count(1) as 及格率1,
100*sum(case when nvl(score,0)>=60 and cno=2 then 1 else 0 end)/count(1) as 及格率2,
100*sum(case when nvl(score,0)>=60 and cno=3 then 1 else 0 end)/count(1) as 及格率3,
100*sum(case when nvl(score,0)>=60 and cno=4 then 1 else 0 end)/count(1) as 及格率4
from sc;

--21、查询不同老师所教不同课程平均分, 从高到低显示
-- 张老师 数据库 88
select t.tname,a.cname,avg(sc.score)
from fy_teacher t,course a,sc
where t.tno=a.tno and a.cno=sc.cno
group by a.cname,t.tname
order by avg(sc.score) desc;

--22、查询如下课程成绩均在第3名到第6名之间的学生的成绩：
-- [学生ID],[学生姓名],企业管理,马克思,UML,数据库,平均成绩
select stu.sno as 学生ID,
stu.sname as 学生姓名,
max(case when sc.cno=1 then score end) as 企业管理,
max(case when sc.cno=2 then score end) as 马克思,
max(case when sc.cno=3 then score end) as UML,
max(case when sc.cno=4 then score end) as 数据库,
avg(score) as 平均成绩
from fy_student stu,sc
where stu.sno=sc.sno and
stu.sno in (select * from (select sno from sc where cno=1 order by score desc) where rownum <7) and
stu.sno not in (select * from (select sno from sc where cno=1 order by score desc) where rownum <3) and
stu.sno in (select * from (select sno from sc where cno=2 order by score desc) where rownum <7) and
stu.sno not in (select * from (select sno from sc where cno=2 order by score desc) where rownum <3) and
stu.sno in (select * from (select sno from sc where cno=3 order by score desc) where rownum <7) and
stu.sno in (select * from (select sno from sc where cno=4 order by score desc) where rownum <7) and
stu.sno not in (select * from (select sno from sc where cno=4 order by score desc) where rownum <3)
group by stu.sname ,stu.sno;

--23、统计打印各科成绩,各分数段人数:课程ID,课程名称,[100-85],[85-70],[70-60],[ <60]
select sc.cno as 课程ID,
b.cname as 课程名称,
sum(case when sc.score>=85 and sc.score<=100 then 1 else 0 end) as 从100到85， 
sum(case when sc.score>=70 and sc.score<85 then 1 else 0 end) as 从85到70, 
sum(case when sc.score>=60 and sc.score<70 then 1 else 0 end) as 从70到60, 
sum(case when sc.score<60 then 1 else 0 end) as 小于60
from sc,course b
where sc.cno=b.cno
group by b.cname,sc.cno;

--24、查询学生平均分及其名次
select sno as 学生编号,
score_avg as 平均分,
rownum as 名次 from
(select sno,avg(score) as score_avg from sc
group by sno
order by score_avg desc);

--25、查询课程2成绩前三名的记录:(不考虑成绩并列情况) 
select * from (
select * from sc order by score desc
)where rownum<4 and cno=2;

--26、查询每门课程被选修的学生数 
select cno,count(*) from sc group by cno order by count(*);

--27、查询出只选修了一门课程的全部学生的学号和姓名 
select a.sno ,a.sname
from fy_student a,sc
where a.sno=sc.sno
group by a.sname,a.sno
having count(*)=7;

--28、查询男生、女生人数 
select sum(case when ssex='男' then 1 else 0 end) as 男生人数,
sum(case when ssex='女' then 1 else 0 end) as 女生人数
from fy_student;

--29、查询姓“张”的学生名单 
select * from fy_student where sname like '张%';

--30、查询同名同性学生名单，并统计同名人数
select sname,ssex from fy_student
group by sname,ssex
having count(*)>1;

--31、1981年出生的学生名单(注：student表中sage列的类型是date) 
--采用字符串方式比较年数
select * from fy_student
where to_char(sage) like '%81';

--32、查询每门课程的平均成绩，结果按平均成绩升序排列，平均成绩相同时，按课程号降序排列 
select cno,avg(score) from sc
group by cno
order by cno desc,avg(score) asc;

--33、查询平均成绩大于80的所有学生的学号、姓名和平均成绩
select a.sno,a.sname,avg(score)
from fy_student a,sc
where a.sno=sc.sno
group by a.sname,a.sno
having avg(score)>80;

--34、查询 数据库 分数 低于60的学生姓名和分数
select a.sname,sc.score
from fy_student a,sc,course b
where a.sno=sc.sno and sc.cno=b.cno and cname='数据库' and sc.score<60;

--35、查询所有学生的选课情况
select a.sno, a.sname,count(sc.cno)
from fy_student a left join sc on a.sno=sc.sno
group by a.sname,a.sno;

--36、查询成绩在70分以上的学生姓名、课程名称和分数
select a.sname,b.cname,sc.score from
fy_student a,course b, sc
where a.sno=sc.sno and b.cno=sc.sno and sc.score>70;

--37、查询有不及格成绩的课程，并按课程号从大到小排列
select distinct cno from sc
where score<60
order by cno desc;

--38、查询课程编号为3且课程成绩在80分以上的学生的学号和姓名
select a.sno ,a.sname
from fy_student a,sc
where a.sno=sc.sno and cno=3 and sc.score>80;

--39、求选了课程的学生人数 
select count(distinct(a.sno))
from fy_student a inner join sc on a.sno=sc.sno;

--40、查询选修“叶平”老师所授课程的学生中，成绩最高的学生姓名及其成绩 
select a.sname ,sc.score
from fy_student a ,sc,fy_teacher b,course c
where sc.cno=c.cno and c.tno=b.tno and b.tname='叶平' and
score=(select max(score) from sc  d where d.cno=c.cno);

--41、查询各个课程及相应的选修人数 
select c.cname,count(*)
from course c inner join sc on c.cno=sc.cno
group by c.cname;

--42、查询不同课程成绩相同的学生的学号、课程号、学生成绩
--自表查询 
select a.sno,a.cno,a.score from sc a,sc b where a.score=b.score and a.cno!=b.cno;

--43、查询课程编号为2成绩最好的前两名的学生ID
select sno from (
select * from sc where cno=2 order by score)
where rownum<3;

--44、统计每门课程的学生选修人数(至少有2人选修的课程才统计)。要求输出课程号和选修人数，
--查询结果按人数降序排列，若人数相同，按课程号升序排列 
select cno ,count(sno)
from sc
group by cno
having count(sno)>2;

--45、检索至少选修了5门课程的学生学号
select sno,count(cno)
from sc
group by sno
having count(cno)>=5;

--46、查询全部学生都选修的课程的课程号和课程名
select cno ,count(sno)
from sc
group by cno
having count(sno)=(select count(stu.sno) from fy_student stu);

--47、查询没学过“叶平”老师讲授的任一门课程的学生姓名
select sname from fy_student
where sno not in (
	select distinct sno from sc,course a,fy_teacher b
	where sc.cno=a.cno and a.tno=b.tno and b.tname='叶平'
);

--48、查询两门以上不及格课程的同学的学号及其平均成绩
select a.sno ,avg(a.score)
from sc a
where a.sno in (
	select sno
	from sc
	where score<60
	group by sno
	having count(sno)>=2)
group by a.sno;

--49、检索4号课程分数大于60的同学学号，按分数降序排列
select sno,score
from sc
where cno=4 and score>=60
order by score desc;

--50、删除2号同学的课程1的成绩
delete from sc where sno=2 and cno=1;

/*
总结：
1. oracle使用select * from （SQL）where rownum<n来代替mysql中的top n用法。
2. group by必须与select的参数同步，聚合函数除外。
3. 使用（case when 条件 then ... else ... end)来执行条件操作。
4. 含%,_,&字符的字段需要用转译字符，设置转移字符set escape /。
5. oracle使用nvl(字段，填充数)来代替mysql中的isnull(字段，填充数)，表示当该字段为空时，用填充数表示。
6. 子查询只能嵌套上一层的属性。
*/