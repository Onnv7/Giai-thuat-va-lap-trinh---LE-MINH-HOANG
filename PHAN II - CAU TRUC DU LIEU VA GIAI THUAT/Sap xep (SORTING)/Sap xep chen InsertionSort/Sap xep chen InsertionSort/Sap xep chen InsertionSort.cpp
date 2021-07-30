#include <iostream>
using namespace std;
void SelectionSort(int A[], int n);
void Output(int A[], int n);
int main()
{
	int A[10] = { 3,2,1,4,6,5,7,9,8,0 };
	int n = 10;
	SelectionSort(A, n);
	Output(A, n);
	return 0;
}
void SelectionSort(int A[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		int key = A[i];
		while (A[j] > key && j >= 0)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;
	}
}
void Output(int A[], int n)
{
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
}