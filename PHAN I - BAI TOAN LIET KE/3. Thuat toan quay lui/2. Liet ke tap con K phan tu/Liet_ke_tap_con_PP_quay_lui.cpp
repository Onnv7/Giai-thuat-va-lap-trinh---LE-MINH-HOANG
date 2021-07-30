#include <stdio.h>
void liet_ke_tap_con_PP_quay_lui(int i, int A[], int n, int k);
void nhapMang(int A[], int n);
void nhap(int &n);void xuat(int A[], int k);

void main()
{
	int n, k;
	nhap(n);
	nhap(k);
	int A[1000] = {0};
	nhapMang(A, n);
	A[0] = 0;
	liet_ke_tap_con_PP_quay_lui(1, A, n, k);
	
}
void liet_ke_tap_con_PP_quay_lui(int i, int A[], int n, int k)
{
	for(int j = A[i-1] + 1; j<= n-k+i; j++)
	{
		A[i] = j;
		if(i == k)
			xuat(A, k);
		else
			liet_ke_tap_con_PP_quay_lui(i+1, A, n, k);
	}
}
void nhapMang(int A[], int n)
{
	for(int i=1; i<=n; i++)
		A[i] = i;
}
void nhap(int &n)
{
	scanf("%d", &n);
}
void xuat(int A[], int k)
{
	for(int i=1; i<=k; i++)
		printf("%d ", A[i]);
	printf("\n");
}
