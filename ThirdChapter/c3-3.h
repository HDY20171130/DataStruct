// c3-3.h 队列的顺序存储结构（循环队列）
#define MAX_QSIZE 5
struct SqQueue
{
    QElemType *base;
    int front1;
    int rear;
};
