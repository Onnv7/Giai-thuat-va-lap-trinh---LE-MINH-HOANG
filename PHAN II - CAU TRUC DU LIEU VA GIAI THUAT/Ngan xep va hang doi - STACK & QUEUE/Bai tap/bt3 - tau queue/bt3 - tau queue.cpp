#include <iostream>
using namespace std;
void xuLy(int n, int A[], int B[], int C[]);
void nhap(int& n, int A[], int C[]);
void PushQUEUE(int X[], int x, int& top);
void PopQUEUE(int X[], int& x, int& top);
void PopSTACK(int X[], int& x, int& top);

int main()
{
	int n, A[1000], B[1000], C[1000];
	nhap(n, A, C);
	xuLy(n, A, B, C);
	return 0;
}
void xuLy(int n, int A[], int B[], int C[])
{
	int t = 0;
	
	int topA = n;
	int topB = 0;
	for (int i = 1; i <= n; i++)
	{
		int key = C[i];
		if (key >= A[topA] && topA > 0)
		{
			int x;
			while (A[topA] != key)
			{
				PopSTACK(A, x, topA);
				PushQUEUE(B, x, topB);
				cout << "\nA -> B";
			}
			PopSTACK(A, x, topA);
			cout << "\nA -> C";
		}
		else
		{
			int x;
			if (key != B[1])
			{
				cout << "\nKHONG TIM THAY !!!";
				return;
			}
			PopQUEUE(B, x, topB);
			cout << "\nB -> C";
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
void PushQUEUE(int X[], int x, int& top)
{
	top++;
	X[top] = x;
}
void PopQUEUE(int X[], int& x, int& top)
{
	x = X[1];
	top--;
	for (int i = 1; i <= top; i++)
		X[i] = X[i + 1];
}
void PopSTACK(int X[], int& x, int& top)
{
	x = X[top];
	top--;
}