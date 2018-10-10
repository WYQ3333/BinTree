#include"BinTree.h"

void test()
{
	char *str = "ABD###CE##F";
	BinTree *pRoot = NULL;
	int index = 0;
	CreatBinTree(&pRoot, str, strlen(str), &index, '#');//创建二叉树
	pBinTree pNewRoot = CopyBTNode(&pRoot);
	printf("先序遍历为：\n");
	PreBTNode(pRoot);
	printf("\n");
	PreBTNode(pNewRoot);
	printf("\n");
	printf("中序遍历为:\n");
	InBTNode(pRoot);
	printf("\n");
	InBTNode(pNewRoot);
	printf("\n");
	printf("二叉树中的结点个数:%d \n", GetBinTreeNodeCount(pRoot));
}

int main()
{

	test();
	system("pause");
	return 0;
}