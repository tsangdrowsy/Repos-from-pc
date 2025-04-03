#include<stdio.h>
#include<stdlib.h>
	void HoanVi(int a, int b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	int x = 5, y = 10;
	printf("x=%d, y=%d\n", x, y);
	HoanVi(x, y);
	printf("x=%d, y=%d\n", x, y);

	void HoanVi(int& a, int& b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	int x = 5, y = 10;
	printf("x=%d, y=%d\n", x, y);
	HoanVi(x, y);
	printf("x=%d,y=%d\n", x, y);

	void HoanVi(int* a, int* b) {
		int tmp = (*a);
		(*a) = (*b);
		(*b) = tmp;
	}
	int x = 5, y = 10;
	printf("x=%d, y=%d\n", x, y);
	HoanVi(&x, &y);
	printf("x=%d,y=%d\n", x, y);
	int x = 5;
	int y = &x;

	printf("x:Adrr=%X, Val=%d", &x, x);
	printf("y:Adrr=%Y, Val=%d", &x, y);


