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
#ifndef C7-1_H_INCLUDED
#define C7-1_H_INCLUDED

#define INFINITY INT_MAX           // 鐢ㄦ暣鍨嬫渶澶у€间唬鏇挎棤绌峰ぇ
typedef int VRType;                // 瀹氫箟椤剁偣鍏崇郴绫诲瀷涓烘暣鍨?涓嶪NFINITY绫诲瀷涓€鑷?
#define MAX_VERTEX_NUM 26          // 鏈€澶ч《鐐逛釜鏁?
enum GrapgKind{DG, DN, UDG, UDN};  // {鏈夊悜鍥?鏈夊悜缃?鏃犲悜鍥?鏃犲悜缃憓
typedef struct                     // 寮т俊鎭?
{
    VRType adj;                    // 椤剁偣鍏崇郴绫诲瀷
    InfoType *info;                // 璇ュ姬鐩稿叧淇℃伅鐨勬寚閽?鍙棤)
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];     //浜岀淮鏁扮粍
struct MGraph                          // 鍥剧殑缁撴瀯
{
    VertexType vexs[MAX_VERTEX_NUM];   // 椤剁偣鍚戦噺
    AdjMatrix arcs;                    // 閭绘帴鐭╅樀
    int vexnum, arcnum;                // 椤剁偣鏁?寮ф暟
    GrapgKind kind;                    // 鍥剧殑绉嶇被鏍囧織(鏋氫妇绫诲瀷)
};
