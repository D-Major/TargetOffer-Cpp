// Created by renduo on 20-1-11.
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

template <typename T>
class StackWithMin{
public :
    StackWithMin() = default;
    virtual ~StackWithMin() = default;
    void push(const T& value);
    void pop();
    const T& min() const;
private:
    std::stack<T> m_data;
    std::stack<T> m_min;
};

template <typename T>
void StackWithMin<T>::push(const T& v){
    /*  这里利用了栈每次只能操作栈顶一个元素的特性,
    * m_min记录了每一个步骤下当前m_data栈的最小元素值,
    * 从而保证弹出栈顶元素后还能找到上一个状态的最小元素值 */
    m_data.push(v);
    if (m_min.empty() || v < m_min.top())
        m_min.push(v);
    else
        m_min.push(m_min.top());
}

template <typename T>
void StackWithMin<T>::pop(){
    if (m_data.empty() && m_min.empty())
        return;
    m_data.pop();
    m_min.pop();
}

template <typename T>
const T& StackWithMin<T>::min() const{
    if (m_data.empty() && m_min.empty())
        return nullptr;
    return m_min.top();
}