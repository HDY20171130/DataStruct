// func8-4.h
#include "bo6-1.h"
#define InitDSTable InitBiTree           // 构造二叉排序树和平衡二叉树与初始化二叉树的操作相同
#define DestroyDSTable DestroyBiTree     // 销毁
#define TraverseDSTable InOrderTraverse  // 按关键字遍历二叉排序树

BiTree SearchBST(BiTree T, KeyType key)
{// 递归查找关键字为key的数据元素,若查找成功,返回该元素指针,不存在返回空指针
    if(!T || EQ(key, T->data.key))
        return T;
    else if LT(key, T->data.key)
        return SearchBST(T->lchild,key);
    else
        return SearchBST(T->rchild,key);
}
