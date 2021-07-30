#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* pNext;
};
typedef struct Node NODE;

struct Stack
{
	Node* pTop;
};
typedef struct Stack STACK;

void MenuStack(STACK& s);
void Output(STACK s);
bool Pop(STACK& s, int& x);
bool Top(STACK& s, int& x);
bool Push(STACK& s, NODE* p);
bool IsEmpty(STACK s);
NODE* GetNode(int x);
void Init(STACK& s);

int main()
{
	STACK s;
	Init(s);
	MenuStack(s);
	return 0;
}
void MenuStack(STACK& s)
{
	int choose;
	while (1)
	{
		system("cls");
		cout << "\n\n\t\t===================== MENU =====================";
		cout << "\n1. Them phan tu vao stack.";
		cout << "\n2. Xuat danh sach stack.";
		cout << "\n3. Pop stack.";
		cout << "\n4. Top stack.";
		cout << "\n0. Ket thuc.";
		cout << "\nNhap lua chon: ";
		cin >> choose;
		if (choose == 1)
		{
			int x;
			cout << "\nNhap gia tri can them: ";
			cin >> x;
			NODE* p = GetNode(x);
			Push(s, p);
		}
		else if (choose == 2)
		{
			Output(s);
			system("pause");
		}
		else if (choose == 3)
		{
			int x;
			if (Pop(s, x) == false)
				cout << "\nSTACK RONG !!!";
			else
				cout << "\nPhan tu lay ra co gia tri: " << x;
			system("pause");
		}
		else if (choose == 4)
		{
			int x;
			if (Top(s, x) == false)
				cout << "\nSTACK RONG !!!";
			else
				cout << "\nGia tri Top cua stack la: " << x;
			system("pause");
		}
		else
			break;
	}
}
void Output(STACK s)
{
	if (IsEmpty(s))
	{
		cout << "\nSTACK RONG !!!";
		return;
	}
	NODE* p = s.pTop;
	do
	{
		cout << p->data << " ";
		p = p->pNext;
	} while (p != NULL);
}
bool Pop(STACK& s, int& x)
{
	if ((IsEmpty(s)))
		return false;
	NODE* p = s.pTop;
	x = s.pTop->data;
	s.pTop = p->pNext;
	delete p;
	return true;
}
bool Top(STACK& s, int& x)
{
	if ((IsEmpty(s)))
		return false;
	x = s.pTop->data;
	return true;
}
bool Push(STACK& s, NODE* p)
{
	if (p == NULL)
		return false;
	if (IsEmpty(s))
		s.pTop = p;
	else
	{
		p->pNext = s.pTop;
		s.pTop = p;
	}
	return true;
}
bool IsEmpty(STACK s)
{
	if (s.pTop == NULL)
		return true;
	return false;
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
void Init(STACK &s)
{
	s.pTop = NULL;
}