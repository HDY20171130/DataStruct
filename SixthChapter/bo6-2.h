// bo6-2.h 二叉链表（存储结构由c6-1.h定义）的基本操作（18个），包括算法6.2～6.4
Status BiTreeEmpty(BiTree T)
{// 判断二叉树是否为空
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
{// 返回树的根的值
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

typedef BiTree QElemType;  // 二叉树指针类型
#include"c3-2.h"
#include"bo3-2.h"

BiTree Point(BiTree T, TElemType s)
{// 返回二叉树T中指向元素值为s的结点的指针
    LinkQueue q;     // 队列
    QElemType a;     // 二叉树指针类型
    if(T)
    {
        InitQueue(q);
        EnQueue(q,T);
        while(!QueueEmpty)
        {
            DeQueue(q, a);
            if(a->data == s)
            {
                DestroyQueue(q);
                return a;
            }
            if(a->lchild)
                EnQueue(q, a->lchild);
            if(a->rchild)
                EnQueue(q, a->rchild);
        }
        DestroyQueue(q);
    }
    return NULL;
}

TElemType LeftChild(BiTree T, TElemType e)
{// 二叉树存在，e为树中某个结点
 // 返回e的左孩子，若无返回空
    BiTree a;
    if(T)
    {
        a = Point(T,e);               // 先定位元素的位置
        if(a && a->lchild)
            return a->lchild->data;
    }
    return Nil;
}

TElemType RightChild(BiTree T, TElemType e)
{// 二叉树存在，e为树中某个结点
 // 返回e的左孩子，若无返回空
    BiTree a;
    if(T)
    {
        a = Point(T,e);
        if(a &&a->rchild)
            return a->rchild->data;
    }
    return Nil;
}

Status DeleteChild(BiTree p, int LR)
{// 二叉树存在，p指向T中某个结点，LR为0或1
 // 根据LR为0或1，删除T中指向p所指结点的左子树或右子树
    if(p)
    {
        if(LR == 0)
            ClearBiTree(p->lchild);
        else if(LR == 1)
            ClearBiTree(p->rchild);
        return OK;
    }
    return ERROR;
}

void PostOrderTraverse(BiTree T, void(*Visit)(TElemType))
{// 二叉树存在，Visit是对结点操作的应用函数
 // 后序递归遍历,对每个结点只调用一次Visit
    if(T)
    {
        PostOrderTraverse(T->lchild, Visit);
        PostOrderTraverse(T->rchild, Visit);
        Visit(T->data);
    }
}

void LevelOrderTraverse(BiTree T, void(*Visit)(TElemType))
{// 二叉树存在，Visit是对结点操作的应用函数
 // 层序递归遍历T(利用队列)
    LinkQueue q;
    QElemType a;
    if(T)
    {
        InitQueue(q);
        EnQueue(q, T);
        while(!QueueEmpty(q))
        {
            DeQueue(q,a);
            Visit(a->data);
            if(a->lchild)
                EnQueue(q,a->lchild);
            if(a->rchild)
                EnQueue(q,a->rchild);
        }
        printf("\n");
        DestroyQueue(q);
    }
}

void CreateBiTree(BiTree &T)
{// 按先序次序输入二叉树中结点的值
 // 构造二叉链表表示的二叉树,Nil表示空树
    TElemType ch;
    scanf(form, &ch);   // 输入结点的值
    if(ch == Nil)
        T = NULL;
    else
    {
        T = (BiTree)malloc(sizeof(BiTNode));
        if(!T)
            exit(OVERFLOW);
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

TElemType Parent(BiTree T, TElemType e)
{// 二叉树存在,e为T中某个结点
 // 若e为T的非根节点,则返回其双亲,否则返回空
    LinkQueue q;
    QElemType a;
    if(T)
    {
        InitQueue(q);
        EnQueue(q,T);
        while(!QueueEmpty(q))
        {
            DeQueue(q,a);
            if(a->lchild && a->lchild->data == e || a->rchild && a->rchild->data == e)
                return a->data;
            else
            {
                if(a->lchild)
                    EnQueue(q,a->lchild);
                if(a->rchild)
                    EnQueue(q,a->rchild);
            }
        }
    }
    return Nil;
}

TElemType LeftSibling(BiTree T, TElemType e)
{// 二叉树存在,e为T中某个结点
 // 返回e的左兄弟,若e无左孩子,返回空
    TElemType a;
    BiTree p;
    if(T)
    {
        a = Parent(T,e);
        if(a != Nil)
        {
            p = Point(T,a);
            if(p->lchild && p->rchild && p->rchild->data == e)
                return p->lchild->data;
        }
    }
    return Nil;
}

TElemType RightSibling(BiTree T, TElemType e)
{
    TElemType a;
    BiTree p;
    if(T)
    {
        a = Parent(T,e);
        if(a != Nil)
        {
            p = Point(T,a);
            if(p->lchild && p->rchild && p->lchild->data == e)
                return p->rchild->data;
        }
    }
    return Nil;
}

Status InsertChild(BiTree p, int LR, BiTree c)
{// 二叉树存在,p指向T中某个结点,LR为0或1, 非空二叉树c与T不相交且右子树为空
 // 根据LR为0或1,插入c为p所指结点的左子树或右子树,p所指结点的原左子树或右子树成为c的左子树或右子树
    if(p)
    {
        if(LR == 0)
        {
            c->rchild = p->lchild;
            p->lchild = c;
        }
        if(LR == 1)
        {
            c->rchild = p->rchild;
            p->rchild = c;
        }
        return OK;
    }
    return ERROR;
}

typedef BiTree SElemType;
#include"c3-1.h"
#include"bo3-1.h"

void InOrderTraverse1(BiTree T, void(*Visit)(TElemType))
{// 采用二叉链表存储结构,Visit是对每个元素进行操作的函数
 // 中序遍历二叉树T的非递归算法(利用栈)
    SqStack S;
    InitStack(S);
    while(T || !StackEmpty(S))
    {
        if(T)
        {// 根指针进栈,遍历左子树
            Push(S, T);
            T = T->lchild;
        }
        else
        {
            Pop(S, T);
            Visit(T->data);
            T = T->rchild;
        }
    }
    printf("\n");
    DestroyStack(S);
}

void InOrderTraverse2(BiTree T, void(*Visit)(TElemType))
{
    SqStack S;
    BiTree p;
    InitStack(S);
    Push(S, T);
    while(!StackEmpty(S))
    {
        while(GetTop(S, p) && p)
            Push(S, p->lchild);
        Pop(S, p);
        if(!StackEmpty(S))
        {
            Pop(S, p);
            Visit(p->data);
            Push(S, p->rchild);
        }
    }
    printf("\n");
    DestroyStack(S);
}


