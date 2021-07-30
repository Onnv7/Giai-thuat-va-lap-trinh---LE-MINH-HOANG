#include <stdio.h>
#include <stdlib.h>
void nhap(int &n);
void nhapten(char s[]);
void xuat(char s[]);
void main()
{
	int n;
	nhap(n);
	char *name;
	name = (char*)malloc(n*sizeof(char));
	for(int i=0; i<n; i++)
		nhapten((name+i));
//	LietKeCachChonKNguoi(n);
}
void nhap(int &n)
{
	scanf("%d", &n);
}
void nhapten(char s[])
{
	scanf("%d[^\n]%*c", s);
}
void xuat(char s[])
{
	printf("%s", s);
}
