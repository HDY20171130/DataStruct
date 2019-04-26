// 线性表的双向链表结构
typedef struct DuLNode
{
    ElemType data;
    DuLNode *prior, *next;
}DuLNode, *DuLinkList;
