// Created by renduo on 19-11-28.
#include <iostream>
#include <vector>

using namespace std;

bool g_InvalidInput = false;

bool equal(double m, double n){
    if((m - n > -0.0000001) && (m - n < 0.0000001))
        return true;
    else
        return false;
}

double Power_Iterative(double base, unsigned int absExponent){
    // O(n)的方法
    double res = 1.0;
    for(int i = 0; i < absExponent; i++) {
        res *= base;
    }
    return res;
}

double Power_Recursive(double base, unsigned int absExponent){
    // 快速幂算法, 复杂度O(logn)
    if(absExponent == 0)
        return 1;
    if(absExponent == 1)
        return base;
    double result = Power_Recursive(base, absExponent >> 1);
    result *= result;
    if(absExponent & 0x1 == 1)
        result *= base;
    return result;
}

double Power(double base, int exponent) {
    g_InvalidInput = false;
    // 不能直接判断两个double是否相等, 无法比较
    if(equal(base, 0.0) && exponent < 0){
        g_InvalidInput = true;
        return 0.0;
    }
    unsigned int absExponent = (unsigned int) (exponent);
    if(exponent < 0)
        absExponent = (unsigned int) (-exponent);
    double result = Power_Recursive(base, absExponent);
    if(exponent < 0)
        result = 1 / result;

    return result;
}