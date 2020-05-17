#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int IncreaseOrder(int a[], int n) {
	int max = 0;
	int* L;
	L = (int*)malloc(sizeof(int) * n);
	L[0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = i - 1; j >= 0; j--) {
			if (a[j] >= a[i]) {
				if (L[i] < L[j] + 1) {
					L[i] = L[j] + 1;
				}
			}
		}
		if (max < L[i]) {
			max = L[i];
		}
	}
	return max;
}
int mainjgisojgoi() {
	int n;
	int max;
	scanf("%d", &n);
	int* a = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	max = IncreaseOrder(a, n);
	printf("%d", max);
	return 0;
}