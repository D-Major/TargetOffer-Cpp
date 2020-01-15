// Created by renduo on 20-1-15.
#include <iostream>
#include <vector>

using namespace std;

void Permutation(string str, vector<string>& res, int begin) {
    if (begin == str.size())
        res.push_back(str);
    for (int i = begin; i < str.size(); i++) {
        if(i!=begin && str[i]==str[begin])//有重复字符时，跳过
            continue;
        swap(str[i], str[begin]);
        Permutation(str, res, begin+1);
        swap(str[i], str[begin]);
    }
}
vector<string> Permutation(string str) {
    vector<string> result;
    if (str.empty())
        return result;
    Permutation(str, result, 0);
    sort(result.begin(), result.end());
    return result;
}