#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Bàn phim: giá trị a, b, c
//Trả về: Trả về kêt quẩ delta
//Vd: [1,2,1] ---> 0

void delta(double* a, double* b, double* c,double *x, double *y)
{
	double kq = 0;
	kq = (((*b)*(*b)) - 4 * (*a) * (*c));
	if (kq < 0)
	{
		printf("Phuong trinh vo nghiem\n");
	}
	else if (kq == 0)
	{
		*x = -(*b) / (2 * (*a));
		*y = -(*b) / (2 * (*a));
	}
	else 
	{
		*x = (-(*b) + (sqrt(kq) / 2 * (*a)));
		*y = (-(*b) - (sqrt(kq) / 2 * (*a)));
	}
}
int main()
{
	double a, b, c, x, y;
	printf("Moi ban nhap gia tri a: ");
	scanf("%lf", &a);
	printf("Moi ban nhap gia tri b: ");
	scanf("%lf", &b);
	printf("Moi ban nhap gia tri c: ");
	scanf("%lf", &c);
	delta(&a, &b, &c, &x, &y);
	if (x == y)
	{
		printf("Phuong trinh co nghiem kep: %lf ", x);
	}
	else
	{
		printf("Phuong trinh co 2 nghiem la: x=%f , y=%lf\n", x, y);
	}


	return 0;

}