// func4-1.h 与存储结构无关的两个基本操作
int Index(String S, String T, int pos)
{// T为非空串,若S中第pos个字符之后存在与T相等的子串,返回该子串的首字符位置
    int m, n, i;
    String sub;
    InitString(sub);
    if(pos > 0)
    {
        n = StrLength(S);
        m = StrLength(T);
        i = pos;
        while(i <= n-m+1)
        {
            SubString(sub, S, i, m);
            if(StrCompare(sub, T) != 0)
                i++;
            else
                return i;
        }
    }
    return 0;
}

Status Replace(String &S, String T, String V)
{// 串S,T和V存在,T非空  用V替换S中所有与T相等的不重叠子串
    int i = 1;
    Status k;
    if(StrEmpty(T))
        return ERROR;
    while(i)
    {
        i = Index(S, T, i);
        if(i)
        {
            StrDelete(S, i, StrLength(T));
            k = StrInsert(S, i, V);
            if(!k)
                return ERROR;
            i += StrLength(V);
        }
    }
    return OK;
}
