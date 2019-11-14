// Created by renduo on 19-11-14.
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void PrintListReversingly_Iterative(LinkList L){
    if(!L->next)
        return;
    LinkList p=L->next;
    stack<LinkList> Nodes;
    while(p){
        Nodes.push(p);
        p = p->next;
    }
    while(!Nodes.empty()){
        p = Nodes.top();
        cout << p->data << " ";
        Nodes.pop();
    }
}

void PrintListReversingly_Recursive(LinkList L){
    if(!L->next)
        return;
    PrintListReversingly_Recursive(L->next);
    cout << L->next->data << " ";
}
