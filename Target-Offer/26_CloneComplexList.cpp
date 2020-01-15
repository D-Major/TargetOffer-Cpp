// Created by renduo on 20-1-15.
#include <iostream>
#include <vector>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x)
    : label(x), next(NULL), random(NULL) {}
};

void CloneNodes(RandomListNode* pHead) {
    RandomListNode* pNode = pHead;
    while (pNode != nullptr) {
        RandomListNode* pClone = new RandomListNode(pNode->label);
        pClone->label = pNode->label;
        pClone->next = pNode->next;
        pClone->random = nullptr;
        pNode->next = pClone;
        pNode = pClone->next;
    }
}

void ConnectSiblingNode(RandomListNode* pHead) {
    RandomListNode* pNode = pHead;
    while (pNode != nullptr) {
        RandomListNode* pClone = pNode->next;
        if (pNode->random)
            pClone->random = pNode->random->next; // 把C'赋值给A->random, 不是C
        pNode = pClone->next;
    }
}

RandomListNode* ReconnectNodes(RandomListNode* pHead) {
    RandomListNode* pNode = pHead;
    RandomListNode* pClone = pHead->next;
    RandomListNode* pCloneHead = pClone;
    // 这里Node领先Clone一个位置是因为遍历到最后只有一个NULL, E'无法被赋值成NULL->next
    pNode->next = pClone->next;
    pNode = pNode->next;
    while (pNode) {
        pClone->next = pNode->next;
        pClone = pClone->next;
        pNode->next = pClone->next;
        pNode = pNode->next;
    }
    return pCloneHead;
}

RandomListNode* Clone(RandomListNode* pHead) {
    if (!pHead)
        return nullptr;
    CloneNodes(pHead);
    ConnectSiblingNode(pHead);
    return ReconnectNodes(pHead);
}