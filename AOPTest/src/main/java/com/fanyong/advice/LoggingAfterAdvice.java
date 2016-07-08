package com.fanyong.advice;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.springframework.aop.AfterReturningAdvice;
import org.springframework.aop.MethodBeforeAdvice;
import org.springframework.stereotype.Component;

import java.lang.reflect.Method;
import java.util.Arrays;

/**
 * Created by fanyong on 16-6-5.
 * 前置通知
 */
@Component
public class LoggingAfterAdvice implements AfterReturningAdvice{

    private Log log= LogFactory.getLog(this.getClass());


    public void afterReturning(Object returnValue, Method method, Object[] args, Object target) throws Throwable {
        log.info("This method "+method.getName()+"() ends with "+ returnValue);

    }
}
