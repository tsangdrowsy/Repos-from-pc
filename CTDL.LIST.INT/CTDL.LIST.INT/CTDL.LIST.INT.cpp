#include<iostream>
using namespace std;

typedef struct node
{
	int info;
	struct node* next;
}Node;

Node* pHead = NULL;
bool isEmpty(Node* pHead)
{
	return (pHead == NULL);
}
void init(Node* pHead)
{
	pHead = NULL;
}
Node* createnode(int x)
{
	Node* p = new Node;
	p->info = x;
	p->next = NULL;
	return p;
}
void Showlist(Node* pHead)
{
	if (pHead = NULL)
		printf("danh sach rong \n");
	else
	{
		Node* p = pHead;
		while (p != NULL)
		{
			printf("Phan tu la: %d ", p->info);
			p = p->next;
		}
	}
}
void insertFirst(Node*& pHead, int x)
{
	Node* p = createnode(x);
	p->next = pHead;
	pHead = p;
}
void insertAfter(Node*& p, int x)
{
	if (p != NULL)
	{
		node* q = createnode(x);
		q->next = p->next;
		p->next = q;
	}
}
