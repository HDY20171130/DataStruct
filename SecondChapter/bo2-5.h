// bo2-5.h 静态链表的基本操作
#define DestroyList ClearList
int Malloc(SLinkList space)
{// 若备用链表space非空,则返回分配的结点下标
 // 调用后会少一个结点
    int i = space[0].cur;
    if(i)
        space[0].cur = space[i].cur;
    return i;
}

void Free(SLinkList space, int k)
{// 将下标为k的空闲结点回收到备用链表的头结点
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

void InitList(SLinkList L)
{// 构造一个空的链表L,表头为L的最后一个单元L[MAX_SIZE-1],其余
 // 单元链成一个备用链表,表头为L[0]
    int i;  // 相当于指针
    L[MAX_SIZE-1].cur = 0;  // 表头
    for(i = 0; i < MAX_SIZE-2; i++)
        L[i].cur = i+1;
    L[MAX_SIZE-2].cur = 0;
}

void ClearList(SLinkList L)
{
    int j, i = L[0].cur;  // 相当于指针
    while(i)
    {
        j = i;
        i = L[i].cur;
    }
    L[j].cur = L[MAX_SIZE-1].cur;  // 指向表头
    L[MAX_SIZE-1].cur = 0;     // 链表空
}

Status ListEmpty(SLinkList L)
{
    if(L[MAX_SIZE-1].cur == 0)
        return TRUE;
    return FALSE;
}

int ListLength(SLinkList L)
{
    int j = 0, i = L[0].cur;
    while(i)
    {
        j++;
        i = L[i].cur;
    }
    return j;
}

Status GetElem(SLinkList L, int i, ElemType &e)
{
    int m, k = MAX_SIZE-1;  // 指向头结点
    if(i < 1 || i > ListLength(L))
        return ERROR;
    for(m = 1; m <= i; m++)
        k = L[k].cur;
    e = L[k].data;
    return OK;
}

int LocateElem(SLinkList L, ElemType e)
{
    int i = L[MAX_SIZE-1].cur;
    while(i && L[i].data != e)
        i = L[i].cur;
    return i;
}

Status PriorElem(SLinkList L, ElemType cur_e, ElemType &pre_e)
{
    int j, i = L[MAX_SIZE-1].cur;
    do
    {
        j = i;
        i = L[i].cur;
    }while(i && L[i].data != cur_e);
    if(i)
    {
        pre_e = L[i].data;
        return OK;
    }
    return ERROR;
}

Status NextElem(SLinkList L, ElemType cur_e, ElemType &next_e)
{
//    int i = L[MAX_SIZE-1].cur;
//    while(i && L[i].data != cur_e)
//    {
//        i = L[i].cur;
//    }
//    i = L[i].cur;
//    next_e = L[i].data;
//    return OK;
    int j, i = LocateElem(L, cur_e);
    if(i)
    {
        j = L[i].cur;
        if(j)
        {
            next_e = L[j].data;
            return OK;
        }
    }
    return ERROR;
}

Status ListInsert(SLinkList L, int i, ElemType e)
{
    int m, j, k = MAX_SIZE-1;
    if(i < 1 || i > ListLength(L)+1)
        return ERROR;
    j = Malloc(L);   // 申请新单元
    if(j)
    {
        L[j].data = e;
        for(m = 1; m < i; m++)
            k = L[k].cur;
        L[j].cur = L[k].cur;
        L[k].cur = j;
        return OK;
    }
    return ERROR;
}

Status ListDelete(SLinkList L, int i, ElemType &e)
{
    int j, k = MAX_SIZE-1;
    if(i < 1 || i > ListLength(L))
        return ERROR;
    for(j = 1; j < i; j++)
        k = L[k].cur;
    j = L[k].cur;
    L[k].cur = L[j].cur;
    e = L[j].data;
    Free(L,j);
    return OK;
}

void ListTraverse(SLinkList L, void(*visit)(ElemType))
{
    int i = L[MAX_SIZE-1].cur;
    while(i)
    {
        visit(L[i].data);
        i = L[i].cur;
    }
    printf("\n");
}
