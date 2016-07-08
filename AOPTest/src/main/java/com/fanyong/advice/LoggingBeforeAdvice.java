package com.fanyong.advice;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.springframework.aop.MethodBeforeAdvice;
import org.springframework.stereotype.Component;

import java.lang.reflect.Method;
import java.util.Arrays;

/**
 * Created by fanyong on 16-6-5.
 * 返回通知
 */
@Component
public class LoggingBeforeAdvice implements MethodBeforeAdvice{

    private Log log= LogFactory.getLog(this.getClass());

    public void before(Method method, Object[] args, Object target) throws Throwable {
        log.info("This method "+method.getName()+"() begins with "+ Arrays.toString(args));
    }
}
