// Created by renduo on 19-11-14.
#include <iostream>
#include <vector>

using namespace std;

void MergeArray(int arr1[], const int arr2[], int m, int n){
    /** 从尾到头逐个比较插入, 若arr2剩下的部分均小于arr1, 则直接插入
     *  无论是否有返回值, 都是直接在传入的数组(指针)自身修改 */
    if(m < n || arr1 == NULL || arr2 == NULL)
        return;
    int len = m + n - 1;
    while(m > 0 && n > 0){
        if(arr1[m-1] > arr2[n-1])
            arr1[len--] = arr1[--m];
        else
            arr1[len--] = arr2[--n];
    }
    while(n > 0)
        arr1[len--] = arr2[--n];
}