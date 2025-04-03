#include<iostream>
#include<stdlib.h>

void hoanvi(int* a, int* b)
{
    int tmp = (*a);
    (*a) = (*b);
    (*b) = tmp;
}
int main()
{
    int x, y;
    printf("Moi ban nhap so a: ");
    scanf("d", &x);
    printf("Moi ban nhap so b: ");
    scanf("d", &y);

    printf("Truoc khi hoan vi, a=%d va b=%d\n", x, y);
    hoanvi(&x, &y);
    printf("Sau khi hoan vi, a=%d va b=%d\n", x, y);

    system("PAUSE");

    return 0;
}