// Created by renduo on 19-12-18.
#include <iostream>
#include <vector>

using namespace std;

ListNode* ReverseList(ListNode* pHead)
{
    /** 简单地说就3步,
     *  1. 每次都获取新的pNext节点
     *  2. 将pNode指向pPre
     *  3. 分别将pPre,pNode替换为pNode,pNext*/
    ListNode* ReversedHead = NULL;
    ListNode* pNode = pHead;
    ListNode* pPre = NULL;
    while(pNode != NULL)
    {
        ListNode* pNext = pNode->next;
        if (!pNext)
            ReversedHead = pNode;
        // 设此时pNode状态为(3,->4). 先把它指向pPre变成(3,->2), 然后复制给原pPre(2,->1), 相当于更新pPre到下一个状态(3,->2)
        // 然后pNode(3,->2)相当于废弃, 被pNext(4,->5)覆盖掉变成pNode(4,->5), 更新到下一状态
        pNode->next = pPre;
        pPre = pNode;
        pNode = pNext;
    }
    return ReversedHead;
}