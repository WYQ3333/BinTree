#include"BinTree.h"

pBinTree BuyNewNode(KeyType data)
{
	pBinTree NewNode = (pBinTree)malloc(sizeof(BinTree));
	if (NewNode == NULL)
		return NULL;
	NewNode->data = data;
	NewNode->Lchild = NULL;
	NewNode->Rchild = NULL;
	return NewNode;
}
void CreatBinTree(pBinTree *pRoot, char *str, int size, int *index, KeyType invalid)//����������
{
	assert(pRoot);
	assert(str);
	if ('#' != str[*index] && (*index) < size)
	{
		*pRoot = BuyNewNode(str[*index]);
		(*index)++;
		CreatBinTree(&(*pRoot)->Lchild, str, size, index, invalid);//����������
		(*index)++;
		CreatBinTree(&(*pRoot)->Rchild, str, size, index, invalid);//����������
	}
}

void PreBTNode(BinTree * pRoot)//�������
{
	if (pRoot != NULL)
	{
		printf("%c ", pRoot->data);
		PreBTNode(pRoot->Lchild);
		PreBTNode(pRoot->Rchild);
	}
}
void InBTNode(BinTree * pRoot)//�������
{
	if (pRoot != NULL)
	{
		InBTNode(pRoot->Lchild);
		printf("%c ", pRoot->data);
		InBTNode(pRoot->Rchild);
	}
}
void PostBTNode(BinTree *pRoot)//�������
{
	if (pRoot != NULL)
	{
		PostBTNode(pRoot->Lchild);
		PostBTNode(pRoot->Rchild);
		printf("%c ", pRoot->data);
	}
}

void DestoryBTNode(pBinTree *pRoot)//���ٶ�����
{
	assert(pRoot);
	if (*pRoot)
	{
		DestoryBTNode(&(*pRoot)->Lchild);//����������
		DestoryBTNode(&(*pRoot)->Rchild);//����������
		free(*pRoot);
		*pRoot = NULL;
	}
}

pBinTree CopyBTNode(pBinTree *pRoot)//����������
{
	assert(pRoot != NULL);
	pBinTree NewRoot = BuyNewNode((*pRoot)->data);
	if (NewRoot != NULL)
	{
		if ((*pRoot)->Lchild!=NULL)
			NewRoot->Lchild = CopyBTNode(&(*pRoot)->Lchild);
		if ((*pRoot)->Rchild!=NULL)
			NewRoot->Rchild = CopyBTNode(&(*pRoot)->Rchild);
	}
	return NewRoot;
}

int GetBinTreeNodeCount(pBinTree pRoot)//��ȡ������������
{
	if (pRoot == NULL)
	{
		return 0;
	}
	else
	{
		return GetBinTreeNodeCount(pRoot->Lchild) + GetBinTreeNodeCount(pRoot->Rchild) + 1;
	}
}

int GetLeafBTnodCount(pBinTree pRoot)//��ȡҶ�ӽڵ�ĸ���
{
	if (pRoot == NULL)
	{
		return 0;
	}
	if ((pRoot->Lchild == NULL) && (pRoot->Rchild == NULL))
	{
		return 1;
	}
	return GetLeafBTnodCount(pRoot->Lchild) + GetLeafBTnodCount(pRoot->Rchild);
}