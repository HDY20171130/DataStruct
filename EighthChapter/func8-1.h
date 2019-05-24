// func8-1.h ��������Ԫ�ص����Ͷ���Ͷ����Ĳ���
typedef long KeyType;      // ����ؼ�����Ϊ������
#define key number         // ����ؼ���Ϊ׼��֤��
struct ElemType
{
    long number;           // ׼��֤��,��ؼ���������ͬ
    char name[9];          // ����(4�����ּ�һ����������Ƿ�)
    int politics;          // ����
    int Chinese;           // ����
    int English;           // Ӣ��
    int math;              // ��ѧ
    int physics;           // ����
    int chemistry;         // ��ѧ
    int biology;           // ����
    int total;             // �ܷ�
};

void Visit(ElemType c)
{
    printf("%-8ld%-8s%5d%5d%5d%5d%5d%5d%5d%5d\n",c.number,c.name,c.politics,c.Chinese,c.English,c.math,c.physics,c.chemistry,c.biology,c.total);
}

void InputFromFile(FILE *f, ElemType &c)
{// ���ļ���������Ԫ��
    fscanf(f,"%ld%s%d%d%d%d%d%d%d",&c.number,c.name,&c.politics,&c.Chinese,&c.English,&c.math,&c.physics,&c.chemistry,&c.biology,&c.total);
}

void InputKey(KeyType &k)
{
    scanf("%ld",&k);
}

