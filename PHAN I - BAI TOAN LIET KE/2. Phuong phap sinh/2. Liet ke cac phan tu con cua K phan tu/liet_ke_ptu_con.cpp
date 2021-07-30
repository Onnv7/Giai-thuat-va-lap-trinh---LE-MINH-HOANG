#include <stdio.h>
int GioiHanTren(int k, int n, int A[], int i);
void LietKeTapConKPhanTu(int k, int n);
void xuat(int A[], int n);
void nhap(int &k);
void main()
{
	int k, n;
	nhap(k);
	nhap(n);
	if(n!=0 && k!=0)
		LietKeTapConKPhanTu(k, n);
}
int GioiHanTren(int k, int n, int A[], int i)
{
	if(A[i] == n-k+i+1)
		return 1;
	return 0;
}
void LietKeTapConKPhanTu(int k, int n)
{
	int A[10000];
	for(int i=0; i<n; i++)
		A[i] = i+1;
	xuat(A, k);
	while(1)
	{
		int x = k-1;
		while(GioiHanTren(k, n, A, x)==1 && x>=0)
		{
			x--;
		}
		if(x<0)
			break;
		A[x] = A[x] + 1;
		for(int j=x+1; j<k; j++)
			A[j] = A[j-1] + 1;
		xuat(A, k);
	}
}
void nhap(int &k)
{
	scanf("%d", &k);
}
void xuat(int A[], int n)
{
	for(int i=0; i<n; i++)
		printf("%d ", A[i]);
	printf("\n");
}