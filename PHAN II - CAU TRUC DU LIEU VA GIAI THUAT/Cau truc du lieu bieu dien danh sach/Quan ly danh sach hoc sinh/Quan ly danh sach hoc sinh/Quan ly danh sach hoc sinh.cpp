// Quan ly danh sach hoc sinh - lien ket don
#include <iostream>
#include <iomanip>
#include <string.h>
#include <string>
using namespace std;

struct HocSinh
{
	char name[31];
	char cla[10];
	char NumPhone[12];
	float scoreAvg;
};
typedef struct HocSinh HOCSINH;

struct Node
{
	HOCSINH data;
	Node* pNext;
};
typedef struct Node NODE;

struct List
{
	NODE* pHead;
	NODE* pTail;
};
typedef struct List LIST;
 
int SlgHs = 0;

void Init(LIST& l);
HOCSINH GetInforStudent();
NODE* GetNode(HOCSINH x);
void InputOne(LIST& l);
void Input(LIST& l);
void AddHead(LIST& l, NODE* p);
void AddTail(LIST& l, NODE* p);
void AddAt(LIST& l, NODE* p, int n);
void Output(LIST l);
void OutInforStud(HOCSINH x, int i);
int menuChinh();
void xuLyLuaChon(int x, LIST &l);
void DelIforStu(LIST& l);
void DelHead(LIST& l);
void DelTail(LIST& l);
void DelAt(LIST& l, int x);
char* Rating(HOCSINH p);
void OutputRating(HOCSINH p, int i);
void OutputRatingList(LIST l);
NODE* TimKiemTenvaLop(LIST l);
void OutputFindNameAndClass(LIST l);


int main()
{
	LIST l;
	int luaChon = -1;
	while (luaChon != 0)
	{
		system("cls");
		luaChon = menuChinh();
		xuLyLuaChon(luaChon, l);
	}
	return 0;
}
void Init(LIST& l)
{
	l.pHead = l.pTail = NULL;
}
HOCSINH GetInforStudent()
{
	HOCSINH p;
	cout << "\n======================= NHAP THONG TIN HOC SINH " << "=======================\n";

	cin.ignore();
	cout << "Nhap ho va ten: ";
	cin.getline(p.name, sizeof(p.name));

	cout << "Nhap lop: ";
	cin.getline(p.cla, sizeof(p.cla));

	cout << "Nhap sdt: ";
	cin.getline(p.NumPhone, sizeof(p.NumPhone));

	cout << "Nhap diem trung binh: ";
	cin >> p.scoreAvg;

	return p;
}
NODE* GetNode(HOCSINH x)
{
	NODE* p = new NODE[1];
	if (p == NULL)
	{
		cout << "\nHET BO NHO\n";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}
void InputOne(LIST& l)
{
	NODE* p;
	HOCSINH x;
	x = GetInforStudent();
	p = GetNode(x);
	if (SlgHs==0)
		Init(l);
	int pos;
	cout << "\nMoi ban nhap vi tri can them: ";
	cin >> pos;
	while (pos<1 || pos>1+SlgHs)
	{
		cout << "\nMoi ban nhap lai: ";
		cin >> pos;
	}
	if (pos == SlgHs + 1)
		AddTail(l, p);
	else if (pos == 1)
		AddHead(l, p);
	else
		AddAt(l, p, pos);
	SlgHs++;
	cout << "\nTHEM THANH CONG !!!";
}
void Input(LIST& l)
{
	int soHs;
	cout << "\nNhap so luong hoc sinh can nhap thong tin: ";
	cin >> soHs;
	if(SlgHs==0)
		Init(l);
	for (int i = 1; i <= soHs; i++)
	{
		NODE* p;
		HOCSINH x;
		x = GetInforStudent();
		p = GetNode(x);
		AddTail(l, p);
	}	
	SlgHs += soHs;
	cout << "\nTHEM THANH CONG !!!";
}
void AddHead(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void AddTail(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void AddAt(LIST& l, NODE* p, int n)
{
	NODE* befor, * after;
	befor = l.pHead;
	for (int i = 1; i < n - 1; i++)
		befor = befor->pNext;
	after = befor->pNext;
	befor->pNext = p;
	p->pNext = after;
}
void Output(LIST l)
{
	int i = 1;
	cout << "\n\n========================= DANH SACH HOC SINH =========================\n\n";
	cout << setw(5) << left << "STT";
	cout.width(2);
	cout << setw(31) << left << "HO VA TEN";
	cout.width(2);
	cout << setw(10) << left << "LOP";
	cout.width(2);
	cout << setw(12) << left << "SDT";
	cout.width(2);
	cout << setw(7) << left << "DIEM TB\n";

	cout << setfill('-');
	cout << setw(70) << "-" << endl;
	cout << setfill(' '); // reset lai setfill
	for (NODE* p = l.pHead; p != NULL; p = p->pNext)
	{
		OutInforStud(p->data, i);
		i++;
	}
}
void OutInforStud(HOCSINH x, int i)
{
	cout << setw(5) << left << i;
	cout.width(2);
	cout << setw(31) << left << x.name;
	cout.width(2);
	cout << setw(10) << left << x.cla;
	cout.width(2);
	cout << setw(12) << left << x.NumPhone;
	cout.width(2);
	cout << setw(7) << left << x.scoreAvg << "\n";
	
}
void OutputRating(HOCSINH p, int i)
{
	char* xepLoai = Rating(p);
	cout << setw(5) << left << i;
	cout.width(2);
	cout << setw(31) << left << p.name;
	cout.width(2);
	cout << setw(31) << left << xepLoai << "\n";
}
void OutputRatingList(LIST l)
{
	cout << "\n\n========================= DANH SACH XEP LOAI HOC LUC =========================\n\n";
	cout << setw(5) << left << "STT";
	cout.width(2);
	cout << setw(31) << left << "HO VA TEN";
	cout.width(2);
	cout << setw(12) << left << "XEP LOAI" << "\n";

	cout << setfill('-');
	cout << setw(54) << "-" << endl;
	cout << setfill(' '); // reset lai setfill
	int i = 1;
	for (NODE* p = l.pHead; p != NULL; p = p->pNext)
	{
		OutputRating(p->data, i);
		i++;
	}
}
void DelIforStu(LIST& l)
{
	if (SlgHs == 0)
	{
		cout << "\nDanh sach rong";
		return;
	}
	int x = -1;
	cout << "\nNhap vi tri thong tin can xoa: ";
	cin >> x;
	while (x<1 || x>SlgHs)
	{
		cout << "Ban nhap vi tri khong hop le, vui long nhap lai vi tri can xoa: ";
		cin >> x;
	}
	if (x == 1)
		DelHead(l);
	else if (x == SlgHs)
		DelTail(l);
	else
		DelAt(l, x);
	SlgHs--;
	cout << "XOA THANH CONG";
}
void DelAt(LIST& l, int x)
{
	NODE* truoc, * sau;
	truoc = l.pHead;
	for (int i = 1; i < x - 1; i++)
		truoc = truoc->pNext;
	sau = truoc->pNext;
	truoc->pNext = sau->pNext;
	delete sau;
}
void DelHead(LIST& l)
{
	NODE* p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete p;
}
void DelTail(LIST& l)
{
	NODE* truoc, * sau;
	truoc = l.pHead;
	for (int i = 1; i < SlgHs - 1; i++)
		truoc = truoc->pNext;
	sau = truoc->pNext;
	truoc->pNext = NULL;
	delete sau;
}
char* Rating(HOCSINH p)
{
	char* kq = new char[12];
	char XL[12];
	if (p.scoreAvg >= 9)
		strcpy_s(XL, "Xuat sac");
	else if(p.scoreAvg >= 8)
		strcpy_s(XL, "Gioi");
	else if (p.scoreAvg >= 6.5)
		strcpy_s(XL, "Kha");
	else if (p.scoreAvg >= 5)
		strcpy_s(XL, "Trung binh");
	else 
		strcpy_s(XL, "Yeu");
	int i;
	for (i = 0; i < strlen(XL); i++)
		*(kq + i) = XL[i];
	*(kq + i) = '\0';
	return kq;
}
NODE* TimKiemTenvaLop(LIST l)
{
	char ten[31];
	char lop[10];
	cin.ignore();
	cout << "\nNhap ten tim kiem: ";
	cin.getline(ten, sizeof(ten));
	cout << "\nNhap lop tim kiem: ";
	cin.getline(lop, sizeof(lop));
	_strupr_s(ten);
	_strupr_s(lop);
	
	for (NODE* p = l.pHead; p != NULL; p = p->pNext)
	{
		char NAME[31];
		char CLA[10];
		strcpy_s(NAME, p->data.name);
		strcpy_s(CLA, p->data.cla);
		_strupr_s(NAME);
		_strupr_s(CLA);
		if (NAME == ten && CLA == lop)
			return p;
	}
}
void OutputFindNameAndClass(LIST l)
{
	NODE* x = TimKiemTenvaLop(l);
	cout << "\n\n========================= THONG TIN TIM KIEM =========================\n\n";
	cout << setw(5) << left << "STT";
	cout.width(2);
	cout << setw(31) << left << "HO VA TEN";
	cout.width(2);
	cout << setw(10) << left << "LOP";
	cout.width(2);	
	cout << setw(12) << left << "SDT";
	cout.width(2);
	cout << setw(7) << left << "DIEM TB\n";

	cout << setfill('-');
	cout << setw(70) << "-" << endl;
	cout << setfill(' '); // reset lai setfill
	
	cout << setw(31) << left << x->data.name;
	cout.width(2);
	cout << setw(10) << left << x->data.cla;
	cout.width(2);
	cout << setw(12) << left << x->data.NumPhone;
	cout.width(2);
	cout << setw(7) << left << x->data.scoreAvg << "\n";
}
int menuChinh()
{
	int luaChon;
	cout << "\n1. Nhap thong tin nhieu hoc sinh: ";
	cout << "\n2. Nhap them thong tin 1 hoc sinh: ";
	cout << "\n3. Xoa thong tin 1 hoc sinh: ";
	cout << "\n4. In bang ten va xep loai: ";
	cout << "\n5. In danh sach: ";
	cout << "\n6. Tim kiem thong tin theo ten va lop: ";
	cout << "\n0. THOAT";
	cout << "\nNHAP LUA CHON: ";
	cin >> luaChon;
	while (luaChon < 0 || luaChon>6)
	{
		system("cls");
		cout << "\n1. Nhap thong tin nhieu hoc sinh: ";
		cout << "\n2. Nhap them thong tin 1 hoc sinh: ";
		cout << "\n3. Xoa thong tin hoc sinh: ";
		cout << "\n4. In bang ten va xep loai: ";
		cout << "\n5. In danh sach: ";
		cout << "\n6. Tim kiem thong tin theo ten va lop: ";
		cout << "\n0. THOAT";
		cout << "\nLua chon khong hop le, moi ban nhap lai: ";
		cin >> luaChon;
	}
	return luaChon;
}
void xuLyLuaChon(int x, LIST &l)
{
	if (x == 0)
	{
		cout << "\n================================BYE================================\n\n";
		return;
	}
	if (x == 1)
	{
		Input(l);
	//	Output(l);
		system("pause");
	}
	else if (x == 2)
	{
		InputOne(l);
	//	Output(l);
		system("pause");
	}
	else if(x==3)
	{
		DelIforStu(l);
	//	Output(l);
		system("pause");
	}
	else if(x==4)
	{
		OutputRatingList(l);
		system("pause");
	}
	else if (x == 5)
	{
		Output(l);
		system("pause");
	}
	else
	{
		OutputFindNameAndClass(l);
		system("pause");
	}
}






















