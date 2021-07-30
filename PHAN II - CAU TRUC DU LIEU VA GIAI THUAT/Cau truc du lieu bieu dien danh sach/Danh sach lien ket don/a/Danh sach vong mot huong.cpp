#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* pNext;
};
typedef struct Node NODE;

struct List
{
	NODE* pHead;
	NODE* pTail;
};
typedef struct List LIST;

void Output(LIST l);
void Input(LIST& l);
void AddHead(LIST& l, NODE* p);
void AddTail(LIST& l, NODE* p);
NODE* GetNode(int x);
void Init(LIST& l);

int main()
{
	LIST l;
	Input(l);
	Output(l);
	return 0;
}
void Output(LIST l)
{
	NODE* p = l.pHead;
	do
	{
		cout << p->data << " ";
		p = p->pNext;
	} while (p != l.pHead);
}
void Input(LIST& l)
{
	int n;
	cout << "\nNhap so luong NODE: ";
	cin >> n;
	Init(l);
	for (int i = 1; i <= n; i++)
	{
		int x;
		cout << "\nNhap gia tri NODE: ";
		cin >> x;
		NODE* p = GetNode(x);
	//	AddHead(l, p);
		AddTail(l, p);
	}
}
void AddHead(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
	l.pTail->pNext = l.pHead;
}
void AddTail(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{	
		l.pTail->pNext = p;
		l.pTail = p;
	}
	l.pTail->pNext = l.pHead;
}
NODE* GetNode(int x)
{
	NODE* p = new NODE[1];
	if (p == NULL)
	{
		cout << "\nKHONG DU BO NHO !!!";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}
void Init(LIST& l)
{
	l.pHead = l.pTail = NULL;
}