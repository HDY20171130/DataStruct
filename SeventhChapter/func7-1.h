#ifndef FUNC7-1_H_INCLUDED
#define FUNC7-1_H_INCLUDED

#define MAX_NAME 9   // 顶点名称字符串最大长度+1
struct VertexType    // 最简单的顶点信息类型(只有顶点名称)
{
    char name[MAX_NAME];   // 顶点名
};

void Visit(VertexType ver)
{
    printf("%s",ver.name);
}

void Input(VertexType &ver)
{
    printf("%s",ver.name);
}

void InputFromFile(FILE *f, VertexType &ver)
{
    fscanf(f,"%s",ver.name);
}


#endif // FUNC7-1_H_INCLUDED
