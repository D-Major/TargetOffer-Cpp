// Created by renduo on 19-11-30.
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

bool Increment(char* number){
    bool is_overflow = false;
    int take_over = 0;
    int length = strlen(number);
    for (int i = length - 1; i >= 0; i--) {
        int sum = number[i] - '0' + take_over;  // 两个字符型数字运算可以化为整型
        if (i == length - 1)    // 个位自增
            sum++;
        if (sum >= 10) {
            if (i == 0)
                is_overflow = true;
            else {
                sum -= 10;
                take_over = 1;
                number[i] = '0' + sum;
            }
        }
        else {
            number[i] = '0' + sum;
            break;
        }
    }
    return is_overflow;
}

void PrintNumber(char* number){
    bool is_begin0 = true;
    int length = strlen(number);

    for (int i = 0; i < length; i++) {
        if (is_begin0 && number[i] != '0')
            is_begin0 = false;
        if (!is_begin0)
            printf("%c", number[i]);
    }
    printf(" ");
}

void Print1ToMax(int n){
    if (n <= 0)
        return;
    char *number = new char[n+1];
    memset(number, '0', n);     // 初始化字符串
    number[n] = '\0';

    while (!Increment(number)){
        PrintNumber(number);
    }
    delete []number;
}