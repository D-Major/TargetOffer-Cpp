// Created by renduo on 19-12-13.
#include <iostream>
#include <vector>

using namespace std;

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k){
    // 使用双指针法只需要遍历一次就能得到倒数第K个节点
    // 对于无符号整数, 要考虑0的边界情况
    if (!pListHead || k <= 0)   // k<=0时k-1是INT8_MAX, 与k超过链表长度时相同, 其实不用单独处理
        return NULL;
    auto pAhead = pListHead;
    auto pBehind = pListHead;
    for (int i = 0; i < k-1; i++)
    {
        if (pAhead->next != NULL)
            pAhead = pAhead->next;  // k过大时跳出
        else
            return NULL;
    }
    while (pAhead->next != NULL)
    {
        pAhead = pAhead->next;
        pBehind = pBehind->next;
    }
    return pBehind;
}

ListNode* FindMiddleNode(ListNode* pListHead){
    if (!pListHead)
        return NULL;
    auto pAhead = pListHead;
    auto pBehind = pListHead;
    while (pAhead != NULL)
    {
        if (pAhead->next->next)
            pAhead = pAhead->next->next;
        pBehind = pBehind->next;
    }
    return pBehind;
}