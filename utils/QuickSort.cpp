// Created by renduo on 19-11-20.
#include <iostream>
#include <vector>
#include <ctime>
#define random(a, b) int(rand()%(b-a+1)+a)

using namespace std;

template <typename T>
vector<T> &operator +(vector<T> &v1,vector<T> &v2)
{
    v1.insert(v1.end(),v2.begin(),v2.end());
    return v1;
}

vector<int> QuickSort(vector<int> array){
    if(array.size() < 2)
        return array;
//    srand(time(0));
    int pivot = array[random(0, array.size())];
    vector<int> less, greater;
    for(int i = 0; i < array.size(); i++) {
        if (array[i] <= pivot)
            less.push_back(array[i]);
        else
            greater.push_back(array[i]);
    }
    vector<int> v1 = QuickSort(less);
    vector<int> v2 = QuickSort(greater);
//    v1.insert(v1.end(), v2.begin(), v2.end());

    return v1+v2;
}