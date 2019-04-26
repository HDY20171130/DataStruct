// bo3-4.h 循环队列基本操作(9个)
void InitQueue(SqQueue &Q)
{
    Q.base = (QElemType*)malloc(MAX_QSIZE*sizeof(QElemType));
    if(!Q.base)
        exit(OVERFLOW);
    Q.front1 = Q.rear = 0;  // 用序号代替指针
}

void DestroyQueue(SqQueue &Q)
{
    if(Q.base)
        free(Q.base);
    Q.base = NULL;
    Q.front1 = Q.rear = 0;
}

void ClearQueue(SqQueue &Q)
{
    Q.front1 = Q.rear = 0;
}

Status QueueEmpty(SqQueue Q)
{
    if(Q.front1 == Q.rear)
        return TRUE;
    return FALSE;
}

int QueueLength(SqQueue Q)
{// ???
    return (Q.rear - Q.front1 + MAX_QSIZE)%MAX_QSIZE;
}

Status GetHead(SqQueue Q, QElemType &e)
{
    if(Q.front1 == Q.rear)
        return ERROR;
    e = Q.base[Q.front1];
    return OK;
}

Status EnQueue(SqQueue &Q, QElemType e)
{
    if((Q.rear + 1)%MAX_QSIZE == Q.front1)
        return ERROR;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAX_QSIZE;
    return OK;
}

Status DeQueue(SqQueue &Q, QElemType &e)
{
    if(Q.front1 == Q.rear)
        return ERROR;
    e = Q.base[Q.front1];
    Q.front1 = (Q.front1 + 1) % MAX_QSIZE;
    return OK;
}

void QueueTraverse(SqQueue Q, void(*visit)(QElemType))
{
    int i = Q.front1;
    while(i != Q.rear)
    {
        visit(Q.base[i]);
        i = (i + 1) % MAX_QSIZE;
    }
    printf("\n");
}


