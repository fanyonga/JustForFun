package com.fanyong.calculator;

/**
 * Created by fanyong on 16-6-5.
 */
public class CounterImp  implements Counter {
    //保存一个计数器
    private int count=0;

    public int getCount() {
        return count;
    }

    public void increase() {
        ++count;
    }
}
