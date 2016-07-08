package com.fanyong.calculator;

import com.fanyong.proxy.CalculatorValidationHandler;
import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

/**
 * Created by fanyong on 16-6-2.
 * 测试spring代理类
 */
public class CalculatorSpringTest {
    @Test
    public void testProxy()
    {

        ApplicationContext context=new ClassPathXmlApplicationContext("spring.xml");
//        ArithmeticCalculator c1=(ArithmeticCalculator)context.getBean("arithmeticCalculatorProxy");
////        c1.add(2,3);
        UnitCalculator u1=(UnitCalculator)context.getBean("unitCalculatorImp");
//        u1.kilometerToMile(-1000);
        ArithmeticCalculator c1=(ArithmeticCalculator)context.getBean("arithmeticCalculatorImp");
        c1.add(2,3);
        c1.add(3,4);

        u1.kilometerToMile(200);

        ((MaxCalculator)c1).max(2,3);//动态实现其他的接口
        ((MinCalculator)c1).min(2,3);

        ((Counter)c1).getCount();//输出算法运算器的运算次数
        ((Counter)u1).getCount();//输出度量计算器的运算次数
    }
}
