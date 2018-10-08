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
		printf("%c ", pRoot->data);
		InBTNode(pRoot->Lchild);
		InBTNode(pRoot->Rchild);
	}
}
void PostBTNode(BinTree *pRoot)//�������
{
	if (pRoot != NULL)
	{
		printf("%c ", pRoot->data);
		PostBTNode(pRoot->Lchild);
		PostBTNode(pRoot->Rchild);
	}
}