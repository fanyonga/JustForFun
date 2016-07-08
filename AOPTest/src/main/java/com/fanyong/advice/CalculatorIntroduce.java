package com.fanyong.advice;

import com.fanyong.calculator.*;
import org.aspectj.lang.annotation.After;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.DeclareParents;
import org.springframework.stereotype.Component;

/**
 * Created by fanyong on 16-6-5.
 */
@Component
@Aspect
public class CalculatorIntroduce {/*动态地实现多个接口的功能*/

    @DeclareParents(
            value = "com.fanyong.calculator.ArithmeticCalculatorImp",
            defaultImpl = MaxCalculatorImp.class
    )
    public MaxCalculator maxCalculator;
    @DeclareParents(
            value = "com.fanyong.calculator.ArithmeticCalculatorImp",
            defaultImpl = MinCalculatorImp.class
    )
    public MinCalculator minCalculator;

    @DeclareParents(
            value = "com.fanyong.calculator.*CalculatorImp",
            defaultImpl = CounterImp.class
    )
    public Counter counter;//记录各种运算器的状态

    @After("execution(* com.fanyong.calculator.*Calculator.*(..))"+
            "&&this(counter)")
    public  void increaseCount(Counter counter)
    {
        counter.increase();
    }
}
