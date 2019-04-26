// bo2-3.h 不带头结点的单链表基本操作
#define DestroyList ClearList

void InitList(LinkList &L)
{
    L = NULL;
}

void ClearList(LinkList &L)
{
    LinkList p;
    while(L)
    {
        p = L;
        L = L->next;
        free(p);
    }
}

Status ListEmpty(LinkList L)
{
    if(L)
        return FALSE;
    return TRUE;
}

int ListLength(LinkList L)
{
    int i = 0;
    LinkList p = L;
    while(p)
    {
        i++;
        p = p->next;
    }
    return i;
}

Status GetElem(LinkList L, int i, ElemType &e)
{
    int j = 1;
    LinkList p = L;
    while(p && j < i)
    {
        j++;
        p = p->next;
    }
    if(j == i && p)
    {
        e = p->data;
        return OK;
    }
    return ERROR;
}

int LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
    int i = 0;
    LinkList p = L;
//    while(p && !compare(e,p->data))
//    {
//        i++;
//        p = p->next;
//    }
//    return i;
    while(p)
    {
        i++;
        if(compare(e, p->data))
            return i;
        p = p->next;
    }
    return 0;
}

Status ListInsert(LinkList &L, int i, ElemType e)
{// 在第i个元素前插入值
    int j = 1;
    LinkList s, p = L;
    if(i < 0)
        return ERROR;
    s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    if(i == 1)  // 插入表头
    {
        s->next = L;
        L = s;
    }
    else
    {
        while(p && j < i-1)   // 找到第i-1个结点
        {
            j++;
            p = p->next;
        }
        if(!p)    // 超过表长
            return ERROR;
        s->next = p->next;
        p->next = s;
    }
    return OK;
}

Status ListDelete(LinkList &L, int i, ElemType &e)
{
    int j = 1;
    LinkList q, p = L;
    if(!p)
        return ERROR;
    else if(i == 1)
    {
        L = p->next;
        e = p->data;
        free(p);
    }
    else
    {
        while(p && j < i)
        {
            j++;
            p = p->next;
        }
        if(!p || j > i-1)
            return ERROR;
        q = p->next;
        e = p->data;
        p->next = q->next;
        free(q);
    }
    return OK;
}

void ListTraverse(LinkList L, void(*vi)(ElemType))
{
    LinkList p = L;
    while(p && p->next)
    {
        vi(p->data);
        p = p->next;
    }
    printf("\n");
}
