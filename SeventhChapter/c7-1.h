#define INFINITY INT_MAX           // ���������ֵ���������
typedef int VRType;                //
#define MAX_VERTEX_NUM 26          //
enum GrapgKind{DG, DN, UDG, UDN};  // {����ͼ,������,����ͼ,������}
typedef struct                     // ����Ϣ
{
    VRType adj;                    // �����ϵ����,������Ȩͼ,1:����,0:������;������Ȩͼ,��ΪȨֵ
    InfoType * info;                // �û������Ϣ��ָ��(����)
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];     //��ά����
struct MGraph
{// ͼ�Ľṹ
    VertexType vexs[MAX_VERTEX_NUM];   // ��������
    AdjMatrix arcs;                    // �ڽӾ���
    int vexnum, arcnum;                // ������,����
    GrapgKind kind;                    // ͼ�������־(ö������)
};
