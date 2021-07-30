#include <stdio.h>
void lietKeCacChinhHopLap(int n);
void nhap(int &n);
void xuat(int A[], int k);
void main()
{
	int n;
	nhap(n);
	lietKeCacChinhHopLap(n);
}
void lietKeCacChinhHopLap(int n)
{
	int A[10000] = {0};
	int i;
	xuat(A, n);
	while(1)
	{
		i = n-1;
		while((A[i] == n-1) && (i>=0))
			i--;
		if(i<0)
			break;
		A[i]++;
		for(int j=i+1; j<n; j++)
			A[j] = 0;
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
		printf("%d ", A[i]);
	printf("\n");
}