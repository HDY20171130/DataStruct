//#include "c1.h"
//typedef int ElemType;
//#include "c2-1.h"
//#include "bo2-1.h"
//#include "func2-2.h"
//
//Status sq(ElemType c1, ElemType c2)
//{
//    if(c1 == c2*c2)
//        return TRUE;
//    return FALSE;
//}
//
//void dbl(ElemType &c)
//{
//    c *= 2;
//}
//
//
//int main()
//{
//    SqList L;
//    ElemType e, e0;
//    Status i;
//    int j, k;
//    InitList(L);
//    printf("初始化L后，L.length=%d，L.listsize=%d，L.elem=%u\n",
//    L.length, L.listsize, L.elem);
//    for(j=1; j<=5; j++)
//        i=ListInsert(L, 1, j);
//    printf("在L的表头依次插入1～5后，*L.elem=");
//    for(j=1; j<=5; j++)
//        printf("%d ", *(L.elem+j-1));
//    printf("\n调用ListTraverse()函数，依次输出表L中的元素：");
//    ListTraverse(L, print1);
//    i=ListEmpty(L);
//    printf("L.length=%d，L.listsize=%d（不变），", L.length, L.listsize);
//    printf("L.elem=%u（不变），L是否空？i=%d\n", L.elem, i);
//    ClearList(L);
//    i=ListEmpty(L);
//    printf("清空L后，L.length=%d，L.listsize=%d，", L.length, L.listsize);
//    printf("L.elem=%u，L是否空？i=%d（1：是 0：否）\n", L.elem, i);
//    for(j=1; j<=10; j++)
//        ListInsert(L, j, j);
//    printf("在L的表尾依次插入1～10后，L=");
//    ListTraverse(L, print1);
//    printf("L.length=%d，L.listsize=%d，L.elem=%u\n",L.length,L.listsize,L.elem);
//    ListInsert(L, 1, 0);
//    printf("在L的表头插入0后，L.length=%d，L.listsize=%d（改变），"
//    "L.elem=%u（可能改变）\n", L.length, L.listsize, L.elem);
//    GetElem(L, 5, e);
//    printf("第5个元素的值为%d\n", e);
//    for(j=10; j<=11; j++)
//    {
//        k=LocateElem(L, j, equal);
//        if(k)
//            printf("第%d个元素的值为%d，", k, j);
//        else
//            printf("没有值为%d的元素\n", j);
//    }
//    for(j=3; j<=4; j++)
//    {
//        k=LocateElem(L, j, sq);
//        if(k)
//            printf("第%d个元素的值为%d的平方，", k, j);
//        else
//            printf("没有值为%d的平方的元素\n", j);
//    }
//    for(j=1; j<=2; j++)
//    {
//        GetElem(L, j, e0);
//        i=PriorElem(L, e0, e);
//        if(i==ERROR)
//            printf("元素%d无前驱，", e0);
//        else
//            printf("元素%d的前驱为%d\n", e0, e);
//    }
//    for(j=ListLength(L)-1; j<=ListLength(L); j++)
//    {
//        GetElem(L, j, e0);
//        i=NextElem(L, e0, e);
//        if(i==ERROR)
//            printf("元素%d无后继\n", e0);
//        else
//            printf("元素%d的后继为%d，", e0, e);
//    }
//    k=ListLength(L);
//    for(j=k+1; j>=k; j--)
//    {
//        i=ListDelete(L, j, e);
//        if(i==ERROR)
//            printf("删除第%d个元素失败。", j);
//        else
//            printf("删除第%d个元素成功，其值为%d", j, e);
//    }
//    ListTraverse(L, dbl);
//    printf("L的元素值加倍后，L=");
//    ListTraverse(L, print1);
//    DestroyList(L);
//    printf("销毁L后，L.length=%d，L.listsize=%d，L.elem=%u\n",
//    L.length, L.listsize, L.elem);
//    return 0;
//}


//// algo2-1.cpp 实现算法2.7的程序
//#include"c1.h"
//typedef int ElemType;
//#include"c2-1.h"
//#include"bo2-1.h"
//#include"func2-2.h"
//void MergeList(SqList La, SqList Lb, SqList &Lc)
//{
//
//    ElemType *pa, *pa_last, *pb, *pb_last, *pc;
//    pa=La.elem;
//    pb=Lb.elem;
//    Lc.listsize=Lc.length=La.length+Lb.length;
//    pc=Lc.elem=(ElemType*)malloc(Lc.listsize*sizeof(ElemType));
//    if(!Lc.elem)
//    exit(OVERFLOW);
//    pa_last=La.elem+La.length-1;
//    pb_last=Lb.elem+Lb.length-1;
//    while(pa<=pa_last && pb<=pb_last)
//    {
//        if(*pa<=*pb)
//            *pc++=*pa++;
//        else
//            *pc++=*pb++;
//    }
//    while(pa<=pa_last)
//        *pc++=*pa++;
//    while(pb<=pb_last)
//        *pc++=*pb++;
//}
//int main()
//{
//    SqList La, Lb, Lc;
//    int j;
//    InitList(La);
//    for(j=1; j<=5; j++)
//        ListInsert(La, j, j);
//    printf("La= ");
//    ListTraverse(La, print1);
//    InitList(Lb);
//    for(j=1; j<=5; j++)
//        ListInsert(Lb, j, 2*j);
//    printf("Lb= ");
//    ListTraverse(Lb, print1);
//    MergeList(La, Lb, Lc);
//    printf("Lc= ");
//    ListTraverse(Lc, print1);
//    return 0;
//}


//// main2-2.cpp 检验bo2-2.h的主程序
//#include"c1.h"
//typedef int ElemType;
//#include"c2-2.h"
//#include"bo2-2.h"
//#include"func2-2.h"
//#include"func2-3.h"

// algo2-2.cpp 用SqList类型和LinkList类型分别实现算法2.1和2.2的程序
//#include"c1.h"
//typedef int ElemType;
//#define Sq
//#ifdef Sq
//  #include"c2-1.h"
//  #include"bo2-1.h"
//  typedef SqList List;
//  #define printer print1
//#else
//  #include"c2-2.h"
//  #include"bo2-2.h"
//  typedef LinkList List;
//  #define printer print
//#endif
//#include"func2-2.h"
//#include"func2-1.h"
//int main()
//{
//    List La, Lb, Lc;
//    int j, b[7]={2, 6, 8, 9, 11, 15, 20};
//
//    InitList(La);
//    for(j=1; j<=5; j++)
//        ListInsert(La, j, j);
//    printf("La= ");
//    ListTraverse(La, printer);
//
//    InitList(Lb);
//    for(j=1; j<=5; j++)
//        ListInsert(Lb, j, 2*j);
//    printf("Lb= ");
//    ListTraverse(Lb, printer);
//
//    Union(La, Lb);
//    printf("new La= ");
//    ListTraverse(La, printer);
//
//    ClearList(Lb);
//    for(j=1; j<=7; j++)
//        ListInsert(Lb, j, b[j-1]);
//    printf("Lb= ");
//    ListTraverse(Lb, printer);
//
//    MergeList(La, Lb, Lc);
//    printf("Lc= ");            /// ??? 为什么不输出Lc
//    ListTraverse(Lc, printer);
//
//    return 0;
//}

// algo2-3.cpp 实现算法2.11和算法2.12
//#include "c1.h"
//typedef int ElemType;
//#include "c2-2.h"
//#include "bo2-2.h"
//#include "func2-2.h"
//
//void CreateList(LinkList &L, int n)
//{// 逆位序,结点插在表头,输入n个元素的值,简历带头结点的链表
//    LinkList p;
//    int i;
//    L = (LinkList)malloc(sizeof(LNode));  // 创建头结点
//    L->next = NULL;
//    printf("请输入%d个数据\n",n);
//    for(i = n; i > 0; i--)
//    {
//        p = (LinkList)malloc(sizeof(LNode));
//        scanf("%d",&p->data);
//        p->next = L->next;
//        L->next = p;
//    }
//
//}
//
//void CreateList1(LinkList &L, int n)
//{// 正位序
//    int i;
//    LinkList p, q;
//    L = (LinkList)malloc(sizeof(LNode));
//    L->next = NULL;
//    q = L;
//    printf("请输入%d个数据\n",n);
//    for(i = 1; i <= n; i++)
//    {
//        p = (LinkList)malloc(sizeof(LNode));
//        scanf("%d",&p->data);
//        q->next = p;
//        q = q->next;
//    }
//    p->next = NULL;
//}
//
//void MergeList(LinkList &La, LinkList &Lb, LinkList &Lc)
//{// La与Lb按非递减合并
//    LinkList pa = La->next, pb = Lb->next, pc;
//    Lc = pc = La;
//    while(pa && pb)
//        if(pa->data <= pb->data)
//        {
//            pc->next = pa;
//            pc = pa;
//            pa = pa->next;
//        }
//        else
//        {
//            pc->next = pb;
//            pc = pb;
//            pb = pb->next;
//        }
//    pc->next = pa ? pa : pb;
//    free(Lb);
//    Lb = NULL;
//}
//
//int main()
//{
//    int n = 5;
//    LinkList La, Lb, Lc;
//
//    CreateList1(La, n);
//    printf("La = ");
//    ListTraverse(La, print);
//
//    CreateList(Lb, n);
//    printf("Lb = ");
//    ListTraverse(Lb, print);
//
//    MergeList(La, Lb, Lc);
//    printf("Lc = ");
//    ListTraverse(Lc, print);
//
//    return 0;
//}

// main2-3.cpp 检验bo2-3.h 和bo2-4.h
//#include"c1.h"
//typedef int ElemType;
//#include"c2-2.h"
//#include"bo2-3.h"
//#include"bo2-4.h"
//#include"func2-2.h"
//#include"func2-3.h"

// algo2-4.cpp 静态链表示例
//#include "c1.h"
//#define N 6
//typedef char ElemType[N];
//#include "c2-3.h"
//
//int main()
//{
//    SLinkList s = {{"",1}, {"ZHAO",2}, {"QIAN",3}, {"SUN",4}, {"LI",5}, {"ZHOU",6}, {"WU",7}, {"ZHEN",8}, {"WANG", 0} };
//    int i = s[0].cur;
//    while(i)
//    {
//        printf("%s ",s[i].data);
//        i = s[i].cur;
//    }
//    printf("\n");
//    s[4].cur = 9;
//    s[9].cur = 5;
//    strcpy(s[9].data, "SHI");
//    s[6].cur = 8;
//    i = s[0].cur;
//    while(i)
//    {
//        printf("%s ",s[i].data);
//        i = s[i].cur;
//    }
//    printf("\n");
//    return 0;
//}

// main2-4.cpp 检验bo2-5.h
//#include"c1.h"
//typedef int ElemType;
//#include"c2-3.h"
//#include"bo2-5.h"
//#include"func2-2.h"
//typedef SLinkList LinkList;
//#define SLL
//#include"func2-3.h"


// main2-5.cpp 检验bo2-6.h
//#include"c1.h"
//typedef int ElemType;
//#include"c2-2.h"
//#include"bo2-6.h"
//#include"func2-2.h"
//#include"func2-3.h"

// main2-6.cpp 检验bo2-7.h的主程序
#include"c1.h"
typedef int ElemType;
#include"c2-4.h"
#include"bo2-7.h"
#include"func2-2.h"
int main()
{
    DuLinkList L;
    int i, n=4;
    Status j;
    ElemType e;
    InitList(L);
    for(i=1; i<=5; i++)
        ListInsert(L, i, i);
    printf("逆序输出链表：");
    ListTraverseBack(L, print);
    j=GetElem(L, 2, e);
    if(j)
        printf("链表的第2个元素值为%d\n", e);
    else
        printf("不存在第2个元素\n");
    i=LocateElem(L, n, equal1);
    if(i)
        printf("等于%d的元素是第%d个\n", n, i);
    else
        printf("没有等于%d的元素\n", n);
    j=PriorElem(L, n, e);
    if(j)
        printf("%d的前驱是%d，", n, e);
    else
        printf("不存在%d的前驱\n", n);
    j=NextElem(L, n, e);
    if(j)
        printf("%d的后继是%d\n", n, e);
    else
        printf("不存在%d的后继\n", n);
    ListDelete(L, 2, e);
    printf("删除第2个结点，值为%d，其余结点为 ", e);
    ListTraverse(L, print);
    printf("链表的元素个数为%d，", ListLength(L));
    printf("链表是否空？%d（1：是 0：否）\n", ListEmpty(L));
    ClearList(L);
    printf("清空后，链表是否空？%d（1：是 0：否）\n", ListEmpty(L));
    DestroyList(L);
    return 0;
}


