#ifndef C7-1_H_INCLUDED
#define C7-1_H_INCLUDED

#define INFINITY INT_MAX           // ���������ֵ���������
typedef int VRType;                //
#define MAX_VERTEX_NUM 26          //
enum GrapgKind{DG, DN, UDG, UDN};  // {����ͼ,������,����ͼ,������}
typedef struct                     // ����Ϣ
{
    VRType adj;                    // �����ϵ����
    InfoType *info;                // �û������Ϣ��ָ��(����)
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];     //��ά����
struct MGraph                          // ͼ�Ľṹ
{
    VertexType vexs[MAX_VERTEX_NUM];   // ��������
    AdjMatrix arcs;                    // �ڽӾ���
    int vexnum, arcnum;                // ������,����
    GrapgKind kind;                    // ͼ�������־(ö������)
};

#endif // C7-1_H_INCLUDED
