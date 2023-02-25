#include "BinaaryTree.h"
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>


//创建一个二叉树树节点（创建出来的根，左右子树都有可能）
BTNode* BuyNode(DataType x)
{
    BTNode* node=malloc(sizeof(BTNode));
    assert(node);
    node->data=x;
    node->left=node->right=NULL;
    return node;
}




//创建二叉树
BTNode* CreatBinaaryTree()
{
    BTNode* nodeA=BuyNode('A');
    BTNode* nodeB=BuyNode('B');
    BTNode* nodeC=BuyNode('C');
    BTNode* nodeD=BuyNode('D');
    BTNode* nodeE=BuyNode('E');
    BTNode* nodeF=BuyNode('F');

    nodeA->left=nodeB;
    nodeA->right=nodeC;
    nodeB->left=nodeD;
    nodeC->left=nodeE;
    nodeC->right=nodeF;

    return nodeA;
}



//前序遍历     -----重点之一
BTNode* PreOrder(BTNode* root)   //root  根的意思
{
    if(root==NULL)//请注意这种不能用assert了，因为这个空是递归的停止条件
    {
        printf("NULL ");
        return NULL;
    }
    printf("%c ",root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}


//中序遍历
BTNode* InOrder(BTNode* root)
{
    if(root==NULL)
    {
        printf("NULL ");
        return NULL;
    }
    InOrder(root->left);
    printf("%c ",root->data);
    InOrder(root->right);
}


//后续遍历
BTNode* PostOrder(BTNode* root)
{
    if(root==NULL)//1.根节点不能为空     2.这是个停止的条件
    {
        printf("NULL ");
        return NULL;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%c ",root->data);
}




//后续遍历
