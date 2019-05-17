// c6-3.h 哈夫曼树和哈夫曼编码的存储结构
typedef struct
{
    unsigned int weight;                    // 结点权值
    unsigned int parent, lchild, rchild;
}HTNode, *HuffmanTree;                      // 动态分配数组存储哈弗曼树
typedef char* *HuffmanCode;                // 动态分配数组存储哈夫曼编码表

