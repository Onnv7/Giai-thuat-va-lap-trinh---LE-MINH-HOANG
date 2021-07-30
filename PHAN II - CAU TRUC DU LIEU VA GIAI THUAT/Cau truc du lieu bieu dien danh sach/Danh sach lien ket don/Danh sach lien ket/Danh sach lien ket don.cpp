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

NODE* GetNode(int x);
void Output(LIST l);
void Input(LIST& l);
void AddHead(LIST& l, NODE* p);
void AddTail(LIST& l, NODE* p);
void Init(LIST& l);

int main()
{
	LIST l;

	Input(l);
	Output(l);

	return 0;
}
NODE* GetNode(int x)
{
	NODE* p = new NODE[1];
	if (p == NULL)
	{
		cout << "\n\t\tKHONG DU BO NHO !!!";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}
void Output(LIST l)
{
	for (NODE* p = l.pHead; p != NULL; p = p->pNext)
		cout << p->data << " ";
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
}
void Init(LIST& l)
{
	l.pHead = l.pTail = NULL;
}