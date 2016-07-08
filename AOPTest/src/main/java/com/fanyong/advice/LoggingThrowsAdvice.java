package com.fanyong.advice;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.springframework.aop.ThrowsAdvice;
import org.springframework.stereotype.Component;

/**
 * Created by fanyong on 16-6-5.
 * 异常通知
 */
@Component
public class LoggingThrowsAdvice implements ThrowsAdvice{

    private Log log= LogFactory.getLog(this.getClass());

    public void afterThrowing(IllegalArgumentException e) throws Throwable
    {
        log.error("Illegal argument!");
    }
}
