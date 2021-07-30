#include <stdio.h>
void chinh_hop_khong_lap(int i, int k, int n, int C[], int A[]);
void xuat(int A[], int p);
void nhap(int &n);
void main()
{
	int n, k;
	nhap(n);
	nhap(k);
	int C[1000] = {0};
	int A[1000] = {0};
	chinh_hop_khong_lap(1, k, n, C, A); 
}
void chinh_hop_khong_lap(int i, int k, int n, int C[], int A[])
{
	for(int j=1; j<=n; j++)
	{
		if(C[j]==0)
		{
			A[i] = j;
			if(i==k)
				xuat(A, k);
			else
			{
				C[j] = 1;
				chinh_hop_khong_lap(i+1, k, n, C, A);
				C[j] = 0;
			}
			
		}
	}
}
void nhap(int &n)
{
	scanf("%d", &n);
}
void xuat(int A[], int p)
{
	for(int i=1; i<=p; i++)
		printf("%d ", A[i]);
	printf("\n");
}