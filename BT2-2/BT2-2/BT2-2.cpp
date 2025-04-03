#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n, a[100];
	printf("Nhap so luong phan tu: ");
	scanf("%d", &n);
	for (int i = 0; i <= n - 1; i++)
	{
		printf("Nhap vao phan tu thu %d:", i);
		scanf("%d", &a[i]);
	}
	int chanle = 1;
	for (int i = 0; i <= n - 1; i++)
	{
		if ((a[i] % 2) == (a[i + 1] % 2))
		{
			chanle = 0;
			break;
		}
	}
	int toanchan = 1;
	for (int i = 0; i <= n - 1; i++)
	{
		if (a[i] % 2 != 0)
		{
			toanchan = 0;
			break;
		}
	}
	for (int i = 0; i <= n - 1; i++)
	{
		printf("%d\n", a[i]);
	}
	printf("%s\n", chanle ? "Day co tinh chan le" : "Day khong co tinh chan le");
	printf("%s\n", toanchan ? "Day co tinh toan chan" : "Day khong co tinh toan chan");
	return 0;
}