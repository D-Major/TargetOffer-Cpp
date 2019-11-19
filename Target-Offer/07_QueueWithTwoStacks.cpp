// Created by renduo on 19-11-15.
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

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

/** Stack with two queues */
class Queue_Stack{
public:
    void push(int node){
        if(queue1.empty() && queue2.empty())
            queue1.push(node);
        else if(!queue1.empty() && queue2.empty())
            queue1.push(node);
        else if(queue1.empty() && !queue2.empty())
            queue2.push(node);
        else
            return;
    }

    int pop(){
        int p = 0;
        if(queue2.empty()){
            while(queue1.size() > 1){
                queue2.push(queue1.front());
                queue1.pop();
            }
            p = queue1.front();
            queue1.pop();
        }else if(queue1.empty()){
            while(queue2.size() > 1){
                queue1.push(queue2.front());
                queue2.pop();
            }
            p = queue2.front();
            queue2.pop();
        }
        return p;
    }

    int top(){
        if(!queue1.empty() && queue2.empty())
            return queue1.back();
        else if(queue1.empty() && !queue2.empty())
            return queue2.back();
        else if(queue1.empty() && queue2.empty())
            return 0;
    }

private:
    queue<int> queue1;
    queue<int> queue2;
};