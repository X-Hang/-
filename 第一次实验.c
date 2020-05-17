#include <stdio.h>
#include <stdlib.h>
#define CARDPATH   "d:\\data.txt"

int judge(int n) {
	if (n % 2 == 0) {
		return 0;
	}
	else
	{
		return 1;
	}
}
float find_middle(int n, float a[], float b[]) {
	if (n == 1) {
		return (a[0] + b[0]) / 2;
	}
	float amiddle, bmiddle;
	//求出对应的中位数
	if (judge(n)) {
		amiddle = a[((n + 1) / 2) - 1];
		bmiddle = b[(n + 1) / 2 - 1];
	}
	else
	{
		amiddle = (a[n / 2 - 1] + a[n / 2]) / 2;
		bmiddle = (b[n / 2 - 1] + b[n / 2]) / 2;
	}
	//求出对应中位数
	if (amiddle > bmiddle) {
		b = b + n / 2;
		return find_middle((n + 1) / 2, a, b);
	}
	else
	{
		a = a + n / 2;
		return find_middle((n + 1) / 2, a, b);
	}
}
int mainedg() {
	FILE* fp = NULL;
	FILE* fp2 = NULL;
	if ((fp = fopen(CARDPATH, "r")) == NULL)
	{
		printf("文件打开失败");
	}
	if ((fp2 = fopen("d:\\result.txt", "w")) == NULL)
	{
		printf("文件打开失败");
	}
	int n;
	fscanf(fp, "%d", &n);
	float a[5], b[5];
	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%f", &a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%f", &b[i]);
	}
	float result;
	result = find_middle(5, a, b);
	fprintf(fp2, "%f", result);
	fclose(fp2);
	fclose(fp);
	return 0;
}