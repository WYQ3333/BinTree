#pragma once
#include<Windows.h>
#include<string.h>
#include<assert.h>
#include<malloc.h>
#include<stdio.h>

typedef char KeyType;

typedef struct Node
{
	KeyType data;
	struct Node * Lchild;
	struct Node * Rchild;
}BinTree,*pBinTree;

void CreatBinTree(pBinTree *pB, char *str, int size, int *index, KeyType invalid);//创建二叉树
pBinTree BuyNewNode(KeyType data);//购买新结点
void PreBTNode(BinTree * pRoot);//先序遍历
void InBTNode(BinTree * pRoot);//中序遍历
void PostBTNode(BinTree *pRoot);//后序遍历
void DestoryBTNode(pBinTree *pRoot);//销毁二叉树
pBinTree CopyBTNode(pBinTree *pRoot);//拷贝二叉树
void PrintBinTree(pBinTree pRoot);//打印二叉树
int GetBinTreeNodeCount(pBinTree pRoot);//获取二叉树结点个数
int GetLeafBTnodCount(pBinTree pRoot);//获取叶子节点的个数
int GetBTNnodeHeight(pBinTree pRoot);//获取二叉树的高度