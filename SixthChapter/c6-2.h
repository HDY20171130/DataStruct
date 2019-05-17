// c6-2.h 树的二叉链表存储结构(孩子-兄弟)
typedef struct CSNode
{
    TElemType data;
    CSNode *firstchild, *nextsibling;
}CSNode, *CSTree;
