// Created by renduo on 19-12-3.
#include <iostream>
#include <vector>

using namespace std;

void DeleteNode(LinkList *head, LinkList deleted){
    if(!head || !deleted)
        return;
    if(deleted->next != NULL){
        LinkList next_node = deleted->next;
        deleted->data = next_node->data;
        deleted->next = next_node->next;
        next_node = NULL;
        delete next_node;
    }else if(deleted == *head){
        deleted = NULL;
        delete deleted;
        *head = NULL;
    }else{
        LinkList p = *head;
        while(p->next != deleted){
            p = p->next;
        }
        p->next = NULL;
        deleted = NULL;
        delete deleted;
    }
}