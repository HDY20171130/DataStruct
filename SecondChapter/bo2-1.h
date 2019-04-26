// bo2-1.h 顺序存储的线性表
void InitList(SqList &L)
{
    L.elem = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L.elem)
        exit(OVERFLOW);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
}

void DestroyList(SqList &L)
{
    free(L.elem);
    L.elem = NULL;
    L.length = 0;
    L.listsize = 0;

}

void ClearList(SqList &L)
{
    L.length = 0;
}

Status ListEmpty(SqList L)
{
    if(L.length == 0)
        return TRUE;
    return FALSE;
}

int ListLength(SqList L)
{
    return L.length;
}

Status GetElem(SqList L, int i, ElemType &e)
{
    if(i < 1 || i > L.length)
        return ERROR;
    e = *(L.elem+i-1);
    return OK;
}

int LocateElem(SqList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
    int i = 1;
    ElemType *p = L.elem;
    while(i <= L.length && !compare(*p++, e));
        i++;
//    if(i>L.length)
//        return 0;
//    return i;
    if(i <= L.length)
        return i;
    return 0;
}

Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e)
{
    int i = 2;
    ElemType *p = L.elem+1;
    while(i <= L.length && *p != cur_e)
    {
        i++;
        p++;
    }

    if(i > L.length)
        return ERROR;
    pre_e = *--p;
    return OK;
}

Status NextElem(SqList L, ElemType cur_e, ElemType &next_e)
{
    int i = 1;
    ElemType *p = L.elem;
    while(i < L.length && *p != cur_e)
    {
        i++;
        p++;
    }
    if(i == L.length)
        return ERROR;
    next_e = *++p;
    return OK;
}

Status ListInsert(SqList &L, int i, ElemType e)
{
    ElemType *p, *q, *newbase;
    if(i < 1 || i > L.length+1)   // 插入位置可以是第L.length位,所以i不能大于L.length+1
        return ERROR;
    if(L.length == L.listsize)  // 线性表满,追加内存
    {
        newbase = (ElemType*)realloc(L.elem,(L.listsize+LIST_INCREMENT)*sizeof(ElemType));
        if(!newbase)
            exit(OVERFLOW);
        L.elem = newbase;
        L.listsize += LIST_INCREMENT;
    }
    q = L.elem+i-1;
    for(p = L.elem+L.length-1; p >= q; --p)
        *(p+1) = *p;
    *q = e;
    L.length++;
    return OK;
}

Status ListDelete(SqList &L, int i, ElemType &e)
{
    ElemType *p, *q;
    if(i < 1 || i > L.length)
        return ERROR;
    p = L.elem+i-1;
    e = *p;
//    for(j = 0; j < L.length; j++)
//    {
//        *p = *(p+1);
//        p++;
//    }
    q = L.elem+L.length-1;
    for(p++; p <= q; p++)
        *(p-1) = *p;
    L.length--;
    return OK;
}

void ListTraverse(SqList L, void(*visit)(ElemType&))
{
    ElemType *p = L.elem;
    for(int i = 1; i <= L.length; i++)
        visit(*p++);
    printf("\n");
}
