package com.fanyong.advice;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.*;
import org.springframework.core.Ordered;
import org.springframework.stereotype.Component;

import java.util.Arrays;

/**
 * Created by fanyong on 16-6-5.
 */
@Component
@Aspect
/*@Order(1) 使用注解来实现切面优先级*/
public class AllLogAdvice implements Ordered{
    private Log log= LogFactory.getLog(this.getClass());

    @Pointcut("execution(* com.fanyong.calculator.*.*(..))")//定义横切点
    public void pointcut1()
    {

    }

    public int getOrder() {
        return 1;//日志输出切面优先级最小
    }

    @Before("pointcut1()")/*前置通知*/
    public void beforeAdvice(JoinPoint join)
    {
        log.info("This method "+join.getSignature().getName()+"() begins with "
                + Arrays.toString(join.getArgs()));
    }

    @AfterReturning("pointcut1()")/*返回通知*/
    public void afterAdvice(JoinPoint join)  /*一般都用返回通知取代后置通知*/
    {

        log.info("This method "+join.getSignature().getName()+"() end.");
    }

    @After("pointcut1()")/*后置通知*/
    public void doAfter()
    {
        log.info("methoa completed!");
    }

    @AfterThrowing(pointcut = "pointcut1()",throwing = "e")
    public void throwAdvice(JoinPoint join,IllegalArgumentException e)
    {
        log.info("An exception "+e+"has been thrown in function "+join.getSignature().getName()+"()");
    }
    @Around("pointcut1()")/*环绕通知*/
    public Object arroundAdvice(ProceedingJoinPoint join)throws Throwable
    {
        String method=join.getSignature().getName();
        Object[] args=join.getArgs();
        log.info("This method "+method+"() begins with "+ Arrays.toString(args));
        try {
            Object result = join.proceed();/*执行原始方法*/
            log.info("This method " + method + "() ends with " + result);
            return result;
        }catch (IllegalArgumentException e) {
            log.info("Illegal argument " + Arrays.toString(args) + " in " + method + "()");
            throw e;
        }
    }
}
