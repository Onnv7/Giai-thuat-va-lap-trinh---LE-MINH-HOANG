#include <stdio.h>
void LK_NhiPhanPP_QuayLui(int i, int n, int A[]);
void xuat(int A[], int n);
void nhap(int &n);
void main()
{
	int n;
	nhap(n);
	int A[1000] = {0};
	LK_NhiPhanPP_QuayLui(0, n, A);
}
void LK_NhiPhanPP_QuayLui(int i, int n, int A[])
{
	for(int j=0; j<2; j++)
	{
		A[i] = j;
		if(i==n-1)
			xuat(A, n);
		else
			LK_NhiPhanPP_QuayLui(i+1, n, A);
	}
}
/*void LietKeDayNhiPhan(int n)
{
	int A[1000] = {0};
}*/
void nhap(int &n)
{
	scanf("%d", &n);
}
void xuat(int A[], int n)
{
	for(int i=0; i<n; i++)
		printf("%d", A[i]);
	printf("\n");
}
