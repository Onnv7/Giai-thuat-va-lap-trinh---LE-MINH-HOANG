#include <stdio.h>
void du_lich(int i, int n, int &feeMin);
void nhap(int &m, int &n, int C[][10]);
void cap_nhat_duong_tot(int n);
void xuat(int n, int feeMin);
int feeMin =99999;
int X[10];
int A[10];
int C[10][10] = {0};	
int T[10];
int F[20]={0};
int count=0;
void main()
{
	
	int m, n;	
	F[1] = 1;
	T[1] = 0;
	X[1] = 1;
	nhap(m, n, C);
	du_lich(2, n, feeMin);
	xuat(n, feeMin);
}
void du_lich(int i, int n, int &feeMin)
{
	for(int j=1; j<=n; j++)
	{
		if(F[j]==0)
		{
			X[i] = j;
			T[i] = T[i-1] + C[X[i-1]][j];
			if(T[i]<feeMin)
			{
				if(i<n)
				{
					F[j] = 1;
					du_lich(i+1, n, feeMin);
					F[j] = 0;
				}
				
				else if(T[n] + C[X[n]][1] < feeMin)
				{
					cap_nhat_duong_tot(n);
					feeMin = T[n] + C[X[n]][1];
				}
			}
		}
		
	}
}
void cap_nhat_duong_tot(int n)
{
	for(int i=1; i<=n; i++)
		A[i] = X[i];
}
void xuat(int n, int feeMin)
{
	for(int i=1; i<=n; i++)
		printf("%d -> ", A[i]);
	printf("1");
	printf("\nPhi: %d", feeMin);
}
void nhap(int &m, int &n, int C[][10])
{
	int x, y;
	scanf("%d%d", &n, &m);
	for(int i=1; i<=m; i++)
	{
		scanf("%d%d", &x, &y);
		scanf("%d", &C[x][y]);
		C[y][x] = C[x][y];
	}
/*	for(i =1; i<=n; i++)
		for(int j=1; j<=n; j++)
		{
			if(i==j)
				C[i][j] = 0;
			else if(j>i)
				C[j][i] = C[i][j];
		}*/
}

