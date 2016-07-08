package com.fanyong.calculator;

/**
 * Created by fanyong on 16-6-5.
 * 计算每个运算器调用次数
 */
public interface Counter {
    void increase();
    int getCount();
}
