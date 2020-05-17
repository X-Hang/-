#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
void Reverse(char R[], int left, int right)
{
	int k = left, j = right;    //k������߽�left, j �����ұ߽�right
	char tmp;
	while (k < j)     //����R[k]��R[j]
	{
		tmp = R[k];
		R[k] = R[j];
		R[j] = tmp;
		k++;   //k����һ��λ��
		j--;    //j����һ��λ��
	}
}
void LeftShift(char R[], int n, int p)   //ѭ������ p��Ԫ��
{
	if (p > 0 && p < n)
	{
		Reverse(R, 0, n - 1);  //��ȫ����������
		Reverse(R, 0, n - p - 1); //��ǰn-p��Ԫ������
		Reverse(R, n - p, n - 1); //����p��Ԫ������
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