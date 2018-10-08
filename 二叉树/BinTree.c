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
void CreatBinTree(pBinTree *pRoot, char *str, int size, int *index, KeyType invalid)//创建二叉树
{
	assert(pRoot);
	assert(str);
	if ('#' != str[*index] && (*index) < size)
	{
		*pRoot = BuyNewNode(str[*index]);
		(*index)++;
		CreatBinTree(&(*pRoot)->Lchild, str, size, index, invalid);//创建左子树
		(*index)++;
		CreatBinTree(&(*pRoot)->Rchild, str, size, index, invalid);//创建右子树
	}
}

void PreBTNode(BinTree * pRoot)//先序遍历
{
	if (pRoot != NULL)
	{
		printf("%c ", pRoot->data);
		PreBTNode(pRoot->Lchild);
		PreBTNode(pRoot->Rchild);
	}
}
void InBTNode(BinTree * pRoot)//中序遍历
{
	if (pRoot != NULL)
	{
		printf("%c ", pRoot->data);
		InBTNode(pRoot->Lchild);
		InBTNode(pRoot->Rchild);
	}
}
void PostBTNode(BinTree *pRoot)//后序遍历
{
	if (pRoot != NULL)
	{
		printf("%c ", pRoot->data);
		PostBTNode(pRoot->Lchild);
		PostBTNode(pRoot->Rchild);
	}
}