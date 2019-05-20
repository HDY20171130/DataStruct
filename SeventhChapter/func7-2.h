#ifndef FUNC7-2_H_INCLUDED
#define FUNC7-2_H_INCLUDED

#define MAX_INFO 20           // ���������Ϣ�ַ�������󳤶�+1
typedef char InfoType;        // ���������Ϣ����
void InputArc(InfoType * &arc)
{// ���뻡�������Ϣ
    char s[MAX_INFO];         // ��ʱ�洢�ռ�
    int m;
    printf("������û��������Ϣ(<%d���ַ�):",MAX_INFO);
    gets(s);                                      // �����ַ���(�ɰ����ո�)
    m = strlen(s);                                // �ַ�������
    if(m)
    {
        arc = (char*)malloc((m+1)*sizeof(char));  // ��̬���������Ϣ�洢�ռ�
        strcpy(arc,s);                            // ��s���Ƶ�arc
    }
}

void InputArcFromFile(FILE* f, InfoType* &arc)
{// ���ļ����뻡�������Ϣ�ĺ���
    char s[MAX_INFO];
    fgets(s, MAX_INFO, f);                           // ���ļ������ַ���
    arc = (char*)malloc((strlen(s)+1)*sizeof(char)); // ��̬���������Ϣ�洢�ռ�
    strcpy(arc,s);
}

void OutputArc(InfoType *arc)
{// ���������Ϣ
    printf("%s\n",arc);
}

#endif // FUNC7-2_H_INCLUDED
