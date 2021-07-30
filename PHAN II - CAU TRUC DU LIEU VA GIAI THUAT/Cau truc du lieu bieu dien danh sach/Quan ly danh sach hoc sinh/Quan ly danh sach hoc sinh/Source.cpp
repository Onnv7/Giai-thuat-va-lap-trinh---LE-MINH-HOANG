#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
void Rating(int x, char ten[]);
int main()
{

	char ten[31];
	cin.getline(ten, sizeof(ten));
	Rating(5, ten);
//	cout << ten;
	return 0;

}
void Rating(int y, char ten[])
{
//	char ten[31];
//	cout << "\nNhap ten tim kiem: ";
//	cin.getline(ten, sizeof(ten));
//	char* a = _strupr_s(ten);
	char x[31];
	strcpy_s(x, ten);
	_strupr_s(x);
	_strupr_s(ten)

//	char* TEN = _strupr_s(ten);
	cout << ten << x;
//	cout << TEN;
}