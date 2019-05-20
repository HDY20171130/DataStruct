#define MAX_NAME 9   // 顶点名称字符串最大长度+1
struct VertexType    // 最简单的顶点信息类型(只有顶点名称)
{
    char name[MAX_NAME];   // 顶点名
};

void Visit(VertexType ver)
{// 输出顶点信息
    printf("%s",ver.name);
}

void Input(VertexType &ver)
{// 输入顶点信息
    scanf("%s",ver.name);
}

void InputFromFile(FILE *f, VertexType &ver)
{// 从文件输入顶点信息
    fscanf(f,"%s",ver.name);
}
