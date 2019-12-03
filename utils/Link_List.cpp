// Created by renduo on 19-11-14.
#include <iostream>
#include <vector>

using namespace std;
typedef int ElemType;/* ElemType类型根据实际情况而定，这里假设为int */

typedef struct Node
{
    int data;
    struct Node *next;
}Node;
typedef struct Node *LinkList; /* 定义LinkList */

/* 初始化链表 */
bool InitList(LinkList *L) {
    *L = (LinkList) malloc(sizeof(Node)); /* 产生头结点,并使L指向此头结点 */
    if (!(*L)) /* 存储分配失败 */
        return false;
    (*L)->next = NULL; /* 指针域为空 */
    return true;
}

bool ListInsert(LinkList *L,int i,ElemType e)
{
    int j = 1;;
    LinkList p,s;
    p = *L;
    while (p && j < i)     /* 寻找第i个结点 */
    {
        p = p->next;    // 如果是最后一个节点后(i==12)插入, p指向最后一个节点, p->next==NULL, j==i, 跳出循环
        ++j;
    }
    if (!p || j > i)
        return false;   /* 第i个元素不存在 */
    s = (LinkList)malloc(sizeof(Node));  /*  生成新结点(C语言标准函数) */
    s->data = e;
    s->next = p->next;      /* 将p的后继结点赋值给s的后继  */
    p->next = s;          /* 将s赋值给p的后继 */
    return true;
}

bool ListTraverse(LinkList L)
{
    LinkList p=L->next;
    while(p)
    {
        cout << p->data << " ";
        p=p->next;
    }
    cout << '\n';
    return true;
}

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（头插法） */
void CreateListHead(LinkList *L, int n)
{
    LinkList p;
    int i;
    srand(time(0));                         /* 初始化随机数种子 */
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;                      /*  先建立一个带头结点的单链表 */
    for (i=0; i<n; i++)
    {
        p = (LinkList)malloc(sizeof(Node)); /*  生成新结点 */
        p->data = rand()%100+1;             /*  随机生成100以内的数字 */
        p->next = (*L)->next;
        (*L)->next = p;						/*  插入到表头 */
    }
}

void CreateList(LinkList *L, int n, bool random=false) {
    InitList(L);
    if(random)
        CreateListHead(L, n);
    else {
        for (int j = 1; j <= n; j++)
            ListInsert(L, j, j);
    }
    ListTraverse(*L);
}