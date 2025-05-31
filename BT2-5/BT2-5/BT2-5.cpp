#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void NhapMang(int a[], int n)
{

	for (int i = 0; i <= n - 1; i++)
	{
		printf("Nhap vao phan tu thu %d: ", i);
		scanf("%d", &a[i]);
	}
}
void SapXep(int a[], int n, int b[],int *k, int c[],int *l)
{
	* k = 0;
	* l = 0;
	for (int i = 0; i <= n - 1; i++)
	{
		if (a[i] % 2 == 0)
		{
			b[(*k)++] = a[i];
		}
		else
		{
			c[(*l)++] = a[i];
		}
	}
}
int main()
{
	int a[100], b[100], c[100];
	int n, k, l;
	printf("Nhap vao so phan tu mang: ");
	scanf("%d", &n);
	NhapMang(a, n);
	SapXep(a, n, b,&k, c,&l);
	printf("Phan tu chan trong mang b:\n");
	for (int i = 0; i < k; i++) {
		printf("%d ", b[i]);
	}
	printf("\n");
	printf("Phan tu le trong mang c:\n");
	for (int i = 0; i < l; i++) {
		printf("%d ", c[i]);
	}
	printf("\n");
	return 0;
}