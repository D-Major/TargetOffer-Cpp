// Created by renduo on 19-12-11.
#include <iostream>
#include <vector>

using namespace std;

bool isEven(int n){ // 判断是否是偶数
    return (n & 0x1) == 0;
}

void ReorderArray_DoublePointer(vector<int> &array) {
    /* 不保留顺序, 将奇数移动到偶数前面, 使用双指针 */
    if (array.empty())
        return;
    int begin = 0;
    int end = int(array.size() - 1);
    while (begin < end) {
        // 乘除 > 加减 > 大小于 > 等于不等于 > 按位与& > 与&&
        // 一定要注意运算符优先级
        while (begin < end && (!isEven(array[begin])))
            begin++;
        while (begin < end && (isEven(array[end])))
            end--;
        if (begin < end)
            swap(array[begin], array[end]);
    }
}

void ReorderArray_BubbleSort(vector<int> &array) {
    // 将相邻的奇偶逐个交换, 保证奇数在前且奇数偶数各自的相对位置不变(稳定)
    // 复杂度O(n^2)(冒泡排序), 好处是不需要辅助空间
    for (int i = 0; i < array.size(); i++) {
        for (int j = array.size() - 1; j > i; j--) { // j从后往前逐个交换位置, 最终确保i的位置是奇数
            if (!isEven(array[j]) && isEven(array[j-1])) // 前偶后奇交换
                swap(array[j], array[j-1]);
        }
    }
}

void ReorderArray_TwoVector(vector<int> &array) {
    // 新建一个数组, 空间换时间, 复杂度O(n)
    vector<int> temp_array;
    for (int i = 0; i < array.size(); i++) {
        if (!isEven(array[i]))
            temp_array.push_back(array[i]);
    }
    for (int i = 0; i < array.size(); i++) {
        if (isEven(array[i]))
            temp_array.push_back(array[i]);
    }
    for (int i = 0; i < array.size(); i++) {
        array[i] = temp_array[i];
    }
}
