#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void NhapMang(float a[], char z, int n)
{
	printf("Nhap cac phan tu cua day %c: ",z);

	for (int i = 0; i <= n - 1; i++)
	{
		printf("Phan tu thu %d: ",i);
		scanf("%f", &a[i]);
	}
}
void TronMang(float a[], int n, float b[], int m, float c[], int* k)
{
	int i = 0; int j = 0;
	*k = 0;
	while (i < n && j < m)
	{
		if (a[i] <= b[j])
		{
			c[(*k)++] = a[i++];
		}
		else
		{
			c[(*k)++] = b[j++];
		}
	}
	while (i < n) 
	{
		c[(*k)++] = a[i++];
	}
	while (j < m) 
	{
		c[(*k)++] = b[j++];
	}
}
void XuatMang(float c[], int n, char z)
{
	printf("Day %c co sau khi tron la: \n", z);
	for (int i = 0; i <= n-1; i++)
	{
		printf("%.f ; ", c[i]);

	}
	printf("\n");
}
int main()
{
	int n, m;
	float a[100], b[100], c[200];
	printf("Nhap kich co mang a: ");
	scanf("%d", &n);
	printf("Nhap kich co mang b: ");
	scanf("%d", &m);
	NhapMang(a, 'a', n);
	NhapMang(b, 'b', m);
	int k;
	TronMang(a, n, b, m, c, &k);
	XuatMang(c, k, 'c');
	return 0;
}