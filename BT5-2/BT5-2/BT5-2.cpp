#include <stdio.h>
#define MAX 100
#define FO "Data.out"
void NhapMang1C(int a[], int& n)
{
	//Sinh vi�n t? c�i ??t
	printf("Nhap so phan tu mang: ");
	scanf("%d", n);
	for (int i = 0; i <= n; i++)
	{
		printf("Nhap vao phan tu thu %d: ", i);
		scanf("%d", a[i]);
	}
}
void OutputData(int a[], int n)
{
	FILE* fo;
	fi = fopen(FI, "wt");
	if (fo == NULL)
	{
		printf("Khong the tao file");
		return;
	}
	fprintf(fo, "%d\n", n);
	for (int i = 0; i < n; i++)
		fprintf(fo, "%d\n", a[i]);
	fclose(fo);
}
int main()
{
	int a[MAX];
	int n;
	NhapMang1C(a, n);
	OutputData(a, n);
	return 0;
}