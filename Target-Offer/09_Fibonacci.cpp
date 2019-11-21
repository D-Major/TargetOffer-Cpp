// Created by renduo on 19-11-21.
#include <iostream>
#include <vector>

using namespace std;

long long Fibonacci(unsigned int n){
    /** f(n)=f(n-1)+f(n-2) */
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    long long one = 0;
    long long two = 1;
    long long fib = 0;

    while(n >= 2){
        fib = one + two;
        one = two;
        two = fib;
        n--;
    }

    return fib;
}

long long JumpFloor(unsigned int n){
    /** 一次只能上1个或2个台阶, 可以看作斐波那契数列,
     *  第一个台阶只有1种可能, 第二个台阶有2种可能,
     *  之后前一次上了1个台阶就f(n-1), 上了两个台阶
     *  就f(n-2) */
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    long long one = 1;
    long long two = 1;
    long long fib = 0;

    while(n >= 2){
        fib = one + two;
        one = two;
        two = fib;
        n--;
    }

    return fib;
}

long long JumpFloorII(unsigned int n){
    return 1<<(n-1);
}

long long RectCover(unsigned int n){
    /** 用2*1的小矩形去覆盖2*n的矩形区域, 仍是斐波那契数列
     *  竖着放时后面还有f(n-1)种可能, 横着放时必须再放一个补齐,
     *  后面只剩f(n-2)种可能 */
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    long long one = 1;
    long long two = 1;
    long long fib = 0;

    while(n >= 2){
        fib = one + two;
        one = two;
        two = fib;
        n--;
    }

    return fib;
}