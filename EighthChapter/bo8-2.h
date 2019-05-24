// bo8-2.h 二叉排序树的基本操作(4个)
Status SearchBST(BiTree &T, KeyType key, BiTree f, BiTree &p)
{// S在根指针T所指二叉排序树中递归查找其关键字等于Key的数据元素
 // 若查找成功,p指向该元素结点,并返回TRUE
 // 若不成功,p指向查找路径上访问的最后一个结点,并返回FALSE
 // f指向T的双亲,初始值为NULL
    if(!T)            // 查找不成功
    {
        p = f;
        return FALSE;
    }
    else if EQ(key, T->data.key)   // 查找成功
    {
        p = T;                     // p指向该元素结点
        return TRUE;
    }
    else if LT(key, T->data.key)
        return SearchBST(T->lchild, key, T, p);
    else
        return SearchBST(T->rchild, key, T, p);
}

Status InsertBST(BiTree &T, ElemType e)
{// 若二叉排序树T中没有关键字等于e.key的元素,插入e并返回TRUE,否则返回FALSE
    BiTree p, s;
    if(!SearchBST(T, e.key, NULL, p))  // 没有找到等于e.key的元素
    {
        s = (BiTree)malloc(sizeof(BiTNode));  // 生成新结点
        s->data = e;                          // 新结点赋值
        s->lchild = s->rchild = NULL;
        if(!p)                                // 树T空
            T = s;
        else if LT(e.key, p->data.key)        // s的关键字<p的关键字
            p->lchild = s;                    // s置为p的左孩子
        else
            p->rchild = s;
        return TRUE;
    }
    else
        return FALSE;
}

void Delete(BiTree &p)
{// 从二叉排序树删除p所指结点,重连其左右子树
    BiTree s, q = p;        // q指向待删除结点
    // 待删结点只有半边子树
    if(!p->rchild)          // 若右子树为空,则只需要重连其左子树
    {
        p = p->lchild;
        free(q);
    }
    else if(!p->lchild)
    {
        p = p->rchild;
        free(q);
    }
    // 待删结点有左右子树
    else                    // p左右子树均不空
    {
        s = p->lchild;      // s指向待删结点左孩子
        while(s->rchild)    // s有右孩子
        {
            q = s;          // q指向s
            s = s->rchild;  // s指向右孩子
        }
        p->data = s->data;  // 将待删结点前驱的值取代待删结点的值
        // 待删除结点的左孩子有右子树
        if(q != p)
            q->rchild = s->lchild;
        // 待删除结点的左孩子没有右子树
        else
            q->lchild = s->lchild;
        free(s);            // 释放s所指结点
    }
}

Status DeleteBST(BiTree &T, KeyType key)
{// 存在关键字为key的数据元素,删除并返回TRUE,否则返回FALSE
    if(!T)
        return FALSE;
    else
    {
        if EQ(key, T->data.key)
        {
            Delete(T);
            return TRUE;
        }
        else if LT(key, T->data.key)
            return DeleteBST(T->lchild, key);
        else
            return DeleteBST(T->rchild, key);
    }
}
