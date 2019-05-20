#ifndef FUNC7-2_H_INCLUDED
#define FUNC7-2_H_INCLUDED

#define MAX_INFO 20           // 弧的相关信息字符串的最大长度+1
typedef char InfoType;        // 弧的相关信息类型
void InputArc(InfoType * &arc)
{// 输入弧的相关信息
    char s[MAX_INFO];         // 临时存储空间
    int m;
    printf("请输入该弧的相关信息(<%d个字符):",MAX_INFO);
    gets(s);                                      // 输入字符串(可包括空格)
    m = strlen(s);                                // 字符串长度
    if(m)
    {
        arc = (char*)malloc((m+1)*sizeof(char));  // 动态生成相关信息存储空间
        strcpy(arc,s);                            // 将s复制到arc
    }
}

void InputArcFromFile(FILE* f, InfoType* &arc)
{// 由文件输入弧的相关信息的函数
    char s[MAX_INFO];
    fgets(s, MAX_INFO, f);                           // 由文件输入字符串
    arc = (char*)malloc((strlen(s)+1)*sizeof(char)); // 动态生成相关信息存储空间
    strcpy(arc,s);
}

void OutputArc(InfoType *arc)
{// 输出弧的信息
    printf("%s\n",arc);
}

#endif // FUNC7-2_H_INCLUDED
