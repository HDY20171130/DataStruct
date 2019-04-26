// 队列的链式存储结构
typedef struct QNode
{
    QElemType data;
    QNode *next;
} *QueuePtr;

struct LinkQueue
{
    QueuePtr front1, rear;  // 队头, 队尾
};
