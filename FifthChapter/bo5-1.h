// bo5-1.h 顺序存储数组的基本操作(5个)
Status InitArray(Array &A, int dim, ...)
{// 若维数dim和各维长度合法,则构造数组A,返回OK
    int elemtotal = 1, i;                                        // 数组元素总数
    va_list ap;                                                  // 边长参数类型,在stdarg.h中
    if(dim < 1 || dim > MAX_ARRAY_DIM)
        return ERROR;
    A.dim = dim;
    A.bounds = (int*)malloc(dim*sizeof(int));                    // 动态分配维界基址
    if(!A.bounds)
        exit(OVERFLOW);

    va_start(ap,dim);
    for(i = 0; i < dim ;i++)
    {
        A.bounds[i] = va_arg(ap, int);                           // 逐一将变长参数赋给A.bounds[i]
        if(A.bounds[i] < 0)
            return UNDERFLOW;
        elemtotal *= A.bounds[i];
    }
    va_end(ap);                                                  // 结束提取变长参数

    A.base = (ElemType*)malloc(elemtotal * sizeof(ElemType));
    if(!A.base)
        exit(OVERFLOW);
    A.constants = (int*)malloc(dim*sizeof(int));                 // 动态分配数组偏移量基址
    if(!A.constants)
        exit(OVERFLOW);
    A.constants[dim - 1] = 1;                                    // 最后一维的偏移量为1
    for(i = dim - 2; i >= 0; i--)
        A.constants[i] = A.bounds[i + 1] * A.constants[i + 1];   // 每一维的偏移量
    return OK;
}

void DestroyArray(Array &A)
{
    if(A.base)
        free(A.base);
    if(A.bounds)
        free(A.bounds);
    if(A.constants)
        free(A.constants);
    A.base = A.bounds = A.constants = NULL;
    A.dim = 0;
}

Status Locate(Array A, va_list ap, int &off)
{
    int i, ind;
    off = 0;
    for(i = 0; i < A.dim; i++)
    {
        ind = va_arg(ap, int);
        if(ind < 0 || ind >= A.bounds[i])
            return OVERFLOW;
        off += A.constants[i]*ind;
    }
    return OK;
}

Status Value(ElemType &e, Array A, ...)
{
    va_list ap;
    int off;
    va_start(ap, A);
    if(Locate(A, ap, off) == OVERFLOW)
        return ERROR;
    e = *(A.base + off);
    return OK;
}

Status Assign(Array A, ElemType e, ...)
{
    va_list ap;
    int off;
    va_start(ap,e);
    if(Locate(A, ap, off) == OVERFLOW)
        return ERROR;
    *(A.base + off) = e;
    return OK;
}
