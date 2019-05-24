void Create_SeqFromFile(SSTable &ST, char *filename)
{// 由数据文件构造静态顺序查找表ST
    int i;
    FILE *f;
    f = fopen(filename,"r");
    fscanf(f,"%d",&ST.length);            // 输入数据元素个数
    ST.elem = (ElemType*)calloc(ST.length+1,sizeof(ElemType));  // calloc动态分配内存后并清零
    if(!ST.elem)                          // 分配空间失败
        exit(OVERFLOW);
    for(i = 1; i <= ST.length; i++)
        InputFromFile(f, ST.elem[i]);     // 从文件依次输入ST的元素
    fclose(f);
}

void Ascend(SSTable &ST)
{// 重建静态查找表为按关键字非降序排序
    int i, j, k;
    for(i = 1; i < ST.length; i++)
    {
        k = i;                        // k存当前关键字最小值的序号
        ST.elem[0] = ST.elem[i];      // 待比较值存[0]单元
        for(j = i + 1; j <= ST.length; j++)
            if LT(ST.elem[j].key, ST.elem[0].key)   // 当前元素的关键字小于待比较元素的关键字
            {
                k = j;                              // 将当前元素序号存到k中
                ST.elem[0] = ST.elem[j];            // 将当前元素的值存[0]中
            }
        if(k != i) // 有比[i]更小的值则交换
        {
            ST.elem[k] = ST.elem[i];
            ST.elem[i] = ST.elem[0];
        }
    }
}

void Create_OrdFromFile(SSTable &ST, char *filename)
{// 由含n个数据元素的数组r构造按关键字非降序查找表ST
    Create_SeqFromFile(ST,filename);
    Ascend(ST);     // 按关键字非降序重构
}

Status Destroy(SSTable &ST)
{// 销毁静态查找表ST
    free(ST.elem);
    ST.elem = NULL;
    ST.length = 0;
    return OK;
}

int Search_Seq(SSTable ST, KeyType key)
{// 查找关键字为key的数据元素,返回其在表中位置,若不存在,返回0
    int i;
    ST.elem[0].key = key;   // 哨兵,关键字存[0]单元
    for(i = ST.length; !EQ(ST.elem[i].key, key); --i);  // 从后往前找
        return i;
}

int Search_Bin(SSTable ST, KeyType key)
{// 在有序表ST中折半查找其关键字为key的数据元素,返回其在表中的位置,若不存在,返回0
    int mid, low = 1, high = ST.length;
    while(low <= high)
    {
        mid = (low + high)/2;
        if(EQ(key, ST.elem[mid].key))
            return mid;                       // 找到
        else if(LT(key, ST.elem[mid].key))    // 往前查找
            high = mid - 1;
        else                                  // 往后查找
            low = mid + 1;
    }
    return 0;                                 // 未找到
}

void Traverse(SSTable ST, void(*Visit)(ElemType))
{// 按顺序对ST的每个元素调用Visit()一次
    int i;
    ElemType *p = ++ST.elem;           // p指向第一个元素
    for(i = 1; i <= ST.length; i++)
        Visit(* p++);                   // 调用Visit(),p指向下一个元素
}
