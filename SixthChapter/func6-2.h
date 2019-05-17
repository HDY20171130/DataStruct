// func6-2.h 程序algo6-1.cpp 和algo6-2.cpp要调用的两个函数
#define Order
int minum(HuffmanTree t,int i)
{// 返回哈夫曼树t的前i个结点权值最小的树的根节点序号,函数select()调用
    int j, m;
    unsigned int k = UINT_MAX;  // k存最小权值,初值取无符号整型最大值
    for(j = 1; j <= i; j++)
    {
        if(t[j].weight < k && t[j].parent == 0)   // t[j]的权值小于k,又是树的根结点
        {
            k = t[j].weight;                      // t[j]的权值赋给k
            m = j;                                // 序号赋给m
        }
    }
    t[m].parent = 1;                              // 选中的根结点的双亲赋非零值,避免第二次查找该结点
    return m;                                     // 返回权值最小的根结点序号
}

void select(HuffmanTree t, int i, int &s1, int &s2)
{// 在哈夫曼树t的前i个结点中选择两个权值最小的树的根节点序号,s1为其中序号(权值)较小的
#ifdef Order // 如果定义了Order,则以下语句起作用
    int j;
#endif // Order
    s1 = minum(t,i);  // 权值最小的根结点序号
    s2 = minum(t,i);  // 权值第二小的根结点序号
#ifdef Order
    if(s1 > s2)       // s1的序号大于s2的序号
    {
        j = s1;
        s1 = s2;
        s2 = j;
    }
#endif // Order
}
