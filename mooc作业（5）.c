#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int  CommonOrder(char x[], int m, char y[], int n, char z[]) {
	int i, j, k;
	int** L;
	L = (int**)malloc(sizeof(int*) * (m + 1));//动态分配二维数组的内存
	for (i = 0; i < m + 1; i++) {
		L[i] = (int*)malloc((n + 1) * sizeof(int));
	}
	int** S;
	S = (int**)malloc(sizeof(int*) * (m + 1));//动态分配二维数组的内存
	for (i = 0; i < m + 1; i++) {
		S[i] = (int*)malloc((n + 1) * sizeof(int));
	}
	for (j = 0; j <= n; j++) {//初始化第0行
		L[0][j] = 0;
	}
	for (i = 0; i <= m; i++) {//初始化第0列
		L[i][0] = 0;
	}
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			if (x[i - 1] == y[j - 1]) {
				L[i][j] = L[i - 1][j - 1] + 1;
				S[i][j] = 1;
			}
			else
			{
				if (L[i][j - 1] >= L[i - 1][j]) {
					L[i][j] = L[i][j - 1];
					S[i][j] = 2;
				}
				else
				{
					L[i][j] = L[i - 1][j];
					S[i][j] = 3;
				}
			}
		}
	}
	i = m; j = n;
	k = L[m][n];
	int term = k;
	while (i >= 0 && j >= 0)
	{
		if (S[i][j] == 1) {
			z[k - 1] = x[i - 1];
			k--;
			i--;
			j--;
		}
		else
		{
			if (S[i][j] == 2)
			{
				j--;
			}
			else
			{
				i--;
			}
		}
	}
	return term;
}
int mainds() {
	char x[100];
	char y[100];
	scanf("%s %s", x, y);
	char z[100] = { 0 };
	int m = strlen(x);
	int n = strlen(y);
	int k = CommonOrder(x, m, y, n, z);
	printf("%s", x);
	for (int j = 0; j < n; j++) {
		int term = 0;
		for (int i = 0; i < k; i++)
		{
			char tempz = z[i];
			char tempy = y[j];
			if (y[j] == z[i]) {
				term = 1;
				break;
			}
		}
		if (term == 0) {
			printf("%c", y[j]);
		}
	}
	return 0;
}