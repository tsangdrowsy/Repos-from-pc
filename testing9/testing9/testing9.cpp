#include<iostream>
using namespace std;

struct BST_NODE
{
	int Key;
	int So_lan;
	struct BST_NODE* Left, * Right;

};

struct BST_TREE
{
	BST_NODE* pRoot;
};

struct BST_TREE t;

int deleteNode(BST_NODE*& root, int x) {
	if (root == NULL) return 0;

	if (x < root->Key) {
		return deleteNode(root->Left, x);
	}
	else if (x > root->Key) {
		return deleteNode(root->Right, x);
	}
	else {
		if (root->So_lan > 1) {
			root->So_lan--;
			return 1;
		}

		
		if (root->Left == NULL) {
			BST_NODE* temp = root->Right;
			delete root;
			root = temp;
		}
		else if (root->Right == NULL) {
			BST_NODE* temp = root->Left;
			delete root;
			root = temp;
		}
		else {
			
			BST_NODE* temp = root->Right;
			while (temp->Left != NULL) {
				temp = temp->Left;
			}
			root->Key = temp->Key;
			root->So_lan = temp->So_lan;
		
			deleteNode(root->Right, temp->Key);
		}
		return 1;
	}
}
void insertNode(BST_NODE*& root, int x) {
	if (root == NULL) {
		root = new BST_NODE;
		root->Key = x;
		root->So_lan = 1;
		root->Left = root->Right = NULL;
	}
	else if (x == root->Key) {
		root->So_lan++;
	}
	else if (x < root->Key) {
		insertNode(root->Left, x);
	}
	else {
		insertNode(root->Right, x);
	}
}
void XoaGiaTri(struct BST_TREE& t, int x)
{
	if (deleteNode(t.pRoot, x) == 0)
	{
		cout << "Khong tim thay gia tri can xoa" << endl;
	}
	else
	{
		cout << "Xoa thanh cong" << endl;
	}
}
void init(struct BST_TREE& t)
{
	t.pRoot = NULL;
}

void insertNode(struct BST_TREE& t, int x)
{
	if (t.pRoot == NULL)
	{
		t.pRoot = new BST_NODE;
		t.pRoot->Key = x;
		t.pRoot->So_lan = 1;
		t.pRoot->Left = NULL;
		t.pRoot->Right = NULL;
	}
	else
	{
		if (t.pRoot->Key == x)
		{
			t.pRoot->So_lan++;
		}
		else if (x < t.pRoot->Key)
		{
			t.pRoot = t.pRoot->Left;
			insertNode(t, x);
		}
		else
		{
			t.pRoot = t.pRoot->Right;
			insertNode(t, x);
		}
	}
}
void Xuat(BST_NODE* root)
{
	if (root != NULL)
	{
		Xuat(root->Left);
		cout << root->Key << " " << root->So_lan << endl;
		Xuat(root->Right);
	}
}

void lietke(struct BST_TREE& t)
{
	Xuat(t.pRoot);
}
void NLR(struct BST_NODE* root)
{
	if (root != NULL)
	{
		cout << root->Key << " " << root->So_lan << endl;
		NLR(root->Left);
		NLR(root->Right);
	}
}
void XuatNLR(struct BST_TREE& t)
{
	NLR(t.pRoot);
}
void testcase1() {
	BST_TREE t;
	init(t);
	insertNode(t.pRoot, 5);
	insertNode(t.pRoot, 1);
	insertNode(t.pRoot, 3);
	insertNode(t.pRoot, 7);

	cout << "Truoc khi xoa:" << endl;
	Xuat(t.pRoot);

	XoaGiaTri(t, 7);

	cout << "Sau khi xoa:" << endl;
	Xuat(t.pRoot);
}
int main()
{
	testcase1();
	return 0;
}

