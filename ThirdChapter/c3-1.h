// 栈的顺序存储结构
#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 2
struct SqStack
{
    SElemType *top;
    SElemType *base;
    int stacksize;
};
