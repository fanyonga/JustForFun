
## 学习JSTL标签库

### 自定义标签库

* 首先建立一个标签库文件

```xml
<?xml version="1.0" encoding="UTF-8"?>
<taglib xmlns="http://java.sun.com/xml/ns/javaee"
        xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
        xsi:schemaLocation="http://java.sun.com/xml/ns/javaee http://java.sun.com/xml/ns/javaee/web-jsptaglibrary_2_1.xsd"
        version="2.1">
    <tlib-version>1.0</tlib-version> <!--制定标签库版本-->
    <short-name>x</short-name> <!--指定使用时的前缀-->
    <uri>http://www.xc66.cc/functions</uri> <!--制定引用时需要导入的标签库地址-->
    <!--标签库的静态方法-->
    <function>
        <!--方法名-->
        <name>formatDate</name>
        <!--对应的类-->
        <function-class>com.honey.web.ElFunctions</function-class>
        <!--对应类的方法，格式为[返回值类型] 方法名(参数类型）-->
        <function-signature>java.lang.String formatSecond(java.lang.Long)</function-signature>
    </function>
    <function>
        <name>formatDateToLong</name>
        <function-class>com.honey.web.ElFunctions</function-class>
        <function-signature>long formatToLong(java.util.Date)</function-signature>
    </function>
</taglib>
```

* 在web.xml中声明

```xml
<jsp-config>
        <taglib>
            <taglib-uri>http://www.xc66.cc/functions</taglib-uri>
            <taglib-location>/WEB-INF/ElFunctions.tld</taglib-location>
        </taglib>
    </jsp-config>
```

* 写类`com.honey.web.ElFunctions`的方法的具体逻辑，建立`ElFunctions.java`文件

```java
public class ElFunctions {

    /**
     * 秒转化为格式为hh小时mm分钟的字符串
     * @param second
     * @return
     */
    public static String formatSecond(Long second) {
        long timeHour = second / 3600;
        long timeMin = (second - timeHour * 3600) / 60;
        return (timeHour > 0 ? timeHour + "小时" : "") + (timeMin > 0 ? timeMin + "分钟" : "")+
                (timeHour  == 0 && timeMin == 0 ? "0分钟" : "");
    }

    /**
     * Date类型转long
     * @param date
     * @return
     */
    public static long formatToLong(Date date) {
        return date.getTime()/1000;
    }
}
```

* 自定义标签库的使用

```java
<%@ taglib prefix="x" uri="http://www.xc66.cc/functions"%>
 <span class="d" t="${x:formatDate(p.createTime)}"></span>
  <span class="d" t="${x:formatDateToLong(p.createTime)}"></span>
```