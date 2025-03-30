#include<iostream>
using namespace std;

typedef struct node
{
	int info;
	struct node* left;
	struct node* right;
}NODE;
typedef NODE* TREE;

int DemMotCon(TREE t)
{
	if (t == NULL)
		return 0;
	if ((t->left && !t->right) || (!t->left && t->right))
		return 1 + DemMotCon(t->left) + DemMotCon(t->right);
	return DemMotCon(t->left) + DemMotCon(t->right);
}

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
	cout << DemMotCon(Root) << endl;
}

int main()
{
	TREE Root;
	testcase(Root);
	return 0;
}