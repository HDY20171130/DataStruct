// func6-1.h �����������룬����������ѡ��������ͣ����������ĺ���
#include "c1.h"
#if CHAR
    typedef char TElemType;
    TElemType Nil = '#';
    #define form "%c"
#else
    typedef int TElemType;
    TElemType Nil = 0;
    #define form "%d"
#endif // CHAR
void Visit(TElemType e)
{
    printf(form" ",e);
}
