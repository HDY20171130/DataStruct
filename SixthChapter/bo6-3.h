// bo6-3.h  数的二叉链表存储结构基本操作(16个)
#define CLearTree DestroyTree
void InitTree(CSTree &T)
{// 构造空树
    T = NULL;
}

void DestroyTree(CSTree &T)
{// 销毁树T
    if(T)
    {
        DestroyTree(T->firstchild);
        DestroyTree(T->nextsibling);
        free(T);
        T = NULL;
    }
}

typedef CSTree QElemType;                      // 定义队列元素类型为二叉链表的指针类型
#include "c3-2.h"
#include "bo3-2.h"
void CreateTree(CSTree &T)
{// 构造树
    char c[20];                                // 临时存放孩子结点的值(设不超过20个)
    CSTree p, p1;
    LinkQueue q;
    int i,m;
    InitQueue(q);
    printf("请输入根结点(字符型,#为空):");
    scanf("%c%*c",&c[0]);                       // 输入根结点的值
    if(c[0] != Nil)
    {
        T = (CSTree)malloc(sizeof(CSNode));    // 建立根结点
        T->data = c[0];
        T->nextsibling = NULL;                 // 根结点无兄弟结点
        EnQueue(q,T);                          // 根结点入队
        while(!QueueEmpty(q))
        {
            DeQueue(q,p);                      // 出队一个结点的指针
            printf("请按长幼顺序输入结点 %c 的所有孩子:", p->data);
            gets(c);                           // 将结点的所有孩子作为字符串输入
            m = strlen(c);
            if(m > 0)
            {
                p1 = p->firstchild = (CSTree)malloc(sizeof(CSNode));        // 建立第一个孩子结点
                p1->data = c[0];                                            // 给长子结点赋值
                EnQueue(q, p1);                                             // 入队p1结点的指针
                for(i = 1; i < m; i++)
                {
                    p1->nextsibling = (CSTree)malloc(sizeof(CSNode));       // 建立下一个兄弟结点
                    p1 = p1->nextsibling;                                   // p1指向下一个兄弟结点
                    p1->data = c[i];
                    EnQueue(q, p1);
                }
                p1->nextsibling = NULL;                                      // 最后一个结点没有下一个兄弟
            }
            else
                p->firstchild = NULL;                                       // 长子为空
        }
    }
    else
        T = NULL;                                                           // 空树
}

Status TreeEmpty(CSTree T)
{// 树T存在,判空
    if(T)
        return FALSE;
    return TRUE;
}

int TreeDepth(CSTree T)
{// 树空,则树的深度为0,树不空,返回树的深度(递归)
    CSTree p;
    int depth, max_depth = 0;
    if(!T)
        return 0;
    for(p = T->firstchild; p; p = p->nextsibling)
    {
        depth = TreeDepth(p);
        if(depth > max_depth)
            max_depth = depth;
    }
    return max_depth+1;
}

TElemType Value(CSTree p)
{// 返回p所指结点的值
    return p->data;
}

TElemType Root(CSTree T)
{// 返回T的根
    if(T)
        return Value(T);
    else
        return Nil;
}

CSTree Point(CSTree T, TElemType s)
{// 返回二叉链表树T中指向元素值为s的结点指针
    LinkQueue q;
    QElemType a;
    if(T)
    {
        InitQueue(q);
        EnQueue(q, T);
        while(!QueueEmpty(q))
        {
            DeQueue(q, a);
            if(a->data == s)
                return a;
            if(a->firstchild)
                EnQueue(q, a->firstchild);
            if(a->nextsibling)
                EnQueue(q, a->nextsibling);
        }
    }
    return NULL;
}

Status Assign(CSTree &T, TElemType cur_e,TElemType value)
{// 树T存在,cur_e是树T中结点的值,将cur_e该为value
    CSTree p;
    if(T)
    {
        p = Point(T,cur_e);
        if(p)
        {
            p->data = value;
            return OK;
        }
    }
    return ERROR;
}

TElemType Parent(CSTree T, TElemType cur_e)
{// 树T存在,cur_e为T中某结点的值,若cur_e非根节点,返回其双亲结点,否则返回空
    CSTree p,t;
    LinkQueue q;
    InitQueue(q);
    if(T)
    {
        if(Value(T) == cur_e)
            return Nil;
        EnQueue(q, T);
        while(!QueueEmpty(q))
        {
            DeQueue(q, p);
            if(p->firstchild)                    // p有长子
            {
                if(p->firstchild->data == cur_e)
                    return Value(p);
                t = p;
                p = p->firstchild;
                EnQueue(q, p);                   // 长子入队
                while(p->nextsibling)
                {
                    p = p->nextsibling;
                    if(Value(p) == cur_e)
                        return Value(t);
                    EnQueue(q, p);               // 入队下一个兄弟
                }
            }
        }
    }
    return Nil;
}

TElemType LeftChild(CSTree T, TElemType cur_e)
{// 若cur_e为非叶子结点,则返回其左孩子,否则返回空
    CSTree f;
    f = Point(T, cur_e);   // f指向cur_e
    if(f->firstchild && f)
        return f->firstchild->data;
    else
        return Nil;
}

TElemType RightSibling(CSTree T, TElemType cur_e)
{// 若cur_e有右兄弟,则返回其右兄弟,否则返回空
    CSTree f;
    f = Point(T,cur_e);
    if(f && f->nextsibling)
        return f->nextsibling->data;
    else
        return Nil;
}

Status InsertChild(CSTree &T, CSTree p, int i, CSTree c)
{// p指向T中某个结点,1<= i <=p所指结点的度+1,非空树T与c不相交
 // 插入c为T中p结点的第i棵子树(因为p所指结点地址不变,所以p不需要引用)
    int j;
    CSTree q;
    if(T)                                    // T不空
    {
        if(i == 1)                           // 插入c作为p的长子
        {
            c->nextsibling = p->firstchild;  // p的原长子是现在c的兄弟
            p->firstchild = c;               // c成为p的长子
        }
        else                                 // c不是p的长子
        {
            q = p->firstchild;               // q指向p的长子
            j = 2;
            while(q && j < i)                // 找c的插入点
            {
                q = q->nextsibling;          // q指向下一个兄弟结点
                j++;
            }
            if(j == i)
            {
                c->nextsibling = q->nextsibling;  // c的下一个兄弟指向p的原第i个孩子
                q->nextsibling = c;               // p中插入c作为p的第i个孩子
            }
            else                                  // 原有孩子数小于i-1
                return ERROR;
        }
        return OK;
    }
    else                                          // T空
        return ERROR;
}

Status DeleteChild(CSTree &T, CSTree p, int i)
{// 删除T中p所指结点的第i棵子树
    CSTree b,q;
    int j;
    if(T)
    {
        if(i == 1)                                     // 删除长子
        {
            b = p->firstchild;                         // b指向p的长子
            p->firstchild = b->nextsibling;            // p的第二个孩子成为长子
            b->nextsibling = NULL;                     // p的长子结点成为待删除子树的根节点,其下一个兄弟指针为空
            DestroyTree(b);
        }
        else                                           // 删除非长子
        {
            q = p->firstchild;                         // q指向p的长子
            j = 2;
            while(q && j < i)                          // 找第i棵子树
            {
                q = q->nextsibling;                    // q指向下一个兄弟结点
                j++;
            }
            if(j == i)
            {
                b = q->nextsibling;                    // b指向待删子树
                q->nextsibling = b->nextsibling;       // 从树p中删除该子树
                b->nextsibling = NULL;                 // 待删子树的下一个兄弟指针为空
                DestroyTree(b);
            }
            else                                       // p原有孩子数小于i
                return ERROR;
        }
        return OK;
    }
    else
        return ERROR;
}

void PostOrderTraverse(CSTree T, void(*Visit)(TElemType))
{// 后序遍历
    CSTree p;
    if(T)
    {
        if(T->firstchild)                              // 长子存在
        {
            PostOrderTraverse(T->firstchild,Visit);    // 后根遍历长子子树
            p = T->firstchild->nextsibling;            // p指向长子的下一个兄弟
            while(p)                                   // 还有下一个兄弟
            {
                PostOrderTraverse(p, Visit);           // 后根遍历下一个兄弟子树
                p = p->nextsibling;                    // p指向下一个兄弟
            }
        }
        Visit(Value(T));                               // 最后访问根节点
    }
}

void LevelOrderTraverse(CSTree T, void(*Visit)(TElemType))
{// 层序遍历
    CSTree p;
    LinkQueue q;
    InitQueue(q);
    if(T)                                    // 树非空
    {
        Visit(Value(T));                     // 先访问根节点
        EnQueue(q,T);                        // 根指针入队
        while(!QueueEmpty(q))
        {
            DeQueue(q,p);                    // 指针出队
            if(p->firstchild)                // 长子存在
            {
                p = p->firstchild;
                Visit(Value(p));             // 访问长子结点
                EnQueue(q,p);                // 入队长子结点
                while(p->nextsibling)        // 有下一个兄弟
                {
                    p = p->nextsibling;
                    Visit(Value(p));         // 访问下一个兄弟
                    EnQueue(q,p);            // 入队兄弟结点
                }
            }
        }
    }
    printf("\n");
}


