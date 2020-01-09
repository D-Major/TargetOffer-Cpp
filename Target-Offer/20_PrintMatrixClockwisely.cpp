// Created by renduo on 20-1-9.
#include <iostream>
#include <vector>

using namespace std;

vector<int> PrintMatrixClockwisely(vector<vector<int>> matrix) {
    vector<int> list;
    if(matrix.empty() || matrix[0].empty())
        return list;
    int up = 0;
    int down = (int)matrix.size()-1;
    int left = 0;
    int right = (int)matrix[0].size()-1;
    while(true){
        // 最上面一行
        for(int col=left;col<=right;col++)
            list.push_back(matrix[up][col]);
        up++;   // 向下逼近
        if(up > down)   // 判断是否越界
            break;
        // 最右边一列
        for(int row=up;row<=down;row++)
            list.push_back(matrix[row][right]);
        right--;    // 向左逼近
        if(left > right)    // 判断是否越界
            break;
        // 最下面一行
        for(int col=right;col>=left;col--)
            list.push_back(matrix[down][col]);
        down--;     // 向上逼近
        if(up > down)   // 判断是否越界
            break;
        // 最左边一列
        for(int row=down;row>=up;row--)
            list.push_back(matrix[row][left]);
        left++;     // 向右逼近
        if(left > right)    // 判断是否越界
            break;
    }
    return list;
}