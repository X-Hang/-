#include <stdio.h>
#include <stdlib.h>
int nixu(int n, int* a) {
	int i, j;
	int term;
	int count = 0;
	int test;
	for (i = 0; i < n - 1; i++) {
		term = a[i];
		for (j = i + 1; j < n; j++) {
			test = a[j];
			if (term > test) {
				count++;
			}
		}
	}
	return count;
}
int mainfdsklfjdka() {
	int n;
	int count;
	scanf("%d", &n);
	int* a = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	count = nixu(n, a);
	printf("%d", count);
	return 0;
}