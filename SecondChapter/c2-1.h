// 线性表的动态分配顺序存储结构
#define LIST_INIT_SIZE 10
#define LIST_INCREMENT 2
struct SqList
{
    ElemType *elem;
    int length;
    int listsize;
};
