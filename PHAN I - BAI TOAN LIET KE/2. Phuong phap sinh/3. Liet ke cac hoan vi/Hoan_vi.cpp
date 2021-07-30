#include <stdio.h>
void xuat(int A[], int k);
void nhap(int &n);
void LietKeCacHoanVi(int n);
void latNguocMang(int A[], int x, int y);
void swap(int &a, int &b);
int timKiemNhiPhan(int A[], int x, int y, int k);

void main()
{
	int n;
	nhap(n);
	if(n!=0)
		LietKeCacHoanVi(n);
}
int timKiemNhiPhan(int A[], int x, int y, int k)
{
	int l = x, r = y;
	
	while(x<=y)
	{
		int mid = (x+y)/2;
		if(A[mid] == k)
			return mid;
		if(k > A[mid])
			y = mid - 1;
		if(k < A[mid])
			x = mid + 1;
	}
	return -1;
}
void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void latNguocMang(int A[], int x, int y)
{
	while(x<y)
	{
		swap(A[x], A[y]);
		x++;
		y--;
	}
}
void LietKeCacHoanVi(int n)
{
	int A[1000];
	for(int i=1; i<=n; i++)
		A[i] = i;
	xuat(A, n);
	while(1)
	{
		int i = n-1;
		while(A[i]>A[i+1] && i>0)
			i--;
		if(i<=0)
			break;
		int GiaTriLon = A[i]+1;
		while(timKiemNhiPhan(A, i+1, n, GiaTriLon)==-1)
			GiaTriLon++;
		int k = timKiemNhiPhan(A, i+1, n, GiaTriLon);
	/*	for(k=n; k>i; k--)
			if(A[k] > A[i])
				break;*/
		swap(A[i], A[k]);
		latNguocMang(A, i+1, n);
		xuat(A, n);
	}
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