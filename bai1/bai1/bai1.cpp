#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


// 1.1 Stack b?ng m?ng
typedef struct {
    int* data;
    int top;
    int capacity;
} StackInt;

void InitStack(StackInt* s, int capacity) {
    s->data = (int*)malloc(capacity * sizeof(int));
    s->top = -1;
    s->capacity = capacity;
}

int IsEmpty(StackInt s) {
    return s.top == -1;
}

int IsFull(StackInt s) {
    return s.top == s.capacity - 1;
}

void PushStack(StackInt* s, int value) {
    if (IsFull(*s)) {
        printf("Stack da day! Khong the them %d\n", value);
        return;
    }
    s->data[++s->top] = value;
}

int PopStack(StackInt* s) {
    if (IsEmpty(*s)) {
        printf("Stack rong!\n");
        return -1;
    }
    return s->data[s->top--];
}

int PeekStack(StackInt s) {
    if (IsEmpty(s)) {
        printf("Stack rong!\n");
        return -1;
    }
    return s.data[s.top];
}

void ClearStack(StackInt* s) {
    s->top = -1;
}
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} LinkedStackInt;

void InitLinkedStack(LinkedStackInt* s) {
    s->top = NULL;
}

int IsEmptyLinked(LinkedStackInt s) {
    return s.top == NULL;
}

void PushLinkedStack(LinkedStackInt* s, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

int PopLinkedStack(LinkedStackInt* s) {
    if (IsEmptyLinked(*s)) {
        printf("Stack rong!\n");
        return -1;
    }
    Node* temp = s->top;
    int value = temp->data;
    s->top = s->top->next;
    free(temp);
    return value;
}

int PeekLinkedStack(LinkedStackInt s) {
    if (IsEmptyLinked(s)) {
        printf("Stack rong!\n");
        return -1;
    }
    return s.top->data;
}

void ClearLinkedStack(LinkedStackInt* s) {
    while (!IsEmptyLinked(*s)) {
        PopLinkedStack(s);
    }
}

// 2.1 ??o ng??c s? dùng stack
int DaoNguocSo(int num) {
    StackInt s;
    InitStack(&s, 20); // Gi? s? s? có t?i ?a 20 ch? s?

    int isAm = num < 0;
    num = abs(num);

    while (num > 0) {
        PushStack(&s, num % 10);
        num /= 10;
    }

    int result = 0;
    int mu = 1;

    while (!IsEmpty(s)) {
        result += PopStack(&s) * mu;
        mu *= 10;
    }

    return isAm ? -result : result;
}

// 2.2 Ki?m tra xâu ??i x?ng
typedef struct {
    char* data;
    int top;
    int capacity;
} StackChar;

void InitStackChar(StackChar* s, int capacity) {
    s->data = (char*)malloc(capacity * sizeof(char));
    s->top = -1;
    s->capacity = capacity;
}

void PushStackChar(StackChar* s, char c) {
    if (s->top == s->capacity - 1) return;
    s->data[++s->top] = c;
}

char PopStackChar(StackChar* s) {
    if (s->top == -1) return '\0';
    return s->data[s->top--];
}

char PeekStackChar(StackChar s) {
    if (s.top == -1) return '\0';
    return s.data[s.top];
}

int KiemTraDoiXung(const char* str) {
    StackChar s;
    int len = strlen(str);
    InitStackChar(&s, len);

    // ??y n?a ??u vào stack
    for (int i = 0; i < len / 2; i++) {
        PushStackChar(&s, str[i]);
    }

    // So sánh v?i n?a sau
    int start = (len % 2 == 0) ? len / 2 : len / 2 + 1;
    for (int i = start; i < len; i++) {
        if (PopStackChar(&s) != str[i]) {
            return 0;
        }
    }
    return 1;
}

// 2.3 ??i s? th?p phân sang nh? phân
void DecToBin(int n, char* result) {
    StackInt s;
    InitStack(&s, 32); // ?? cho s? 32-bit

    if (n == 0) {
        strcpy(result, "0");
        return;
    }

    while (n > 0) {
        PushStack(&s, n % 2);
        n /= 2;
    }

    int i = 0;
    while (!IsEmpty(s)) {
        result[i++] = PopStack(&s) + '0';
    }
    result[i] = '\0';
}

// 2.4 Chuy?n sang h?u t? và tính giá tr?
int DoUuTien(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void InfixToPostfix(const char* infix, char* postfix) {
    StackChar s;
    int len = strlen(infix);
    InitStackChar(&s, len);

    int j = 0;
    for (int i = 0; i < len; i++) {
        char c = infix[i];
        if (isalnum(c)) {
            postfix[j++] = c;
        }
        else if (c == '(') {
            PushStackChar(&s, c);
        }
        else if (c == ')') {
            while (s.top != -1 && PeekStackChar(s) != '(') {
                postfix[j++] = PopStackChar(&s);
            }
            PopStackChar(&s); 
        }
        else {
            while (s.top != -1 && DoUuTien(c) <= DoUuTien(PeekStackChar(s))) {
                postfix[j++] = PopStackChar(&s);
            }
            PushStackChar(&s, c);
        }
    }

    while (s.top != -1) {
        postfix[j++] = PopStackChar(&s);
    }
    postfix[j] = '\0';
}

int TinhHauTo(const char* postfix) {
    StackInt s;
    int len = strlen(postfix);
    InitStack(&s, len);

    for (int i = 0; i < len; i++) {
        char c = postfix[i];
        if (isdigit(c)) {
            PushStack(&s, c - '0');
        }
        else {
            int b = PopStack(&s);
            int a = PopStack(&s);
            switch (c) {
            case '+': PushStack(&s, a + b); break;
            case '-': PushStack(&s, a - b); break;
            case '*': PushStack(&s, a * b); break;
            case '/': PushStack(&s, a / b); break;
            case '^': PushStack(&s, (int)pow(a, b)); break;
            }
        }
    }

    return PopStack(&s);
}
void test1()
{
    // Test hàm ??o ng??c s?
    printf("Ket qua dao nguoc so 12345: %d\n", DaoNguocSo(12345));
    printf("Ket qua dao nguoc so -12345: %d\n", DaoNguocSo(-12345));
    printf("\n");
    // Test hàm ki?m tra xâu ??i x?ng
    printf("Ket qua kiem tra xau ABBA: %d\n", KiemTraDoiXung("ABBA"));
    //Test hàm chuy?n s? th?p phân sang nh? phân
    char result[100];
    DecToBin(10, result);
    printf("Ket qua chuyen so 10 sang nhi phan: %s\n", result);
    //Test hàm chuy?n bi?u th?c trung t? sang h?u t? và tính giá tr?
    char postfix[100];
    InfixToPostfix("3+4*2/(1-5)^2", postfix);
    printf("Bieu thuc hau to: %s\n", postfix);
    printf("Gia tri cua bieu thuc: %d\n", TinhHauTo(postfix));
}

int main()
{
	test1();
	return 0;
}