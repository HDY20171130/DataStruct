// bo3-2.h链队列的基本操作(9个)
void InitQueue(LinkQueue &Q)
{
    Q.front1 = Q.rear = (QueuePtr)malloc(sizeof(QNode));
    if(!Q.front1)
        exit(OVERFLOW);
    Q.front1->next = NULL;
}

void DestroyQueue(LinkQueue &Q)
{
    while(Q.front1)
    {
        Q.rear = Q.front1->next;
        free(Q.front1);
        Q.front1 = Q.rear;
    }
}

void ClearQueue(LinkQueue &Q)
{
    DestroyQueue(Q);
    InitQueue(Q);
}

Status QueueEmpty(LinkQueue Q)
{
    if(Q.front1 == Q.rear)
        return TRUE;
    return FALSE;
}

int QueueLength(LinkQueue Q)
{
    int len = 0;
    QueuePtr p = Q.front1;
    while(Q.rear != p)
    {
        len++;
        p = p->next;
    }
    return len;
}

Status GetHead(LinkQueue Q, QElemType &e)
{
    if(Q.front1 == Q.rear)
        return ERROR;
    QueuePtr p = Q.front1->next;
    e = p->data;
    return OK;
}

void EnQueue(LinkQueue &Q, QElemType e)
{// 入队
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if(!p)
        exit(OVERFLOW);
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;  // 追加到队尾
    Q.rear = p;
}

Status DeQueue(LinkQueue &Q, QElemType &e)
{
    if(Q.front1 == Q.rear)
        return ERROR;
    QueuePtr p = Q.front1->next;
    e = p->data;
    Q.front1->next = p->next;  // 队头后移
    if(Q.rear == p)
        Q.rear = Q.front1;
    free(p);
    return OK;
}

void QueueTraverse(LinkQueue Q, void(*visit)(QElemType))
{
    QueuePtr p = Q.front1->next;
    while(p)
    {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
}
