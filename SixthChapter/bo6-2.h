// bo6-2.h 二叉链表（存储结构由c6-1.h定义）的基本操作（18个），包括算法6.2～6.4
Status BiTreeEmpty(BiTree T)
{
    if(T)
        return FALSE;
    return TRUE;
}

int BiTreeDepth(BiTree T)
{// 求树深度
    int i, j;
    if(!T)
        return 0;
    i = BiTreeDepth(T->lchild);
    j = BiTreeDepth(T->rchild);
    return i > j ? i + 1 : j + 1;
}

TElemType Root(BiTree T)
{// 返回树的根
    if(BiTreeEmpty(T))
        return Nil;
    return T->data;
}

TElemType Value(BiTree p)
{// 返回p所指结点的值
    return p->data;
}

void Assign(BiTree p, TElemType value)
{// 给p所指结点赋值
    p->data = value;
}

typedef BiTree QElemType;
#include"c3-2.h"
#include"bo3-2.h"

BiTree Point(BiTree T, TElemType s)
{// 返回二叉树T中指向元素值为s的结点的指针
    LinkQueue q;
    QElemType a;
    if(T)
    {
        InitQueue(q);
        EnQueue(q,T);
        while(!QueueEmpty)
    }
}

TElemType LeftChild(BiTree T, TElemType e)
{

}

TElemType RightChild(BiTree T, TElemType e)
{

}

Status DeleteChild(BiTree p, int LR)
{

}

void PostOrderTraverse(BiTree T, void(*Visit)(TElemType))
{

}

void LevelOrderTraverse(BiTree T, void(*Visit)(TElemType))
{

}

void CreateBiTree(BiTree &T)
{

}

TElemType Parent(BiTree T, TElemType e)
{

}

TElemType LeftSibling(BiTree T, TElemType e)
{

}

TElemType RightSibling(BiTree T, TElemType e)
{

}

Status InsertChild(BiTree p, int LR, BiTree c)
{

}

typedef BiTree SElemType;
#include"c3-1.h"
#include"bo3-1.h"

void InOrderTraverse1(BiTree T, void(*Visit)(TElemType))
{

}

void InOrderTraverse2(BiTree T, void(*Visit)(TElemType))
{

}


