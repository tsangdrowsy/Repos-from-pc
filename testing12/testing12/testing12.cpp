#include <iostream>
using namespace std;

typedef struct node {
	int info;
	struct node* left;
	struct node* right;
}Node;

typedef Node* Tree;

void init(Tree& t) {
	t = NULL;
}

Node* createNode(int x) {
	Node* p = new Node;
	if (!p) {
		exit(1);
	}
	p->info = x;
	p->left = p->right = NULL;
	return p;
}

Node* LonNhat(Tree t)
{
	if (t == NULL) {
		return NULL;
	}
	Node* lc = t;
	Node* a = LonNhat(t->left);
	if (a && a->info > lc->info)
	{
		lc = a;
	}
	Node* b = LonNhat(t->right);
	if (b && b->info > lc->info)
	{
		lc = b;
	}
	return lc;
}

Node* NhoNhat(Tree t)
{
	if (t == NULL) {
		return NULL;
	}
	Node* lc = t;
	Node* a = NhoNhat(t->left);
	if (a && a->info < lc->info)
	{
		lc = a;
	}
	Node* b = NhoNhat(t->right);
	if (b && b->info < lc->info)
	{
		lc = b;
	}
	return lc;
}

int ChieuCao(Tree t)
{
	if (t == NULL)
	{
		return 0;
	}
	int a = ChieuCao(t->left);
	int b = ChieuCao(t->right);
	if (a > b)
	{
		return a + 1;
	}
	return b + 1;
}

int ktCanBang(Tree t)
{
	if (t == NULL)
	{
		return 1;
	}
	if (ktCanBang(t->left) == 0)
	{
		return 0;
	}
	if (ktCanBang(t->right) == 0)
	{
		return 0;
	}
	Node* a = LonNhat(t->left);
	if (a && a->info > t->info)
	{
		return 0;
	}
	a = NhoNhat(t->right);
	if (a && a->info < t->info)
	{
		return 0;
	}
	int x = ChieuCao(t->left);
	int y = ChieuCao(t->right);
	if (abs(x - y) > 1)
	{
		return 0;
	}
	return 1;
}

void insertNode(Tree& t, int x) {
	Node* p = createNode(x);
	if (t == NULL) {
		t = p;
	}
	else {
		Node* f = NULL;
		Node* q = t;
		while (q != NULL) {
			f = q;
			if (q->info == x) {
				return;
			}
			else if (q->info > x) {
				q = q->left;
			}
			else {
				q = q->right;
			}
		}
		if (f->info > x) {
			f->left = p;
		}
		else {
			f->right = p;
		}
	}
}

void xuat(Tree t) {
	if (t != NULL) {
		cout << t->info << " ";
		xuat(t->left);
		xuat(t->right);
	}
}

void test()
{
	Tree t;
	init(t);
	insertNode(t, 5);
	insertNode(t, 1);
	insertNode(t, 3);
	insertNode(t, 7);

	ktCanBang(t);
	xuat(t);
	cout << "\nCay co can bang khong? " << (ktCanBang(t) ? "Co" : "Khong") << endl;
}

int main() {
	test();
	return 0;
}