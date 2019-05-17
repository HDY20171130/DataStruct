// func6-4.h 求哈夫曼编码的主函数
int main()
{
    HuffmanTree HT;                   // 哈夫曼树
    HuffmanCode HC;                   // 哈夫曼编码
    int *w, n, i;                     // w存放权值,n权值个数
    printf("请输入权值的个数(>1):");
    scanf("%d",&n);
    w = (int*)malloc(n * sizeof(int));
    printf("请依次输入%d个权值(整型):\n",n);
    for(i = 0; i <= n-1; i++)
        scanf("%d",w+i);
    HuffmanCoding(HT,HC,w,n);         // 根据w所存的n个权值构造哈夫曼树HT,n个哈夫曼编码存于HC
    for(i = 1; i <= n; i++)
        puts(HC[i]);                  // 依次输出哈夫曼编码
    return 0;
}
