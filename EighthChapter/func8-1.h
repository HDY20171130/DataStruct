// func8-1.h 包括数据元素的类型定义和对它的操作
typedef long KeyType;      // 定义关键字域为长整型
#define key number         // 定义关键字为准考证号
struct ElemType
{
    long number;           // 准考证号,与关键字类型相同
    char name[9];          // 姓名(4个汉字加一个串结束标记符)
    int politics;          // 政治
    int Chinese;           // 语文
    int English;           // 英语
    int math;              // 数学
    int physics;           // 物理
    int chemistry;         // 化学
    int biology;           // 生物
    int total;             // 总分
};

void Visit(ElemType c)
{
    printf("%-8ld%-8s%5d%5d%5d%5d%5d%5d%5d%5d\n",c.number,c.name,c.politics,c.Chinese,c.English,c.math,c.physics,c.chemistry,c.biology,c.total);
}

void InputFromFile(FILE *f, ElemType &c)
{// 从文件输入数据元素
    fscanf(f,"%ld%s%d%d%d%d%d%d%d",&c.number,c.name,&c.politics,&c.Chinese,&c.English,&c.math,&c.physics,&c.chemistry,&c.biology,&c.total);
}

void InputKey(KeyType &k)
{
    scanf("%ld",&k);
}

