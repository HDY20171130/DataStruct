// func8-2.h ��������Ԫ�����Ͷ��弰�����Ĳ���
typedef int KeyType;     // �ؼ�������Ϊint
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
