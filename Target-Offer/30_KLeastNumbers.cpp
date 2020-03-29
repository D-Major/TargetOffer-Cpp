// Created by D_Major on 2020/1/26.

#include <iostream>
#include <vector>

using namespace std;

//vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
//
//}

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    int len=input.size();
    if(len<=0||k>len||k<=0)
        return vector<int>();
    vector<int> res(input.begin(),input.begin()+k);
    print(res);
    make_heap(res.begin(),res.end());   //建堆
    for(int i=k;i<len;i++)
    {
        if(input[i]<res[0])
        {
        //先pop,然后在容器中删除
        pop_heap(res.begin(),res.end());
        res.pop_back();
        //先在容器中加入，再push
        res.push_back(input[i]);
        push_heap(res.begin(),res.end());
        }
    }
    //使其从小到大输出
    sort_heap(res.begin(),res.end());

    return res;

}