
# Mybaits学习笔记

## 简介

Mybatis是支持定制化SQL,存储过程以及高级映射的优秀的持久层框架.MyBatis 避免了几乎所有的JDBC代码和手动设置参数以及获取结果集.Mybatis可以对配置和原生的map使用简单的XML或注解,将接口和Java的POJOs映射成数据库中的记录.

## Mybatis的使用

### 构建SqlSessionFactory

* 从XML中构建`SqlSessionFactory`:一般需一个配置文件和多个`mybatis-config.xml`和多个习惯上基于类的映射文件,获取代码如下:

```java
String resource = "org/mybatis/example/mybatis-config.xml";
InputStream inputStream = Resources.getResourceAsStream(resource);
sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);
```

注意在mybatis3中`mybatis-config.xml`的节点有着严格的顺序:

	properties>settings>typeAliases>typeHandlers>objectFactory>objectWrapperFactory>plugins>environments>databaseIdProvider>mappers

* 不使用XML构建`SqlSessionFactory`:即使用映射器类的方式,获取代码如下:

```java
DataSource dataSource = BlogDataSourceFactory.getBlogDataSource();
TransactionFactory transactionFactory = new JdbcTransactionFactory();
Environment environment = new Environment("development", transactionFactory, dataSource);
Configuration configuration = new Configuration(environment);
configuration.addMapper(BlogMapper.class);
SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(configuration);
```

### 从`SqlSessionFactory`中获取`SqlSession`

* 通过类映射的XML文件来获取`SqlSession`

```java
SqlSession session = sqlSessionFactory.openSession();
try {
  Blog blog = (Blog) session.selectOne("org.mybatis.example.BlogMapper.selectBlog", 101);
} finally {
  session.close();
}
```

* 通过映射器类的方式获取`SqlSession`

```java
SqlSession session = sqlSessionFactory.openSession();
try {
  /*BlogMapper为实体类Blog的映射器类*/
  BlogMapper mapper = session.getMapper(BlogMapper.class);
  Blog blog = mapper.selectBlog(101);
} finally {
  session.close();
}
```

### 实体类映射两种方式

* 通过映射器类来进行映射,代码如下:

```java
package org.mybatis.example;
public interface BlogMapper {
  @Select("SELECT * FROM blog WHERE id = #{id}")
  Blog selectBlog(int id);
}
```

在`mybatis-config.xml`中<mappers>节点下加入代码

	<mapper class="org.mybatis.example.BlogMapper"/>

* 通过xml文件来进行映射,简单实力如下:

```xml
<?xml version="1.0" encoding="UTF-8" ?>
<!DOCTYPE mapper
  PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN"
  "http://mybatis.org/dtd/mybatis-3-mapper.dtd">
<mapper namespace="org.mybatis.example.BlogMapper">
  <select id="selectBlog" resultType="Blog">
    select * from Blog where id = #{id}
  </select>
</mapper>
```

在`mybatis-config.xml`中<mappers>节点下加入代码

	<mapper resource="org/mybatis/example/BlogMapper.xml"/>

### Mapper XML 文件

SQL映射文件的9大顶级元素:  

* cache 	给定命名空间的缓存配置,用来存储使用过的SQL语句.
* cache -ref	通过引用来使用其他命名空间的缓存设置  
* resultMap	**最复杂也最强大的元素,用于描述如何从数据库结果集中加载对象**
* ~~parameterMap 已废弃,老式风格的参数映射~~
* sql 		可被其他语句引用的可重用语句块  
* insert 	映射插入语句块
* update 	映射更新语句块
* delete 	映射删除语句块
* insert 	映射插入语句块

#### 在增删改查映射有个非常重要的属性
* `parameterType`用来指定传入参数的值
	- 简单类型(java8大类型)	可以取任何名称,它的值通过反射获得,但是在混写的ONGL语言中必须使用_parameter
	- 对象类型	直接引用对象的属性名
	- List类型	使用foreach时`collection="list"`是固定的
	- 数组类型	会自动转化为`java.util.HashList`类型,但是使用foreach时,`collection="array"`
	- 传入Map类型	使用map对应的keyname,但是如果map中含有array或这list类型的对象时,则collection必须等于具体array或这list类型的变量名

#### resultMap
* resultMap最基本的用法是通过制定属性和列之间的对应关系来解决名称不一致的问题,如下所示

```xml
<resultMap id="userResultMap" type="User">
  <id property="id" column="user_id" />
  <result property="username" column="user_name"/>
  <result property="password" column="hashed_password"/>
</resultMap>
```

* 高级映射

```sql
<!-- Very Complex Statement -->
<select id="selectBlogDetails" resultMap="detailedBlogResultMap">
  select
       B.id as blog_id,
       B.title as blog_title,
       B.author_id as blog_author_id,
       A.id as author_id,
       A.username as author_username,
       A.password as author_password,
       A.email as author_email,
       A.bio as author_bio,
       A.favourite_section as author_favourite_section,
       P.id as post_id,
       P.blog_id as post_blog_id,
       P.author_id as post_author_id,
       P.created_on as post_created_on,
       P.section as post_section,
       P.subject as post_subject,
       P.draft as draft,
       P.body as post_body,
       C.id as comment_id,
       C.post_id as comment_post_id,
       C.name as comment_name,
       C.comment as comment_text,
       T.id as tag_id,
       T.name as tag_name
  from Blog B
       left outer join Author A on B.author_id = A.id
       left outer join Post P on B.id = P.blog_id
       left outer join Comment C on P.id = C.post_id
       left outer join Post_Tag PT on PT.post_id = P.id
       left outer join Tag T on PT.tag_id = T.id
  where B.id = #{id}
</select>
```

对应的映射关系:

```xml
<!-- Very Complex Result Map -->
<resultMap id="detailedBlogResultMap" type="Blog">
   <!--通过构造参数传值,如果有多个构造参数则通过javaType的排列来确定具体的构造参数-->
  <constructor>
    <idArg column="blog_id" javaType="int"/>
  </constructor>
  <!-- 最基本的传值方式 -->
  <result property="title" column="blog_title"/>
  <!-- 通过关联关系来构造一个对象并传入-->
  <association property="author" javaType="Author" columnPrefix="author_" >
    <id property="id" column="author_id"/>
    <result property="username" column="username"/>
    <result property="password" column="password"/>
    <result property="email" column="email"/>
    <result property="bio" column="bio"/>
    <result property="favouriteSection" column="favourite_section"/>
  </association>
  <!--一对多关系,传入多的一方的集合-->
  <collection property="posts" ofType="Post" >
    <id property="id" column="post_id"/>

    <result property="subject" column="post_subject"/>

    <association property="author" javaType="Author"/>

    <collection property="comments" ofType="Comment" columnPrefix="comment_">
      <id property="id" column="id"/>
      <result property="name" column="name"/>
      <result property="text" column="text"/>
    </collection>
    <collection property="tags" ofType="Tag" >
      <id property="id" column="tag_id"/>
      <id property="name" column="tag_name"/>
    </collection>

    <!-- 鉴别器通过查询出来的值,来过滤掉不符合条件的数据 -->
    <discriminator javaType="int" column="draft">
      <case value="1" resultType="DraftPost"/>
    </discriminator>

  </collection>
</resultMap>
```

* 三种自动映射的级别
	- NONE - disables auto-mapping. Only manually mapped properties will be set.
	- PARTIAL - will auto-map results except those that have nested result mappings defined inside (joins).
	- FULL - auto-maps everything.
通常默认使用PARTIAL,映射完所有指定的列后,在将剩下的列按名称与类的属性名相对映射

### 动态SQL
在mybatis的mapper文件中支持ognl语言,可在test等表达式中直接调用java方法,但是注意特殊符号要转义成HTML类型如:

	<if test="&quot;&quot;.equals(command.trim())">....</if> //等价与"".equals()方法

* if 满足条件则输出

* choose, when, otherwise 判断参数类型,并执行相应的条件语句

```xml
<select id="findActiveBlogLike"
     resultType="Blog">
  SELECT * FROM BLOG WHERE state = ‘ACTIVE’
  <choose>
    <when test="title != null">
      AND title like #{title}
    </when>
    <when test="author != null and author.name != null">
      AND author_name like #{author.name}
    </when>
    <otherwise>
      AND featured = 1
    </otherwise>
  </choose>
</select>
```

* trim

```xml
<select id="findActiveBlogLike"
     resultType="Blog">
  SELECT * FROM BLOG 
 <!--  语句开头是prefixOverrides内值之一时,将其替换为prefix的属性值 -->
  <trim prefix="WHERE" prefixOverrides="AND| OR"> 
    <if test="state != null">
         AND state = #{state}
    </if> 
    <if test="title != null">
        OR title like #{title}
    </if>
    <if test="author != null and author.name != null">
        AND author_name like #{author.name}
    </if>
  </trim>
</select>
```

* where 

```xml
<select id="findActiveBlogLike"
     resultType="Blog">
  SELECT * FROM BLOG 
  <!-- 至少满足一个条件时,输出where -->
  <where> 
    <if test="state != null">
         state = #{state}
    </if> 
    <if test="title != null">
        AND title like #{title}
    </if>
    <if test="author != null and author.name != null">
        AND author_name like #{author.name}
    </if>
  </where>
</select>
```

* set

```xml
<update id="updateAuthorIfNecessary">
  update Author
    <set>
      <if test="username != null">username=#{username},</if>
      <if test="password != null">password=#{password},</if>
      <if test="email != null">email=#{email},</if>
      <if test="bio != null">bio=#{bio}</if>
    </set>
  where id=#{id}
</update>
```

* foreach

```xml
<select id="selectPostIn" resultType="domain.blog.Post">
  SELECT *
  FROM POST P
  WHERE ID in
  <!-- 遍历一个集合,并将SQL值拼接为(?,?,?)的形式 -->
  <foreach item="item" index="index" collection="list"
      open="(" separator="," close=")">
        #{item}
  </foreach>
</select>
```

* bind

```xml
<select id="selectBlogsLike" resultType="Blog">
   <!-- 从 OGNL 表达式中创建一个变量并将其绑定到上下文 -->
  <bind name="pattern" value="'%' + _parameter.getTitle() + '%'" />
  SELECT * FROM BLOG
  WHERE title LIKE #{pattern}
</select>
```
