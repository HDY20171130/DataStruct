// func6-3.h  �����������
int m, i, s1, s2;
unsigned c;
HuffmanTree p;
char *cd;
if(n <= 1)  // Ҷ�ӽ����������1
    return;
m = 2*n-1;  // n��Ҷ�ӽ��Ĺ�����������m�����
HT = (HuffmanTree)malloc((m+1)*sizeof(HTNode));         // 0�ŵ�Ԫδ��
for(p = HT+1,i = 1; i <= n; i++, p++, w++)              // ��1�ŵ�Ԫ��ʼ��n�ŵ�Ԫ,��Ҷ�ӽ�㸳ֵ
{// ��Ҷ�ӽ�㸳ֵ
    (*p).weight = *w;       // ��Ȩֵ
    (*p).parent = 0;        // ˫����Ϊ��(Ҷ�ӽ��ĸ����)
    (*p).lchild = 0;        // ���Һ���Ϊ��(Ҷ�ӽ��)
    (*p).rchild = 0;
}
for(; i <= m; i++, p++)     // i��n+1��m
{
    (*p).parent = 0;        // �������˫�����ֵΪ0
}
for(i = n+1; i <= m; i++)   // ����������
{
    select(HT,i-1,s1,s2);
    HT[s1].parent = HT[s2].parent = i;                // i�ŵ�ԪΪs1��s2��˫��
    HT[i].lchild = s1;                                // i�ŵ�Ԫ�����Һ��ӷֱ�Ϊs1��s2
    HT[i].rchild = s2;
    HT[i].weight = HT[s1].weight + HT[s2].weight;     // i�ŵ�Ԫ��Ȩֵ��s1��s2Ȩֵ��
}
