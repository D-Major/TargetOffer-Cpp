// Created by renduo on 19-11-27.
#include <iostream>
#include <vector>

using namespace std;

/* 负数右移在左边补n个1, 如-10补码为11110110, 若右移两位为11111101, 结果是-3的补码(减1取反), 相当于-10/4=-2.5后向下取整
 * -128在INT_32下的表示:
 * 原码: 10000000 00000000 00000000 10000000
 * 反码: 11111111 11111111 11111111 01111111
 * 补码: 11111111 11111111 11111111 10000000
 */
int NumberOf1_Iterative(int n){
    int count = 0;
    uint flag = 1;
    while(flag != 0){
        // 这里判断条件用是否等于0要加括号, 因为&优先级小于!=
        // TODO: 为什么整数和true相与结果有1有0? 只比较了最后一位?
        if((n & flag) != 0)
            count++;
        flag = flag << 1;
    }
    return count;
}

/* 对于INT8长度的负数来说:
 * -1在计算机中的补码表示为1111 1111, -127的补码表示为1000 0001, -128的补码表示为1000 0000(相当于-0, 或-127的补码减1)
 * -128-1就又变成127, 127的补码和原码相同为0111 1111, 则-128 & 127 == 0
 * 同理对于INT32长度来说:
 * INT32_MAX = 2147483647, 补码为01111111 11111111 11111111 11111111(0x7FFFFFFF)
 * INT32_MIN = -2147483648,补码为10000000 00000000 00000000 00000000(0x80000000)
 * (INT32_MIN-1) & INT32_MIN == 0, 所以最后算上了符号位的1
 * -2147483647的补码为10000000 00000000 00000000 00000001
 */

int NumberOf1(int n){
    int count = 0;
    while(n != 0){
        count++;
        n = n & (n-1);
    }
    return count;
}

bool NthPowerOf2(int n){
    /* 用一条语句判断一个整数是不是2的整数次方 */
    bool res = (n & (n-1)) == 0;
    return res;
}

int BinaryXOR(int m, int n){
    /* 输入两个整数m和n, 计算需要改变m的二进制中的多少位才能得到n */
    int xor_res = m ^ n;
    return NumberOf1(xor_res);
}