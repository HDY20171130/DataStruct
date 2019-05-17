// bo6-3.h  ���Ķ�������洢�ṹ��������(16��)
#define CLearTree DestroyTree
void InitTree(CSTree &T)
{// �������
    T = NULL;
}

void DestroyTree(CSTree &T)
{// ������T
    if(T)
    {
        DestroyTree(T->firstchild);
        DestroyTree(T->nextsibling);
        free(T);
        T = NULL;
    }
}

typedef CSTree QElemType;                      // �������Ԫ������Ϊ���������ָ������
#include "c3-2.h"
#include "bo3-2.h"
void CreateTree(CSTree &T)
{// ������
    char c[20];                                // ��ʱ��ź��ӽ���ֵ(�費����20��)
    CSTree p, p1;
    LinkQueue q;
    int i,m;
    InitQueue(q);
    printf("����������(�ַ���,#Ϊ��):");
    scanf("%c%*c",&c[0]);                       // ���������ֵ
    if(c[0] != Nil)
    {
        T = (CSTree)malloc(sizeof(CSNode));    // ���������
        T->data = c[0];
        T->nextsibling = NULL;                 // ��������ֵܽ��
        EnQueue(q,T);                          // ��������
        while(!QueueEmpty(q))
        {
            DeQueue(q,p);                      // ����һ������ָ��
            printf("�밴����˳�������� %c �����к���:", p->data);
            gets(c);                           // ���������к�����Ϊ�ַ�������
            m = strlen(c);
            if(m > 0)
            {
                p1 = p->firstchild = (CSTree)malloc(sizeof(CSNode));        // ������һ�����ӽ��
                p1->data = c[0];                                            // �����ӽ�㸳ֵ
                EnQueue(q, p1);                                             // ���p1����ָ��
                for(i = 1; i < m; i++)
                {
                    p1->nextsibling = (CSTree)malloc(sizeof(CSNode));       // ������һ���ֵܽ��
                    p1 = p1->nextsibling;                                   // p1ָ����һ���ֵܽ��
                    p1->data = c[i];
                    EnQueue(q, p1);
                }
                p1->nextsibling = NULL;                                      // ���һ�����û����һ���ֵ�
            }
            else
                p->firstchild = NULL;                                       // ����Ϊ��
        }
    }
    else
        T = NULL;                                                           // ����
}

Status TreeEmpty(CSTree T)
{// ��T����,�п�
    if(T)
        return FALSE;
    return TRUE;
}

int TreeDepth(CSTree T)
{// ����,���������Ϊ0,������,�����������(�ݹ�)
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
{// ����p��ָ����ֵ
    return p->data;
}

TElemType Root(CSTree T)
{// ����T�ĸ�
    if(T)
        return Value(T);
    else
        return Nil;
}

CSTree Point(CSTree T, TElemType s)
{// ���ض���������T��ָ��Ԫ��ֵΪs�Ľ��ָ��
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
{// ��T����,cur_e����T�н���ֵ,��cur_e��Ϊvalue
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
{// ��T����,cur_eΪT��ĳ����ֵ,��cur_e�Ǹ��ڵ�,������˫�׽��,���򷵻ؿ�
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
            if(p->firstchild)                    // p�г���
            {
                if(p->firstchild->data == cur_e)
                    return Value(p);
                t = p;
                p = p->firstchild;
                EnQueue(q, p);                   // �������
                while(p->nextsibling)
                {
                    p = p->nextsibling;
                    if(Value(p) == cur_e)
                        return Value(t);
                    EnQueue(q, p);               // �����һ���ֵ�
                }
            }
        }
    }
    return Nil;
}

TElemType LeftChild(CSTree T, TElemType cur_e)
{// ��cur_eΪ��Ҷ�ӽ��,�򷵻�������,���򷵻ؿ�
    CSTree f;
    f = Point(T, cur_e);   // fָ��cur_e
    if(f->firstchild && f)
        return f->firstchild->data;
    else
        return Nil;
}

TElemType RightSibling(CSTree T, TElemType cur_e)
{// ��cur_e�����ֵ�,�򷵻������ֵ�,���򷵻ؿ�
    CSTree f;
    f = Point(T,cur_e);
    if(f && f->nextsibling)
        return f->nextsibling->data;
    else
        return Nil;
}

Status InsertChild(CSTree &T, CSTree p, int i, CSTree c)
{// pָ��T��ĳ�����,1<= i <=p��ָ���Ķ�+1,�ǿ���T��c���ཻ
 // ����cΪT��p���ĵ�i������(��Ϊp��ָ����ַ����,����p����Ҫ����)
    int j;
    CSTree q;
    if(T)                                    // T����
    {
        if(i == 1)                           // ����c��Ϊp�ĳ���
        {
            c->nextsibling = p->firstchild;  // p��ԭ����������c���ֵ�
            p->firstchild = c;               // c��Ϊp�ĳ���
        }
        else                                 // c����p�ĳ���
        {
            q = p->firstchild;               // qָ��p�ĳ���
            j = 2;
            while(q && j < i)                // ��c�Ĳ����
            {
                q = q->nextsibling;          // qָ����һ���ֵܽ��
                j++;
            }
            if(j == i)
            {
                c->nextsibling = q->nextsibling;  // c����һ���ֵ�ָ��p��ԭ��i������
                q->nextsibling = c;               // p�в���c��Ϊp�ĵ�i������
            }
            else                                  // ԭ�к�����С��i-1
                return ERROR;
        }
        return OK;
    }
    else                                          // T��
        return ERROR;
}

Status DeleteChild(CSTree &T, CSTree p, int i)
{// ɾ��T��p��ָ���ĵ�i������
    CSTree b,q;
    int j;
    if(T)
    {
        if(i == 1)                                     // ɾ������
        {
            b = p->firstchild;                         // bָ��p�ĳ���
            p->firstchild = b->nextsibling;            // p�ĵڶ������ӳ�Ϊ����
            b->nextsibling = NULL;                     // p�ĳ��ӽ���Ϊ��ɾ�������ĸ��ڵ�,����һ���ֵ�ָ��Ϊ��
            DestroyTree(b);
        }
        else                                           // ɾ���ǳ���
        {
            q = p->firstchild;                         // qָ��p�ĳ���
            j = 2;
            while(q && j < i)                          // �ҵ�i������
            {
                q = q->nextsibling;                    // qָ����һ���ֵܽ��
                j++;
            }
            if(j == i)
            {
                b = q->nextsibling;                    // bָ���ɾ����
                q->nextsibling = b->nextsibling;       // ����p��ɾ��������
                b->nextsibling = NULL;                 // ��ɾ��������һ���ֵ�ָ��Ϊ��
                DestroyTree(b);
            }
            else                                       // pԭ�к�����С��i
                return ERROR;
        }
        return OK;
    }
    else
        return ERROR;
}

void PostOrderTraverse(CSTree T, void(*Visit)(TElemType))
{// �������
    CSTree p;
    if(T)
    {
        if(T->firstchild)                              // ���Ӵ���
        {
            PostOrderTraverse(T->firstchild,Visit);    // ���������������
            p = T->firstchild->nextsibling;            // pָ���ӵ���һ���ֵ�
            while(p)                                   // ������һ���ֵ�
            {
                PostOrderTraverse(p, Visit);           // ���������һ���ֵ�����
                p = p->nextsibling;                    // pָ����һ���ֵ�
            }
        }
        Visit(Value(T));                               // �����ʸ��ڵ�
    }
}

void LevelOrderTraverse(CSTree T, void(*Visit)(TElemType))
{// �������
    CSTree p;
    LinkQueue q;
    InitQueue(q);
    if(T)                                    // ���ǿ�
    {
        Visit(Value(T));                     // �ȷ��ʸ��ڵ�
        EnQueue(q,T);                        // ��ָ�����
        while(!QueueEmpty(q))
        {
            DeQueue(q,p);                    // ָ�����
            if(p->firstchild)                // ���Ӵ���
            {
                p = p->firstchild;
                Visit(Value(p));             // ���ʳ��ӽ��
                EnQueue(q,p);                // ��ӳ��ӽ��
                while(p->nextsibling)        // ����һ���ֵ�
                {
                    p = p->nextsibling;
                    Visit(Value(p));         // ������һ���ֵ�
                    EnQueue(q,p);            // ����ֵܽ��
                }
            }
        }
    }
    printf("\n");
}


