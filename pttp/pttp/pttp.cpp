#include<iostream>
#include<stdlib.h>

int main() {
	int n;
	int* p = NULL;

	n = 20;
	p = &n;
	printf("n: Adrr=%X, Val=%d\n", &n, n);
	printf("p: Adrr=%X, Val=%X, ValRef=%d\n", &p, p, *p);
	int* pn = NULL;
	pn = (int*)malloc(sizeof(int));
	(*pn) = 10;
	printf("sizeof(int):%d byte(s)\n", sizeof(int));
	printf("pn: Adrr=%X, Val=%X, ValRef=%d\n", &pn, pn, *pn);
	free(pn);
	return 0;
}

