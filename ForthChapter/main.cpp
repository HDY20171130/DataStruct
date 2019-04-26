// main4-1.cpp 检验bo4-1.h的主程序
//#include"c1.h"
//#include"c4-1.h"
//#include"bo4-1.h"
//typedef SString String;
//#include"func4-1.h"
//int main()
//{
//    int i, j;
//    Status k;
//    char s, c[MAX_STR_LEN+1];
//    String t, s1, s2;
//    printf("请输入串s1：");
//    gets(c);
//    k=StrAssign(s1, c);
//    if(!k)
//    {
//        printf("串长超过MAX_STR_LEN（=%d）\n", MAX_STR_LEN);
//        exit(OVERFLOW);
//    }
//    printf("串长为%d，串空否？%d（1：是 0：否）\n", StrLength(s1), StrEmpty(s1));
//    StrCopy(s2, s1);
//    printf("复制s1生成的串为");
//    StrPrint(s2);
//    printf("请输入串s2：");
//    gets(c);
//    StrAssign(s2, c);
//    i=StrCompare(s1, s2);
//    if(i<0)
//        s = '<';
//    else if(i==0)
//        s = '=';
//    else
//        s = '>';
//    printf("串s1%c串s2\n", s);
//    k=Concat(t, s1, s2);
//    printf("串s1连接串s2得到的串t为");
//    StrPrint(t);
//    if(k==FALSE)
//        printf("串t有截断\n");
//    ClearString(s1);
//    printf("清为空串后，串s1为");
//    StrPrint(s1);
//    printf("串长为%d，串空否？%d（1：是 0：否）\n", StrLength(s1), StrEmpty(s1));
//    printf("求串t的子串，请输入子串的起始位置,子串长度：");
//    scanf("%d,%d", &i, &j);
//    k=SubString(s2, t, i, j);
//    if(k)
//    {
//        printf("子串s2为");
//        StrPrint(s2);
//    }
//    printf("从串t的第pos个字符起，删除len个字符，请输入pos,len：");
//    scanf("%d,%d", &i, &j);
//    StrDelete(t, i, j);
//    printf("删除后的串t为");
//    StrPrint(t);
//    i=StrLength(s2)/2;
//
//    StrInsert(s2, i, t);
//
//    printf("在串s2的第%d个字符之前插入串t后，串s2为", i);
//    StrPrint(s2);
//    i=Index1(s2, t, 1);
//    printf("s2的第%d个字符起和t第一次匹配\n", i);
//    i=Index(s2, t, 1);
//    printf("s2的第%d个字符起和t第一次匹配\n", i);
//    SubString(t, s2, 1, 1);
//    printf("串t为");
//    StrPrint(t);
//    Concat(s1, t, t);
//    printf("串s1为");
//    StrPrint(s1);
//    k=Replace(s2, t, s1);
//    if(k)
//    {
//        printf("用串s1取代串s2中和串t相同的不重叠的串后，串s2为");
//        StrPrint(s2);
//    }
//    DestroyString(s2);
//    return 0;
//}

// main4-2.cpp 检验bo4-2.h的主程序
//#include"c1.h"
//#include"c4-2.h"
//#include"bo4-2.h"
//typedef HString String;
//#include"func4-1.h"
//int main()
//{
//    int i;
//    char c, *p="God bye!", *q="God luck!";
//    HString t, s, r;
//    InitString(t);
//    InitString(s);
//    InitString(r);
//    StrAssign(t, p);
//    printf("串t为");
//    StrPrint(t);
//    printf("串长为%d，串空否？%d（1：空 0：否）\n", StrLength(t), StrEmpty(t));
//    StrAssign(s, q);
//    printf("串s为");
//    StrPrint(s);
//    i=StrCompare(s, t);
//    if(i<0)
//        c = '<';
//    else if(i==0)
//        c = '=';
//    else
//        c = '>';
//    printf("串s%c串t\n", c);
//    Concat(r, t, s);
//    printf("串t连接串s产生的串r为");
//    StrPrint(r);
//    StrAssign(s, "oo");
//    printf("串s为");
//    StrPrint(s);
//    StrAssign(t, "o");
//    printf("串t为");
//    StrPrint(t);
//    Replace(r, t, s);
//    printf("把串r中和串t相同的子串用串s代替后，串r为");
//    StrPrint(r);
//    ClearString(s);
//    printf("串s清空后，串长为%d，空否？%d（1：空 0：否）\n", StrLength(s), StrEmpty(s));
//    SubString(s, r, 6, 4);
//    printf("串s为从串r的第6个字符起的4个字符，长度为%d，串s为", s.length);
//    StrPrint(s);
//    StrCopy(t, r);
//    printf("由串r复制得串t，串t为");
//    StrPrint(t);
//    StrInsert(t, 6, s);
//    printf("在串t的第6个字符前插入串s后，串t为");
//    StrPrint(t);
//    StrDelete(t, 1, 5);
//    printf("从串t的第1个字符起删除5个字符后，串t为");
//    StrPrint(t);
//    printf("%d是从串t的第1个字符起，和串s相同的第1个子串的位置\n", Index(t, s, 1));
//    printf("%d是从串t的第2个字符起，和串s相同的第1个子串的位置\n", Index(t, s, 2));
//    DestroyString(t);
//    return 0;
//}

// algo4-1.cpp KMP算法
#include"c1.h"
#include"c4-1.h"
#include"bo4-1.h"
void get_next(SString T, int next[])
{// 求T的next函数值并存入next数组
    int i = 1, j = 0;
    next[1] = 0;      // T的第i个字符与主串不匹配时,主串的下一个字符与T的第1个字符比较
    while(i < T[0])
        if(j == 0 || T[i] == T[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
}

void get_nextval(SString T, int nextval[])
{// 求T的next函数修正值并存入nextval数组
    int i = 1, j = 0;
    nextval[1] = 0;
    while(i < T[0])
        if(j == 0 || T[i] == T[j])
        {
            i++;
            j++;
            if(T[i] != T[j])
                nextval[i] = j;
            else
                nextval[i] = nextval[j];
        }
        else
            j = nextval[j];
}

int Index_KMP(SString S, SString T, int pos, int next[])
{
    int i = pos, j = 1;
    while(i <= S[0] && j <= T[0])
        if(j == 0 || S[i] == T[j])
        {
            i++;
            j++;
        }
        else
            j = next[j];
    if(j > T[0])
        return i - T[0];
    else
        return 0;
}

int main()
{
	int i, *p;
	SString s1, s2;
	StrAssign(s1, "aaabaaaab");
	printf("主串为");
	StrPrint(s1);
	StrAssign(s2, "aaaab");
	printf("子串为");
	StrPrint(s2);
	p=(int*)malloc((StrLength(s2)+1)*sizeof(int));
	get_next(s2, p);
	printf("子串的next数组为");
	for(i=1; i<=StrLength(s2); i++)
        printf("%d ", *(p+i));
	printf("\n");
	i=Index_KMP(s1, s2, 1, p);
	if(i)
        printf("主串和子串在第%d个字符处首次匹配\n", i);
	else
        printf("主串和子串匹配不成功\n");
	get_nextval(s2, p);
	printf("子串的nextval数组为");
	for(i=1; i<=StrLength(s2); i++)
        printf("%d ", *(p+i));
	printf("\n");
	printf("主串和子串在第%d个字符处首次匹配\n", Index_KMP(s1, s2, 1, p));

}


