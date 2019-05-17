//// main6-1.cpp 检验二叉链表基本操作的主程序
//#define CHAR 1
////#define CHAR 0 // 整型（二者选一）。第3行
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
//    printf("构造空二叉树后，树空否？%d（1：是 0：否）。树的深度=%d。\n",
//    BiTreeEmpty(T), BiTreeDepth(T));
//    e1=Root(T);
//    if(e1!=Nil)
//        printf("二叉树的根为"form"。\n", e1);
//    else
//        printf("树空，无根。\n");
//    #if CHAR
//        printf("请按先序输入二叉树（如：ab###表示a为根结点，b为左子树的二叉树）：\n");
//    #else
//        printf("请按先序输入二叉树（如：1 2 0 0 0表示1为根结点，2为左子树的二叉树）：\n");
//    #endif
//    CreateBiTree(T);
//    printf("建立二叉树后，树空否？%d（1：是 0：否）。树的深度=%d。\n", BiTreeEmpty(T),
//    BiTreeDepth(T));
//    e1=Root(T);
//    if(e1!=Nil)
//        printf("二叉树的根为"form"。\n", e1);
//    else
//        printf("树空，无根。\n");
//    printf("中序递归遍历二叉树：\n");
//    InOrderTraverse(T, Visit);
//    printf("\n后序递归遍历二叉树：\n");
//    PostOrderTraverse(T, Visit);
//    printf("\n请输入一个结点的值：");
//    scanf("%*c"form, &e1);
//    p=Point(T, e1);
//    printf("结点的值为"form"。\n", Value(p));
//    printf("欲改变此结点的值，请输入新值：");
//    scanf("%*c"form"%*c", &e2);
//    Assign(p, e2);
//    printf("层序遍历二叉树：\n");
//    LevelOrderTraverse(T, Visit);
//    e1=Parent(T, e2);
//    if(e1!=Nil)
//        printf(form"的双亲是"form"，", e2, e1);
//    else
//        printf(form"没有双亲，", e2);
//    e1=LeftChild(T, e2);
//    if(e1!=Nil)
//        printf("左孩子是"form"，", e1);
//    else
//        printf("没有左孩子，");
//    e1=RightChild(T, e2);
//    if(e1!=Nil)
//        printf("右孩子是"form"，", e1);
//    else
//        printf("没有右孩子，");
//    e1=LeftSibling(T, e2);
//    if(e1!=Nil)
//        printf("左兄弟是"form"，", e1);
//    else
//        printf("没有左兄弟，");
//    e1=RightSibling(T, e2);
//    if(e1!=Nil)
//        printf("右兄弟是"form"。\n", e1);
//    else
//        printf("没有右兄弟。\n");
//    InitBiTree(c);
//    printf("请构造一个右子树为空的二叉树c：\n");
//    #if CHAR
//        printf("请按先序输入二叉树（如：ab###表示a为根结点，b为左子树的二叉树）：\n");
//    #else
//        printf("请按先序输入二叉树（如：1 2 0 0 0表示1为根结点，2为左子树的二叉树）：\n");
//    #endif
//    CreateBiTree(c);
//    printf("中序递归遍历二叉树c：\n");
//    InOrderTraverse(c, Visit);
//    printf("\n树c插到树T中，请输入树T中树c的双亲结点 c为左（0）或右（1）子树：");
//    scanf("%*c"form"%d", &e1, &i);
//    p=Point(T, e1);
//    InsertChild(p, i, c);
//
//    printf("先序递归遍历二叉树：\n");
//    PreOrderTraverse(T, Visit);
//    printf("\n删除子树，请输入待删除子树的双亲结点 左（0）或右（1）子树：");
//    scanf("%*c"form"%d", &e1, &i);
//    p=Point(T, e1);
//    DeleteChild(p, i);
//    printf("先序递归遍历二叉树：\n");
//    PreOrderTraverse(T, Visit);
//    printf("\n中序非递归遍历二叉树：\n");
//    InOrderTraverse1(T, Visit);
//    printf("中序非递归遍历二叉树（另一种方法）：\n");
//    InOrderTraverse2(T, Visit);
//    DestroyBiTree(T);
//    return 0;
//}


// main6-2.cpp 检验bo6-3.h和bo6-4.h的程序
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
//    printf("构造空树后，树空否？%d（1：是 0：否）。树根为%c，树的深度为%d。\n",TreeEmpty(T), Root(T), TreeDepth(T));
//    CreateTree(T);
//    printf("构造树T后，树空否？%d（1：是 0：否）。树根为%c，树的深度为%d。\n",TreeEmpty(T), Root(T), TreeDepth(T));
//    printf("层序遍历树T：\n");
//    LevelOrderTraverse(T, Visit);
//    printf("请输入待修改的结点的值 新值：");
//    scanf("%c%*c%c%*c", &e, &e1);
//    Assign(T, e, e1);
//    printf("层序遍历修改后的树T：\n");
//    LevelOrderTraverse(T, Visit);
//    printf("%c的双亲是%c，长子是%c，下一个兄弟是%c。\n", e1, Parent(T, e1),
//    LeftChild(T, e1), RightSibling(T, e1));
//    printf("建立树p：\n");
//    CreateTree(p);
//    printf("层序遍历树p：\n");
//    LevelOrderTraverse(p, Visit);
//    printf("将树p插到树T中，请输入T中p的双亲结点 子树序号：");
//    scanf("%c%d%*c", &e, &i);
//    q=Point(T, e);
//    InsertChild(T, q, i, p);
//    printf("层序遍历修改后的树T：\n");
//    LevelOrderTraverse(T, Visit);
//    printf("先根遍历树T：\n");
//    PreOrderTraverse(T, Visit);
//    printf("\n后根遍历树T：\n");
//    PostOrderTraverse(T, Visit);
//    printf("\n删除树T中结点e的第i棵子树，请输入e i：");
//    scanf("%c%d", &e, &i);
//    q=Point(T, e);
//    DeleteChild(T, q, i);
//    printf("层序遍历修改后的树T：\n");
//    LevelOrderTraverse(T, Visit);
//    DestroyTree(T);
//    return 0;
//}

// algo6-1.cpp 求哈夫曼编码
//#include "c1.h"
//#include "c6-3.h"
//#include "func6-2.h"
//void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n)
//{// w存放n个字符的权值(均>0)构造哈夫曼树HT并求出n个字符的哈夫曼编码HC
//    int start;
//    unsigned f;
//#include "func6-3.h"
//    HC = (HuffmanCode)malloc((n+1) * sizeof(char*));    // 分配n个字符编码的头指针向量([0]不用)
//    cd = (char*)malloc(n * sizeof(char));               // 分配求编码的工作空间
//    cd[n-1] = '\0';                                     // 编码结束符
//    for(i= 1; i <= n; i++)
//    {// 逐个求哈夫曼编码
//        start = n-1;       // 编码结束符位置
//        for(c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)
//        {
//            if(HT[f].lchild == c)       // c是其双亲左孩子
//                cd[--start] = '0';      // 由叶子结点向根赋值'0'
//            else                        // c是其双亲右孩子
//                cd[--start] = '1';      // 由叶子结点向根赋值'1'
//        }
//        HC[i] = (char*)malloc((n-start) * sizeof(char));
//        strcpy(HC[i], &cd[start]);
//    }
//    free(cd);
//}
//#include "func6-4.h"  // 求哈夫曼编码主函数

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
    cdlen = 0;                // 码长初值为0
    for(i = 1; i <= m; i++)
    {
        HT[i].weight = 0;     // 求编码不需要权值域,改作结点状态标志,0表示左右孩子都没有访问过
    }
    while(c)
    {
        if(HT[c].weight == 0)
        {
            HT[c].weight = 1;        // 左孩子被访问过,右孩子未访问
            if(HT[c].lchild != 0)    // 有左孩子(不是叶子结点)
            {
                c = HT[c].lchild;    // 将c置为其左孩子的序号(向叶子结点方向走一步)
                cd[cdlen++] = '0';   // 左分支编码为0
            }
            else if(HT[c].rchild == 0)    // 序号为c的叶子结点
            {// 登记叶子结点的字符编码
                HC[c] = (char*)malloc((cdlen+1) * sizeof(char));    // 生成编码空间
                cd[cdlen] = '\0';                                   // 最后一个位置赋值串尾结束符
                strcpy(HC[c],cd);                                   // 复制编码
            }
        }
        else if(HT[c].weight == 1)   // 左孩子被访问过
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
