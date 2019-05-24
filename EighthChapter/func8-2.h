// func8-2.h 包括数据元素类型定义及对它的操作
typedef int KeyType;     // 关键字类型为int
struct ElemType
{
    KeyType key;
};

void Visit(ElemType c)
{
    printf("%d ",c.key);
}

void InputFromFile(FILE *f, ElemType &c)
{
    fscanf(f,"%d",&c.key);;
}

void InputKey(KeyType &k)
{
    scanf("%d",&k);
}
