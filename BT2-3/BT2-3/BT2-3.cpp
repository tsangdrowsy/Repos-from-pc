#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<ctype.h>

void NhapMang(char a[], int n)
{
	for (int i = 0; i <= n - 1; i++)
	{
		printf("Phan tu %d: ", i);
		scanf(" %c", &a[i]);
	}
}
int locnguyenam(char a[], char b[], int n)
{
	int count = 0;
	for (int i = 0; i <= n - 1; i++)
	{
		char c = tolower(a[i]);
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		{
			b[count] = a[i];
			count++;
		}
	}
	return count;
}
void XuatMang(char b[], int count)
{
	printf("Day b chua cac ky tu nguyen am: ");
	for (int i = 0; i < count; i++)
	{
		printf("%c", b[i]);
	}
	printf("\n");
}
int main()
{
	int n;
	char a[100], b[100];
	printf("Nhap so luong phan tu: ");
	scanf("%d", &n);
	
	if (n > 100)
	{
		printf("Nhap lai!");
			scanf("%d", &n);
	}
	NhapMang(a, n);
	int count = locnguyenam(a, b, n);
	XuatMang(b, count);
	return 0;
}