#include <iostream>
using namespace std;

void Output(int A[], int n);
void InsertionSort(int A[], int n);
void swap(int& a, int& b);

int main()
{
	int A[10] = { 3,2,1,4,6,5,7,9,8,0 };
	int n = 10;
	InsertionSort(A, n);
	Output(A, n);
	return 0;
}
void Output(int A[], int n)
{
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
}
void InsertionSort(int A[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int jmin = i;
		for (int j = i + 1; j < n; j++)
			if (A[j] < A[jmin])
				jmin = j;
		swap(A[jmin], A[i]);
	}
}
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}