// Created by renduo on 20-1-13.
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool IsPopOrder(const vector<int> &pushV, const vector<int> &popV) {
    if (pushV.empty() || popV.empty() || (pushV.size() != pushV.size()))
        return false;
    stack<int> stack1;
    int j = 0;
    for (int i = 0; i < pushV.size(); i++) {
        stack1.push(pushV[i]);
        // 访问空栈的top()会报错
        while (!stack1.empty() && stack1.top() == popV[j]) {
            stack1.pop();
            j++;
        }
    }
    return stack1.empty();
}