#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    char s[1002];
    int k;
    char c;
    printf("Moi ban nhap chuoi s: ");
    scanf("%s", s);
    printf("Moi ban nhap vi tri can chen: ");
    scanf("%d", &k);
    printf("Moi ban nhap ky tu chen: ");
    scanf(" %c", &c);
    int len = strlen(s);
    if (k < 0 || k > len) {
        printf("Vi tri %d khong hop le.\n", k);
        return 1;
    }
    for (int i = len; i >= k; i--) {
        s[i + 1] = s[i];
    }
    s[k] = c;
    s[len + 1] = '\0';
    printf("Chuoi sau khi them ky tu \"%c\" vao vi tri %d: %s\n", c, k, s);
    return 0;
}
