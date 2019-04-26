// c5-2.h 稀疏矩阵的三元组顺序表存储结构
#define MAX_SIZE 100
struct Triple
{
    int i,j;     // 行, 列下标
    ElemType e;  // 非零元素值
};
struct TSMatrix
{
    Triple data[MAX_SIZE + 1]; // 非零元三元组表,data[0]未使用
    int mu, nu, tu;            // 行数,列数,非零元个数
};
