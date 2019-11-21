// Created by renduo on 19-11-20.
#include <iostream>
#include <vector>
#include <ctime>
#define random(a, b) int(rand()%(b-a+1)+a)

using namespace std;

void QuickSort(vector<int>& array, int left, int right) {
    if(left >= right)
        return;
    int pivot = array[left];
    int i = left, j = right;
    while(i < j){
        while(array[j] >= pivot && i < j)
            j--;
        while(array[i] <= pivot && i < j)
            i++;
        if(i < j)
            swap(array[i], array[j]);
    }
    array[left] = array[i];
    array[i] = pivot;
    QuickSort(array, left, i - 1);//递归左边
    QuickSort(array, i + 1, right);//递归右边
}

//vector<int> QuickSort(vector<int>& array, int low, int high){
//    if(array.size() < 2)
//        return array;
////    srand(time(0));
//    int pivot = array[random(0, array.size())];
//    vector<int> less, greater;
//    for(int i = 0; i < array.size(); i++) {
//        if (array[i] <= pivot)
//            less.push_back(array[i]);
//        else
//            greater.push_back(array[i]);
//    }
////    vector<int> v1 = QuickSort(less);
////    vector<int> v2 = QuickSort(greater);
////    v1.insert(v1.end(), v2.begin(), v2.end());
//
//    return QuickSort(less) + QuickSort(greater);
//}