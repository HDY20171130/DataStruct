// bo4-2.h 串的堆存储结构基本操作(12个)
#define DestroyString ClearString
void InitString(HString &S)
{
    S.length = 0;
    S.ch = NULL;
}

void ClearString(HString &S)
{
    free(S.ch);
    InitString(S);
}

void StrAssign(HString &T, char* chars)
{// 生成一个其值等于串常量chars的串T
    int i,j;
    if(T.ch)
        free(T.ch);
    i = strlen(chars);
    if(!i)
        InitString(T);
    else
    {
        T.ch = (char*)malloc(i*sizeof(char));
        if(!T.ch)
            exit(OVERFLOW);
        for(j = 0; j < i; j++)
            T.ch[j] = chars[j];
        T.length = i;
    }
}

void StrCopy(HString &T, HString S)
{// S的串赋值给T
    int i;
    if(T.ch)
        free(T.ch);
    T.ch = (char*)malloc(S.length*sizeof(char));
    if(!T.ch)
        exit(OVERFLOW);
    for(i = 0; i < S.length; i++)
        T.ch[i] = S.ch[i];
    T.length = S.length;
}

Status StrEmpty(HString S)
{
    if(S.length == 0 && S.ch == NULL)
        return TRUE;
    return FALSE;
}

int StrCompare(HString S, HString T)
{// 若S>T, 则返回值>0 ;若S=T,返回0
    int i;
    for(i = 0; i < S.length && i < T.length; i++)
        if(S.ch[i] != T.ch[i])
            return S.ch[i]-T.ch[i];
    return S.length-T.length;
}

int StrLength(HString S)
{
    return S.length;
}

void Concat(HString &T, HString S1, HString S2)
{// 用T返回S1和S2拼接的新串
    int i;
    if(T.ch)
        free(T.ch);
    T.length = S1.length + S2.length;
    T.ch = (char*)malloc(T.length * sizeof(char));
    for(i = 0; i < S1.length; i++)
        T.ch[i] = S1.ch[i];
    for(i = 0; i < S2.length; i++)
        T.ch[i + S1.length] = S2.ch[i];
}

Status SubString(HString &Sub, HString S, int pos, int len)
{// 返回第pos个位置起,len个长的子串
    int i;
    if(pos < 1 || pos + len > S.length+1 || len < 0)
        return ERROR;
    if(Sub.ch)
        free(Sub.ch);
    if(!len)
        InitString(Sub);
    else
    {
        Sub.ch = (char*)malloc(len * sizeof(char));
        if(!Sub.ch)
            exit(OVERFLOW);
        for(i = 0; i < len - 1; i++)
            Sub.ch[i] = S.ch[i + pos - 1];
        Sub.length = len;
    }
    return OK;
}

Status StrInsert(HString &S, int pos, HString T)
{// 在S的第pos个位置插入T
    int i;
    if(pos < 1 || pos > S.length + 1)
        return ERROR;
    if(T.length)
    {
        S.ch = (char*) realloc(S.ch,(S.length + T.length)*sizeof(char));
        if(!S.ch)
            exit(OVERFLOW);
        // 此时S.length为多少
        for(i = S.length - 1; i >= pos - 1; i--)
            S.ch[i + T.length] = S.ch[i];
        for(i = 0; i < T.length; i++)
            S.ch[i + pos - 1] = T.ch[i];
        S.length += T.length;
    }
    return OK;
}

Status StrDelete(HString &S, int pos, int len)
{// 删除S的第pos个位置后.len个长度的子串
    int i;
    if(pos < 1 || pos + len > S.length +1)
        return ERROR;
    for(i = pos - 1; i <= S.length - len; i++)
        S.ch[i] = S.ch[i + len];
    S.length -=len;
    S.ch = (char*)realloc(S.ch,S.length * sizeof(char));
    return OK;
}

void StrPrint(HString S)
{
    int i;
    for(i = 0; i< S.length; i++)
        printf("%c", S.ch[i]);
    printf("\n");
}
