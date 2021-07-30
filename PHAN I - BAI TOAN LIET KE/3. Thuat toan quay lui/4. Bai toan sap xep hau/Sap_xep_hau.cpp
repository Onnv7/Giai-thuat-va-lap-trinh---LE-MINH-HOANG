#include <stdio.h>
void sap_xep_hau(int i, int n, int A[], int B[], int C[], int X[]);
void nhap(int &n);
void xuat(int X[], int n);
void main()
{
	int n;
	nhap(n);
	int A[1000] = {0};
	int B[1000] = {0};
	int C[1000] = {0};
	int X[1000] = {0};
	sap_xep_hau(1, n, A, B, C, X);
}
void sap_xep_hau(int i, int n, int A[], int B[], int C[], int X[])
{
	for(int j = 1; j<=n; j++)
	{
	//	printf("aaa %d aaa\n", i-j);
		if(A[j]==0 && B[i+j]==0 && C[i-j+n]==0)
		{
			X[i] = j;
			if(i==n)
				xuat(X, n);
			else
			{
				A[j] = 1;
				B[i+j] = 1;
				C[i-j+n] = 1;
				sap_xep_hau(i+1, n, A, B, C, X);
				A[j] = 0;
				B[i+j] = 0;
				C[i-j+n] = 0;
			}
		}
	}
}
void nhap(int &n)
{
	scanf("%d", &n);
}
void xuat(int X[], int n)
{
	for(int k=1; k<=n; k++)
		printf("(%d %d) ", k, X[k]);
	printf("\n");
}