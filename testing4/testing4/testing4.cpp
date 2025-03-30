#include<iostream>
using namespace std;

typedef struct node
{
	int info;
	struct node* left;
	struct node* right;
}NODE;

typedef NODE* TREE;

void init(TREE& Root)
{
	Root = NULL;
}

void insertNode(TREE& Root, int x)
{
	if (Root == NULL)
	{
		NODE* p = new NODE;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
		Root = p;
	}
	else
	{
		if (Root->info == x)
			return;
		if (Root->info > x)
			insertNode(Root->left, x);
		else
			insertNode(Root->right, x);
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

void testcase(TREE& Root)
{
	init(Root);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		insertNode(Root, x);
	}
	cout << DemNode(Root) << endl;
	cout << TongNode(Root) << endl;
}

int main()
{
	TREE Root;
	testcase(Root);
	return 0;
}