package com.fanyong.proxy;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;
import java.util.Arrays;

/**
 * Created by fanyong on 16-6-2.
 */
public class CalculatorValidationHandler implements InvocationHandler{
    private Log log= LogFactory.getLog(this.getClass());/*日志对象*/
    private Object target;/*代理对象/
    /*初始化代理对象*/
    public CalculatorValidationHandler(Object target)
    {
        this.target=target;
    }
    /*调用代理对象的方法*/
    public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {

        for(Object obj:args)/*校验每个参数是否符合要求*/
            validate((Double)obj);

        log.info("This method "+method.getName()+"() begins with "+ Arrays.toString(args));
        Object result=method.invoke(target,args);/*执行对应的方法*/
        log.info("This method "+method.getName()+"() ends with "+ result);
        return result;
    }

    /*校验参数是否正确，否则抛出参数非法异常*/
    public void validate(double a)
    {
        if(a<0)
            throw new IllegalArgumentException("Positive number only");
    }

    /*创建代理对象的实例*/
    public static Object createProxy(Object target)
    {
        return Proxy.newProxyInstance(target.getClass().getClassLoader(),target.getClass().getInterfaces()
        ,new CalculatorValidationHandler(target));
    }
}
