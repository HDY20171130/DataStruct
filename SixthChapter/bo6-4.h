void PreOrderTraverse(CSTree T, void(*Visit)(TElemType))
{
    if(T)
    {
        Visit(Value(T));
        PreOrderTraverse(T->firstchild,Visit);
        PreOrderTraverse(T->nextsibling,Visit);
    }
}
