// c8-1.h 静态查找表的顺序存储结构
struct SSTable // 静态查找表
{
    ElemType *elem;  // 表空间基址,0号单元不存数据
    int length;      // 表长
};
