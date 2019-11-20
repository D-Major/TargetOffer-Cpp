// Created by renduo on 19-11-14.
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void PrintListReversingly_Iterative(LinkList L){
    if(!L->next)
        return;
    LinkList p=L->next;
    stack<LinkList> s;
    while(p){
        s.push(p);
        p = p->next;
    }
    while(!s.empty()){
        p = s.top();
        cout << p->data << " ";
        s.pop();
    }
}

void PrintListReversingly_Recursive(LinkList L){
    if(!L->next)
        return;
    PrintListReversingly_Recursive(L->next);
    cout << L->next->data << " ";
}
