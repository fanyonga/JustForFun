package com.fanyong.calculator;

import com.fanyong.proxy.CalculatorValidationHandler;
import org.junit.Test;

/**
 * Created by fanyong on 16-6-2.
 */
public class CalculatorTest {
    @Test
    public void testProxy()
    {
        ArithmeticCalculator c1=new ArithmeticCalculatorImp();
        ArithmeticCalculator c2= (ArithmeticCalculator)CalculatorValidationHandler.createProxy(c1);
        //c2.add(2,3);
        UnitCalculator u1=new UnitCalculatorImp();
        UnitCalculator u2=(UnitCalculator)CalculatorValidationHandler.createProxy(u1);
        u2.kilometerToMile(200);
    }
}
