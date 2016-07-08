package com.fanyong.calculator;

import org.springframework.context.annotation.Bean;
import org.springframework.stereotype.Component;

/**
 * Created by fanyong on 16-6-2.
 */
@Component
public class ArithmeticCalculatorImp implements  ArithmeticCalculator{
    public double add(double a, double b) {
        return a+b;
    }

    public double sub(double a, double b) {
        return a-b;
    }

    public double mul(double a, double b) {
        return a*b;
    }

    public double div(double a, double b) {
        return a/b;
    }
}
