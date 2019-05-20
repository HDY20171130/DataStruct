// bo7-1.h ͼ���ڽӾ���洢�Ļ�������(17��)
int LocateVex(MGraph G, VertexType u)
{// ��λͼG�ж���u��λ��,���޷���-1
    int i;
    for(i = 0; i < G.vexnum; i++)               // ���β���
    {
        if(strcmp(u.name, G.vexs[i].name) == 0)
            return i;                           // ���ض������
    }
    return -1;
}

void CreateDG(MGraph &G)
{// ��������(�ڽӾ���)��ʾ��,��������ͼG
    int i, j, k, IncInfo;    // IncInfo��Ϊ0,�򻡲��������Ϣ
    VertexType v1, v2;       // ��������
    printf("����������ͼG�Ķ�����,����,���Ƿ������Ϣ(��:1 ��:0):");
    scanf("%d,%d,%d",&G.vexnum,&G.arcnum,&IncInfo);
    printf("������%d�������ֵ(����<%d���ַ�):\n",G.vexnum,MAX_NAME);
    for(i = 0; i < G.vexnum; i++)
    {
        Input(G.vexs[i]);        // ���붥����Ϣ,��func7-1.h��
    }
    for(i = 0; i < G.vexnum; i++)
    {// ��ʼ����ά�ڽӾ���(����Ϣ)
        for(j = 0; j < G.vexnum; j++)
        {
            G.arcs[i][j].adj = 0;     // ͼ,������
            G.arcs[i][j].info = NULL; // �������Ϣ
        }
    }
    printf("������%d�����Ļ�β ��ͷ:\n",G.arcnum);
    for(k = 0; k < G.arcnum; k++)
    {
        scanf("%s%s%*c",v1.name, v2.name);    // %*c�Ե��س���
        i = LocateVex(G, v1);                 // ��β���
        j = LocateVex(G, v2);                 // ��ͷ���
        G.arcs[i][j].adj = 1;                 // ����ͼ
        if(IncInfo)                           // �������Ϣ
            InputArc(G.arcs[i][j].info);      // ��̬���ɻ��������Ϣ
    }
    G.kind = DG;
}

void CreateDN(MGraph &G)
{// ��������(�ڽӾ���)��ʾ��,����������G
    int i, j, k, IncInfo;    // IncInfo��Ϊ0,�򻡲��������Ϣ
    VRType w;             // �����ϵ����
    VertexType v1, v2;    // ��������
    printf("������������G�Ķ�����,����,���Ƿ������Ϣ(��:1 ��:0):");
    scanf("%d,%d,%d",&G.vexnum, &G.arcnum, &IncInfo);
    printf("������%d�������ֵ(����<%d���ַ�):\n",G.vexnum, MAX_NAME);
    for(i = 0; i < G.vexnum; i++)         // ���춥������
        Input(G.vexs[i]);                 // ���ݶ�����Ϣ����,���붥����Ϣ,��func7-1.h��
    for(i = 0; i < G.vexnum; i++)         // ��ʼ����ά�ڽӾ���
        for(j = 0; j < G.vexnum; j++)
        {
            G.arcs[i][j].adj = INFINITY;   // ��,������
            G.arcs[i][j].info = NULL;      // �������Ϣ
        }
    printf("������%d�����Ļ�β ��ͷ Ȩֵ:\n",G.arcnum);
    for(k = 0; k < G.arcnum; k++)
    {
        scanf("%s,%s,%d%*c", v1.name, v2.name, &w);
        i = LocateVex(G, v1);              // ��β�����
        j = LocateVex(G, v2);              // ��ͷ�����
        G.arcs[i][j].adj = w;              // ������
        if(IncInfo)
        {
            InputArc(G.arcs[i][j].info);   // ��̬���ɴ洢�ռ�,������ػ�����Ϣ
        }
    }
    G.kind = DN;
}

void CreateUDG(MGraph &G)
{// ��������(�ڽӾ���)��ʾ��,��������ͼG
    int i, j, k, IncInfo;
    VertexType v1, v2;
    printf("����������ͼG�Ķ�����,����,���Ƿ������Ϣ(��:1 ��:0):");
    scanf("%d,%d,%d",&G.vexnum, &G.arcnum, IncInfo);
    printf("������%d�������ֵ(����<%d���ַ�):\n",G.vexnum,MAX_NAME);
    for(i = 0; i < G.vexnum; i++)
    {
        Input(G.vexs[i]);
    }
    for(i = 0; i < G.vexnum; i++)      // ��ʼ����ά�ڽӾ���
        for(j = 0; j < G.vexnum; j++)
        {
            G.arcs[i][j].adj = 0;          // ͼ,������
            G.arcs[i][j].info = NULL;      // ���������Ϣ
        }
    printf("������%d���ߵĶ���1 ����2:\n",G.arcnum);
    for(k = 0; k < G.arcnum; k++)
    {
        scanf("%s%s%*c",v1.name, v2.name);
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        G.arcs[i][j].adj = 1;     // ͼ
        if(IncInfo)                       // �������Ϣ
        {
            InputArc(G.arcs[i][j].info);
        }
        G.arcs[j][i] = G.arcs[i][j];      // ����,�Գƾ���
    }
    G.kind = UDG;
}

void CreateUDN(MGraph &G)
{// ������
    int i, j, k, IncInfo;
    VRType w;                // �����ϵ����
    VertexType v1, v2;       // ��������
    printf("������������G�Ķ�����,����,���Ƿ������Ϣ:");
    scanf("%d,%d,%d",&G.vexnum, &G.arcnum, IncInfo);
    printf("������%d�������ֵ(����<%d���ַ�):\n",G.vexnum, MAX_NAME);
    for(i = 0; i < G.vexnum; i++)
    {// ��ʼ����������
        Input(G.vexs[i]);
    }
    for(i = 0; i < G.vexnum; i++)
        for(j = 0; j <G.vexnum; j++)
        {
            G.arcs[i][j].adj = INFINITY;    // ��,������
            G.arcs[i][j].info = NULL;
        }
    printf("������%d���ߵĶ���1 ����2Ȩֵ:\n",G.arcnum);
    for(k = 0; k < G.arcnum; k++)
    {
        scanf("%s%s%d%*c",v1.name, v2.name, &w);
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        G.arcs[i][j].adj = w;     // ��
        if(IncInfo)
        {
            InputArc(G.arcs[i][j].info);
        }
        G.arcs[j][i] = G.arcs[i][j];
    }
    G.kind = UDN;
}

void CreateGraph(MGraph &G)
{// ��������(�ڽӾ���)��ʾ��,����ͼG
    printf("������ͼG������(����ͼ:0 ������:1 ����ͼ:2 ������:3)");
    scanf("%d",&G.kind);
    switch(G.kind)
    {
        case DG: CreateDG(G); break;
        case DN: CreateDN(G); break;
        case UDG: CreateUDG(G); break;
        case UDN: CreateUDN(G); break;
    }
}

VertexType GetVex(MGraph G, int v)
{// ���ض������Ϊv��ֵ
    if(v >= G.vexnum || v < 0)
        exit(OVERFLOW);
    return G.vexs[v];
}

Status PutVex(MGraph &G, VertexType v, VertexType value)
{// ��v����ֵ
    int k = LocateVex(G, v);
    if(k < 0)
        return ERROR;
    G.vexs[k] = value;
    return OK;
}

int FirstAdjVex(MGraph G, int v)
{// ����v�ĵ�һ���ڽӶ�������,�����ڽӶ���,����-1
    int i;
    VRType j = 0;       // �����ϵ����,ͼ
    if(G.kind % 2)      // ��
    {
        j = INFINITY;
    }
    for(i = 0; i < G.vexnum; i++)   // �ӵ�һ�����㿪ʼ��
        if(G.arcs[v][i].adj != j)   // �ǵ�һ���ڽӶ���
            return i;
    return -1;
}

int NextAdjVex(MGraph G, int v, int w)
{// ����v����һ���ڽӶ�������,��w��v�����һ���ڽӶ���,�򷵻�-1
    int i;
    VRType j = 0;           // �����ϵ����,ͼ
    if(G.kind % 2)          // ��
    {
        j = INFINITY;
    }
    for(i = w+1; i < G.vexnum; i++)  // �ӵ�w+1�����㿪ʼ��
        if(G.arcs[v][i].adj != j)
            return i;
    return -1;
}

void InsertVex(MGraph &G, VertexType v)
{// ��ͼG����������
    int i;
    VRType j = 0;            // �����ϵ����,ͼ
    if(G.kind % 2)          // ��
    {
        j = INFINITY;
    }
    G.vexs[G.vexnum] = v;   // ��vֵ�����¶���
    for(i = 0; i <= G.vexnum; i++)   // ��ʼ������
    {
        G.arcs[G.vexnum][i].adj = G.arcs[G.vexnum][i].adj = j;
        G.arcs[G.vexnum][i].info = G.arcs[i][G.vexnum].info = NULL;
    }
    G.vexnum++;
}

Status InsertArc(MGraph &G, VertexType v, VertexType w)
{// ��ͼG��������<v,w>��GΪ����,��������<w,v>
    int i, v1, w1;
    v1 = LocateVex(G, v);                        // ��β����v�����
    w1 = LocateVex(G, w);                        // ��ͷ����w�����
    if(v1 < 0 || w1 <0)                          // �����ڶ���v��w
        return ERROR;
    G.arcnum++;                                  // ����+1
    if(G.kind % 2)                               // ��
    {
        printf("������˻���Ȩֵ:");
        scanf("%d",G.arcs[v1][w1].adj);
    }
    else                                         // ͼ
        G.arcs[v1][w1].adj = 1;
    printf("�Ƿ��иû��������Ϣ(0:�� 1:��):");
    scanf("%d%*c",&i);
    if(i)                                        // �������Ϣ
        InputArc(G.arcs[v1][w1].info);
    if(G.kind > 1)                               // ����
        G.arcs[w1][v1] = G.arcs[v1][w1];
    return OK;
}

Status DeleteArc(MGraph &G, VertexType v, VertexType w)
{// ɾ����<v,w>,��G����,ɾ���Գƻ�<w,v>
    int v1, w1;
    VRType j = 0;         // �����ϵ����,ͼ
    if(G.kind % 2)        // ��
    {
        j = INFINITY;
    }
    v1 = LocateVex(G, v);
    w1 = LocateVex(G, w);
    if(v1 < 0 || w1 < 0)
        return ERROR;
    if(G.arcs[v1][w1].adj != j)              // �л�<v,w>
    {
        G.arcs[v1][w1].adj = j;              // ɾ����<v,w>
        if(G.arcs[v1][w1].info)               // �������Ϣ
        {
            free(G.arcs[v1][w1].info);       // �ͷſռ�
            G.arcs[v1][w1].info = NULL;      // ָ���ÿ�
        }
        if(G.kind >= 2)                      // ����
            G.arcs[w1][v1] = G.arcs[v1][w1]; // ɾ���Գƻ�<w,v>
        G.arcnum--;
    }
    return OK;
}

Status DeleteVex(MGraph &G, VertexType v)
{// ɾ������v������ػ�
    int i, j, k;
    k = LocateVex(G, v);       // kΪ��ɾ�������
    if(k < 0)
        return ERROR;
    for(i = 0; i < G.vexnum; i++)
        DeleteArc(G, v, G.vexs[i]);     // ɾ���ɶ���v���������л�
    if(G.kind < 2)                      // ����
        for(i = 0; i < G.vexnum; i++)
            DeleteArc(G, G.vexs[i], v); // ɾ�����򶥵�v�����л�
    for(j = k + 1; j < G.vexnum; j++)
        G.vexs[j-1] = G.vexs[j];        // ���k����Ķ�����������ǰ��
    for(i = 0; i < G.vexnum; i++)
        for(j = k + 1; j < G.vexnum; j++)
        {
            G.arcs[i][j - 1] = G.arcs[i][j];  // �ƶ���ɾ������֮�ҵľ���Ԫ��
        }
    for(i= 0; i< G.vexnum; i++)
        for(j = k + 1; j < G.vexnum; j++)
            G.arcs[j - 1][i] = G.arcs[j][i];  // �ƶ���ɾ������֮�µľ���Ԫ��
    G.vexnum--;
    return OK;
}

void DestroyGraph(MGraph &G)
{// ����ͼG
    int i;
    for(i = G.vexnum - 1; i >= 0; i--)     // �Ӵ�С��һɾ�����㼰����ػ�
        DeleteVex(G, G.vexs[i]);
}

void Display(MGraph G)
{// ����ڽӾ���洢�ṹ��ͼG
    int i, j;
    char s[7] = "����ͼ", s1[3] = "��";
    switch(G.kind)
    {
        case DG:strcpy(s, "����ͼ");
                strcpy(s1, "��");
                break;
        case DN:strcpy(s, "������");
                strcpy(s1, "��");
                break;
        case UDG:strcpy(s, "����ͼ");
                break;
        case UDN: ;
    }
    printf("%d������%d��%s��%s�����������ǣ�",G.vexnum, G.arcnum, s1, s);
    for(i = 0; i < G.vexnum; i++)
        Visit(GetVex(G, i));                       // ���ݶ�����Ϣ������,���ʵ�i������,��func7-1.h��
    printf("\nG.arcs.adj:\n");
    for(i = 0; i < G.vexnum; i++)                  // �����ά����G.arcs.adj
    {
        for(j = 0; j < G.vexnum; j++)
            if(G.arcs[i][j].adj == INFINITY)
                printf("��");
            else
                printf("%4d",G.arcs[i][j].adj);
            printf("\n");
    }
    printf("G.arcs.info:\n");                      // ���G.arcs.info
    if(G.kind < 2)                                 // ����
        printf("��β ��ͷ ��%s����Ϣ:\n",s1);
    else                                           // ����
        printf("����1����2��%s����Ϣ:\n",s1);
    for(i= 0; i< G.vexnum; i++)
        if(G.kind < 2)                             // ����
        {
            for(j = 0; j < G.vexnum; j++)
                if(G.arcs[i][j].info)
                {
                    printf("%5s %5s",G.vexs[i].name, G.vexs[j].name);
                    OutputArc(G.arcs[i][j].info);  // ������������Ϣ,��func7-1.h
                }
        }
        else                                       // ����,���������
        {
            for(j = i + 1; j < G.vexnum; j++)
                if(G.arcs[i][j].info)
                {
                    printf("%5s %5s",G.vexs[i].name, G.vexs[j].name);
                    OutputArc(G.arcs[i][j].info);
                }
        }
}

void CreateFromFile(MGraph &G, char* filename, int IncInfo)
{// ���ļ�����ͼ����G.IncInfo ��ʾ�����������Ϣ1:�� 0:��
    int i, j, k;
    VRType w = 0;              // �����ϵ����,ͼ
    VertexType v1, v2;         // ��������
    FILE *f;                   // �ļ�ָ��
    f = fopen(filename,"r");
    fscanf(f,"%d",&G.kind);    // ���ļ�����G������

    if(G.kind % 2)             // ��
        w = INFINITY;
    fscanf(f, "%d", &G.vexnum);         // ���ļ����붥����
    for(i = 0; i < G.vexnum; i++)
        InputFromFile(f,G.vexs[i]);     // ���ļ����붥����Ϣ,��func7-1.h��
    fscanf(f, "%d", &G.arcnum);         // ���ļ����뻡��
    for(i = 0; i < G.vexnum; i++)
        for(j = 0; j < G.vexnum; j++)
        {
            G.arcs[i][j].adj = w;       // ������
            G.arcs[i][j].info = NULL;   // �������Ϣ
        }

    if(!(G.kind % 2))                   // ͼ
        w = 1;
    for(k = 0; k < G.arcnum; k++)       // �����л�
    {
        fscanf(f,"%s%s",v1.name, v2.name);
        if(G.kind % 2)                  // ��
            fscanf(f,"%d",&w);          // Ȩֵ
        i = LocateVex(G, v1);           // ��β���
        j = LocateVex(G, v2);           // ��ͷ���
        G.arcs[i][j].adj = w;           // Ȩֵ
        if(IncInfo)                     // �������Ϣ
            InputArcFromFile(f,G.arcs[i][j].info);
        if(G.kind >1)                   // ����
            G.arcs[j][i] = G.arcs[i][j];
    }
    fclose(f);
}

