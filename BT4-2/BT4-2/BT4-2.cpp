#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>/
int main() {
    char s[1001];
    int k;
    printf("Moi ban nhap chuoi s: ");
    scanf("%s", s);
    printf("Moi ban nhap vi tri can xoa: ");
    scanf("%d", &k);
    int len = strlen(s);
    if (k < 0 || k >= len) {
        printf("Vi tri %d khong hop le.\n", k);
        return 1;
    }
    for (int i = k-1; i < len - 1; i++) {
        s[i] = s[i + 1];
    }
    s[len - 1] = '\0';
    printf("Chuoi sau khi xoa ky tu tai vi tri %d: %s\n", k, s);

    return 0;
}