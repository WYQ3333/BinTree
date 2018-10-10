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
		InBTNode(pRoot->Lchild);
		printf("%c ", pRoot->data);
		InBTNode(pRoot->Rchild);
	}
}
void PostBTNode(BinTree *pRoot)//后序遍历
{
	if (pRoot != NULL)
	{
		PostBTNode(pRoot->Lchild);
		PostBTNode(pRoot->Rchild);
		printf("%c ", pRoot->data);
	}
}

void DestoryBTNode(pBinTree *pRoot)//销毁二叉树
{
	assert(pRoot);
	if (*pRoot)
	{
		DestoryBTNode(&(*pRoot)->Lchild);//销毁左子树
		DestoryBTNode(&(*pRoot)->Rchild);//销毁右子树
		free(*pRoot);
		*pRoot = NULL;
	}
}

pBinTree CopyBTNode(pBinTree *pRoot)//拷贝二叉树
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

int GetBinTreeNodeCount(pBinTree pRoot)//获取二叉树结点个数
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

int GetLeafBTnodCount(pBinTree pRoot)//获取叶子节点的个数
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