int main()
{
    int i, j, k, n;
    char s[3] = "��";
    Graph g;
    VertexType v1, v2;
    printf("������ѡ������ͼ,������,����ͼ,������:\n");
    for(i = 0; i < 4; i++)        // ��֤4�����
    {
        CreateGraph(g);           // ����ͼg
        Display(g);
        printf("�����¶���,�������¶����ֵ:");
        Input(v1);
        InsertVex(g, v1);
        if(g.kind < 2)            // ����
            strcpy(s,"��");
        printf("�������¶����йص�%s,�����%s��:",s,s);
        scanf("%d",&n);
        for(k = 0; k < n; k++)
        {
            printf("��������һ���������:");
            scanf("%s",v2.name);
            if(g.kind < 2)        // ����
            {
                printf("��������һ����ķ���(0:��ͷ 1:��β):");
                scanf("%d",&j);
                if(j) // v2Ϊ��β
                    InsertArc(g, v2, v1);
                else  // v2Ϊ��ͷ
                    InsertArc(g, v1, v2);
            }
            else                 // ����
                InsertArc(g, v1, v2);
        }
        Display(g);
        printf("ɾ�����㼰��ص�%s,�������ɾ��������:",s);
        scanf("%s",&v1.name);
        DeleteVex(g, v1);
        Display(g);
        if(i == 3)
        {
            printf("�޸Ķ����ֵ,��������޸Ķ�������� ��ֵ:");
            scanf("%s",v1.name);    // ������޸Ķ�������
            Input(v2);              // ���붥����ֵ
            PutVex(g, v1, v2);      // ��ͼg�ж���v1��ֵ��Ϊv2
            if(g.kind < 2)          // ����
                printf("ɾ��һ��%s,�������ɾ��%s�Ļ�β ��ͷ:",s,s);
            else                    // ����
                printf("ɾ��һ��%s,�������ɾ��%s�Ķ���1 ����2:",s,s);
            scanf("%s%s",v1.name, v2.name);     // �����ɾ������������������
            DeleteArc(g,v1,v2);
            Display(g);
        }
        DestroyGraph(g);
    }
    return 0;
}
