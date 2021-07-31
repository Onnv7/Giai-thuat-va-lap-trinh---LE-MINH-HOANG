#include <iostream>
using namespace std;

void BubbleSort(int A[], int n);
void swap(int& a, int& b);
void Output(int A[], int n);

int main()
{
	int A[10] = { 3,2,1,4,6,5,7,9,8,0 };
	int n = 10;
	BubbleSort(A, n);
	Output(A, n);
	return 0;
}
void BubbleSort(int A[], int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = n - 1; j >= i; j--)
			if (A[j] < A[j - 1])
				swap(A[j], A[j - 1]);
	}
}
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void Output(int A[], int n)
{
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
}