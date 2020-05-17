#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int  CommonOrder(int m, int n) {
	int i, j, k;
	int** L;
	L = (int**)malloc(sizeof(int*) * (m + 1));//动态分配二维数组的内存
	for (i = 0; i < m + 1; i++) {
		L[i] = (int*)malloc((n + 1) * sizeof(int));
	}
	//int** S;
	//S = (int**)malloc(sizeof(int*) * (m + 1));//动态分配二维数组的内存
	//for (i = 0; i < m + 1; i++) {
	//	S[i] = (int*)malloc((n + 1) * sizeof(int));
	//}
	L[0][0] = 0;
	for (j = 1; j <= n; j++) {//初始化第0行
		L[0][j] = 1;
	}
	for (i = 1; i <= m; i++) {//初始化第0列
		L[i][0] = 1;
	}
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			L[i][j] = L[i - 1][j] + L[i][j - 1];
		}
	}
	return L[m][n];
}
int mainfdsafdas() {
	int m, n;
	int roads;
	scanf(("%d %d"), &m, &n);
	roads = CommonOrder(m - 1, n - 1);
	printf("%d", roads);
	return 0;
}