// tim gia tri tai vi tri thu p khi da sap xep

#include <iostream>
using namespace std;

int Select(int A[], int L, int H, int p);
void swap(int& a, int& b);
void InsertionSort(int A[], int a, int b);

int main()
{
	int A[1000];
	int n = 1000;
	for (int i = 0; i < 1000; i++)
	{
		A[i] = n;
		n--;
	}
	n = 1000;
	cout << Select(A, 0, n-1, 152) << endl; //152 là vị trí p =152
	return 0;
}
int Select(int A[], int L, int H, int p)
{
	if (H - L < 49) //khi do dai mang <50 thi InsertionSort
	{
		InsertionSort(A, L, H);
		return A[L + p - 1];
	}
	int i = L;
	int j = L - 1;
	while (i + 4 <= H) //chia mang thanh cac doan gom 5 phan tu, tim trung vi cua cac doan va chuyen len dau mang
	{
		InsertionSort(A, i, i + 4);
		j++;
		swap(A[j], A[i + 2]);
		i = i + 5;
	}
	int pivot = Select(A, L, j, (j - L + 1) / 2); //pivot = trung vi cua cac trung vi
	int cE = 0; //dem so khoa = pivot
	int cL = 0; //dem so khoa < pivot
	for (int i = L; i <= H; i++)
	{
		if (A[i] < pivot)
			cL++;
		else if (A[i] == pivot)
			cE++;
	}
	j = L-1;
	if (cL < p && p <= cL + cE) //TH giá trị tai p = pivot
		return pivot;
	if (p < cL) //TH giá trị tai p < pivot
	{
		for(int i=L; i<=H; i++)
			if (A[i] < pivot)
			{
				j++;
				swap(A[i], A[j]);
			}
		return Select(A, L, j, p);
	}
	else //TH giá trị tai p > pivot
	{
		for(int i=L; i<=H; i++)
			if (A[i] > pivot)
			{
				j++;
				swap(A[i], A[j]);
			}
		return Select(A, L, j, p - cL - cE);
	}
}
void swap(int& a, int& b)
{
	int temp = a;
	a = b; 
	b = temp;
}
void InsertionSort(int A[], int a, int b)
{
	for (int i = a + 1; i <= b; i++)
	{
		int j = i - 1;
		int key = A[i];
		while (j >= a && key < A[j])
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;
	}
}