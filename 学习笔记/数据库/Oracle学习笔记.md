## oracle学习笔记

1. 创建表空间    
	
	```sql
	/*创建临时表空间*/
	create temporary tablespace user_temp  
	tempfile 'E:\app\fanyong\oradata\orcl' 
	size 50m  
	autoextend on  
	next 50m maxsize 20480m  
	extent management local;  
	/*创建数据表空间*/
	create tablespace user_data  
	logging  
	datafile 'E:\app\fanyong\oradata\orcl' 
	size 50m  
	autoextend on  
	next 50m maxsize 20480m  
	extent management local;
	```  
1. 创建用户 
 
	```sql
	/*创建用户guest密码为123123*/
	create user guest identified by 123456 
	default tablespace user_data  
	temporary tablespace user_temp;
	```
2. 给用户赋予或收回系统权限  
	
	```sql
	grant create session，create table to guest (with admin option)(系统权限传递)
	revoke connect,resource from guest
	```

	| 系统权限 | 作用 |  
	|:--|:--|  
	| connect | 连接到数据库 |  
	| resource| 创建实体 | 
	| dba | 创建数据库结构 | 

3. 修改用户口令或删除用户(只有在用户包含数据库时，加上cascade)  
	```sql
	alter user guest identified by 123123 /*修改用户guest密码为123123*/
	drop user guest[cascade]
	```
4. 创建或删除学生表  
	```sql
	create table student_fanyong(
	stuno number(6) primary key,/*学号*/
	name varchar2(10) not null,/*姓名*/
	sex char(2) check(sex='男' or sex= '女'),/*性别*/
	age number(3),/*年龄*/
	birth_date date/*出生日期*/);

	drop table student_fanyong;
	```
5. 创建和删除视图
	```sql
	create or replace  view stu_view(stuno,name,age) as
	select stuno,name,age from student_fanyong;
	
	drop view stu_view;
	```
6. 创建和删除索引  
	
	```sql
	/*在查询student_fanyong表时优先搜索索引*/
	create unique index student_fanyong_name on student_fanyong(name);
	```
7. 三种方式的插入操作  

 	```sql
	/*直接赋值的插入*/
	insert into student_fanyong(stuno,name,sex,age,birth_date) 
			values(121334,'李四','男',21,to_date('10/8/95','mm/dd/yy'));
	/*带参数的插入*/
	insert into student_fanyong(stuno,name,sex) values(&stuno,'&name','&sex');
	/*带子查询的插入*/
	insert into student(stuno,name ,sex) select stuno,name,sex from student_fanyong;
	```
8. 修改操作  
	
	```sql
	update student_fanyong set name='王五' where name='李四';
	```
9. 删除操作  
 	
 	```sql
	delete from student_fanyong where name='王五';
	```
10. 单表查询  
	
	```sql
	/*条件查询*/
	select stuno,name from student_fanyong where sex='女';
	/*排序显示查询结果*/
	select * from student_fanyong order by stuno asc;
	/*分组查询，注意select后属性与group by保持一致。属性越靠后，排序比重越大（1,10,100,1000）*/
	select stuno,name,sex from student_fanyong group by stuno,name,sex;
	/*带条件的分组查询*/
	select name ,sex,count(*) from student_fanyong group by name,sex having sex='男';
	```
11. 多表查询  
	
	```sql
	/*等值连接：查询两表符合条件的结果*/
	select s1.name from student s1,student_fanyong s2 where s1.stuno=s2.stuno ;
	/*自连接*/
	select s1.name from student_fanyong s1,student_fanyong s2 where s1.stuno=s2.stuno;
	/*不等连接：除去等值连接的连接运算*/
	select s1.name from student s1,student_fanyong s2 where s1.stuno<>s2.stuno;
	/*外部链接：查询两表符合条件的结果和自表其他的结果*/
	select s1.name from student s1,student_fanyong s2 where s1.stuno=s2.stuno(+);

	/*等值连接*/
	select s1.name from student s1 inner join student_fanyong s2 on s1.stuno=s2.stuno ;
	/*左连接：查询s1表中所有的学生学号和s2中一样的学生姓名和s1表独有中的学生姓名*/
	select s1.name from student s1 left join on student_fanyong s2 on s1.stuno=s2.stuno;  
	/*右连接：查询s1表中所有的学生学号和s2中一样的学生姓名和s2表独有中的学生姓名*/
	select s2.name from student s1 right join on student_fanyong s2 on s1.stuno=s2.stuno; 
	```