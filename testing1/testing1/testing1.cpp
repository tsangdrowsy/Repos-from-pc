#include<iostream>
using namespace std;

struct node
{
	int info;
	struct node* left;
	struct node* right;
};

typedef struct node* NODE;
typedef NODE TREE;

void init(TREE& Root)
{
	Root = NULL;
}
void InsertNode(TREE& Root, int x)
{
	NODE p = new node;
	p->info = x;
	p->left = p->right = NULL;
	if (Root == NULL)
	{
		Root = p;
	}
	else
	{
		NODE q = Root;
		NODE f = NULL;
		while (q != NULL)
		{
			f = q;
			if (q->info > x)
				q = q->left;
			else
				q = q->right;
		}
		if (f->info > x)
			f->left = p;
		else
			f->right = p;
	}
}
int DemNode(TREE Root)
{
	if (Root == NULL)
		return 0;
	int a = DemNode(Root->left);
	int b = DemNode(Root->right);
	return a + b + 1;
}

int TongNode(TREE Root)
{
	if (Root == NULL)
		return 0;
	int a = TongNode(Root->left);
	int b = TongNode(Root->right);
	return a + b + Root->info;
}

float trungbingcong(TREE Root)
{
	int s = TongNode(Root);
	int dem = DemNode(Root);
	if (dem == 0)
		return 0;
	return (float)s / dem;
}

int DemDuong(TREE Root)
{
	if (Root == NULL)
		return 0;
	int a = DemDuong(Root->left);
	int b = DemDuong(Root->right);
	if (Root->info > 0)
		return a + b + 1;
	return a + b;
}
int TongDuong(TREE Root)
{
	if (Root == NULL)
		return 0;
	int a = TongDuong(Root->left);
	int b = TongDuong(Root->right);
	if (Root->info > 0)
		return a + b + Root->info;
	return a + b;
}
float TrungBinhDuong(TREE Root)
{
	int s = TongDuong(Root);
	int dem = DemDuong(Root);
	if (dem == 0)
		return 0;
	return (float)s / dem;
}
int DemAm(TREE Root)
{
	if (Root == NULL)
		return 0;
	int a = DemAm(Root->left);
	int b = DemAm(Root->right);
	if (Root->info < 0)
		return a + b + 1;
	return a + b;
}
int TongAm(TREE Root)
{
	if (Root == NULL)
		return 0;
	int a = TongAm(Root->left);
	int b = TongAm(Root->right);
	if (Root->info < 0)
		return a + b + Root->info;
	return a + b;
}
float TrungBinhAm(TREE Root)
{
	int s = TongAm(Root);
	int dem = DemAm(Root);
	if (dem == 0)
		return 0;
	return (float)s / dem;
}
float TinhTySo(TREE Root)
{
	int a = DemDuong(Root);
	int b = DemAm(Root);
	if (b == 0)
		return 0;
	return (float)a / b;
}

void testcase(TREE& Root)
{
	init(Root);
	InsertNode(Root, 5);
	InsertNode(Root, 3);
	InsertNode(Root, 7);
	InsertNode(Root, 2);
	InsertNode(Root, 4);
	InsertNode(Root, 6);
	InsertNode(Root, 8);
	InsertNode(Root, -1);
	InsertNode(Root, 9);
	cout << "Trung binh cong cac node: " << trungbingcong(Root) << endl;
	cout << "Trung binh duong cac node: " << TrungBinhDuong(Root) << endl;
	cout << "Trung binh am cac node: " << TrungBinhAm(Root) << endl;
	cout << "Ty so duong am: " << TinhTySo(Root) << endl;
}
int main()
{
	TREE Root;
	testcase(Root);
	return 0;
}
