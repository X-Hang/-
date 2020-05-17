#include <stdio.h>
#include <stdlib.h>
#define CARDPATH   "d:\\data.txt"
//把一个数的各个位拆分开放在数组number里
void NumberToArray(int number[20], int num, int n) {
	int term;
	for (int i = n - 1; i >= 0; i--)
	{
		term = num % 10;
		num /= 10;
		number[i] = term;
	}
	return;
}
//求第p到q位整数所代表的数值
int countnumber(int p, int q, int* number)
{
	int newnumber = 0;
	for (int a = p; a <= q; a++)
	{
		newnumber = newnumber * 10 + number[a];
	}
	return newnumber;
}
int main() {
	//从文件中取出变量
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
	int n, p;
	fscanf(fp, "%d %d", &n, &p);
	int num;
	fscanf(fp, "%d", &num);
	int number[10];//存储数组的各个位
	int product[10][10];//product[p][q]存储前p位整数被划分为q段所得到的最大乘积
	NumberToArray(number, num, n);
	for (int i = 0; i < n; i++)//对product初始化第一行
	{
		product[0][i] = countnumber(0, i, number);
	}
	for (int i = 1; i < p; i++) {
		for (int j = 0; j < n; j++) {
			if (i > j)
			{
				product[i][j] = 0;
			}
			else
			{
				int max = 0;
				int temp = 0;
				for (int k = j - 1; k >= 0; k--) {
					int count = countnumber(k + 1, j, number);
					temp = count * product[i - 1][k];
					if (max < temp)
					{
						max = temp;
					}
				}
				product[i][j] = max;
			}
		}
	}
	int result = product[p - 1][n - 1];
	fprintf(fp2, "%d", result);
	fclose(fp2);
	fclose(fp);
	return 0;
}