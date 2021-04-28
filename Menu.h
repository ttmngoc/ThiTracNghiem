#pragma once
#include<iostream>
#include<mylib.h>

#define WHITE 15
#define YELLOW 14
#define RED 4
#define BLUE 1
#define GREEN 2
const int dong = 5;
const int cot = 20;
const int SPACE = 32;
const int ENTER = 13;
const int ESC = 27;
const int BSPACE = 8;

const int Up = 72;
const int Down = 80;
#define MAXMH 300
#define MAXLOP 500
#define MAXCHT 500
#define MAXCT 100
int nhap;
// MON HOC - MANG CON TRO
struct MonHoc
{
	char MaMH[16];
	char TenMH[51];
};
struct dsMonHoc
{
	int n=0;
	MonHoc *nodeMH[MAXMH];	// mang cho tro
};

// CAU DA THI
struct CauThi
{
	int id;
	string ND, A, B, C, D;
	int trangthai=1; // 0 - Dung	1 Sai
	char DapAn=' ';
};
struct dsCauThi
{
	int n=0;
	CauThi *nodeCT[MAXCT];
};

// BAI THI
struct BaiThi
{
	int SoCau;
	int Time;
	dsCauThi ct;
};

// 	DIEM THI - DANH SACH LIEN KET DON
struct DiemThi
{
	char MaMH[16];
	float Diem=-1;
	BaiThi bt;
};
struct dsDiemThi
{
	DiemThi data;
	dsDiemThi *next;	// danh sach lien ket don
};
typedef dsDiemThi *PTRDT;

// SINH VIEN - DANH SACH LIEN KET DON
struct SinhVien
{
	char MaSV[10];
	char Ho[50], Ten[10], Phai[4];
	char Password[10];
	PTRDT FirstDiem = NULL; 	// con tro toi danh sach diem thi
};
struct dsSinhVien
{
	SinhVien data;
	dsSinhVien *next;	// danh sach lien ket don
};
typedef dsSinhVien *PTRSV;

// LOP - MANG CON TRO
struct Lop
{
	char MaLop[10];
	char TenLop[50];
	char NienKhoa[10];
	PTRSV FirstSV =NULL; 	// con tro toi danh sach sinh vien
};
struct dsLop
{
	int n=0;
	Lop *nodelop[MAXLOP];		// mang con tro
};

// CAU HOI THI - CAY NHI PHAN TIM KIEM
struct CauHoiThi
{
	int ID;
	char MaMH[16];
	string ND, A, B, C, D;
	string DapAn;
};
struct dsCauHoiThi
{
	CauHoiThi data;
	dsCauHoiThi *left;
	dsCauHoiThi *right;
};
typedef dsCauHoiThi *PTRCHT;

char MenuGV [10][50]={"1. Them lop                            ",
					  "2. In danh sach lop theo nien khoa     ",
					  "3. Them sinh vien                      ",
					  "4. In danh sach sinh vien theo lop     ",
					  "5. Xem mon hoc                         ",
					  "6. Nhap cau hoi thi                    ",
					  "7. Thi trac nghiem                     ",
					  "8. In bai thi 1 mon hoc cua sinh vien  ",
					  "9. In bang diem cua 1 lop              ",
					  "10. Thoat                              "
};
char MenuCHT [5][50]={"1. Xuat danh sach cau hoi thi  ",
					  "2. Them cau hoi thi             ",
					  "3. Sua cau hoi thi              ",
					  "4. Xoa cau hoi thi              ",
					  "5. Thoat                        "
};
int SoMuc (char td [][50])
{
	int i;
	for(i = 0; td[i][0] != NULL; ++i);
	return i;
}
int MenuDong(char td [][50])
{
  Normal(); 
  clrscr();
  TextColor(236);
  gotoxy(19,2);
  cout << "==============THI TRAC NGHIEM==============";
  TextColor(15);
  int chon =0,so_item;
  int i;
	so_item = SoMuc(td);
  for ( i=0; i< so_item ; i++)
  { gotoxy(cot, dong +i);
    cout << td[i];
  }
  HighLight();
  gotoxy(cot,dong+chon);
  cout << td[chon];
  char kytu;
do {
  kytu = getch();
  if (kytu==0) kytu = getch();
  switch (kytu) {
    case Up :if (chon+1 >1)
  			  {
  		        Normal();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
              	chon --;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
  			  }
  			  break;
  	case Down :if (chon+1 <so_item)
	  			{
	  		        Normal();
	              	gotoxy(cot,dong+chon);
	              	cout << td[chon];
	              	chon ++;
	              	HighLight();
	              	gotoxy(cot,dong+chon);
	              	cout << td[chon];
	  			}
	  			break;
  	case 13 : 
	  {
	  	gotoxy(wherex(),wherey());
	  	Normal ();
	  	return chon+1;
	  }
  }  // end switch
  } while (1);
}
int DH(int phut,int giay,int thgian)
{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	gotoxy(20,0); TextColor(14);
	cout<<"Thoi gian lam bai: "<<thgian<<" phut. Het gio he thong se tu cap nhat ket qua!";
	gotoxy(40,1);
	cout<<"     ";
	gotoxy(40,1);
	int pht = ltm->tm_min;
	int ght = ltm->tm_sec;
	if((phut+thgian)>59 && pht<phut)
	{
		pht=pht+60;
		
	 } 
	if(pht-phut>=thgian&&ght>giay)
	{
		clrscr();
		TextColor(4);
		BaoLoi("HET GIO!");
		Normal();
		return ESC;
	 } 
	if(ght<giay)
	{ 
		pht--;
		ght=ght+60;
	 } 
	cout<<pht-phut<<":"<<ght-giay; TextColor(15);
}
int MenuThi(int x,int phut,int giay,int thgian)
{
	int a[x+1];
  Normal();
  int chon =0;
  int i; int dh=0;
  dh=DH(phut,giay,thgian);
		if(dh==ESC) return ESC;
  for ( i=0; i<=x ; i++)
  { gotoxy(cot, dong +i);
    
    if(i==x) cout<<"Nop bai";
	else cout <<"Cau "<<i+1<<endl;
	a[i] = i +1;
  }
  HighLight();
  gotoxy(cot,dong+chon);
  cout <<"Cau "<<a[chon] ;
  char kytu;
do {
  kytu = getch();
  if (kytu==0) kytu = getch();
  switch (kytu) {
    case Up :if (chon+1 >1)
  			  {
  		        Normal();
  		        dh=DH(phut,giay,thgian);
				if(dh==ESC) return ESC;
              	gotoxy(cot,dong+chon);
              	if(chon==x) cout<<"Nop bai";
              	else cout<<"Cau "<<a[chon];
              	chon --;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	cout<<"Cau "<<a[chon];
  			  }
  			  break;
  	case Down :if (chon+1 <=x)
  			  {
  		        Normal();
  		        dh=DH(phut,giay,thgian);
				if(dh==ESC) return ESC;
              	gotoxy(cot,dong+chon);
              	cout<<"Cau "<<a[chon];
              	chon ++;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	if(chon==x) cout<<"Nop bai";
              	else cout<<"Cau "<<a[chon];
  			  }
  			  break;
  	case 13 :
	  {
	  	dh=DH(phut,giay,thgian);
		if(dh==ESC) return ESC;
	  	Normal();
	  	clrscr();
	  	return chon+1;
	   } 
  }  // end switch
  }  while (1);
}
void Khung_Xuat_Lop() 
{
	gotoxy(0,0);
	cout << "\n\n\n\n\n";
	cout << "   +------------------------------------------------------------------------------------+";
	cout << "\n   |     |		      |					       |	        |";
	cout << "\n   |-----+--------------------+----------------------------------------+----------------|";
	cout << "\n   |	 |		      |					       |		|";
	cout << "\n   |	 |		      |					       |		|";
	cout << "\n   | 	 |		      |					       |		|";
	cout << "\n   |	 |		      |					       |		|";
	cout << "\n   |	 |		      |					       |		|";
	cout << "\n   |	 |		      |					       |		|";
	cout << "\n   |	 |		      |					       |		|";
	cout << "\n   |	 |		      |					       |		|";
	cout << "\n   |	 |		      |					       |		|";
	cout << "\n   |	 |		      |					       |		|";
	cout << "\n   |	 |		      |					       |		|";
	cout << "\n   |	 |		      |					       |		|";
	cout << "\n   |	 |		      |					       |		|";
	cout << "\n   |	 |		      |					       |		|";
	cout << "\n   |	 |		      |					       |		|";
	cout << "\n   |------------------------------------------------------------------------------------|";
	cout << "\n   |                                            				        |";
	cout << "\n   +------------------------------------------------------------------------------------+";
	TextColor(236);	gotoxy(33, 1);	cout << "                              ";
	gotoxy(33, 2);
	cout << "         DANH SACH LOP        ";
	gotoxy(33, 3);	cout << "                              ";
	
	TextColor(14);		gotoxy(5, 6);    	cout << "STT";
	gotoxy(17, 6);		cout << "MA LOP";
	gotoxy(48, 6);		cout << "TEN LOP";
	gotoxy(75, 6);		cout << "NIEN KHOA";
	gotoxy(4, 24);		TextColor(252);		cout << "ESC";
	TextColor(14);		cout << ": THOAT";
	gotoxy(20, 24);		TextColor(252);		cout << " 1 ";
	TextColor(14);		cout << ": THEM";
	gotoxy(36, 24);		TextColor(252);		cout << " 2 ";
	TextColor(14);		cout << ": SUA";
	gotoxy(50, 24);		TextColor(252);		cout << " 3 ";
	TextColor(14);		cout << ": XOA";
	gotoxy(0, 27);	
}

void Khung_Xuat_SV() {
	gotoxy(0, 0);
	cout << "\n\n\n\n\n   +----------------------------------------------------------------+";
	cout << "\n   |     |		 |		      |          |	    |";
	cout << "\n   |-----+---------------+--------------------+----------+----------|";
	cout << "\n   |	 |	         |		      |		 |	    |";
	cout << "\n   |	 |	         |		      |		 |	    |";
	cout << "\n   |	 |	         |		      |		 |	    |";
	cout << "\n   |	 |	         |		      |		 |	    |";
	cout << "\n   |	 |	         |		      |		 |	    |";
	cout << "\n   |	 |	         |		      |		 |	    |";
	cout << "\n   |	 |	         |		      |		 |	    |";
	cout << "\n   |	 |	         |		      |		 |	    |";
	cout << "\n   |	 |	         |		      |		 |	    |";
	cout << "\n   |	 |	         |		      |		 |	    |";
	cout << "\n   |	 |	         |		      |		 |	    |";
	cout << "\n   |	 |	         |		      |		 |	    |";
	cout << "\n   |	 |	         |		      |		 |	    |";
	cout << "\n   |	 |	         |		      |		 |	    |";
	cout << "\n   |	 |	         |		      |		 |	    |";
	cout << "\n   |----------------------------------------------------------------|";
	cout << "\n   |                                                                |";
	cout << "\n   +-----------------------------------------------------------------+";
	TextColor(236);	gotoxy(15, 1);	cout << "                                             ";
	gotoxy(15, 2);	cout << "   XUAT DANH SACH SINH VIEN 	            ";
	gotoxy(15, 3);	cout << "                                             ";
	TextColor(14);	gotoxy(5, 6);    cout << "STT";
	gotoxy(12, 6);	cout << "MA SINH VIEN";
	gotoxy(35, 6);	cout << "HO";
	gotoxy(51, 6);	cout << "TEN";
	gotoxy(61, 6);	cout << "PHAI";
//	gotoxy(72, 6);	cout << "PASSWORD";
	gotoxy(4, 24);		TextColor(252);		cout << "ESC";
	TextColor(14);		cout << ": THOAT";
	gotoxy(20, 24);		TextColor(252);		cout << " 1 ";
	TextColor(14);		cout << ": THEM";
	gotoxy(36, 24);		TextColor(252);		cout << " 2 ";
	TextColor(14);		cout << ": SUA";
	gotoxy(50, 24);		TextColor(252);		cout << " 3 ";
	TextColor(14);		cout << ": XOA";
	gotoxy(0, 27);
}

void Khung_Xuat_MonHoc() 
{
	gotoxy(0,0);
	cout << "\n\n\n\n\n";
	cout << "   +-------------------------------------------------------------------+";
	cout << "\n   |     |		      |					       |";
	cout << "\n   |-----+--------------------+----------------------------------------|";
	cout << "\n   |	 |		      |					       |";
	cout << "\n   |	 |		      |					       |";
	cout << "\n   | 	 |		      |					       |";
	cout << "\n   |	 |		      |					       |";
	cout << "\n   |	 |		      |					       |";
	cout << "\n   |	 |		      |					       |";
	cout << "\n   |	 |		      |					       |";
	cout << "\n   |	 |		      |					       |";
	cout << "\n   |	 |		      |					       |";
	cout << "\n   |	 |		      |					       |";
	cout << "\n   |	 |		      |					       |";
	cout << "\n   |	 |		      |					       |";
	cout << "\n   |	 |		      |					       |";
	cout << "\n   |	 |		      |					       |";
	cout << "\n   |	 |		      |					       |";
	cout << "\n   |-------------------------------------------------------------------|";
	cout << "\n   |                                            		       |";
	cout << "\n   +-------------------------------------------------------------------+";
	TextColor(236);	gotoxy(23, 1);	cout << "                              ";
	gotoxy(23, 2);
	cout << "       DANH SACH MON HOC      ";
	gotoxy(23, 3);	cout << "                              ";
	
	TextColor(14);		gotoxy(5, 6);    	cout << "STT";
	gotoxy(17, 6);		cout << "MA MON";
	gotoxy(48, 6);		cout << "TEN MON";
	gotoxy(4, 24);		TextColor(252);		cout << "ESC";
	TextColor(14);		cout << ": THOAT";
	gotoxy(20, 24);		TextColor(252);		cout << " 1 ";
	TextColor(14);		cout << ": THEM";
	gotoxy(36, 24);		TextColor(252);		cout << " 2 ";
	TextColor(14);		cout << ": SUA";
	gotoxy(50, 24);		TextColor(252);		cout << " 3 ";
	TextColor(14);		cout << ": XOA";
	gotoxy(0, 27);	
}

