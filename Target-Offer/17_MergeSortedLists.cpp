// Created by renduo on 19-12-19.
#include <iostream>
#include <vector>

using namespace std;

ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
    if (pHead1 == NULL)
        return pHead2;
    else if (pHead2 == NULL)
        return pHead1;
    ListNode* pMergedHead = NULL;
    if (pHead1->val < pHead2->val) {
        pMergedHead = pHead1;
        pMergedHead->next = Merge(pHead1->next, pHead2);
    } else {
        pMergedHead = pHead2;
        pMergedHead->next = Merge(pHead1, pHead2->next);
    }
    return pMergedHead;
}