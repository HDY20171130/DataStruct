// bo6-1.h 二叉链表的4个基本操作，包括算法6.1，func8-4.h等调用
#define ClearBiTree DestroyBiTree
void InitBiTree(BiTree &T)
{
    T = NULL;
}

void DestroyBiTree(BiTree &T)
{
    if(T)
    {
        DestroyBitree(T->lchild);
        DestroyBitree(T->rchild);
        free(T);
        T = NULL;
    }
}

void PreOrderTraverse(BiTree T, void(*Visit)(TElemType))
{// 先序遍历
    if(T)
    {
        Visit(T->data);
        PreOrderTraverse(T->lchild, Visit);
        PreOrderTraverse(T->rchild, Visit);
    }
}

void InOrderTraverse(BiTree T, void(*Visit)(TElemType))
{// 中序遍历
    if(T)
    {
        InOrderTraverse(T->lchild,Visit);
        Visit(T->data);
        InOrderTraverse(T->rchild,Visit);
    }
}
