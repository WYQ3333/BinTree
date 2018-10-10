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

void CreatBinTree(pBinTree *pB, char *str, int size, int *index, KeyType invalid);//����������
pBinTree BuyNewNode(KeyType data);//�����½��
void PreBTNode(BinTree * pRoot);//�������
void InBTNode(BinTree * pRoot);//�������
void PostBTNode(BinTree *pRoot);//�������
void DestoryBTNode(pBinTree *pRoot);//���ٶ�����
pBinTree CopyBTNode(pBinTree *pRoot);//����������
void PrintBinTree(pBinTree pRoot);//��ӡ������
int GetBinTreeNodeCount(pBinTree pRoot);//��ȡ������������
int GetLeafBTnodCount(pBinTree pRoot);//��ȡҶ�ӽڵ�ĸ���
int GetBTNnodeHeight(pBinTree pRoot);//��ȡ�������ĸ߶�