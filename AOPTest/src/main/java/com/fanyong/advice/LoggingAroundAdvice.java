package com.fanyong.advice;

import org.aopalliance.intercept.MethodInterceptor;
import org.aopalliance.intercept.MethodInvocation;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

import org.springframework.stereotype.Component;

import java.lang.reflect.Method;
import java.util.Arrays;

/**
 * Created by fanyong on 16-6-5.
 * 环绕通知
 */
@Component
public class LoggingAroundAdvice implements MethodInterceptor{

    private Log log= LogFactory.getLog(this.getClass());

    public Object invoke(MethodInvocation methodInvocation) throws Throwable {
        log.info("This method "+methodInvocation.getMethod().getName()+"() begins with "
                + Arrays.toString(methodInvocation.getArguments()));
        try{
            Object[] args=methodInvocation.getArguments();
            for(Object arg:args)
                if((Double)arg<0) throw new IllegalArgumentException("Positive number only");

            Object result=methodInvocation.proceed();/*注意：在这里执行原始方法*/

            log.info("This method "+methodInvocation.getMethod().getName()+"() ends with "+ result);
            return result;
        }catch (IllegalArgumentException e)
        {
            log.error("Illegal argument "+Arrays.toString(methodInvocation.getArguments())+
            "for method "+methodInvocation.getMethod().getName()+"()");
            throw e;
        }

    }
}
