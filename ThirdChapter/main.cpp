// main3-1.h 检验bo3-1.h的主程序
//#include"c1.h"
//typedef int SElemType;
//#include"c3-1.h"
//#include"bo3-1.h"
//#define ElemType SElemType
//#include"func2-2.h"
//int main()
//{
//    int j;
//    SqStack s;
//    SElemType e;
//    InitStack(s);
//    for(j=1; j<=12; j++)
//        Push(s, j);
//    printf("栈中元素依次为");
//    StackTraverse(s, print);
//    Pop(s, e);
//    printf("弹出的栈顶元素e=%d\n", e);
//    printf("栈空否？%d（1：空 0：否），", StackEmpty(s));
//    GetTop(s, e);
//    printf("栈顶元素e=%d，栈的长度为%d\n", e, StackLength(s));
//    ClearStack(s);
//    printf("清空栈后，栈空否？%d（1：空 0：否）\n", StackEmpty(s));
//    DestroyStack(s);
//    printf("销毁栈后，s.top=%u，s.base=%u，s.stacksize=%d\n", s.top, s.base, s.stacksize);
//    return 0;
//}

// algo3-1.cpp 需调用算法3.1
// 十进制转2进制、8进制或16进制
//#define N 16
//typedef int SElemType;
//#include "c1.h"
//#include "c3-1.h"   // 顺序栈
//#include "bo3-1.h"
//
//void conversion()
//{// 对于输入的任意一个非负十进制整数,打印输出与其对应的N进制数
//    SqStack s;
//    unsigned x;
//    SElemType e;
//    InitStack(s);
//    if(N == 16)
//        Push(s, 'H');
//    printf("请输入一个非负十进制整数: ");
//    scanf("%u",&x);
//    while(x)
//    {
//        Push(s, x%N);
//        x = x / N;
//    }
//    if(N == 8)
//        printf("0");
//    while(!StackEmpty(s))
//    {
//        Pop(s,e);
//        if(e <= 9)
//            printf("%d", e);
//        else
//            printf("%c", e + 55);
//    }
//    if(N == 2)
//        printf("B");
//    if(N == 16)
//        printf("H");
//    printf("\n");
//}
//
//int main()
//{
//    conversion();
//    return 0;
//}

// algo3-3.cpp 行编辑程序 实现算法3.2
//typedef char SElemType;
//#include "c1.h"
//#include "c3-1.h"
//#include "bo3-1.h"
//FILE *fp;
//void copy1(SElemType c)
//{
//    fputc(c, fp);
//}
//
//void LineEdit()
//{
//    SqStack s;
//    char ch;
//    InitStack(s);
//    printf("请输入一个文本文件,^Z结束输入:\n");
//    ch = getchar();
//    while(ch != EOF)
//    {
//        while(ch != '\n')
//        {
//            switch(ch)
//            {
//                case '#': if(!StackEmpty(s))
//                            Pop(s,ch); break;
//                case '@': ClearStack(s); break;
//                default: Push(s,ch);
//            }
//            ch = getchar();
//        }
//        StackTraverse(s,copy1);
//        fputc('\n',fp);
//        ClearStack(s);
//        if(ch != EOF)
//            ch = getchar();
//    }
//    DestroyStack(s);
//}
//int main()
//{
//    fp = fopen("ed.txt","w");
//    if(fp)
//    {
//        LineEdit();
//        fclose(fp);
//    }
//    else
//        printf("建立文件失败!\n");
//    return 0;
//}



// main3-2.cpp
//#include"c1.h"
//typedef int QElemType;
//#include"c3-2.h"
//#include"bo3-2.h"
//#define ElemType QElemType
//#include"func2-2.h"
//#include"func3-2.h"


// main3-3.cpp
//#include"c1.h"
//typedef int QElemType;
//#include"c3-2.h"
//#include"bo3-3.h"
//#include"func2-2.h"
//#include"func3-2.h"


// main3-4.cpp 循环队列 检验bo3-4.h的主程序
//#include"c1.h"
//typedef int QElemType;
//#include"c3-3.h"
//#include"bo3-4.h"
//#define ElemType QElemType
//#include"func2-2.h"
//int main()
//{
//    Status j;
//    int i=0, m;
//    QElemType d;
//    SqQueue Q;
//    InitQueue(Q);
//    printf("初始化队列后，队列空否？%u（1：空 0：否）\n", QueueEmpty(Q));
//    printf("请输入整型队列元素（不超过%d个），-1为提前结束符：", MAX_QSIZE-1);
//    do
//    {
//        scanf("%d", &d);
//        if(d==-1)
//            break;
//        i++;
//        EnQueue(Q, d);
//    }while(i<MAX_QSIZE-1);
//    printf("队列长度为%d，", QueueLength(Q));
//    printf("现在队列空否？%u（1：空 0：否）\n", QueueEmpty(Q));
//    printf("连续%d次由队头删除元素，队尾插入元素：\n", MAX_QSIZE);
//    for(m=1; m<=MAX_QSIZE; m++)
//    {
//        DeQueue(Q, d);
//        printf("删除的元素是%d，请输入待插入的元素：", d);
//        scanf("%d", &d);
//        EnQueue(Q, d);
//    }
//    m=QueueLength(Q);
//    printf("现在队列中的元素为");
//    QueueTraverse(Q, print);
//    printf("共向队尾插入了%d个元素。", i+MAX_QSIZE);
//    if(m-2>0)
//        printf("现在由队头删除%d个元素，", m-2);
//    while(QueueLength(Q)>2)
//    {
//        DeQueue(Q, d);
//        printf("删除的元素值为%d，", d);
//    }
//    j=GetHead(Q, d);
//    if(j)
//        printf("现在队头元素为%d\n", d);
//    ClearQueue(Q);
//    printf("清空队列后，队列空否？%u（1：空 0：否）\n", QueueEmpty(Q));
//    DestroyQueue(Q);
//    return 0;
//}

// algo3-5.cpp 表达式求值（输入的值在0～9之间，中间结果和输出的值在-128～127之间），
// 算法3.4
//typedef char SElemType;
//#include"c1.h"
//#include"c3-1.h"
//#include"bo3-1.h"
//#include"func3-1.h"
//SElemType EvaluateExpression()
//{
//    SqStack OPTR, OPND;
//    SElemType a, b, c, x;
//    InitStack(OPTR);
//    InitStack(OPND);
//    Push(OPTR, '\n');
//    c=getchar();
//    GetTop(OPTR, x);
//    while(c!='\n' || x!='\n')
//    {
//        if(In(c))
//        switch(Precede(x, c))
//        {
//            case'<': Push(OPTR, c);
//                 c=getchar();
//                 break;
//            case'=': Pop(OPTR, x);
//                 c=getchar();
//                 break;
//            case'>': Pop(OPTR,x);
//                 Pop(OPND, b);
//                 Pop(OPND, a);
//                 Push(OPND, Operate(a, x, b));
//        }
//        else if(c>='0' && c<='9')
//        {
//            Push(OPND, c-48);
//            c=getchar();
//        }
//        else
//        {
//            printf("出现非法字符\n");
//            exit(OVERFLOW);
//        }
//        GetTop(OPTR, x);
//    }
//    Pop(OPND, x);
//    if(!StackEmpty(OPND))
//    {
//        printf("表达式不正确\n");
//        exit(OVERFLOW);
//    }
//    return x;
//}
//int main()
//{
//    printf("请输入算术表达式（输入的值要在0～9之间、");
//    printf("中间运算值和输出结果在-128～127之间）\n");
//    printf("%d\n", EvaluateExpression());
//    return 0;
//}

// algo3-6.cpp 表达式求值（范围为int类型，输入负数要用（0-正数）表示）
//typedef int SElemType;
//#include"c1.h"
//#include"c3-1.h"
//#include"bo3-1.h"
//#include"func3-1.h"
//SElemType EvaluateExpression()
//{
//    SqStack OPTR, OPND;
//    SElemType a, b, d, x;
//    char c;
//    c=getchar();
//    InitStack(OPTR);
//    InitStack(OPND);
//    Push(OPTR, '\n');
//    GetTop(OPTR, x);
//    while(c!='\n' || x!='\n')
//    {
//        if(In(c))
//          switch(Precede(x, c))
//          {
//            case'<': Push(OPTR, c);
//                     c=getchar();
//                     break;
//            case'=': Pop(OPTR, x);
//                     c=getchar();
//                     break;
//            case'>': Pop(OPTR, x);
//                     Pop(OPND, b);
//                     Pop(OPND, a);
//                     Push(OPND, Operate(a, x, b));
//          }
//        else if(c>='0' && c<='9')
//        {
//            d=0;
//            while(c>='0' && c<='9')
//            {
//                d=d*10+c-'0';
//                c=getchar();
//            }
//            Push(OPND, d);
//        }
//        else
//        {
//            printf("出现非法字符\n");
//            DestroyStack(OPTR);
//            DestroyStack(OPND);
//            exit(OVERFLOW);
//        }
//        GetTop(OPTR, x);
//    }
//    Pop(OPND, x);
//    if(!StackEmpty(OPND))
//    {
//        printf("表达式不正确\n");
//        DestroyStack(OPTR);
//        DestroyStack(OPND);
//        exit(OVERFLOW);
//    }
//    DestroyStack(OPTR);
//    DestroyStack(OPND);
//    return x;
//}
//int main()
//{
//    printf("请输入算术表达式，负数要用（0-正数）表示\n");
//    printf("%d\n", EvaluateExpression());
//    return 0;
//}


// algo3-7.cpp 用递归调用求Ackerman(m, n)的值
//#include"c1.h"
//int ack(int m, int n)
//{
//    int z;
//    if(m==0)
//        z=n+1;
//    else if(n==0)
//        z=ack(m-1, 1);
//    else
//        z=ack(m-1, ack(m, n-1));
//    return z;
//}
//int main()
//{
//    int m, n;
//    printf("请输入m,n：");
//    scanf("%d,%d", &m, &n);
//    printf("Ack(%d, %d)=%d\n", m, n, ack(m, n));
//    return 0;
//}
