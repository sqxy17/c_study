#ifndef C__BINAARYTREE_H
#define C__BINAARYTREE_H

#endif C__BINAARYTREE_H


typedef char DataType;
//二叉树的链式结构

typedef struct BinaaryTreeNode
{
    struct BinaaryTreeNode* left;//左子树
    struct BinaaryTreeNode* right;//右子树
    DataType data;//数据
}BTNode;

BTNode* CreatBinaaryTree();

BTNode* BuyNode(DataType x);

BTNode* PreOrder(BTNode* root);

BTNode* InOrder(BTNode* root);

BTNode* PostOrder(BTNode* root);
