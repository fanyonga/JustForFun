package com.fanyong.calculator;

/**
 * Created by fanyong on 16-6-5.
 */

public class MinCalculatorImp implements MinCalculator{
    /*求最小值*/
    public double min(double a, double b)
    {
        return a>b?b:a;
    }
}
