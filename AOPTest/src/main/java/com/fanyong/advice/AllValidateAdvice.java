package com.fanyong.advice;

import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.annotation.*;
import org.springframework.core.Ordered;
import org.springframework.core.annotation.Order;
import org.springframework.stereotype.Component;


/**
 * Created by fanyong on 16-6-5.
 * 验证参数通知
 */
@Component
@Aspect
/*@Order(0) 使用注解来实现切面优先级*/
public class AllValidateAdvice implements Ordered{
    @Pointcut("execution(* com.fanyong.calculator.*.*(..))")
    public void pointcut1() {

    }

    public int getOrder() {//实现Ordered接口来指定切面的顺序
        return 0;//返回值越小，优先级越高
    }

    @Before("pointcut1()")
    public void beforeAdvice(JoinPoint join) {//方法执行验证参数是否合法
        for(Object arg:join.getArgs())
                validate((Double)arg);
    }

    private void validate(double arg)
    {
        if(arg<0)
            throw new IllegalArgumentException("Positive number only");
    }

}