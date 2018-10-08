#include"BinTree.h"

void test()
{
	char *str = "ABD###CE##F";
	BinTree *pRoot = NULL;
	int index = 0;
	CreatBinTree(&pRoot, str, strlen(str), &index, '#');//´´½¨¶þ²æÊ÷

}

int main()
{

	test();
	system("pause");
	return 0;
}