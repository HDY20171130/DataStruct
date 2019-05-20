#define INFINITY INT_MAX           // 用整型最大值代替无穷大
typedef int VRType;                //
#define MAX_VERTEX_NUM 26          //
enum GrapgKind{DG, DN, UDG, UDN};  // {有向图,有向网,无向图,无向网}
typedef struct                     // 弧信息
{
    VRType adj;                    // 顶点关系类型,对于无权图,1:相邻,0:不相邻;对于有权图,则为权值
    InfoType * info;                // 该弧相关信息的指针(可无)
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];     //二维数组
struct MGraph
{// 图的结构
    VertexType vexs[MAX_VERTEX_NUM];   // 顶点向量
    AdjMatrix arcs;                    // 邻接矩阵
    int vexnum, arcnum;                // 顶点数,弧数
    GrapgKind kind;                    // 图的种类标志(枚举类型)
};
