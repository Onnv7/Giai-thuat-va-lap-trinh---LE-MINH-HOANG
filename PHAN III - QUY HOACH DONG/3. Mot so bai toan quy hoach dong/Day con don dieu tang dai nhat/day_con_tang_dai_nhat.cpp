#include <stdio.h>
void nhap(int &n, int A[]);
void day_tang_nhat(int n, int A[]);
void xuat(int k, int A[]);
void  xuatKQ(int n, int T[], int A[]);
void main()
{
	int A[1000], n;
	nhap(n, A);
	day_tang_nhat(n, A);
}
void day_tang_nhat(int n, int A[])
{
	// cach 1
/*	int L[1000]; 
	int T[1000];  
	L[n+1] = 1;
	for(int i=n; i>=0; i--)
	{
		int jmax = n+1;
		for(int j = i+1; j<=n+1; j++)
		{
			if(A[i] < A[j] && L[jmax] < L[j])
				jmax = j;
			L[i] = L[jmax] + 1;
			T[i] = jmax;   
		}
	}
	xuatKQ(n, T, A);  */


	// cach 2
	int L[1000]; 
	L[n+1] = 1;
	for(int i=n; i>=0; i--)
	{
		int jmax = n+1;
		for(int j = i+1; j<=n+1; j++)
		{
			if(A[i] < A[j] && L[jmax] < L[j])
				jmax = j;
			L[i] = L[jmax] + 1;
		}
	}
	 int nT=0;
	 int T[1000];
	 i = 0;
	 int j = 1, k = L[0]-1;
	 while(j!=n+1)
	 {
		if(L[j] == k && A[j] > A[i])
		{
			i = j;
			T[nT++] = A[j];
			k--;
		}
		j++;
	 }
	 xuat(nT, T);
}
void  xuatKQ(int n, int T[], int A[])
{
	int i = T[0];
	while(i!=n+1)
	{
		printf("%d ", A[i]);
		i =T[i];
	}
}
void xuat(int k, int A[])
{
	for(int i=0; i<k; i++)
		printf("%d ", A[i]);
}	
void nhap(int &n, int A[])
{
	scanf("%d", &n);
	A[0] = -9999;
	A[n+1] = 9999;
	for(int i=1; i<=n; i++)
		scanf("%d", &A[i]);
}