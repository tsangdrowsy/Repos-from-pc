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

void insert(Tree& t, int x)
{
    if (t == NULL)
    {
        t = new Node;
        t->info = x;
        t->left = NULL;
        t->right = NULL;
    }
    else
    {
        if (t->info > x)
            insert(t->left, x);
        else if (t->info < x)
            insert(t->right, x);
    }
}

void Xuat(Tree t)
{
    if (t != NULL)
    {
        Xuat(t->left);
        cout << t->info << " ";
        Xuat(t->right);
    }
}

void removeall(Tree& t)
{
    if (t == NULL)  
        return;

    removeall(t->left);
    removeall(t->right);
    delete t;
    t = NULL; 
}

void test()
{
    Tree t;
    init(t);
    insert(t, 5);
    insert(t, 1);
    insert(t, 3);
    insert(t, 7);

  
    Xuat(t);
    cout << endl;

    removeall(t);

    if (t == NULL)
        cout << "Xoa thanh cong";
    else
        cout << "Xoa that bai";
}

int main()
{
    test();
    return 0;
}