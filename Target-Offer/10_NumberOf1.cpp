// Created by renduo on 19-11-27.
#include <iostream>
#include <vector>

using namespace std;

// -1在计算机中的补码表示为11111111, -127的补码表示为10000001, -128的补码表示为10000000(相当于-0, 或-127减1)
// 负数右移在左边补n个1, 所以-10补码为11110110, 右移两位为11111101, 是-3的补码(减1取反), 相当于-10/4=-2.5后向下取整
int NumberOf1_Iterative(int n){
    int count = 0;
    uint flag = 1;
    while(flag){
        if(n & flag)    // TODO: 为什么这里判断条件不能用是否等于0
            count++;
        flag = flag << 1;
    }
    return count;
}