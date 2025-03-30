#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
using namespace std;

typedef struct node
{
	int info;
	struct node* left;
	struct node* right;
}NODE;

typedef NODE* TREE;

void LNR(TREE Root, FILE* fp)
{
	if (Root != NULL)
	{
		LNR(Root->left, fp);
		fprintf(fp, "%d ", Root->info);
		LNR(Root->right, fp);
	}
}

int xuat(const char* filename, TREE Root)
{
	FILE* fp = fopen(filename, "w");
	if (fp == NULL)
		return 0;
	LNR(Root, fp);
	fclose(fp);
	return 1;
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
	cout << "Nhap so luong phan tu cua cay: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cout << "Nhap phan tu thu " << i << ": ";
		cin >> x;
		insertNode(Root, x);
	}
	xuat("output.txt", Root);
}
int main()
{
	TREE Root;
	testcase(Root);
	return 0;
}