// bo3-3.h 用单链表的基本操作实现链队列基本操作(9个)
typedef QElemType ElemType;
#define LinkList QueuePtr
#define LNode QNode
#include "bo2-2.h"           // 链表的基本操作
void InitQueue(LinkQueue &Q)
{
    InitList(Q.front1);
    Q.rear = Q.front1;
}

void DestroyQueue(LinkQueue &Q)
{
    DestroyList(Q.front1);
    Q.rear = Q.front1;
}

void ClearQueue(LinkQueue &Q)
{
    ClearList(Q.front1);
    Q.rear = Q.front1;
}

Status QueueEmpty(LinkQueue Q)
{
    return ListEmpty(Q.front1);
}

int QueueLength(LinkQueue Q)
{
    return ListLength(Q.front1);
}

Status GetHead(LinkQueue Q, QElemType &e)
{
    return GetElem(Q.front1, 1, e);
}

void EnQueue(LinkQueue &Q, QElemType e)
{
    ListInsert(Q.front1, ListLength(Q.front1)+1, e);
}

Status DeQueue(LinkQueue &Q, QElemType &e)
{
    if(Q.front1->next == Q.rear)
        Q.rear = Q.front1;
    return ListDelete(Q.front1, 1, e);
}

void QueueTraverse(LinkQueue Q, void(*visit)(QElemType))
{
    ListTraverse(Q.front1, visit);
}
