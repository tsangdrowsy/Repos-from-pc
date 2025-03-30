#include <iostream>
using namespace std;

typedef struct node {
    int info;
    struct node* left;
    struct node* right;
} Node;
typedef Node* Tree;

typedef struct nodelist {
    Node* node;
    struct nodelist* next;
} nodelist;

typedef struct list {
    nodelist* head;
    nodelist* tail;
} List;

void init(List& l) {
    l.head = l.tail = NULL;
}

void insertnode(Tree& Root, int x) {
    if (Root == NULL) {
        Node* p = new Node;
        p->info = x;
        p->left = p->right = NULL;
        Root = p;
    }
    else {
        if (x < Root->info) {
            insertnode(Root->left, x);
        }
        else if (x > Root->info) {
            insertnode(Root->right, x);
        }
    }
}

nodelist* getnode(Node* x) {
    nodelist* p = new nodelist;
    if (p == NULL) {
        return NULL;
    }
    p->node = x;
    p->next = NULL;
    return p;
}

void addtail(List& l, nodelist* p) {
    if (l.head == NULL) {
        l.head = l.tail = p;
    }
    else {
        l.tail->next = p;
        l.tail = p;
    }
}

void RNL(Tree Root, List& l);

void buildlist(Tree Root, List& l) {
    init(l);
    RNL(Root, l);
}

void RNL(Tree Root, List& l) {
    if (Root != NULL) {
        RNL(Root->right, l);
        nodelist* p = getnode(Root);
        addtail(l, p);
        RNL(Root->left, l);
    }
}

void freeList(List& l) {
    nodelist* p = l.head;
    while (p != NULL) {
        nodelist* temp = p;
        p = p->next;
        delete temp;
    }
    l.head = l.tail = NULL;
}

void freeTree(Tree& Root) {
    if (Root != NULL) {
        freeTree(Root->left);
        freeTree(Root->right);
        delete Root;
        Root = NULL;
    }
}

void test(Tree Root) {
    List l;
    buildlist(Root, l);
    nodelist* p = l.head;
    while (p != NULL) {
        cout << p->node->info << " ";
        p = p->next;
    }
    freeList(l);
}

int main() {
    Tree Root = NULL;
    insertnode(Root, 5);
    insertnode(Root, 1);
    insertnode(Root, 3);
    insertnode(Root, 7);
    test(Root);
    return 0;
}