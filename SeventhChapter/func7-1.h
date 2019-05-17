#ifndef FUNC7-1_H_INCLUDED
#define FUNC7-1_H_INCLUDED

#define MAX_NAME 9   // ���������ַ�����󳤶�+1
struct VertexType    // ��򵥵Ķ�����Ϣ����(ֻ�ж�������)
{
    char name[MAX_NAME];   // ������
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
