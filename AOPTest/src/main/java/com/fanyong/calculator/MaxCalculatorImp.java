package com.fanyong.calculator;

/**
 * Created by fanyong on 16-6-5.
 */

public class MaxCalculatorImp implements MaxCalculator{
    /*求最大值*/
    public double max(double a, double b){
        return a>b?a:b;
    }
}
