// Created by D_Major on 2019-11-20.
#include <iostream>
#include <vector>

using namespace std;

int MinNumberInRotateArray(vector<int> rotateArray){
    if(rotateArray.empty())
        return 0;
    int start = 0;
    int end = rotateArray.size() - 1;
    int mid = start;
    while(rotateArray[start] >= rotateArray[end]){
        if(start + 1 == end) {
            mid = end;
            break;
        }

        mid = (start + end) / 2;

        if(rotateArray[start] == rotateArray[end] &&
            rotateArray[mid] == rotateArray[start]) {
            int result = rotateArray[0];
            for (int i = 0; i < rotateArray.size(); i++) {
                if (rotateArray[i] < result)
                    result = rotateArray[i];
            }
            return result;
        }
        if(rotateArray[mid] >= rotateArray[start])
            start = mid;
        else if(rotateArray[mid] <= rotateArray[end])
            end = mid;
    }

    return rotateArray[mid];
}