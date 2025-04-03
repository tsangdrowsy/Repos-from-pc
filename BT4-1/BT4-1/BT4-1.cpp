#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
int sosanh(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}
int main() {
    char s[1001];
    printf("Nhap chuoi s: ");
    scanf("%s", s);
    qsort(s, strlen(s), sizeof(char), sosanh);
    printf("Chuoi sau khi sap xep: %s\n", s);

    return 0;
}