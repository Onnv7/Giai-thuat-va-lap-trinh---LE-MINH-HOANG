#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* pNext;
	Node* pPrev;
};
typedef struct Node NODE;

struct List
{
	NODE* pHead;
	NODE* pTail;
};
typedef struct List LIST;

void OutputTail(LIST l);
void OutputHead(LIST l);
void Input(LIST& l);
void AddHead(LIST& l, NODE* p);
void AddTail(LIST& l, NODE* p);
NODE* GetNode(int x);
void Init(LIST& l);
void DelHead(LIST& l);

int main()
{
	LIST l;
	Input(l);
	DelHead(l);
	OutputHead(l);
	OutputTail(l);
	return 0;
}
void DelHead(LIST& l)
{
	NODE* p = l.pHead;
	l.pHead = p->pNext;
	l.pHead->pPrev = NULL;
	delete p;
}

void OutputHead(LIST l)
{
	cout << "\nXUAT TU HEAD\n";
	for (NODE* p = l.pHead; p != NULL; p = p->pNext)
		cout << p->data << " ";
	cout << "\n";
}
void OutputTail(LIST l)
{
	cout << "\nXUAT TU TAIL\n";
	for (NODE* p = l.pTail; p != NULL; p = p->pPrev)
		cout << p->data << " ";
	cout << "\n";
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
		l.pHead->pPrev = p;
		l.pHead = p;
	}
}
void AddTail(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext = p;
		p->pPrev = l.pTail;
		l.pTail = p;
	}
}
NODE* GetNode(int x)
{
	NODE* p = new NODE[1];
	if (p == NULL)
	{
		cout << "\n\tKHONG DU BO NHO !!!";
		return NULL;
	}
	p->data = x;
	p->pPrev = NULL;
	p->pNext = NULL;
	return p;
}
void Init(LIST& l)
{
	l.pHead = l.pTail = NULL;
}