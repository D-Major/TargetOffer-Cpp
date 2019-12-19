// Created by renduo on 19-11-14.
#include <iostream>
#include <vector>

using namespace std;
typedef int ElemType;/* ElemType类型根据实际情况而定，这里假设为int */

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

/* 初始化链表 */
bool InitList(ListNode* *L) {
    *L = (ListNode*) malloc(sizeof(ListNode)); /* 产生头结点,并使L指向此头结点 */
    if (!(*L)) /* 存储分配失败 */
        return false;
    (*L)->next = NULL; /* 指针域为空 */
    return true;
}

bool ListInsert(ListNode* L,int i,ElemType e)
{
    int j = 1;;
    ListNode* p = L;
    ListNode* s;
    while (p && j < i)     /* 寻找第i个结点 */
    {
        p = p->next;    // 如果是最后一个节点后(i==12)插入, p指向最后一个节点, p->next==NULL, j==i, 跳出循环
        ++j;
    }
    if (!p || j > i)
        return false;   /* 第i个元素不存在 */
    s = (ListNode*)malloc(sizeof(ListNode));  /*  生成新结点(C语言标准函数) */
    s->val = e;
    s->next = p->next;      /* 将p的后继结点赋值给s的后继  */
    p->next = s;          /* 将s赋值给p的后继 */
    return true;
}

bool ListTraverse(ListNode* L)
{
    ListNode* p=L;//->next;
    while(p)
    {
        cout << p->val << " ";
        p=p->next;
    }
    cout << '\n';
    return true;
}

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（头插法） */
void CreateListHead(ListNode* *L, int n)
{
    ListNode* p;
    srand(time(0));                         /* 初始化随机数种子 */
    *L = (ListNode*)malloc(sizeof(ListNode));
    (*L)->next = NULL;                      /*  先建立一个带头结点的单链表 */
    for (int i=0; i<n; i++)
    {
        p = (ListNode*)malloc(sizeof(ListNode)); /*  生成新结点 */
        p->val = rand()%10+1;             /*  随机生成10以内的数字 */
        p->next = (*L)->next;
        (*L)->next = p;						/*  插入到表头 */
    }
}

void CreateList(ListNode* *L, int n, bool random=false) {
    InitList(&(*L));
    if(random)
        CreateListHead(L, n);
    else {
        for (int j = 1; j <= n; j++)
            ListInsert(*L, j, j);
    }
    ListTraverse(*L);
}

void MakeCircular(ListNode* L)
{
    ListNode* p=L->next;
    while(p->next)
    {
        p=p->next;
    }
    p->next = L;
}