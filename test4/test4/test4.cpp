#include<iostream>
#include<cstring>
using namespace std;

typedef struct sinhvien
{
    char HoTen[50];
    char diaChi[70];
    char lop[10];
    int khoa;
};

typedef struct node
{
    sinhvien info;
    struct node* next;
} Node;

Node* pHead = NULL;

bool isEmpty(Node* pHead)
{
    return (pHead == NULL);
}

void init(Node*& pHead)
{
    pHead = NULL;
}

Node* createNode(const sinhvien& sv)
{
    Node* p = new Node;
    p->info = sv;
    p->next = NULL;
    return p;
}

void showlist(Node* pHead)
{
    if (pHead == NULL)
        cout << "Danh sach rong" << endl;
    else
    {
        for (Node* p = pHead; p != NULL; p = p->next)
        {
            cout << "Ho ten: " << p->info.HoTen << endl;
            cout << "Dia chi: " << p->info.diaChi << endl;
            cout << "Lop: " << p->info.lop << endl;
            cout << "Khoa: " << p->info.khoa << endl;
        }
    }
}

void insertFirst(Node*& pHead, const sinhvien& sv)
{
    Node* p = createNode(sv);
    p->next = pHead;
    pHead = p;
}

void insertAfter(Node*& p, const sinhvien& sv)
{
    Node* q = createNode(sv);
    q->next = p->next;
    p->next = q;
}

node* find(Node* pHead, const char* Hoten)
{
    for (Node* p = pHead; p != NULL; p = p->next)
    {
        if (strcmp(p->info.HoTen, Hoten) == 0)
            return p;
    }
    return NULL;
}

void insertOrder(Node*& pHead, const sinhvien& sv)
{
    Node* p = createNode(sv);
    if (pHead == NULL)
        pHead = p;
    else
    {
        Node* q = pHead;
        Node* r = NULL;
        while (q != NULL && strcmp(q->info.HoTen, sv.HoTen) < 0)
        {
            r = q;
            q = q->next;
        }
        if (r == NULL)
        {
            p->next = pHead;
            pHead = p;
        }
        else
        {
            p->next = q;
            r->next = p;
        }
    }
}


int sosanhHoten(const sinhvien& Hoten1, const sinhvien& Hoten2)
{
    return strcmp(Hoten1.HoTen, Hoten2.HoTen);
}

int sosanhdiaChi(const sinhvien& diaChi1, const sinhvien& diaChi2) {
    return strcmp(diaChi1.diaChi, diaChi2.diaChi);
}

int sosanhlop(const sinhvien& lop1, const sinhvien& lop2) {
    return strcmp(lop1.lop, lop2.lop);
}

int sosanhkhoa(const sinhvien& khoa1, const sinhvien& khoa2) {
    return khoa1.khoa - khoa2.khoa;
}

void xoatheoHoTen(Node*& pHead, const char* Hoten)
{
    Node* p = pHead;
    Node* q = NULL;
    while (p != NULL && strcmp(p->info.HoTen, Hoten) != 0)
    {
        q = p;
        p = p->next;
    }
    if (p != NULL)
    {
        if (q != NULL)
            q->next = p->next;
        else pHead = p->next;
        delete p;
    }
}

void xoatheodiaChi(Node*& pHead, const char* diaChi)
{
    Node* p = pHead;
    Node* q = NULL;
    while (p != NULL && strcmp(p->info.diaChi, diaChi) != 0)
    {
        q = p;
        p = p->next;
    }
    if (p != NULL)
    {
        if (q != NULL)
            q->next = p->next;
        else pHead = p->next;
        delete p;
    }
}

void SelectionSort(Node*& pHead, int(*sosanh)(const sinhvien&, const sinhvien&))
{
    if (pHead == NULL) return;

    node* p, * q, * pmin;
    sinhvien vmin;

    for (p = pHead; p->next != NULL; p = p->next)
    {
        pmin = p;
        vmin = p->info;
        for (q = p->next; q != NULL; q = q->next)
        {
            if (sosanh(q->info, vmin) < 0)
            {
                pmin = q;
                vmin = q->info;
            }
        }
        if (pmin != p)
        {
            sinhvien temp = p->info;
            p->info = pmin->info;
            pmin->info = temp;
        }
    }
}

void test1()
{
    init(pHead);

    
    for (int i = 0; i < 10; i++)
    {
        sinhvien sv;
        cout << "Nhap Thong Tin Sinh Vien " << i + 1 << endl;
        cout << "Ho Ten: ";
        cin.getline(sv.HoTen, 50);
        cout << "Dia Chi: ";
        cin.getline(sv.diaChi, 70);
        cout << "Lop: ";
        cin.getline(sv.lop, 10);
        cout << "Khoa: ";
        while (!(cin >> sv.khoa)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Nhap lai Khoa (phai la so nguyen): ";
        }
        cin.ignore();
        insertOrder(pHead, sv);
    }

    
    cout << "\nDanh sach sinh vien sau khi nhap:\n" << endl;
    showlist(pHead);

    xoatheoHoTen(pHead, "Nguyen Van Teo");
    cout << "\nDanh sach sinh vien sau khi xoa 'Nguyen Van Teo':\n" << endl;
    showlist(pHead);

   
    xoatheodiaChi(pHead, "Nguyen Van Cu");
    cout << "\nDanh sach sinh vien sau khi xoa 'Nguyen Van Cu':\n" << endl;
    showlist(pHead);

  
    sinhvien svMoi = { "Tran Thi Mo", "25 Hong Bang", "TT0901", 2009 };
    insertOrder(pHead, svMoi);
    cout << "\nDanh sach sinh vien sau khi them 'Tran Thi Mo':\n" << endl;
    showlist(pHead);

    
    SelectionSort(pHead, sosanhHoten);
    cout << "\nDanh sach sinh vien sau khi sap xep theo ho ten:\n" << endl;
    showlist(pHead);

    
}

int main()
{
    test1();
    return 0;
}