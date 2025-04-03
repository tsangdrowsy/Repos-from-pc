
#include<stdio.h>
#include<stdlib.h>

void HoanVi(int* a, int* b)
{
	int tmp = (*a);
	(*a) = (*b);
	(*b) = tmp;
}
int main()
{
	int x, y;
	printf("Moi ban nhap du lieu so a: ");
	scanf("%d", &x);
	printf("Moi ban nhap du lieu so b: ");
	scanf("%d", &y);
	printf("Truoc khi hoan vi, a=%d và b=%d\n", x, y);
	HoanVi(&x, &y);
	printf("Sau khi hoan vi, a=%d va b=%d\n", x, y);
	system("PAUSE");
	return 0;

}