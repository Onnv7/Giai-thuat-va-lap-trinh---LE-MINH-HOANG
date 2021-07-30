#include <iostream>
using namespace std;
//			   3
//		1			   5
//	0		2	    4	  6
struct Node
{
	int data;
	Node* pRight;
	Node* pLeft;
};
typedef struct Node NODE;
typedef NODE* TREE;

void OutputNLR(TREE t);
void OutputNRL(TREE t);
void OutputLNR(TREE t);
void OutputLRN(TREE t);
void OutputRNL(TREE t);
void OutputRLN(TREE t);
void InputTree(TREE& t);
void AddNodeToTree(TREE& t, NODE* p);
NODE* GetNode(int x);
void Init(TREE& t);

int main()
{
	TREE t;
	Init(t);
	int choose = -1;
	while (choose != 0)
	{
		do
		{
			system("cls");
			cout << "\n1.Nhap 1 phan tu vao cay.";
			cout << "\n2.Xuat.";
			cout << "\n0.Thoat.";
			cout << "\nMoi ban nhap lua chon: ";
			cin >> choose;
		} while (choose < 0 || choose> 2);
		if (choose == 1)
		{
			InputTree(t);
			//	OutputNLR(t);
			system("pause");
		}
		else if (choose == 2)
		{
			cout << "\nDuyet NLR: ";
			OutputNLR(t);
			cout << "\nDuyet NRL: ";
			OutputNRL(t);
			cout << "\nDuyet LNR: ";
			OutputLNR(t);
			cout << "\nDuyet LRN: ";
			OutputLRN(t);
			cout << "\nDuyet RNL: ";
			OutputRNL(t);
			cout << "\nDuyet RLN: ";
			OutputRLN(t);
			system("pause");
		}
		else
			return 0;
	}
	return 0;
}
void OutputRLN(TREE t)
{
	if (t != NULL)
	{
		OutputRLN(t->pRight);
		OutputRLN(t->pLeft);
		cout << t->data << " ";
	}
}
void OutputRNL(TREE t)
{
	if (t != NULL)
	{
		OutputRNL(t->pRight);
		cout << t->data << " ";
		OutputRNL(t->pLeft);
	}
}
void OutputLRN(TREE t)
{
	if (t != NULL)
	{
		OutputLRN(t->pLeft);
		OutputLRN(t->pRight);
		cout << t->data << " ";
	}
}
void OutputLNR(TREE t)
{
	if (t != NULL)
	{
		OutputLNR(t->pLeft);
		cout << t->data << " ";
		OutputLNR(t->pRight);
	}
}
void OutputNRL(TREE t)
{
	if (t != NULL)
	{
		cout << t->data << " ";
		OutputNRL(t->pRight);
		OutputNRL(t->pLeft);
	}
}
void OutputNLR(TREE t)
{
	if (t != NULL)
	{
		cout << t->data << " ";
		OutputNLR(t->pLeft);
		OutputNLR(t->pRight);
	}
}
void InputTree(TREE& t)
{
	int x;
	cout << "\nNhap gia tri NODE: ";
	cin >> x;
	NODE* p = GetNode(x);
	AddNodeToTree(t, p);
}
void AddNodeToTree(TREE& t, NODE* p)
{
	if (t == NULL)
	{
		t = p;
	}
	else if (t->data > p->data)
	{
		AddNodeToTree(t->pLeft, p);
	}
	else if (t->data < p->data)
	{
		AddNodeToTree(t->pRight, p);
	}
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
	p->pLeft = p->pRight = NULL;
	return p;
}
void Init(TREE& t)
{
	t = NULL;
}
