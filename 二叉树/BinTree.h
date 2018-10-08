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