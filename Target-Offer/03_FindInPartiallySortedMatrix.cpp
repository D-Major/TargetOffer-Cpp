//
// Created by renduo on 19-11-12.
//
#include <iostream>
#include <vector>

using namespace std;

bool Find(int target, vector<vector<int>> array) {
    if(array.empty()){
        return false;
    }
    int rows = int(array.size());
    int cols = int(array[0].size());
    int i = 0, j = cols-1;  // start with top right

    while(i <= rows-1 && j >= 0){
        if(array[i][j] > target)
            --j;
        else if(array[i][j] < target)
            ++i;
        else
            return true;
    }
    return false;
}

bool Find_BottomLeft(int target, vector<vector<int>> array) {
    if(array.empty()){
        return false;
    }
    int rows = int(array.size());
    int cols = int(array[0].size());
    int i = rows-1, j = 0;

    while(i >= 0 && j <= cols-1) {
        if (array[i][j] > target)   // 此处先比较大还是小无所谓, 因为除非相等否则都要循环下去
            --i;
        else if (array[i][j] < target)
            ++j;
        else
            return true;
    }
    return false;
}
