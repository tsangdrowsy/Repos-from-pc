#include <iostream>
using namespace std;

typedef struct node {
    int info;
    struct node* next;
} Node;

Node* pHead = NULL;

// Hàm khởi tạo danh sách
void Init(Node*& pHead) {
    pHead = NULL;
}

// Hàm kiểm tra danh sách rỗng
bool isEmpty(Node* pHead) {
    return (pHead == NULL);
}

// Hàm tạo một node mới
Node* createNode(int x) {
    Node* p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}

// Hàm hiển thị danh sách
void ShowList(Node* pHead) {
    if (pHead == NULL)
        cout << "Danh sach rong \n";
    else {
        Node* p = pHead;
        while (p != NULL) {
            cout << p->info << " ";
            p = p->next;
        }
        cout << endl;
    }
}

// Hàm thêm phần tử vào đầu danh sách
void InsertFirst(Node*& pHead, int x) {
    Node* p = createNode(x);
    p->next = pHead;
    pHead = p;
}

// Hàm thêm phần tử vào sau một node
void InsertAfter(Node*& p, int x) {
    Node* q = createNode(x);
    q->next = p->next;
    p->next = q;
}

// Hàm thêm phần tử vào danh sách theo thứ tự tăng dần
void InsertOrder(Node*& pHead, int x) {
    Node* q = createNode(x);
    if (isEmpty(pHead) || x < pHead->info) {
        InsertFirst(pHead, x);
    }
    else {
        Node* p = pHead;
        while (p->next != NULL && p->next->info < x) {
            p = p->next;
        }
        InsertAfter(p, x);
    }
}

// Hàm xóa phần tử đầu tiên của danh sách
void DeleteFirst(Node*& pHead) {
    if (!isEmpty(pHead)) {
        Node* p = pHead;
        pHead = pHead->next;
        delete p;
    }
}

// Hàm xóa phần tử sau một node
void DeleteAfter(Node*& p) {
    if (p != NULL && p->next != NULL) {
        Node* q = p->next;
        p->next = q->next;
        delete q;
    }
}

// Hàm xóa phần tử có giá trị x
Node* DeleteX(Node*& pHead, int x) {
    Node* q = NULL;
    if (!isEmpty(pHead)) {
        if (pHead->info == x) {
            q = pHead;
            pHead = pHead->next;
        }
        else {
            Node* p = pHead;
            while (p->next != NULL && p->next->info != x) {
                p = p->next;
            }
            if (p->next != NULL) {
                q = p->next;
                p->next = q->next;
            }
        }
    }
    return q;
}

// Hàm xóa phần tử có giá trị x trong danh sách có thứ tự
Node* RemoveOrder(Node*& pHead, int x) {
    Node* q = NULL;
    if (!isEmpty(pHead)) {
        if (pHead->info == x) {
            q = pHead;
            pHead = pHead->next;
        }
        else {
            Node* p = pHead;
            while (p->next != NULL && p->next->info < x) {
                p = p->next;
            }
            if (p->next != NULL && p->next->info == x) {
                q = p->next;
                p->next = q->next;
            }
        }
    }
    return q;
}

// Hàm thêm một danh sách vào cuối danh sách hiện tại
void AddList(Node*& pHead1, Node* pHead2) {
    if (pHead1 == NULL) {
        pHead1 = pHead2;
    }
    else {
        Node* p = pHead1;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = pHead2;
    }
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;

    
    cout << "Nhap 10 so nguyen vao danh sach thu nhat:\n";
    for (int i = 0; i < 10; i++) {
        int value;
        cout << "Nhap so thu " << i + 1 << ": ";
        cin >> value;
        InsertOrder(list1, value);
    }

    cout << "Danh sach thu nhat: ";
    ShowList(list1);

   
    int k;
    cout << "Nhap so k can xoa: ";
    cin >> k;
    DeleteX(list1, k);

    // In danh sách sau khi xóa
    cout << "Danh sach sau khi xoa " << k << ": ";
    ShowList(list1);

    // Nhập 5 số nguyên vào danh sách thứ hai
    cout << "Nhap 5 so nguyen vao danh sach thu hai:\n";
    for (int i = 0; i < 5; i++) {
        int value;
        cout << "Nhap so thu " << i + 1 << ": ";
        cin >> value;
        InsertOrder(list2, value);
    }

    // Thêm danh sách thứ hai vào danh sách thứ nhất
    AddList(list1, list2);

    // In danh sách thứ nhất sau khi thêm
    cout << "Danh sach thu nhat sau khi them danh sach thu hai: ";
    ShowList(list1);

    return 0;
}