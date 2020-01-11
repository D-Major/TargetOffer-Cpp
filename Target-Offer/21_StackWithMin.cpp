// Created by renduo on 20-1-11.
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class StackWithMin{
public :
    void push(int value);
    void pop();
    int min();
private:
    stack<int> m_data;
    stack<int> m_min;
};

void StackWithMin::push(int v){
    /*  这里利用了栈每次只能操作栈顶一个元素的特性,
    * m_min记录了每一个步骤下当前m_data栈的最小元素值,
    * 从而保证弹出栈顶元素后还能找到上一个状态的最小元素值 */
    m_data.push(v);
    if (m_min.empty() || v < m_min.top())
        m_min.push(v);
    else
        m_min.push(m_min.top());
}

void StackWithMin::pop(){
    if (m_data.empty() && m_min.empty())
        return;
    m_data.pop();
    m_min.pop();
}

int StackWithMin::min(){
    if (m_data.empty() && m_min.empty())
        return NULL;
    return m_min.top();
}