#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


// 1.1 Queue bằng mảng
typedef struct {
    int* data;
    int front;
    int rear;
    int capacity;
} QueueInt;

void InitQueue(QueueInt* q, int capacity) {
    q->data = (int*)malloc(capacity * sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->capacity = capacity;
}

bool IsEmptyQueue(QueueInt q) {
    return q.front == -1;
}

bool IsFullQueue(QueueInt q) {
    return (q.rear + 1) % q.capacity == q.front;
}

void Enqueue(QueueInt* q, int value) {
    if (IsFullQueue(*q)) {
        printf("Hang doi day!\n");
        return;
    }
    if (IsEmptyQueue(*q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = value;
}

int Dequeue(QueueInt* q) {
    if (IsEmptyQueue(*q)) {
        printf("Hang doi rong!\n");
        return -1;
    }
    int value = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    }
    else {
        q->front = (q->front + 1) % q->capacity;
    }
    return value;
}

int PeekQueue(QueueInt q) {
    if (IsEmptyQueue(q)) {
        printf("Hang doi rong!\n");
        return -1;
    }
    return q.data[q.front];
}

void ClearQueue(QueueInt* q) {
    q->front = q->rear = -1;
}

// 1.2 Queue bằng danh sách liên kết
typedef struct QNode {
    int data;
    struct QNode* next;
} QNode;

typedef struct {
    QNode* front;
    QNode* rear;
} LinkedQueueInt;

void InitLinkedQueue(LinkedQueueInt* q) {
    q->front = q->rear = NULL;
}

bool IsEmptyLinkedQueue(LinkedQueueInt q) {
    return q.front == NULL;
}

void EnqueueLinked(LinkedQueueInt* q, int value) {
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    newNode->data = value;
    newNode->next = NULL;

    if (IsEmptyLinkedQueue(*q)) {
        q->front = q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int DequeueLinked(LinkedQueueInt* q) {
    if (IsEmptyLinkedQueue(*q)) {
        printf("Hang doi rong!\n");
        return -1;
    }
    QNode* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return value;
}

int PeekLinkedQueue(LinkedQueueInt q) {
    if (IsEmptyLinkedQueue(q)) {
        printf("Hang doi rong!\n");
        return -1;
    }
    return q.front->data;
}

void ClearLinkedQueue(LinkedQueueInt* q) {
    while (!IsEmptyLinkedQueue(*q)) {
        DequeueLinked(q);
    }
}



// 2.1 Xếp lịch cặp múa nam/nữ
typedef struct {
    char name[50];
    char gender;
} Dancer;

void ScheduleDancingPairs(Dancer dancers[], int n) {
    LinkedQueueInt maleQueue, femaleQueue;
    InitLinkedQueue(&maleQueue);
    InitLinkedQueue(&femaleQueue);

    for (int i = 0; i < n; i++) {
        if (dancers[i].gender == 'M') {
            EnqueueLinked(&maleQueue, i);
        }
        else {
            EnqueueLinked(&femaleQueue, i);
        }
    }

    printf("Cac cap mua:\n");
    while (!IsEmptyLinkedQueue(maleQueue) && !IsEmptyLinkedQueue(femaleQueue)) {
        int maleIndex = DequeueLinked(&maleQueue);
        int femaleIndex = DequeueLinked(&femaleQueue);
        printf("- %s (Nam) va %s (Nu)\n", dancers[maleIndex].name, dancers[femaleIndex].name);
    }

    // Thông báo về những người chưa có cặp
    if (!IsEmptyLinkedQueue(maleQueue)) {
        printf("\nCac nam vu con lai:\n");
        while (!IsEmptyLinkedQueue(maleQueue)) {
            int index = DequeueLinked(&maleQueue);
            printf("- %s\n", dancers[index].name);
        }
    }

    if (!IsEmptyLinkedQueue(femaleQueue)) {
        printf("\nCac nu vu con lai:\n");
        while (!IsEmptyLinkedQueue(femaleQueue)) {
            int index = DequeueLinked(&femaleQueue);
            printf("- %s\n", dancers[index].name);
        }
    }
}

// 2.2 Thuật toán RadixSort
int GetMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void RadixSort(int arr[], int n) {
    int max = GetMax(arr, n);

    // Tạo 10 hàng đợi cho các chữ số từ 0-9
    QueueInt queues[10];
    for (int i = 0; i < 10; i++) {
        InitQueue(&queues[i], n);
    }

    // Thực hiện sắp xếp theo từng chữ số
    for (int exp = 1; max / exp > 0; exp *= 10) {
        // Phân phối các số vào các hàng đợi
        for (int i = 0; i < n; i++) {
            int digit = (arr[i] / exp) % 10;
            Enqueue(&queues[digit], arr[i]);
        }

        // Thu thập các số từ các hàng đợi
        int index = 0;
        for (int i = 0; i < 10; i++) {
            while (!IsEmptyQueue(queues[i])) {
                arr[index++] = Dequeue(&queues[i]);
            }
        }
    }

    // Giải phóng bộ nhớ
    for (int i = 0; i < 10; i++) {
        free(queues[i].data);
    }
}
 
void test1()
    {
int n;
printf("Nhap so vu cong: ");
scanf("%d", &n);

Dancer* dancers = (Dancer*)malloc(n * sizeof(Dancer));
for (int i = 0; i < n; i++) {
printf("Nhap ten vu cong %d: ", i + 1);
scanf("%s", dancers[i].name);
printf("Nhap gioi tinh (M/F): ");
scanf(" %c", &dancers[i].gender);
}

ScheduleDancingPairs(dancers, n);
free(dancers);
               
}
void test2()
{
 int n;
printf("Nhap so phan tu: ");
scanf("%d", &n);

int* a = (int*)malloc(n * sizeof(int));
printf("Nhap cac phan tu: ");
for (int i = 0; i < n; i++) {
 scanf("%d", &a[i]);
 }

 RadixSort(a, n);

printf("Mang sau khi sap xep:\n");
for (int i = 0; i < n; i++) {
printf("%d ", a[i]);
}
 printf("\n");
free(a);
                
}
int main()
{
test1();
test2();
return 0;
}