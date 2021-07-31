#include <iostream>
#include <cmath>
using namespace std;
void Output(int A[], int n);
void ShellSort(int A[], int n);
int countz = 0;
int main()
{
//	int A[10] = { 3,2,1,4,6,5,7,9,8,0 }; //C1: 7647, 7965, 7768 C2: 7348, 7594,
	int A[1000];
	int n = 1000;
	srand((int)time(NULL));
	for (int i = 0; i < n; i++)
	{
		int r = rand();
		A[i] = r;
	}
	ShellSort(A, n);
	Output(A, n);
	return 0;
}
void Output(int A[], int n)
{
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
}
void ShellSort(int A[], int n)
{
	int h;
	int k;
	for (k = 1; k < 1000; k++)
		if (pow(2, k) - 1 > n / 2)
		{
			k--;
			h = int(pow(2, k)) - 1;
			break;
		}
//	int h = n / 2;
	while (h != 0)
	{
		for (int i = h; i < n; i++)
		{
			int key = A[i];
			int j = i - h;
			while (A[j] > key && j >= 0)
			{
				A[j + h] = A[j];
				j = j - h;
				cout << countz++ << endl;
			}
			A[j + h] = key;
		}
		k--;
		h = int(pow(2, k)) - 1;
	//	h = h / 2;
	}
}