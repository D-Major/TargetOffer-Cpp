// Created by renduo on 19-11-15.
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Stack_Queue{
public:
    void push(int node)
    {
        stack1.push(node);
    }

    int pop()
    {
        /** 如果stack2空, 则把stack1整个倒进stack2中, 相当于stack1只负责压入, stack2只负责弹出,
         * 当stack2没弹空时, stack1的必不可能弹出, 因为stack2的元素都在stack1前面 */
        if(stack2.empty())
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int p = stack2.top();
        stack2.pop();
        return p;
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};