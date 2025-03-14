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

Node* createNode(const sinhvien &sv)
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
			cout << "Khoa " << p->info.khoa << endl;
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

node* find(Node* pHead, char* Hoten)
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

void clearList(Node*& pHead)
{
	Node* p;
	while (pHead != NULL)
	{
		p = pHead;
		pHead = pHead->next;
		delete p;
	}
}

int sosanhHoten(const sinhvien& Hoten1, const sinhvien& Hoten2){
return strcmp(Hoten1.HoTen, Hoten2.HoTen);
}

void SelectionSort(Node*& pHead, int(*sosanh)(const sinhvien&, const sinhvien&))
{
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

		for (int i = 0;i < 10; i++)
		{
			sinhvien sv;
			cout << "Nhap Thong Tin Sinh Vien" << i + 1 << endl;
			cout << "Ho Ten: ";
			cin.getline(sv.HoTen, 50);
			cout << "Dia Chi: ";
			cin.getline(sv.diaChi, 70);
			cout << "Lop: ";
			cin.getline(sv.lop, 10);
			cout << "Khoa ";
			cin >> sv.khoa;
			cin.ignore();
			insertOrder(pHead, sv);
		}
		cout << "\nDanh sach sinh vien sau khi nhap:\n" << endl;
		showlist(pHead);
		SelectionSort(pHead, sosanhHoten);
		cout << "\nDanh sach sinh vien sau khi sap xep:\n" << endl;
		showlist(pHead);
		clearList(pHead);
		
	}
	int main()
	{
		test1();
		return 0;
	}