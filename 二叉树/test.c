#include"BinTree.h"

void test()
{
	char *str = "ABD###CE##F";
	BinTree *pRoot = NULL;
	int index = 0;
	CreatBinTree(&pRoot, str, strlen(str), &index, '#');//����������
	pBinTree pNewRoot = CopyBTNode(&pRoot);
	printf("�������Ϊ��\n");
	PreBTNode(pRoot);
	printf("\n");
	PreBTNode(pNewRoot);
	printf("\n");
	printf("�������Ϊ:\n");
	InBTNode(pRoot);
	printf("\n");
	InBTNode(pNewRoot);
	printf("\n");
	printf("�������еĽ�����:%d \n", GetBinTreeNodeCount(pRoot));
}

int main()
{

	test();
	system("pause");
	return 0;
}