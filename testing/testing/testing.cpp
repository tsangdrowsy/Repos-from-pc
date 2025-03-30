#include<iostream>
using namespace std;

struct node
{
	int info;
	struct node*left;
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
void PrintTree(TREE Root)
{
	if (Root != NULL)
	{
		cout << Root->info << " ";
		PrintTree(Root->left);
		PrintTree(Root->right);
	}
}
void DoiTraiPhai(TREE& Root)  
{
	if (Root == NULL) return; 

	
	NODE temp = Root->left;
	Root->left = Root->right;
	Root->right = temp;

	temp = Root->left->left;
	Root->left->left = Root->left->right;
	Root->left->right = temp;
}
void testcase()
{
	TREE Root;
	init(Root);
	int a[9] = { 10,5,15,3,9,12,18,7,20 };
	cout << "Truoc khi hoan doi:\n";
	for (int i = 0; i < 9; i++) {
		InsertNode(Root, a[i]);
	}
	PrintTree(Root); 
	cout << endl;

	DoiTraiPhai(Root);

	cout << "Sau khi hoan doi (Print theo NLR):\n";
	PrintTree(Root); 
	cout << endl;
}


int main()
{
	testcase();
	return 0;
}