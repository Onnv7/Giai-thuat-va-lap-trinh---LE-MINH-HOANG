#include <iostream>
#include <string.h>
using namespace std;

void hieuChinh(char A[]);
void chen(char A[], char x, int j);
int toanTu(char x);
void dichChuyen(char A[], int a, int b);
void xuLy(char A[], char S[], int& top);
void Pop(char S[], char& x, int& top);
void Push(char S[], char x, int& top);

int main()
{
	char A[1000];
	char S[1000];
	int top = 0;
	cin.getline(A, sizeof(A));
	hieuChinh(A);
	cout << A << " = ";
	xuLy(A, S, top);
	return 0;
}
void xuLy(char A[], char S[], int& top)
{
	int len = strlen(A);
	for (int i = 0; i < len; i++)
	{
		if (A[i] == '(')
			Push(S, A[i], top);
		else if (toanTu(A[i]) == 3 || toanTu(A[i]) == 2)
		{
			while (toanTu(S[top]) >= toanTu(A[i]) && top >= 1)
			{
				char x;
				Pop(S, x, top);
				cout << x << " ";
			}
			Push(S, A[i], top);
		}
		else if (A[i] == ' ')
			continue;
		else if (A[i] == ')')
		{
			char x;
			while (S[top] != '(')
			{
				Pop(S, x, top);
				cout << x << " ";
			}
			Pop(S, x, top);
		}
		else if(toanTu(A[i]) == 0)
		{
			int k = i;
			while (toanTu(A[i]) == 0 && i < len)
				i++;
			for (int j = k; j < i; j++)
				cout << A[j];
			cout << " ";
		}
	}
	while (top >= 1)
	{
		char x;
		Pop(S, x, top);
		cout << x << " ";
	}
}
void Pop(char S[], char& x, int& top)
{
	x = S[top];
	top--;
	S[top + 1] = '\0';
}
void Push(char S[], char x, int& top)
{
	top++;
	S[top] = x;
	S[top + 1] = '\0';
}
void hieuChinh(char A[])
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
			while (A[k] == ' ' && k < len)
				k++;
			dichChuyen(A, i + 1, k);
			len = strlen(A);
		}
	}
	if (A[i] == ' ')
		A[i] = '\0';
	for (int j = 0; j < len-1; j++)
	{
		if ((A[j] == ' ' && A[j + 1] != ' ') || (A[j] != ' ' && A[j + 1] == ' ') || (toanTu(A[j]) == 0 && toanTu(A[j + 1]) == 0))
			continue;
		chen(A, ' ', j + 1);
		len = strlen(A);
	}
}
void chen(char A[], char x, int j)
{
	int len = strlen(A);
	for (int i = len; i > j; i--)
		A[i] = A[i - 1];
	A[j] = x;
	A[len + 1] = '\0';
}
int toanTu(char x)
{
	if (x == '*' || x == '/')
		return 3;
	else if (x == '+' || x == '-')
		return 2;
	else if (x == '(')
		return 1;
	else if (x >= '0' && x <= '9')
		return 0;
	else if (x == ')')
		return 4;
	else if (x == ' ')
		return 5;
}
void dichChuyen(char A[], int a, int b)
{
	int len = strlen(A);
	int i;
	for (i = b; i < len; i++)
		A[a++] = A[i];
	A[a] = '\0';
}