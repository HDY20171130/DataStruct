int main()
{
    int i, j, k, n;
    char s[3] = "边";
    Graph g;
    VertexType v1, v2;
    printf("请依次选择有向图,有向网,无向图,无向网:\n");
    for(i = 0; i < 4; i++)        // 验证4种情况
    {
        CreateGraph(g);           // 构造图g
        Display(g);
        printf("插入新顶点,请输入新顶点的值:");
        Input(v1);
        InsertVex(g, v1);
        if(g.kind < 2)            // 有向
            strcpy(s,"弧");
        printf("插入与新顶点有关的%s,请插入%s数:",s,s);
        scanf("%d",&n);
        for(k = 0; k < n; k++)
        {
            printf("请输入另一顶点的名称:");
            scanf("%s",v2.name);
            if(g.kind < 2)        // 有向
            {
                printf("请输入另一顶点的方向(0:弧头 1:弧尾):");
                scanf("%d",&j);
                if(j) // v2为弧尾
                    InsertArc(g, v2, v1);
                else  // v2为弧头
                    InsertArc(g, v1, v2);
            }
            else                 // 无向
                InsertArc(g, v1, v2);
        }
        Display(g);
        printf("删除顶点及相关的%s,请输入待删顶点名称:",s);
        scanf("%s",&v1.name);
        DeleteVex(g, v1);
        Display(g);
        if(i == 3)
        {
            printf("修改顶点的值,请输入待修改顶点的名称 新值:");
            scanf("%s",v1.name);    // 输入待修改顶点名称
            Input(v2);              // 输入顶点新值
            PutVex(g, v1, v2);      // 将图g中顶点v1的值改为v2
            if(g.kind < 2)          // 有向
                printf("删除一条%s,请输入待删除%s的弧尾 弧头:",s,s);
            else                    // 无向
                printf("删除一条%s,请输入待删除%s的顶点1 顶点2:",s,s);
            scanf("%s%s",v1.name, v2.name);     // 输入待删除弧的两个顶点名称
            DeleteArc(g,v1,v2);
            Display(g);
        }
        DestroyGraph(g);
    }
    return 0;
}
