#include <iostream>
using namespace std;
void Output(int A[], int n);
void QuickSort(int A[], int L, int H);
void swap(int& a, int& b);
int main()
{
	int A[10] = { 0,1,2,3,4,6,7,5,8,9 };
	int n = 10;
	QuickSort(A, 0, n-1);
	Output(A, n);
	return 0;
}
void QuickSort(int A[], int L, int H)
{
	if (L >= H)
		return;
	int i = L;
	int j = H;
	int mid = A[(H + L) / 2];
	while (i <= j)
	{
		while (A[i] < mid)
			i++;
		while (A[j] > mid)
			j--;
		if (i <= j)
		{
			if (i < j)
				swap(A[i], A[j]);
			i++;
			j--;
		}
		QuickSort(A, L, j);
		QuickSort(A, i, H);
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