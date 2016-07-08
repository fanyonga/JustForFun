package com.fanyong.calculator;

import org.springframework.stereotype.Component;

/**
 * Created by fanyong on 16-6-2.
 */
@Component
public class UnitCalculatorImp implements UnitCalculator {

    public double kilogarmToPound(double kilogram) {
        return kilogram*2.2;
    }

    public double kilometerToMile(double kilometer) {
        return kilometer*0.62;
    }
}
