// bo2-7.h 带头结点的双向循环列表基本操作(14个)
void InitList(DuLinkList &L)
{
    L = (DuLinkList)malloc(sizeof(DuLNode));
    if(!L)
        exit(OVERFLOW);
    L->next = L;
    L->prior = L;
}

void ClearList(DuLinkList L)
{
    DuLinkList p = L->next;
    while(p != L)
    {
        p = p->next;
        free(p->prior);
    }
    L->next = L->prior = L;
}

void DestroyList(DuLinkList &L)
{
    ClearList(L);
    free(L);
    L->next = L->prior = NULL;
}

Status ListEmpty(DuLinkList L)
{
    if(L->next == L && L->prior == L)
        return TRUE;
    return FALSE;
}

int ListLength(DuLinkList L)
{
    int i = 0;
    DuLinkList p = L->next;
    while(p != L)
    {
        i++;
        p = p->next;
    }
    return i;
}

Status GetElem(DuLinkList L, int i, ElemType &e)
{
    if(i < 1 || i > ListLength(L))
        return ERROR;
    int j = 0;
    DuLinkList p = L->next;
    while(j < i && p != L)
    {
        j++;
        p = p->next;
    }
    if(p == L || j >i)
        return ERROR;
    e = p->data;
    return OK;
}

int LocateElem(DuLinkList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
    int i = 0;
    DuLinkList p = L->next;
    while(p != L)
    {
        i++;
        if(compare(e, p->data))
            return i;
        p = p->next;
    }
    return 0;
}

Status PriorElem(DuLinkList L, ElemType cur_e, ElemType &pre_e)
{
    DuLinkList p = L->next->next;    // 指向第二个元素
    while(p != L)
    {
        if(cur_e = p->data)
        {
            pre_e = p->prior->data;
            return OK;
        }
        p = p->next;
    }
    return ERROR;
}

Status NextElem(DuLinkList L, ElemType cur_e, ElemType &next_e)
{
    DuLinkList p = L->next->next;
    while(p != L)
    {
        if(cur_e = p->data)
        {
            next_e = p->next->data;
            return OK;
        }
        p = p->next;
    }
    return ERROR;
}

DuLinkList GetElemP(DuLinkList L, int i)
{
    int j;
    DuLinkList p = L;
    if(i < 1 || i > ListLength(L))
        return NULL;
    for(j = 0; j < i; j++)
        p = p->next;
    return p;
}

Status ListInsert(DuLinkList L, int i, ElemType e)
{
    DuLinkList s, p;
    if(i < 1 || i > ListLength(L)+1)   // i
        return ERROR;
    p = GetElemP(L, i-1);
    if(!p)
        return ERROR;
    s = (DuLinkList)malloc(sizeof(DuLNode));
    if(!s)
        return ERROR;
    s->data = e;
    s->prior = p;
    s->next = p->next;
    p->next->prior = s;
    p->next = s;
    return OK;
}

Status ListDelete(DuLinkList L, int i, ElemType &e)
{
    DuLinkList p;
    if(i < 1 )   // i
        return ERROR;
    p = GetElemP(L, i);
    if(!p)
        return ERROR;
    e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return OK;
}

void ListTraverse(DuLinkList L, void(*visit)(ElemType))
{
    DuLinkList p = L->next;
    while(p != L)
    {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
}

void ListTraverseBack(DuLinkList L, void(*visit)(ElemType))
{
    DuLinkList p = L->prior;
    while(p != L)
    {
        visit(p->data);
        p = p->prior;
    }
    printf("\n");
}
