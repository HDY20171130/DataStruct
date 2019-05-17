// func6-2.h ����algo6-1.cpp ��algo6-2.cppҪ���õ���������
#define Order
int minum(HuffmanTree t,int i)
{// ���ع�������t��ǰi�����Ȩֵ��С�����ĸ��ڵ����,����select()����
    int j, m;
    unsigned int k = UINT_MAX;  // k����СȨֵ,��ֵȡ�޷����������ֵ
    for(j = 1; j <= i; j++)
    {
        if(t[j].weight < k && t[j].parent == 0)   // t[j]��ȨֵС��k,�������ĸ����
        {
            k = t[j].weight;                      // t[j]��Ȩֵ����k
            m = j;                                // ��Ÿ���m
        }
    }
    t[m].parent = 1;                              // ѡ�еĸ�����˫�׸�����ֵ,����ڶ��β��Ҹý��
    return m;                                     // ����Ȩֵ��С�ĸ�������
}

void select(HuffmanTree t, int i, int &s1, int &s2)
{// �ڹ�������t��ǰi�������ѡ������Ȩֵ��С�����ĸ��ڵ����,s1Ϊ�������(Ȩֵ)��С��
#ifdef Order // ���������Order,���������������
    int j;
#endif // Order
    s1 = minum(t,i);  // Ȩֵ��С�ĸ�������
    s2 = minum(t,i);  // Ȩֵ�ڶ�С�ĸ�������
#ifdef Order
    if(s1 > s2)       // s1����Ŵ���s2�����
    {
        j = s1;
        s1 = s2;
        s2 = j;
    }
#endif // Order
}
