//// main6-1.cpp ��������������������������
//#define CHAR 1
////#define CHAR 0 // ���ͣ�����ѡһ������3��
//#include"func6-1.h"
//#include"c6-1.h"
//#include"bo6-1.h"
//#include"bo6-2.h"
//int main()
//{
//    int i;
//    BiTree T, p, c;
//    TElemType e1, e2;
//    InitBiTree(T);
//    printf("����ն����������շ�%d��1���� 0���񣩡��������=%d��\n",
//    BiTreeEmpty(T), BiTreeDepth(T));
//    e1=Root(T);
//    if(e1!=Nil)
//        printf("�������ĸ�Ϊ"form"��\n", e1);
//    else
//        printf("���գ��޸���\n");
//    #if CHAR
//        printf("�밴����������������磺ab###��ʾaΪ����㣬bΪ�������Ķ���������\n");
//    #else
//        printf("�밴����������������磺1 2 0 0 0��ʾ1Ϊ����㣬2Ϊ�������Ķ���������\n");
//    #endif
//    CreateBiTree(T);
//    printf("���������������շ�%d��1���� 0���񣩡��������=%d��\n", BiTreeEmpty(T),
//    BiTreeDepth(T));
//    e1=Root(T);
//    if(e1!=Nil)
//        printf("�������ĸ�Ϊ"form"��\n", e1);
//    else
//        printf("���գ��޸���\n");
//    printf("����ݹ������������\n");
//    InOrderTraverse(T, Visit);
//    printf("\n����ݹ������������\n");
//    PostOrderTraverse(T, Visit);
//    printf("\n������һ������ֵ��");
//    scanf("%*c"form, &e1);
//    p=Point(T, e1);
//    printf("����ֵΪ"form"��\n", Value(p));
//    printf("���ı�˽���ֵ����������ֵ��");
//    scanf("%*c"form"%*c", &e2);
//    Assign(p, e2);
//    printf("���������������\n");
//    LevelOrderTraverse(T, Visit);
//    e1=Parent(T, e2);
//    if(e1!=Nil)
//        printf(form"��˫����"form"��", e2, e1);
//    else
//        printf(form"û��˫�ף�", e2);
//    e1=LeftChild(T, e2);
//    if(e1!=Nil)
//        printf("������"form"��", e1);
//    else
//        printf("û�����ӣ�");
//    e1=RightChild(T, e2);
//    if(e1!=Nil)
//        printf("�Һ�����"form"��", e1);
//    else
//        printf("û���Һ��ӣ�");
//    e1=LeftSibling(T, e2);
//    if(e1!=Nil)
//        printf("���ֵ���"form"��", e1);
//    else
//        printf("û�����ֵܣ�");
//    e1=RightSibling(T, e2);
//    if(e1!=Nil)
//        printf("���ֵ���"form"��\n", e1);
//    else
//        printf("û�����ֵܡ�\n");
//    InitBiTree(c);
//    printf("�빹��һ��������Ϊ�յĶ�����c��\n");
//    #if CHAR
//        printf("�밴����������������磺ab###��ʾaΪ����㣬bΪ�������Ķ���������\n");
//    #else
//        printf("�밴����������������磺1 2 0 0 0��ʾ1Ϊ����㣬2Ϊ�������Ķ���������\n");
//    #endif
//    CreateBiTree(c);
//    printf("����ݹ����������c��\n");
//    InOrderTraverse(c, Visit);
//    printf("\n��c�嵽��T�У���������T����c��˫�׽�� cΪ��0�����ң�1��������");
//    scanf("%*c"form"%d", &e1, &i);
//    p=Point(T, e1);
//    InsertChild(p, i, c);
//
//    printf("����ݹ������������\n");
//    PreOrderTraverse(T, Visit);
//    printf("\nɾ���������������ɾ��������˫�׽�� ��0�����ң�1��������");
//    scanf("%*c"form"%d", &e1, &i);
//    p=Point(T, e1);
//    DeleteChild(p, i);
//    printf("����ݹ������������\n");
//    PreOrderTraverse(T, Visit);
//    printf("\n����ǵݹ������������\n");
//    InOrderTraverse1(T, Visit);
//    printf("����ǵݹ��������������һ�ַ�������\n");
//    InOrderTraverse2(T, Visit);
//    DestroyBiTree(T);
//    return 0;
//}


// main6-2.cpp ����bo6-3.h��bo6-4.h�ĳ���
//#define CHAR 10
//#include"func6-1.h"
//#include"c6-2.h"
//#include"bo6-3.h"
//#include"bo6-4.h"
//int main()
//{
//    int i;
//    CSTree T, p, q;
//    TElemType e, e1;
//    InitTree(T);
//    printf("������������շ�%d��1���� 0���񣩡�����Ϊ%c���������Ϊ%d��\n",TreeEmpty(T), Root(T), TreeDepth(T));
//    CreateTree(T);
//    printf("������T�����շ�%d��1���� 0���񣩡�����Ϊ%c���������Ϊ%d��\n",TreeEmpty(T), Root(T), TreeDepth(T));
//    printf("���������T��\n");
//    LevelOrderTraverse(T, Visit);
//    printf("��������޸ĵĽ���ֵ ��ֵ��");
//    scanf("%c%*c%c%*c", &e, &e1);
//    Assign(T, e, e1);
//    printf("��������޸ĺ����T��\n");
//    LevelOrderTraverse(T, Visit);
//    printf("%c��˫����%c��������%c����һ���ֵ���%c��\n", e1, Parent(T, e1),
//    LeftChild(T, e1), RightSibling(T, e1));
//    printf("������p��\n");
//    CreateTree(p);
//    printf("���������p��\n");
//    LevelOrderTraverse(p, Visit);
//    printf("����p�嵽��T�У�������T��p��˫�׽�� ������ţ�");
//    scanf("%c%d%*c", &e, &i);
//    q=Point(T, e);
//    InsertChild(T, q, i, p);
//    printf("��������޸ĺ����T��\n");
//    LevelOrderTraverse(T, Visit);
//    printf("�ȸ�������T��\n");
//    PreOrderTraverse(T, Visit);
//    printf("\n���������T��\n");
//    PostOrderTraverse(T, Visit);
//    printf("\nɾ����T�н��e�ĵ�i��������������e i��");
//    scanf("%c%d", &e, &i);
//    q=Point(T, e);
//    DeleteChild(T, q, i);
//    printf("��������޸ĺ����T��\n");
//    LevelOrderTraverse(T, Visit);
//    DestroyTree(T);
//    return 0;
//}

// algo6-1.cpp �����������
//#include "c1.h"
//#include "c6-3.h"
//#include "func6-2.h"
//void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n)
//{// w���n���ַ���Ȩֵ(��>0)�����������HT�����n���ַ��Ĺ���������HC
//    int start;
//    unsigned f;
//#include "func6-3.h"
//    HC = (HuffmanCode)malloc((n+1) * sizeof(char*));    // ����n���ַ������ͷָ������([0]����)
//    cd = (char*)malloc(n * sizeof(char));               // ���������Ĺ����ռ�
//    cd[n-1] = '\0';                                     // ���������
//    for(i= 1; i <= n; i++)
//    {// ��������������
//        start = n-1;       // ���������λ��
//        for(c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)
//        {
//            if(HT[f].lchild == c)       // c����˫������
//                cd[--start] = '0';      // ��Ҷ�ӽ�������ֵ'0'
//            else                        // c����˫���Һ���
//                cd[--start] = '1';      // ��Ҷ�ӽ�������ֵ'1'
//        }
//        HC[i] = (char*)malloc((n-start) * sizeof(char));
//        strcpy(HC[i], &cd[start]);
//    }
//    free(cd);
//}
//#include "func6-4.h"  // �����������������

// algo6-2.cpp
#include"c1.h"
#include"c6-3.h"
#include"func6-2.h"
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n)
{
    unsigned cdlen;
#include"func6-3.h"
    HC = (HuffmanCode)malloc((n+1)*sizeof(char*));
    cd = (char*)malloc(n*sizeof(char));
    c = m;                    // m = 2*n-1
    cdlen = 0;                // �볤��ֵΪ0
    for(i = 1; i <= m; i++)
    {
        HT[i].weight = 0;     // ����벻��ҪȨֵ��,�������״̬��־,0��ʾ���Һ��Ӷ�û�з��ʹ�
    }
    while(c)
    {
        if(HT[c].weight == 0)
        {
            HT[c].weight = 1;        // ���ӱ����ʹ�,�Һ���δ����
            if(HT[c].lchild != 0)    // ������(����Ҷ�ӽ��)
            {
                c = HT[c].lchild;    // ��c��Ϊ�����ӵ����(��Ҷ�ӽ�㷽����һ��)
                cd[cdlen++] = '0';   // ���֧����Ϊ0
            }
            else if(HT[c].rchild == 0)    // ���Ϊc��Ҷ�ӽ��
            {// �Ǽ�Ҷ�ӽ����ַ�����
                HC[c] = (char*)malloc((cdlen+1) * sizeof(char));    // ���ɱ���ռ�
                cd[cdlen] = '\0';                                   // ���һ��λ�ø�ֵ��β������
                strcpy(HC[c],cd);                                   // ���Ʊ���
            }
        }
        else if(HT[c].weight == 1)   // ���ӱ����ʹ�
        {
            HT[c].weight = 2;
            if(HT[c].rchild != 0)
            {
                c = HT[c].rchild;
                cd[cdlen++] = '1';
            }
        }
        else
        {
            c = HT[c].parent;
            --cdlen;
        }
    }
    free(cd);
}
#include "func6-4.h"
