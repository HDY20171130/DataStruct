// c8-3.h 平衡二叉树的存储结构
typedef struct BSTNode
{
    ElemType data;             // 结点值
    int bf;                    // 结点的平衡因子,比二叉树结构多此项
    BSTNode *lchild, *rchild;   // 左、右孩子指针
}BSTNode, *BSTree;
