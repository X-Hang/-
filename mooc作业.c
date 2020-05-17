#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
void Reverse(char R[], int left, int right)
{
	int k = left, j = right;    //k等于左边界left, j 等于右边界right
	char tmp;
	while (k < j)     //交换R[k]与R[j]
	{
		tmp = R[k];
		R[k] = R[j];
		R[j] = tmp;
		k++;   //k右移一个位置
		j--;    //j左移一个位置
	}
}
void LeftShift(char R[], int n, int p)   //循环左移 p个元素
{
	if (p > 0 && p < n)
	{
		Reverse(R, 0, n - 1);  //将全部数据逆置
		Reverse(R, 0, n - p - 1); //将前n-p个元素逆置
		Reverse(R, n - p, n - 1); //将后p个元素逆置
	}
}

int mainfdsaeafjio() {
	int n, p;
	scanf("%d", &n);
	char* a = (char*)malloc(n * sizeof(char));
	scanf("%d", &p);
	/*for (int i = 0; i < n; i++)
	{
		scanf(" %c", &a[i]);
	}*/
	scanf("%s", a);
	LeftShift(a, n, p);
	for (int i = 0; i < n; i++) {
		printf("%c", a[i]);
	}
	return 0;
}