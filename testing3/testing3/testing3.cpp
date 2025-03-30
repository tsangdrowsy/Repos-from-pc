#include<iostream>
using namespace std;

typedef struct node
{
	int info;
	struct node* left;
	struct node* right;
}NODE;

typedef NODE* TREE;

NODE* NhoNhat(TREE Root)
{
	if (Root == NULL)
		return NULL;
	NODE* lc = Root;
	while (lc->left != NULL)
		lc = lc->left;
	return lc;
}

NODE* LonNhat(TREE Root)
{
	if (Root == NULL)
		return NULL;
	NODE* rc = Root;
	while (rc->right != NULL)
		rc = rc->right;
	return rc;
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
	int n;
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		insertNode(Root, x);
	}
	LonNhat(Root);
	NhoNhat(Root);
	cout << LonNhat(Root)->info << " " << NhoNhat(Root)->info << endl;

}

int main()
{
	TREE Root;
	init(Root);
	testcase(Root);
	return 0;
}