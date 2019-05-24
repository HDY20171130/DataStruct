// bo8-3.h 平衡二叉树的基本操作
void R_Rotate(BSTree &p)
{// 以*p为根的二叉排序树作右旋处理,使二叉排序树的重心右移,但不改变平衡因子
 // 处理之后p指向新的树根节点,即旋转处理之前的左子树的根结点
    BSTree lc;
    lc = p->lchild;          // lc指向p的左孩子,lc的左子树不变
    p->lchild = lc->rchild;  // lc的右子树挂接为p的左子树
    lc->rchild = p;          // 原根结点成为lc的右孩子
    p = lc;                  // p指向原左孩子结点
}

void L_Rotate(BSTree &p)
{// 左旋
    BSTree rc;
    rc = p->rchild;
    p->rchild = lc->lchild;
    rc->lchild = p;
    p = rc;
}

void LR_Rotate(BSTree &p)
{// 对以*p为根的平衡二叉树的LR型失衡,直接进行平衡旋转处理,不修改平衡因子
    BSTree lc = p->lchild;          // lc指向小值结点
    p->lchild = lc->rchild->rchild; // 中值结点的右子树成为大值结点的左子树
    lc->rchild->rchild = p;         // 大值结点成为中值结点的右子树
    p = lc->rchild;                  // p指向中值结点
    lc->rchild = p->lchild;         // 中值结点左子树成为小值结点的右子树
    p->lchild = lc;                 // 小值结点成为中值结点左子树
}

void RL_Rotate(BSTree &p)
{
    BSTree rc = p->rchild;
    p->rchild = rc->lchild->lchild;
    rc->lchild->lchild = p;
    p = rc->lchild;
    rc->lchild = p->rchild;
    p->rchild = rc;
}

#define LH +1   // 左高
#define EH 0    // 等高
#define RH -1   // 右高

void LeftBalance(BSTree &T)
{// 初始条件:原平衡二叉排序树T的左子树比右子树高(T->bf=1)
 // 操作:在左子树中插入结点,导致树T不平衡,对不平衡的树T进行左旋处理使其平衡
    BSTree lc, rd;
    lc = T->lchild;
    switch(T->bf)
    {
        case LH: T->bf = lc->bf = EH;
                 R_Rotate(T);
                 break;
        case RH: rd = lc->rchild;
                 switch(rd->bf)
                 {
                     case LH: T->bf = RH;
                              lc->bf = EH;
                              break;
                     case EH: T->bf = lc->bf = EH;
                              break;
                     case RH: T->bf = EH;
                              lc->bf = LH;
                 }
                 rd->bf = EH;
#ifndef FLAG   // 未定义FLAG使用两个函数实现双旋处理
    L_Rotate(T->lchild);
    R_Rotate(T);
#else
    LR_Rotate(T);
#endif // FLAG
    }
}


