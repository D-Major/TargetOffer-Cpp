// Created by renduo on 19-11-20.
#include <iostream>
#include <vector>
#include <ctime>
#define random(a, b) int(rand()%(b-a+1)+a)

using namespace std;

void QuickSort(vector<int>& array, int left, int right) {
    if(left < 0 || right >= array.size())
        return;
    if(left >= right)   // 递归边界条件
        return;
    int pivot = array[left];
    int i = left, j = right;
    while(i < j){
        while(array[j] >= pivot && i < j)   // 基准数选左边的则要从右面的j开始移动
            j--;
        while(array[i] <= pivot && i < j)
            i++;
        if(i < j)
            swap(array[i], array[j]);
    }
    swap(array[left], array[i]);
    QuickSort(array, left, i - 1);      //递归左边
    QuickSort(array, i + 1, right);     //递归右边
}

// 从大到小排序
void QuickSortReverse(vector<int>& array, int left, int right) {
    if(left < 0 || right >= array.size())
        return;
    if(left >= right)   // 递归边界条件
        return;
    int pivot = array[left];
    int i = left, j = right;
    while(i < j){
        while(array[j] <= pivot && i < j)   // 基准数选左边的则要从右面的j开始移动
            j--;
        while(array[i] >= pivot && i < j)   // 从大到小排序只需要修改>号
            i++;
        if(i < j)
            swap(array[i], array[j]);
    }
    swap(array[left], array[i]);
    QuickSort(array, left, i - 1);      //递归左边
    QuickSort(array, i + 1, right);     //递归右边
}