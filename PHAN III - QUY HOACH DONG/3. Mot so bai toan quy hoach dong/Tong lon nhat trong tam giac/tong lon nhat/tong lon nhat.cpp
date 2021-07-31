//                     (7)
//                (3)		 5
//			  (8)		1		0
//		   2	  (7)		 4		4
//		4	 (5)		2		6		5
//				tam giac so
// Viet chtr tinh tong lon nhat cac so tren con duong bat dau tu dinh va ket thuc o day
// - moi buôc co the di cheo xuong trai hoac cheo xuong phai
// - so luong hang trong tam gia > 1 va <= 100
// - cac so trong tam gia deu la so nguyen 0->99

#include <iostream>
using namespace std;

int TongLonNhat(int A[][100], int n);
int max(int a, int b);
void nhap(int& n, int A[][100]);

int main()
{
	int n;
	int A[100][100] = { 0 };
	nhap(n, A);
	cout << TongLonNhat(A, n);
	return 0;
}
int TongLonNhat(int A[][100], int n)
{
	int K[100][100] = { 0 };
	K[0][0] = A[0][0];
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
			K[i][j] = A[i][j] + max(K[i - 1][j - 1], K[i - 1][j]);
	}
	int max = K[n - 1][0];
	for (int k = 0; k < n; k++)
	{
		if (K[n - 1][k] > max)
			max = K[n - 1][k];
	}
	return max;
}
int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
void nhap(int& n, int A[][100])
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
			cin >> A[i][j];
	}
}