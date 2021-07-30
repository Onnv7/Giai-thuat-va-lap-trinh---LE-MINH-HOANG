#include <iostream>
using namespace std;

void xuLy(int n, int A[], int B[], int C[]);
void nhap(int& n, int A[], int C[]);
void Push(int X[], int x, int& top);
void Pop(int X[], int& x, int& top);

int main()
{
	int A[1000], B[1000], C[1000];
	int n;
	nhap(n, A, C);
	xuLy(n, A, B, C);
	return 0;
}
void xuLy(int n, int A[], int B[], int C[])
{
	int topA = n;
	int topB = 0;
	int t = 0;
	for (int i = 1; i <= n; i++)
	{
		int key = C[i];
		if (key > t)
		{
			int x;
			while (A[topA] != key)
			{
				Pop(A, x, topA);
				Push(B, x, topB);
				cout << "A -> B\n";
			}
			Pop(A, x, topA);
			cout << "A -> C\n";
			t = key;
		}
		else
		{
			int x;
			if (key != B[topB])
			{
				cout << "\nKHONG TIM THAY !!!";
				return;
			}
			Pop(B, x, topB);
			cout << "B -> C\n";
			t = key;
		}
	}
}
void nhap(int& n, int A[], int C[])
{
	cin >> n;
	int k = n;
	for (int i = 1; i <= n; i++)
	{
		A[i] = k--;
		cin >> C[i];
	}
}
void Push(int X[], int x, int& top)
{
	top++;
	X[top] = x;
}
void Pop(int X[], int& x, int& top)
{
	x = X[top];
	top--;
}