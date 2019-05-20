// bo7-1.h 图的邻接矩阵存储的基本操作(17个)
int LocateVex(MGraph G, VertexType u)
{// 定位图G中顶点u的位置,若无返回-1
    int i;
    for(i = 0; i < G.vexnum; i++)               // 依次查找
    {
        if(strcmp(u.name, G.vexs[i].name) == 0)
            return i;                           // 返回顶点序号
    }
    return -1;
}

void CreateDG(MGraph &G)
{// 采用数组(邻接矩阵)表示法,构造有向图G
    int i, j, k, IncInfo;    // IncInfo若为0,则弧不含相关信息
    VertexType v1, v2;       // 顶点类型
    printf("请输入有向图G的顶点数,弧数,弧是否含相关信息(是:1 否:0):");
    scanf("%d,%d,%d",&G.vexnum,&G.arcnum,&IncInfo);
    printf("请输入%d个顶点的值(名称<%d个字符):\n",G.vexnum,MAX_NAME);
    for(i = 0; i < G.vexnum; i++)
    {
        Input(G.vexs[i]);        // 输入顶点信息,在func7-1.h中
    }
    for(i = 0; i < G.vexnum; i++)
    {// 初始化二维邻接矩阵(弧信息)
        for(j = 0; j < G.vexnum; j++)
        {
            G.arcs[i][j].adj = 0;     // 图,不相邻
            G.arcs[i][j].info = NULL; // 无相关信息
        }
    }
    printf("请输入%d条弧的弧尾 弧头:\n",G.arcnum);
    for(k = 0; k < G.arcnum; k++)
    {
        scanf("%s%s%*c",v1.name, v2.name);    // %*c吃掉回车符
        i = LocateVex(G, v1);                 // 弧尾序号
        j = LocateVex(G, v2);                 // 弧头序号
        G.arcs[i][j].adj = 1;                 // 有向图
        if(IncInfo)                           // 有相关信息
            InputArc(G.arcs[i][j].info);      // 动态生成弧的相关信息
    }
    G.kind = DG;
}

void CreateDN(MGraph &G)
{// 采用数组(邻接矩阵)表示法,构造有向网G
    int i, j, k, IncInfo;    // IncInfo若为0,则弧不含相关信息
    VRType w;             // 顶点关系类型
    VertexType v1, v2;    // 顶点类型
    printf("请输入有向网G的顶点数,弧数,弧是否含相关信息(是:1 否:0):");
    scanf("%d,%d,%d",&G.vexnum, &G.arcnum, &IncInfo);
    printf("请输入%d个顶点的值(名称<%d个字符):\n",G.vexnum, MAX_NAME);
    for(i = 0; i < G.vexnum; i++)         // 构造顶点向量
        Input(G.vexs[i]);                 // 根据顶点信息类型,输入顶点信息,在func7-1.h中
    for(i = 0; i < G.vexnum; i++)         // 初始化二维邻接矩阵
        for(j = 0; j < G.vexnum; j++)
        {
            G.arcs[i][j].adj = INFINITY;   // 网,不相邻
            G.arcs[i][j].info = NULL;      // 无相关信息
        }
    printf("请输入%d条弧的弧尾 弧头 权值:\n",G.arcnum);
    for(k = 0; k < G.arcnum; k++)
    {
        scanf("%s,%s,%d%*c", v1.name, v2.name, &w);
        i = LocateVex(G, v1);              // 弧尾的序号
        j = LocateVex(G, v2);              // 弧头的序号
        G.arcs[i][j].adj = w;              // 有向网
        if(IncInfo)
        {
            InputArc(G.arcs[i][j].info);   // 动态生成存储空间,输入相关弧的信息
        }
    }
    G.kind = DN;
}

void CreateUDG(MGraph &G)
{// 采用数组(邻接矩阵)表示法,构造无向图G
    int i, j, k, IncInfo;
    VertexType v1, v2;
    printf("请输入无向图G的顶点数,边数,边是否含相关信息(是:1 否:0):");
    scanf("%d,%d,%d",&G.vexnum, &G.arcnum, IncInfo);
    printf("请输入%d个顶点的值(名称<%d个字符):\n",G.vexnum,MAX_NAME);
    for(i = 0; i < G.vexnum; i++)
    {
        Input(G.vexs[i]);
    }
    for(i = 0; i < G.vexnum; i++)      // 初始化二维邻接矩阵
        for(j = 0; j < G.vexnum; j++)
        {
            G.arcs[i][j].adj = 0;          // 图,不相邻
            G.arcs[i][j].info = NULL;      // 不含相关信息
        }
    printf("请输入%d条边的顶点1 顶点2:\n",G.arcnum);
    for(k = 0; k < G.arcnum; k++)
    {
        scanf("%s%s%*c",v1.name, v2.name);
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        G.arcs[i][j].adj = 1;     // 图
        if(IncInfo)                       // 有相关信息
        {
            InputArc(G.arcs[i][j].info);
        }
        G.arcs[j][i] = G.arcs[i][j];      // 无向,对称矩阵
    }
    G.kind = UDG;
}

void CreateUDN(MGraph &G)
{// 无向网
    int i, j, k, IncInfo;
    VRType w;                // 顶点关系类型
    VertexType v1, v2;       // 顶点类型
    printf("请输入无向网G的顶点数,边数,边是否含相关信息:");
    scanf("%d,%d,%d",&G.vexnum, &G.arcnum, IncInfo);
    printf("请输入%d个顶点的值(名称<%d个字符):\n",G.vexnum, MAX_NAME);
    for(i = 0; i < G.vexnum; i++)
    {// 初始化顶点向量
        Input(G.vexs[i]);
    }
    for(i = 0; i < G.vexnum; i++)
        for(j = 0; j <G.vexnum; j++)
        {
            G.arcs[i][j].adj = INFINITY;    // 网,不相邻
            G.arcs[i][j].info = NULL;
        }
    printf("请输入%d条边的顶点1 顶点2权值:\n",G.arcnum);
    for(k = 0; k < G.arcnum; k++)
    {
        scanf("%s%s%d%*c",v1.name, v2.name, &w);
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        G.arcs[i][j].adj = w;     // 网
        if(IncInfo)
        {
            InputArc(G.arcs[i][j].info);
        }
        G.arcs[j][i] = G.arcs[i][j];
    }
    G.kind = UDN;
}

void CreateGraph(MGraph &G)
{// 采用数组(邻接矩阵)表示法,构造图G
    printf("请输入图G的类型(有向图:0 有向网:1 无向图:2 无向网:3)");
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
{// 返回顶点序号为v的值
    if(v >= G.vexnum || v < 0)
        exit(OVERFLOW);
    return G.vexs[v];
}

Status PutVex(MGraph &G, VertexType v, VertexType value)
{// 对v赋新值
    int k = LocateVex(G, v);
    if(k < 0)
        return ERROR;
    G.vexs[k] = value;
    return OK;
}

int FirstAdjVex(MGraph G, int v)
{// 返回v的第一个邻接顶点的序号,若无邻接顶点,返回-1
    int i;
    VRType j = 0;       // 顶点关系类型,图
    if(G.kind % 2)      // 网
    {
        j = INFINITY;
    }
    for(i = 0; i < G.vexnum; i++)   // 从第一个顶点开始找
        if(G.arcs[v][i].adj != j)   // 是第一个邻接顶点
            return i;
    return -1;
}

int NextAdjVex(MGraph G, int v, int w)
{// 返回v的下一个邻接顶点的序号,若w是v的最后一个邻接顶点,则返回-1
    int i;
    VRType j = 0;           // 顶点关系类型,图
    if(G.kind % 2)          // 网
    {
        j = INFINITY;
    }
    for(i = w+1; i < G.vexnum; i++)  // 从第w+1个顶点开始找
        if(G.arcs[v][i].adj != j)
            return i;
    return -1;
}

void InsertVex(MGraph &G, VertexType v)
{// 向图G中新增顶点
    int i;
    VRType j = 0;            // 顶点关系类型,图
    if(G.kind % 2)          // 网
    {
        j = INFINITY;
    }
    G.vexs[G.vexnum] = v;   // 将v值赋给新顶点
    for(i = 0; i <= G.vexnum; i++)   // 初始化新增
    {
        G.arcs[G.vexnum][i].adj = G.arcs[G.vexnum][i].adj = j;
        G.arcs[G.vexnum][i].info = G.arcs[i][G.vexnum].info = NULL;
    }
    G.vexnum++;
}

Status InsertArc(MGraph &G, VertexType v, VertexType w)
{// 向图G中新增弧<v,w>若G为无向,则还新增弧<w,v>
    int i, v1, w1;
    v1 = LocateVex(G, v);                        // 弧尾顶点v的序号
    w1 = LocateVex(G, w);                        // 弧头顶点w的序号
    if(v1 < 0 || w1 <0)                          // 不存在顶点v或w
        return ERROR;
    G.arcnum++;                                  // 弧数+1
    if(G.kind % 2)                               // 网
    {
        printf("请输入此弧的权值:");
        scanf("%d",G.arcs[v1][w1].adj);
    }
    else                                         // 图
        G.arcs[v1][w1].adj = 1;
    printf("是否有该弧的相关信息(0:无 1:有):");
    scanf("%d%*c",&i);
    if(i)                                        // 有相关信息
        InputArc(G.arcs[v1][w1].info);
    if(G.kind > 1)                               // 无向
        G.arcs[w1][v1] = G.arcs[v1][w1];
    return OK;
}

Status DeleteArc(MGraph &G, VertexType v, VertexType w)
{// 删除弧<v,w>,若G无向,删除对称弧<w,v>
    int v1, w1;
    VRType j = 0;         // 顶点关系类型,图
    if(G.kind % 2)        // 网
    {
        j = INFINITY;
    }
    v1 = LocateVex(G, v);
    w1 = LocateVex(G, w);
    if(v1 < 0 || w1 < 0)
        return ERROR;
    if(G.arcs[v1][w1].adj != j)              // 有弧<v,w>
    {
        G.arcs[v1][w1].adj = j;              // 删除弧<v,w>
        if(G.arcs[v1][w1].info)               // 有相关信息
        {
            free(G.arcs[v1][w1].info);       // 释放空间
            G.arcs[v1][w1].info = NULL;      // 指针置空
        }
        if(G.kind >= 2)                      // 无向
            G.arcs[w1][v1] = G.arcs[v1][w1]; // 删除对称弧<w,v>
        G.arcnum--;
    }
    return OK;
}

Status DeleteVex(MGraph &G, VertexType v)
{// 删除顶点v及其相关弧
    int i, j, k;
    k = LocateVex(G, v);       // k为待删顶点序号
    if(k < 0)
        return ERROR;
    for(i = 0; i < G.vexnum; i++)
        DeleteArc(G, v, G.vexs[i]);     // 删除由顶点v发出的所有弧
    if(G.kind < 2)                      // 有向
        for(i = 0; i < G.vexnum; i++)
            DeleteArc(G, G.vexs[i], v); // 删除发向顶点v的所有弧
    for(j = k + 1; j < G.vexnum; j++)
        G.vexs[j-1] = G.vexs[j];        // 序号k后面的顶点向量依次前移
    for(i = 0; i < G.vexnum; i++)
        for(j = k + 1; j < G.vexnum; j++)
        {
            G.arcs[i][j - 1] = G.arcs[i][j];  // 移动待删除顶点之右的矩阵元素
        }
    for(i= 0; i< G.vexnum; i++)
        for(j = k + 1; j < G.vexnum; j++)
            G.arcs[j - 1][i] = G.arcs[j][i];  // 移动待删除顶点之下的矩阵元素
    G.vexnum--;
    return OK;
}

void DestroyGraph(MGraph &G)
{// 销毁图G
    int i;
    for(i = G.vexnum - 1; i >= 0; i--)     // 从大到小逐一删除顶点及其相关弧
        DeleteVex(G, G.vexs[i]);
}

void Display(MGraph G)
{// 输出邻接矩阵存储结构的图G
    int i, j;
    char s[7] = "无向图", s1[3] = "边";
    switch(G.kind)
    {
        case DG:strcpy(s, "有向图");
                strcpy(s1, "弧");
                break;
        case DN:strcpy(s, "有向网");
                strcpy(s1, "弧");
                break;
        case UDG:strcpy(s, "无向图");
                break;
        case UDN: ;
    }
    printf("%d个顶点%d条%s的%s。顶点依次是：",G.vexnum, G.arcnum, s1, s);
    for(i = 0; i < G.vexnum; i++)
        Visit(GetVex(G, i));                       // 根据顶点信息的类型,访问第i个顶点,在func7-1.h中
    printf("\nG.arcs.adj:\n");
    for(i = 0; i < G.vexnum; i++)                  // 输出二维数组G.arcs.adj
    {
        for(j = 0; j < G.vexnum; j++)
            if(G.arcs[i][j].adj == INFINITY)
                printf("∞");
            else
                printf("%4d",G.arcs[i][j].adj);
            printf("\n");
    }
    printf("G.arcs.info:\n");                      // 输出G.arcs.info
    if(G.kind < 2)                                 // 有向
        printf("弧尾 弧头 该%s的信息:\n",s1);
    else                                           // 无向
        printf("顶点1顶点2该%s的信息:\n",s1);
    for(i= 0; i< G.vexnum; i++)
        if(G.kind < 2)                             // 有向
        {
            for(j = 0; j < G.vexnum; j++)
                if(G.arcs[i][j].info)
                {
                    printf("%5s %5s",G.vexs[i].name, G.vexs[j].name);
                    OutputArc(G.arcs[i][j].info);  // 输出弧的相关信息,在func7-1.h
                }
        }
        else                                       // 无向,输出上三角
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
{// 由文件构造图或网G.IncInfo 表示弧有无相关信息1:有 0:无
    int i, j, k;
    VRType w = 0;              // 顶点关系类型,图
    VertexType v1, v2;         // 顶点类型
    FILE *f;                   // 文件指针
    f = fopen(filename,"r");
    fscanf(f,"%d",&G.kind);    // 由文件输入G的类型

    if(G.kind % 2)             // 网
        w = INFINITY;
    fscanf(f, "%d", &G.vexnum);         // 由文件输入顶点数
    for(i = 0; i < G.vexnum; i++)
        InputFromFile(f,G.vexs[i]);     // 由文件输入顶点信息,在func7-1.h中
    fscanf(f, "%d", &G.arcnum);         // 由文件输入弧数
    for(i = 0; i < G.vexnum; i++)
        for(j = 0; j < G.vexnum; j++)
        {
            G.arcs[i][j].adj = w;       // 不相邻
            G.arcs[i][j].info = NULL;   // 无相关信息
        }

    if(!(G.kind % 2))                   // 图
        w = 1;
    for(k = 0; k < G.arcnum; k++)       // 对所有弧
    {
        fscanf(f,"%s%s",v1.name, v2.name);
        if(G.kind % 2)                  // 网
            fscanf(f,"%d",&w);          // 权值
        i = LocateVex(G, v1);           // 弧尾序号
        j = LocateVex(G, v2);           // 弧头序号
        G.arcs[i][j].adj = w;           // 权值
        if(IncInfo)                     // 有相关信息
            InputArcFromFile(f,G.arcs[i][j].info);
        if(G.kind >1)                   // 无向
            G.arcs[j][i] = G.arcs[i][j];
    }
    fclose(f);
}

