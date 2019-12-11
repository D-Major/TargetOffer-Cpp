// Created by renduo on 19-12-3.
#include <iostream>
#include <vector>

using namespace std;

void DeleteNode(LinkList *head, LinkList deleted){
    if(!head || !deleted)
        return;
    if(deleted->next != NULL){      // 当链表长度大于1时, 删除头结点, 头结点仍会被保留, 并被赋值为1, 只是第一个节点被删除
        LinkList next_node = deleted->next;
        deleted->data = next_node->data;
        deleted->next = next_node->next;
        delete next_node;
        next_node = NULL;
        return;
    }else if(deleted == *head){     // 考虑链表只有一个头结点的情况, 头结点的next也是NULL
        delete deleted;
        deleted = NULL;
        *head = NULL;   // 不要忘记清空头结点
    }else{      // 考虑删除尾节点的情况, 此时只能顺序查找O(n)
        LinkList p = *head;
        while(p->next != deleted){
            p = p->next;
        }
        p->next = NULL;
        delete deleted;
        deleted = NULL;
    }
}