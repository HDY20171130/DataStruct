// bo4-1.h 串采用定长顺序存储结构的基本操作(12个)
#define DestroyString ClearString
#define InitString ClearString

Status StrAssign(SString T, char *chars)
{// 生成一个其值等于chars的串T
    int i;
    if(strlen(chars) > MAX_STR_LEN)
        return ERROR;
    else
    {
        T[0] = strlen(chars);
        for(i = 1; i <= T[0]; i++)
            T[i] = *(chars + i - 1);
        return OK;
    }
}

void StrCopy(SString T, SString S)
{// T <- S 赋值
    int i;
    for(i = 0; i <= S[0]; i++)
        T[i] = S[i];
}

Status StrEmpty(SString S)
{
    if(S[0] == 0)
        return TRUE;
    return FALSE;
}

int StrCompare(SString S, SString T)
{
    int i;
    for(i = 1; i <= S[0] && i <= T[0]; i++)
        if(S[i] != T[i])
            return S[i] - T[i];
    return S[0] - T[0];
}

int StrLength(SString S)
{
    return S[0];
}

void ClearString(SString S)
{
    S[0] = 0;
}

Status Concat(SString T, SString S1, SString S2)
{// 用T返回S1和S2连接成的新串,若未截断,返回TRUE
    int i;
    if(S1[0] + S2[0] <= MAX_STR_LEN)
    {
        for(i = 1; i <= S1[0]; i++)
            T[i] = S1[i];
        for(i = 1; i <= S2[0]; i++)
            T[S1[0]+i] = S2[i];
        T[0] = S1[0] + S2[0];
        return TRUE;
    }
    else
    {
        for(i = 1; i < S1[0]; i++)
            T[i] = S1[i];
        for(i = 1; i <= MAX_STR_LEN - S1[0]; i++)
            T[S1[0]+i] = S2[i];
        T[0] = MAX_STR_LEN;
        return FALSE;
    }
}

Status SubString(SString Sub, SString S, int pos, int len)
{// 用Sub返回S的第pos个字符起长度为len的子串
    int i;
    if(pos < 1 || pos > S[0] || pos + len > S[0]+1 || len < 0 )
        return ERROR;
    for(i = 1; i <= len; i++)
        Sub[i] = S[pos + i - 1];
    Sub[0] = len;
    return OK;
}

int Index1(SString S, SString T, int pos)
{// 返回T在S中第pos个字符之后的位置,若不存在,返回0
 // T非空, 1 <= pos <= StrLength(S)
    int i, j;
    if(1 <= pos && pos <= S[0])
    {
        i = pos;
        j = 1;
        while(i <= S[0] && j <= T[0])
            if(S[i] == T[j])
            {
                i++;
                j++;
            }
            else
            {
                i = i - j + 2;
                j = 1;
            }
        if(j > T[0])
            return i - T[0];
        else
            return 0;
    }
    else
        return 0;
}

Status StrInsert(SString S, int pos, SString T)
{// S和T存在, 1 <= pos <= StrLength(S) + 1
 // 在S的第pos个字符之前插入T,完全插入返回TRUE
    int i;
    if(pos < 1 || pos > S[0]+1)
         return ERROR;
    if(S[0] + T[0] <= MAX_STR_LEN)
    {
        for(i = S[0]; i >= pos; i--)  // S的pos后面部分后移T[0]个位置
            S[i+T[0]] = S[i];
        for(i = pos; i < pos + T[0]; i++) // 错过 i--
            S[i] = T[i - pos + 1];
        S[0] += T[0];

        return TRUE;
    }
    else
    {
        for(i = MAX_STR_LEN; i >= pos +T[0]; i--)
            S[i] = S[i-T[0]];
        for(i = pos; i < pos + T[0] && i <= MAX_STR_LEN; i++)
            S[i] = T[i - pos + 1];
        S[0] = MAX_STR_LEN;
        return FALSE;
    }
}

Status StrDelete(SString S, int pos, int len)
{// S存在.1 <= pos <= StrLength(S) - len + 1
 // 从S中删除第pos个字符起长度为len的子串
    int i;
    if(pos < 1 || pos > S[0] - len + 1 || len < 0)
        return ERROR;
    for(i = pos + len; i <= S[0]; i++)     // 错过没有考虑剩余字符
        S[i - len] = S[i];
    S[0] -= len;
    return OK;
}

void StrPrint(SString S)
{
    int i;
    for(i = 1; i <= S[0]; i++)
        printf("%c",S[i]);
    printf("\n");
}
