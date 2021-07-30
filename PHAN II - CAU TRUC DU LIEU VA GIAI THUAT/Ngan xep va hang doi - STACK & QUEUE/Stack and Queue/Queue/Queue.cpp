#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* pNext;
};
typedef struct Node NODE;

struct Queue
{
	NODE* pHead;
	NODE* pTail;
};
typedef struct Queue QUEUE;

bool IsEmpty(QUEUE q);
void Output(QUEUE q);
void Input(QUEUE& q);
bool Push(QUEUE& q, NODE* p);
bool Top(QUEUE q, int& x);
bool Pop(QUEUE& q, int& x);
NODE* GetNode(int x);
void Init(QUEUE& q);


int main()
{
	int choose;
	QUEUE q;
	Init(q);
	while (1)
	{
		system("cls");
		cout << "\n1. Push.";
		cout << "\n2. Pop.";
		cout << "\n3. Top.";
		cout << "\n4. Output.";
		cout << "\n0. Exit.";
		cout << "\nInput choose: ";
		cin >> choose;

		if (choose == 1)
		{
			Input(q);
			system("pause");
		}
		else if (choose == 2)
		{
			int x;
			if (Pop(q, x) == false)
				cout << "\nQUEUE TRONG !!!!!!!!";
			else
				cout << "\nPhan tu lay ra co gia tri la: " << x;
			system("pause");
		}
		else if (choose == 3)
		{
			int x;
			if (Top(q, x) == false)
				cout << "\nQUEUE TRONG !!!!!!!!";
			else
				cout << "\nGia tri cua top la: " << x;
			system("pause");
		}
		else if (choose == 4)
		{
			Output(q);
			system("pause");
		}
		else
			break;
	}
	return 0;
}
bool IsEmpty(QUEUE q)
{
	if (q.pHead == NULL)
		return true;
	return false;
}
void Output(QUEUE q)
{
	if (IsEmpty(q))
	{
		cout << "\nQUEUE TRONG !!!";
		return;
	}
	for (NODE* p = q.pHead; p != NULL; p = p->pNext)
		cout << p->data << " ";
}
void Input(QUEUE& q)
{
	int x;
	cout << "\nNhap gia tri NODE: ";
	cin >> x;
	NODE* p = GetNode(x);
	Push(q, p);
}
bool Push(QUEUE& q, NODE* p)
{
	if (p == NULL)
		return false;
	if (IsEmpty(q))
		q.pHead = q.pTail = p;
	else
	{
		q.pTail->pNext = p;
		q.pTail = p;
	}
	return true;
}
bool Top(QUEUE q, int& x)
{
	if (IsEmpty(q))
		return false;
	x = q.pHead->data;
	return true;
}
bool Pop(QUEUE& q, int& x)
{
	if (IsEmpty(q))
		return false;
	NODE* p = q.pHead;
	x = q.pHead->data;
	q.pHead = p->pNext;
	delete p;
	return true;
}
NODE* GetNode(int x)
{
	NODE* p = new NODE[1];
	if (p == NULL)
	{
		cout << "\nKHONG DU BO NHO !!!!!!!";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}
void Init(QUEUE& q)
{
	q.pHead = q.pTail = NULL;
}