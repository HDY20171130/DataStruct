// func6-4.h ������������������
int main()
{
    HuffmanTree HT;                   // ��������
    HuffmanCode HC;                   // ����������
    int *w, n, i;                     // w���Ȩֵ,nȨֵ����
    printf("������Ȩֵ�ĸ���(>1):");
    scanf("%d",&n);
    w = (int*)malloc(n * sizeof(int));
    printf("����������%d��Ȩֵ(����):\n",n);
    for(i = 0; i <= n-1; i++)
        scanf("%d",w+i);
    HuffmanCoding(HT,HC,w,n);         // ����w�����n��Ȩֵ�����������HT,n���������������HC
    for(i = 1; i <= n; i++)
        puts(HC[i]);                  // �����������������
    return 0;
}
