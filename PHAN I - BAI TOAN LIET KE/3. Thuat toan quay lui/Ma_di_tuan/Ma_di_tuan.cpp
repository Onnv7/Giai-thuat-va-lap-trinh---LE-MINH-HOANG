#include <stdio.h>
#include <stdlib.h>
void ma_di_tuan(int i, int j);
void xuat();
void nhap(int &n);
int A[1000][1000] = {0};
int X[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int Y[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int n;
int dem=0;
void main()
{
	int i, j;
	nhap(n);
	nhap(i);
	nhap(j);
	ma_di_tuan(i, j);

}
void ma_di_tuan(int x, int y) 
{
    ++dem;
    A[x][y] = dem;
    for (int i = 0; i < 8; i++)    
	{
        
        if (dem == n * n) 
		{
            xuat();
            exit(0);
        }
        
        int u = x + X[i];
        int v = y + Y[i];
        if (u >= 0 && u < n&&v >= 0 && v < n&& A[u][v] == 0)
            ma_di_tuan(u, v);
    }
    --dem;
    A[x][y] = 0;
}
void xuat()
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			printf("%2d  ", A[i][j]);
		printf("\n");
	}
}
void nhap(int &n)
{
	scanf("%d", &n);
}
