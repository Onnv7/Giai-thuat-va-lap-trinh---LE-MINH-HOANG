#include <iostream>
#include <string.h>
using namespace std;
void xuLy(char A[], float T[], int& top);
float tinh(char x, float a, float b);
void Pop(float T[], int& top, float& x);
void Push(float T[], int& top, float x);
float layGiaTri(char A[], int a, int b);
void HieuCHinh(char A[]);
void chen(char A[], int a, char x);
bool toanTu(char x);
void dichChuyen(char A[], int a, int b);

int main()
{
	char A[10000];
	float T[10000];
	int top = 0;
	cin.getline(A, sizeof(A));
	HieuCHinh(A);
	xuLy(A, T, top);
	cout << "\n" << A << " = " << T[1];
	return 0;
}
void xuLy(char A[], float T[], int& top)
{
	int len = strlen(A);
	for (int i = 0; i < len; i++)
	{
		if (A[i] >= '0' && A[i] <= '9')
		{
			int k = i;
			while (A[i] >= '0' && A[i] <= '9')
				i++;
			float x = layGiaTri(A, k, i - 1);
			Push(T, top, x);
		}
		else if (toanTu(A[i]) == true)
		{
			float x1, x2;
			Pop(T, top, x2);
			Pop(T, top, x1);
			float t = tinh(A[i], x1, x2);
			Push(T, top, t);
		}
	}
}
float tinh(char x, float a, float b)
{
	if (x == '+')
		return a + b;
	else if (x == '-')
		return a - b;
	else if (x == '*')
		return a * b;
	else 
		return a / b;
}
void Pop(float T[], int& top, float& x)
{
	x = T[top];
	top--;
}
void Push(float T[], int& top, float x)
{
	top++;
	T[top] = x;
}
float layGiaTri(char A[], int a, int b)
{
	float t = 0;
	for (int i = a; i <= b; i++)
	{
		t = t*10 + A[i] - '0';
	}
	return t;
}
void HieuCHinh(char A[])
{
	int i = 0;
	while (A[i] == ' ')
		i++;
	dichChuyen(A, 0, i);
	int len = strlen(A);
	for (i = 0; i < len; i++)
	{
		if (A[i] == ' ')
		{
			int k = i + 1;
			while (A[k] == ' ')
				k++;
			dichChuyen(A, i + 1, k);
		}
		len = strlen(A);
	}
	A[i] = '\0';
	len = strlen(A);
	for (int j = 0; j < len; j++)
	{
		if (    (  A[j] >= '0' && A[j] <= '9' && toanTu(A[j + 1])   ) || (   A[j + 1] >= '0' && A[j + 1] <= '9' && toanTu(A[j])  ) || (  toanTu(A[j]) && toanTu(A[j + 1]) )   )
		{
			chen(A, j + 1, ' ');
			len = strlen(A);
		}
	}
}
void chen(char A[], int a, char x)
{
	int len = strlen(A);
	for (int i = len; i >= a + 1; i--)
		A[i] = A[i - 1];
	A[a] = x;
	A[len + 1] = '\0';
}
bool toanTu(char x)
{
	if (x == '+' || x == '-' || x == '*' || x == '/')
		return true;
	return false;
}
void dichChuyen(char A[], int a, int b)
{
	int i;
	int len = strlen(A) - (b - a);
	for (i = a; i < len; i++)
		A[i] = A[b++];
	A[i] = '\0';
}