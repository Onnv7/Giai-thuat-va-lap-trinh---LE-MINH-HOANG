#include <stdio.h>
void lietKeDayNhiPhanCo2Cap01(int n);
void nhap(int &n);
void xuat(int A[], int k);
void main()
{
	int n;
	nhap(n);
	lietKeDayNhiPhanCo2Cap01(n);
}
int checkNhiPhanCo2Cap01(int A[], int n)
{
	int dem=0;
	for(int i=0; i<n; i++)
		if(A[i]==0 && A[i+1]==1)
			dem++;
	return dem;
}
void lietKeDayNhiPhanCo2Cap01(int n)
{
	int A[1000] = {0};
	while(1)
	{
		int i=n-1;
		while(A[i]==1 && i>=0)
		{
			A[i]=0;
			i--;
		}
		if(i<0)
			break;
		A[i] = 1;
		if(checkNhiPhanCo2Cap01(A, n)==2)
			xuat(A, n);
	}
}
void nhap(int &n)
{
	scanf("%d", &n);
}
void xuat(int A[], int k)
{
	for(int i=0; i<k; i++)
		printf("%d", A[i]);
	printf("\n");
}