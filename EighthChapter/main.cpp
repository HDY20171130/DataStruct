//// algo8-1.cpp 无序顺序表部分程序
//#include "c1.h"
//#include "func8-1.h"
//#include "c8-1.h"
//#include "c8-2.h"
//#include "bo8-1.h"
//int main()
//{
//    SSTable st;
//    int i;
//    long s;
//    char filename[13] = "f8-1.txt";
//    Create_SeqFromFile(st, filename);
//    for(i = 1; i <= st.length; i++)
//        st.elem[i].total = st.elem[i].politics + st.elem[i].Chinese + st.elem[i].math + st.elem[i].English + st.elem[i].physics + st.elem[i].chemistry + st.elem[i].biology;
//    printf("准考证号 姓名     政治 语文 数学 英语 物理 化学 生物 总分\n");
//    Traverse(st, Visit);
//    printf("进行非降序排列:\n");
//    Ascend(st);
//    Traverse(st, Visit);
//    printf("请输入待查找人的考号:");
//    InputKey(s);
//    i = Search_Bin(st, s);
//    if(i)
//        Visit(st.elem[i]);
//    else
//        printf("未找到\n");
//    Destroy(st);
//    return 0;
//}

// algo8-2.cpp
//#include "c1.h"
//#include "func8-2.h"
//#include "c8-1.h"
//#include "c8-2.h"
//#include "bo8-1.h"
//int main()
//{
//    SSTable st;
//    int i;
//    KeyType s;
//    Create_OrdFromFile(st,"f8-2.txt");
//    printf("有序表为:");
//    Traverse(st, Visit);
//    printf("\n");
//    printf("请输入待查找数据的关键字:");
//    InputKey(s);
//    i = Search_Bin(st,s);
//    if(i)
//        printf("%d是第%d个数据的关键字\n",st.elem[i].key,i);
//    else
//        printf("未找到\n");
//    Destroy(st);
//    return 0;
//}

// algo8-3.app 静态查找树的操作
//#include "c1.h"
//#include "func8-3.h"
//#include "c8-1.h"
//#include "c8-2.h"
//#include "bo8-1.h"
//typedef ElemType TElemType;
//#include "c6-1.h"
//#include "bo6-1.h"
//#define N 100
//Status SecondOptimal(BiTree &T, ElemType R[], int sw[], int low, int high)
//{// 由有序表R[low~high]及其累计权值表sw(其中sw[0]==0)递归构造次优查找树T
//    int j, i = low;  // 有最小deltPi值的序号,初值设为当low==high(有序表仅为一个元素)时的值
//    double dw = sw[high] + sw[low - 1];
//    double min_ = fabs(sw[high]-sw[low]);
//    for(j = low + 1; j <= high; j++)
//        if(fabs(dw - sw[j] - sw[j-1]) < min_)
//        {
//            i = j;
//            min_ = fabs(dw - sw[j] - sw[j-1]);
//        }
//    if(!(T = (BiTree)malloc(sizeof(BiTree))))  // 生成结点失败
//        return ERROR;
//    T->data = R[i];
//    if(i == low)
//        T->lchild = NULL;
//    else
//        SecondOptimal(T->lchild, R, sw, low, i-1);
//    if(i == high)
//        T->rchild = NULL;
//    else
//        SecondOptimal(T->rchild, R, sw, i+1, high);
//    return OK;
//}
//
//void FindSW(int sw[],SSTable ST)
//{// 按照有序表ST中各数据元素的weight域求累计权值数组sw,CreateSOSTree()调用
//    int i;
//    sw[0] = 0;  // 置边界值
//    printf("\nsw = 0");
//    for(i = 1; i <= ST.length; i++)
//    {
//        sw[i] = sw[i - 1] + ST.elem[i].weight;
//        printf("%5d",sw[i]);
//    }
//}
//
//typedef BiTree SOSTree;    // 次优查找树采用二叉链表的存储结构
//void CreateSOSTree(SOSTree &T, SSTable ST)
//{
//    int sw[N + 1];
//    if(ST.length == 0)
//        T = NULL;
//    else
//    {
//        FindSW(sw, ST);
//        SecondOptimal(T, ST.elem, sw, 1, ST.length);
//    }
//}
//
//Status Search_SOSTree(SOSTree &T, KeyType key)
//{
//    while(T)
//        if(T->data.key == key)
//            return OK;
//        else if(T->data.key > key)
//            T = T->lchild;
//        else
//            T = T->rchild;
//    return FALSE;
//}
//
//int main()
//{
//    SSTable st;
//    SOSTree t;
//    Status i;
//    KeyType s;
//    Create_OrdFromFile(st, "f8-3.txt");
//    printf("        ");
//    Traverse(st, Visit);
//    CreateSOSTree(t,st);
//    printf("\n请输入待查找的字符:");
//    InputKey(s);
//    i = Search_SOSTree(t, s);
//    if(i)
//        printf("%c的权值是%d\n",s,t->data.weight);
//    else
//        printf("表中不存在此字符\n");
//    DestroyBiTree(t);
//    return 0;
//}

// algo8-4.cpp
#include "c1.h"
#include "func8-5.h"           // 包括数据元素类型的定义及其操作
#include "c8-2.h"              // 对两个数值型关键字比较的约定
typedef ElemType TElemType;    // 定义二叉树的元素类型为数据元素类型
#include "c6-1.h"              // 二叉链表的存储结构
#include "func8-4.h"
#include "bo8-2.h"             // 二叉排序树的基本操作
int main()
{
    BiTree dt, p;
    int i, n;
    KeyType j;
    ElemType r;
    Status k;
    FILE *f;
    f = fopen("f8-4.txt","r");
    fscanf(f,"%d",&n);
    InitDSTable(dt);            // 构造空二叉排序树dt
    for(i = 0; i < n; i++)      // 依次在二叉排序树dt中插入n个数据元素
    {
        InputFromFile(f,r);     // 由数据文件输入数据元素的值并赋给r
        k = InsertBST(dt, r);   // 依次将数据元素r插入二叉排序树dt中
        if(!k)                  // 插入数据元素r失败
            printf("二叉排序树dt中已存在关键字为%d的数据,故(%d,%d)无法插入到dt中。\n",r.key,r.key,r.others);
    }
    fclose(f);
    printf("中序遍历二叉排序树dt:\n");
    TraverseDSTable(dt, Visit);
    printf("先序遍历二叉排序树dt:\n");
    PreOrderTraverse(dt, Visit);
    printf("\n请输入待查找的关键字的值:");
    InputKey(j);
    p = SearchBST(dt, j);
    if(p)
    {
        printf("dt中存在关键字为%d的结点。",j);
        DeleteBST(dt,j);
        printf("删除此结点后,中序遍历二叉树dt:\n");
        TraverseDSTable(dt, Visit);
        printf("\n先序遍历二叉树dt:\n");
        PreOrderTraverse(dt,Visit);
        printf("\n");
    }
    else     // 未找到,p为空
        printf("dt中不存在关键字为%d的结点。\n",j);
    DestroyDSTable(dt);                              // 销毁二叉树
    return 0;
}
