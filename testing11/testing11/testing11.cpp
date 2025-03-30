#include<iostream>
using namespace std;

typedef struct node
{
    int info;
    struct node* left;
    struct node* right;
} Node;

typedef Node* Tree;

void init(Tree& t)
{
    t = NULL;
}

Node* GetNode(int x)
{
    Node* p = new Node;
    if (p == NULL)
        return NULL;
    p->info = x;
    p->left = p->right = NULL;
    return p;
}

int insert(Tree& t, int x)
{
    if (t)
    {
        if (t->info == x)
            return 0;
        if (t->info > x)
            return insert(t->left, x);
        else
            return insert(t->right, x);
    }
    t = GetNode(x);
    if (t == NULL)
        return -1;
    return 1;
}

int TaoCay(Tree& t, int a[], int n)
{
    init(t);
    for (int i = 0; i < n; i++)
    {
        if (insert(t, a[i]) == -1) 
            return 0;
    }
    return 1;
}

void LNR(Tree t, int a[], int& n)
{
    if (t == NULL)
        return;
    LNR(t->left, a, n);
    a[n++] = t->info;
    LNR(t->right, a, n);
}

void Xuat(Tree t, int a[], int& n)  
{
    n = 0; 
    LNR(t, a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void test()
{
    Tree t;
    init(t);
    int a[4] = { 5, 1, 3, 7 };
    int n = 4;
    TaoCay(t, a, n);

    int b[100]; 
    int count = 0;
    Xuat(t, b, count);
}

int main()
{
    test();
    return 0;
}