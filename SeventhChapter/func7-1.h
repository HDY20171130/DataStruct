#define MAX_NAME 9   // ���������ַ�����󳤶�+1
struct VertexType    // ��򵥵Ķ�����Ϣ����(ֻ�ж�������)
{
    char name[MAX_NAME];   // ������
};

void Visit(VertexType ver)
{// ���������Ϣ
    printf("%s",ver.name);
}

void Input(VertexType &ver)
{// ���붥����Ϣ
    scanf("%s",ver.name);
}

void InputFromFile(FILE *f, VertexType &ver)
{// ���ļ����붥����Ϣ
    fscanf(f,"%s",ver.name);
}
