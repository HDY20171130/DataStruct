// main1-1.cpp 检验基本操作bo1-1.h的主函数
#include"c1.h"
// 以下两行可根据需要选其一（且只能选其一），而无须改变基本操作bo1-1.h
typedef int ElemType;
//typedef double ElemType; // 定义抽象数据类型ElemType在本程序中为双精度型。第5行
#include"c1-1.h"
#include"bo1-1.h"
#include"func1-1.h"
int main()
{
    Triplet T;
    ElemType m;
    Status i;
    i=InitTriplet(T, 5, 7, 9);
    //i=InitTriplet(T, 5.0, 7.1, 9.3); // 当ElemType为双精度型时，可取代上句。第15行
    printf("调用初始化函数后，i=%d（1：成功）。T的3个值为",i);
    PrintT(T);
    i=Get(T, 2, m);
    if(i==OK)
    {
        printf("T的第2个值为");
        PrintE(m);
    }
    i=Put(T, 2, 6);
    if(i==OK)
    {
        printf("将T的第2个值改为6后，T的3个值为");
        PrintT(T);
    }
    i=IsAscending(T);
    printf("调用测试升序的函数后，i=%d（0：否 1：是）\n", i);
    i=IsDescending(T);
    printf("调用测试降序的函数后，i=%d（0：否 1：是）\n", i);
    if((i=Max(T, m))==OK)
    {
        printf("T中的最大值为");
        PrintE(m);
    }
    if((i=Min(T, m))==OK)
    {
        printf("T中的最小值为");
        PrintE(m);
    }
    DestroyTriplet(T);
    printf("销毁T后，T=%u\n", T);

    return 0;
}


//// algo1-1.cpp 变量的引用类型和非引用类型的区别
//#include"c1.h"
//void fa(int a)
//{
//    a++;
//    printf("在函数fa中：a=%d\n", a);
//}
//void fb(int &a)
//{
//    a++;
//    printf("在函数fb中：a=%d\n", a);
//}
//int main()
//{
//    int n=1;
//    printf("在主程中，调用函数fa之前：n=%d\n", n);
//    fa(n);
//    printf("在主程中，调用函数fa之后，调用函数fb之前：n=%d\n", n);
//    fb(n);
//    printf("在主程中，调用函数fb之后：n=%d\n", n);
//    return 0;
//}

//// algo1-2.cpp 计算1-1/x+1/(x*x)…
//#include"c1.h"
//int main()
//{
//    timeb t1, t2;
//    long t;
//    double x, sum=1, sum1;
//    int i, j, n;
//    printf("请输入x n：");
//    scanf("%lf%d", &x, &n);
//    ftime(&t1);
//    for(i=1; i<=n; i++)
//    {
//        sum1=1;
//        for(j=1; j<=i; j++)
//            sum1=sum1*(-1.0/x);
//        sum+=sum1;
//    }
//    ftime(&t2);
//    t=(t2.time-t1.time)*1000+(t2.millitm-t1.millitm);
//    printf("sum=%lf，用时%ld毫秒\n", sum, t);
//
//    return 0;
//}

//// algo1-3.cpp 计算1-1/x+1/(x*x)…的更快捷的算法
//#include"c1.h"
//int main()
//{
//    timeb t1, t2;
//    long t;
//    double x, sum1=1, sum=1;
//    int i, n;
//    printf("请输入x n：");
//    scanf("%lf%d", &x, &n);
//    ftime(&t1);
//    for(i=1; i<=n; i++)
//    {
//        sum1*=-1.0/x;
//        sum+=sum1;
//    }
//    ftime(&t2);
//    t=(t2.time-t1.time)*1000+(t2.millitm-t1.millitm);
//    printf("sum=%lf，用时%ld毫秒\n", sum, t);
//    return 0;
//}




