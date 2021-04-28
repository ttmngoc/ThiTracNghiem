#pragma once
#include"Menu.h"
#include<fstream>
using namespace std;

// ============ THAO TAC NHAP ===========
void VietHoa(char *x)
{
	char a;
	for (int i = 0; i < strlen(x); ++i)
	{
		a = x[i];
		if (a >= 97 && a <= 122)
		{
			x[i] = a - 32;
		}
		else
			x[i] = a;
	}
}
int NhapMa(char *x, int n_max)
{
	char c;
	int i = 0;
	while(1)
	{
		c = getch();
		if (c == ESC)
		{
			x = "";	
			cout<<endl;		
			return ESC;
		}
		else if (c == ENTER)
		{
			if (i == 0){ 
				BaoLoi("Ban chua nhap thong tin, moi nhap lai!!");
				Sleep(2000);
				continue;
			}
			x[i] = '\0';
			cout << endl;
			return ENTER;
		}
		else if (c == BSPACE)
		{
			if (i == 0)	continue;
			else 
			{
				--i;
				cout << c << " " << c;
				x[i] = NULL;
				continue;
			}
		}
		else if (c == SPACE){
			BaoLoi("Chuoi can nhap khong duoc chua khoang trang. Xin nhap lai");
			continue;		
		}
		else if (i == n_max){
			BaoLoi("Vuot qua ki tu can nhap!");
			continue;
		}
		else 
		{
			if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))// nhap chu, so
				x[i] = c;
			else 
			{
				BaoLoi("Chuoi chi chua chu hoac so. Xin kiem tra lai!");
				continue;			
			}
		}
		if(c != 0){
			x[i] = c;
			cout << x[i];
		}
		++i;
	}
}
int NhapChuoi(char *x, int n_max)
{
	char c;
	int i = 0;
	int x1 = 0,y1 = 0, x2 = 0,y2 = 0;
	while(1)
	{
		c = getch();
		if (c == ESC)
		{
			x = "";
			cout<<endl;		
			return ESC;
		}
		else if (c == ENTER)
		{
			if (i == 0)
			{
				BaoLoi("Ban chua nhap thong tin, moi nhap lai!!");
				continue;
			}
			x[i] = '\0';
			cout << endl;
			return ENTER;
		}
		else if (c == BSPACE)
		{
			if (i == 0)	continue;
			else 
			{
				--i;
				cout << c << " " << c;
				x[i] = NULL;
				continue;
			}
		}
		else if (i == n_max){
			BaoLoi("Vuot qua ki tu can nhap!");
			continue;
		}
		else if (i == 0 && c == SPACE)
		{
			BaoLoi("Ki tu dau tien khong duoc la khoang trang. Xin kiem tra lai!");
			continue;
		}
		x[i] = c;
		if (c != 0)
			cout<< x[i];
		++i;
	}
}
int NhapPass( char *x, int n_max)
{
	char c;
	int i = 0;
	while(1)
	{
		c = getch();
		if (c == ESC)
		{
			x = "";
			cout<<endl;	
			return ESC;
		}
	
		else if (c == ENTER)
		{
			if (i == 0){
				BaoLoi("Muc nay khong duoc de trong. Xin kiem tra lai");
				continue;
			}
			x[i] = '\0';
			cout << endl;
			return ENTER;
		}
		else if (c == BSPACE)
		{
			if (i == 0)	continue;
			else 
			{
				--i;
				cout << c << " " << c;
				x[i] = NULL;
				continue;
			}
		}
		else if (c == SPACE){
			BaoLoi("Mat khau khong duoc chua khoang trang. Xin kiem tra lai!");
			continue;		
		}
		else if (i==n_max){
			BaoLoi("Vuot qua so ki tu can nhap!");
			continue;
		}
		else 
		{
			if (c >= 33 && c <= 126)// nhap chu, so, ki tu dac biet
				x[i] = c;
			else 
			{
				BaoLoi("Chuoi chi chua chu hoac so. Xin kiem tra lai!");	
				continue;			
			}
		}
		if(c != 0)
		{
			x[i] = c;
			cout<<"*";
		}
		++i;
	}
}

//==========GIAI PHONG========
void GPdsSV(PTRSV &First)
{ 
	PTRSV p;
	while(First != NULL)
	{
		p = First;
		First = First->next;
		delete p;
	}
}
void GPdsDiem(PTRDT &First)
{ 
	PTRDT p;
	while(First != NULL)
	{
		p = First;
		First = First->next;
		delete p;
	}
}
void GPdsLop(dsLop &ds)
{
	for(int i = 0; i < ds.n; ++i)
	{
		GPdsSV(ds.nodelop[i]->FirstSV);
		delete ds.nodelop[i];
	}
}
void GPdsMonHoc(dsMonHoc &ds)
{
	for(int i = 0; i < ds.n; ++i)
	{
		delete ds.nodeMH[i];
	}
}
void GPdsCHT(PTRCHT &root)
{
	if(root != NULL)    
   	{  
		GPdsCHT(root->left);
      	GPdsCHT(root->right);
     	delete root;
   	}
}

// ============ DIEM ==============
int DemSoMonDaThi(PTRDT dt)
{
	int dem = 0;
	for (PTRDT p = dt; p != NULL; p = p->next)  dem++; 
	return dem;
}
void ThemMonDaThi(PTRDT &dsdt, DiemThi diem)
{
	PTRDT p, first, last; 
	p = new dsDiemThi;
	p->data = diem;
	first = NULL;
	for (last = dsdt; last != NULL && stricmp(last->data.MaMH,diem.MaMH) < 0 ; first = last, last = last->next);
	if (last == dsdt)  // them nut vao dau danh sach lien ket
	{
		p->next = dsdt;
		dsdt = p;
	}
	else           // them nut p vao truoc nut last
	{
		p->next = last;
		first->next = p;
	}
}
bool KTMHDaThi(dsLop ds, char c[])
{
	for(int i=0;i<ds.n;i++)
	{
		for (PTRSV p = ds.nodelop[i]->FirstSV; p != NULL; p = p->next) 
		{
			if(stricmp(p->data.FirstDiem->data.MaMH,c)==0) return true;
		}
	}
	return false;
}

//========== MON HOC ===============
int KTMaMH(dsMonHoc ds, char c[])
{
	for(int i=0;i<ds.n;i++)
	{
		if(stricmp(ds.nodeMH[i]->MaMH,c)==0) return i;
	}
	return -1;
}
void KTMaMHCHT (PTRCHT dscht,char c[],bool &check)
{
	if(dscht!=NULL)
	{
		if( stricmp(dscht->data.MaMH,c)==0) check= true;
		KTMaMHCHT(dscht->left,c,check);
		KTMaMHCHT(dscht->right,c,check);
	}
}
int NhapMonHoc(dsMonHoc ds, MonHoc &mh)
{
	while(1)
	{
	clrscr();
	gotoxy(20,0); TextColor(236);
	cout<<"Nhan ESC de thoat!";
	gotoxy(20,1); TextColor(YELLOW);
	cout<<"Nhap MA MON: ";
	nhap = NhapMa(mh.MaMH,16);
	if(nhap==ESC) return ESC;
	if(mh.MaMH[strlen(mh.MaMH)-1]<=48||mh.MaMH[strlen(mh.MaMH)-1]>57)
   {
	   BaoLoi ("Ma mon chua dung");
       continue;
   }
   if(mh.MaMH[strlen(mh.MaMH)-2]>=48&&mh.MaMH[strlen(mh.MaMH)-2]<=57)
   {
	   BaoLoi ("Ma mon chua dung");
       continue;
   }
	VietHoa(mh.MaMH);
	if(KTMaMH(ds,mh.MaMH)>=0)
	{
		BaoLoi("MA MON bi trung!");
		continue;
	}
	else
	{
		gotoxy(20,3);
		cout<<"Nhap TEN MON HOC: ";
		nhap = NhapChuoi(mh.TenMH,50);
		if(nhap==ESC) return ESC;
		VietHoa(mh.TenMH);
		return 1;
	}
	}
}
int ThemMonHoc(dsMonHoc &ds)
{
	MonHoc mh;
	while(ds.n<MAXMH)
	{
		nhap = NhapMonHoc(ds,mh);
		if(nhap==ESC) return ESC;
		else
		{
			int i,k;
			if (ds.n ==MAXLOP )
			{
				BaoLoi ("Danh sach day"); return ESC;
			}
			for (i=0; i < ds.n && stricmp(ds.nodeMH[i]->MaMH,mh.MaMH) <0  ; i++ );
			for ( k = ds.n-1; k >=i  ; k--) 
			   ds.nodeMH[k+1]= ds.nodeMH[k];
			ds.nodeMH[i]= new MonHoc;
			*ds.nodeMH[i]=mh; ds.n++;
			return 1;
		}
	}
	if(ds.n==MAXMH) 
	{
		BaoLoi("Danh sach mon hoc day!");
		return ESC;
	}
}
int XoaMonHoc (dsLop dsLop, dsMonHoc &ds,PTRCHT dscht, int vitri)
{
	if (ds.n==0)
	{
		BaoLoi("Danh sach mon hoc rong!");
		return ESC;
	}
	char ma[16];
	XoaDong(27,3);
	TextColor(236);
	cout<<"Nhan ESC de thoat!";TextColor(YELLOW);
	cout<<"\nNhap MA MON HOC can xoa: ";
	nhap = NhapMa(ma,16);
	if(nhap==ESC) return ESC;
	vitri = KTMaMH(ds,ma);
	if(vitri <0)
	{
		BaoLoi("Khong co ma mon hoc nay!");
		return 0;
	}
	else
	{ 	
		// SINH VIEN CO DIEM MON DO ROI THI KHONG DUOC XOA
		if(KTMHDaThi(dsLop,ma)==true)
		{
			BaoLoi("Mon nay da co diem. Khong the xoa! ");
			return 0;
		}
		// TRONG DS CAU HOI THI CO MON DO THI KHONG DUOC XOA
		bool check=false;KTMaMHCHT(dscht,ma,check);
		if(check==true)
		{
			BaoLoi("Da co cau hoi thi cho mon nay. Khong the xoa!"); return 0;
		}
		// XOA BTH MON DO CHUA CO DIEM
		else
		{
			if(vitri==ds.n-1)
			{
			delete ds.nodeMH[vitri];
				ds.n--;
				ds.nodeMH[ds.n]==NULL;//tranh tinh trang con tro bi treo
			}
			else
			{
				delete ds.nodeMH[vitri];
				for(int j = vitri+1;j<ds.n;j++)
				{
					ds.nodeMH[j-1]=ds.nodeMH[j];
				}
				ds.n--;
				ds.nodeMH[ds.n]==NULL;//tranh tinh trang con tro bi treo
			}
			return 1;
		}
	}
}
int SuaMonHoc(dsLop dsLop,dsMonHoc &ds,PTRCHT dscht)
{
	int vitri;
	MonHoc mh;
	XoaDong(27,4);TextColor(236);
	cout<<"Nhan ESC de thoat!";TextColor(YELLOW);
	cout<<"\nNhap MA MON HOC can sua: ";
	nhap = NhapMa(mh.MaMH,16);
	if(nhap ==ESC) return ESC;
	vitri = KTMaMH(ds,mh.MaMH);
	if(vitri<0)
	{
		BaoLoi("Khong co ma mon hoc nay!");
		return 0;
	}
	else
	{
		// DIEU KIEN MON DO DA CO DIEM THI KHONG THE SUA MA MON
		if(KTMHDaThi(dsLop,mh.MaMH)==true)
		{
			BaoLoi("Mon nay da co diem. Khong the sua MA MON! ");
			TextColor(236);
			cout<<"Nhan ESC de thoat!"; TextColor(YELLOW);
			cout<<"\nNhap ten mon can sua: ";
		    nhap= NhapChuoi (mh.TenMH,50);
		    VietHoa(mh.TenMH);
		    if(nhap == ESC) return ESC;
		    strcpy(ds.nodeMH[vitri]->TenMH,mh.TenMH);
		    BaoLoi("Cap nhat thanh cong");
			return 1;
		}
		// MON DO DA CO TRONG DS CAU HOI THI KHONG THE SUA MA MON
		bool check=false;KTMaMHCHT(dscht,mh.MaMH,check);
		if(check==true)
		{
			BaoLoi("Mon nay da co cau hoi thi. Khong the sua MA MON! ");
			TextColor(236);
			cout<<"Nhan ESC de thoat!"; TextColor(YELLOW);
			cout<<"\nNhap ten mon can sua: ";
		    nhap= NhapChuoi (mh.TenMH,50);
		    VietHoa(mh.TenMH);
		    if(nhap == ESC) return ESC;
		    strcpy(ds.nodeMH[vitri]->TenMH,mh.TenMH);
		    BaoLoi("Cap nhat thanh cong");
			return 1;
		}
		// SUA BTH MON DO CHUA CO DU LIEU LIEN QUAN
		if(vitri==ds.n-1)
		{
		delete ds.nodeMH[vitri];
			ds.n--;
			ds.nodeMH[ds.n]==NULL;//tranh tinh trang con tro bi treo
		}
		else
		{
			delete ds.nodeMH[vitri];
			for(int j = vitri+1;j<ds.n;j++)
			{
				ds.nodeMH[j-1]=ds.nodeMH[j];
			}
			ds.n--;
			ds.nodeMH[ds.n]==NULL;//tranh tinh trang con tro bi treo
		}
		nhap = ThemMonHoc(ds);
		return nhap;
	}
}

int XetMon(char *x) // XET MON DANH CHO LOP MAY
{
	return x[strlen(x)-1] -48;
}
//========== CAU HOI THI ============
int DemCauHoiThi(PTRCHT dscht) 
{
	if (dscht != NULL)
	{
		return (DemCauHoiThi(dscht->left) + DemCauHoiThi(dscht->right) + 1);
	}
	else return 0;
}

PTRCHT KTCHT (PTRCHT dscht,int x)
{
	PTRCHT p;
	p = dscht;
	if(p==NULL) return NULL;
	while(p!=NULL && p->data.ID!=x)
	{
		if(x<p->data.ID) p = p->left;
		else p = p->right;
	}
	return p;
}

int SoSanhChuoi(string s1, string s2)
{
		for(int i = 0; i < s1.length(); i++)//string.length() => Tra ve so ki tu chuoi so
		{
			s1[i] = toupper(s1[i]);//toupper(int c) => bien doi ki tu thuong thanh in hoa
		}
		for(int i = 0; i < s2.length(); i++)
		{
			s2[i] = toupper(s2[i]);
		}
		if(s1 == s2)
			return 0;
		else 
			return 1;		
}
int random(PTRCHT dscht,int min,int max)
{ 
	int x=0;
	x= min + rand()%(max - min +1);
	if(KTCHT(dscht,x)!=NULL) random(dscht,min,max);
	return x;
}  
void ThemCauHoiThi(PTRCHT &dscauhoithi, CauHoiThi cht)
{
	if (dscauhoithi==NULL) 
	{
		PTRCHT p = new dsCauHoiThi;
		p->data = cht;
		p->left = p->right = NULL;
		dscauhoithi = p;
		return;
	}
	else 
	{
		if (dscauhoithi->data.ID > cht.ID) {
			ThemCauHoiThi(dscauhoithi->left, cht);
		}
		else {
			ThemCauHoiThi(dscauhoithi->right, cht);
		}
	}
}

int NhapCauHoiThi(dsMonHoc dsmh,PTRCHT &dscht)
{
	if(DemCauHoiThi(dscht)==MAXCHT)
	{
		BaoLoi("Danh sach cau hoi thi day!");
		return ESC;
	}
	CauHoiThi cht;
	int y;
	y = wherey();
	while(true)
	{
		XoaDong(y,3);
		TextColor(236);
		cout<<"\nNhan ESC de thoat!";
		TextColor(YELLOW);
		cout<<"\nNhap MA MON HOC: ";
		nhap = NhapMa(cht.MaMH,16);
		if(nhap == ESC) return ESC;
		VietHoa(cht.MaMH);
		if(KTMaMH(dsmh,cht.MaMH)<0)
		{
			BaoLoi("Ma mon khong dung!");
			continue;
		}
		break;
	}
	cout<<"\nID CAU HOI DUOC CAP PHAT NGAU NHIEN.\n";
	if(DemCauHoiThi(dscht)==0) cht.ID=MAXCHT;	// HAN CHE CAY BI SUY BIEN
	else if(DemCauHoiThi(dscht->left)>=DemCauHoiThi(dscht->right))cht.ID=random(dscht,MAXCHT+1,MAXCHT*2);
	else cht.ID=random(dscht,1,MAXCHT-1);
	TextColor(236);
	cout<<"\nNhan ENTER khi Cau Hoi trong de thoat!";
	TextColor(WHITE);
	cout<<"\nNhap cau hoi: ";
	fflush(stdin);
  	getline(cin,cht.ND);
  	if(cht.ND=="") return ESC;
A:	cout<<"A. ";
 	fflush(stdin);
  	getline(cin,cht.A);
  	if(cht.A=="")
	  {
	  	XoaDong(wherey()-1,1);
	  	BaoLoi("Dap an khong trong!");
	  	goto A;
	  } 
B:	cout<<"B. ";
	fflush(stdin);
  	getline(cin,cht.B);
  	if(cht.B=="")
	  {
	  	XoaDong(wherey()-1,1);
	  	BaoLoi("Dap an khong trong!");
	  	goto B;
	  }
C:	cout<<"C. ";
	fflush(stdin);
  	getline(cin,cht.C);
  	if(cht.C=="")
	  {
	  	XoaDong(wherey()-1,1);
	  	BaoLoi("Dap an khong trong!");
	  	goto C;
	  }
D:	cout<<"D. ";
	fflush(stdin);
  	getline(cin,cht.D);
  	if(cht.D=="")
	  {
	  	XoaDong(wherey()-1,1);
	  	BaoLoi("Dap an khong trong!");
	  	goto D;
	  }
  	y = wherey();
	while(true)
	{
		XoaDong(y,1);
		TextColor(YELLOW);
	DA:	cout<<"Nhap dap an: ";
		fflush(stdin);
  		getline(cin,cht.DapAn);
  		if(cht.DapAn=="")
		  {
		  	XoaDong(wherey()-1,1);
		  	BaoLoi("Dap an khong trong!");
		  	goto DA;
		  }
		if(SoSanhChuoi(cht.A,cht.DapAn)==0||SoSanhChuoi(cht.B,cht.DapAn)==0||SoSanhChuoi(cht.C,cht.DapAn)==0||SoSanhChuoi(cht.D,cht.DapAn)==0) break;
		else
		{
			BaoLoi("Khong co dap an nay! Moi nhap lai.");
			continue;
		}
	}
	ThemCauHoiThi(dscht,cht);
	BaoLoi("Them cau hoi thi thanh cong!");
	return 1;
}

int SuaCauHoiThi(dsMonHoc dsmh,PTRCHT &dscht)
{
	if(dscht==NULL) return ESC;
	CauHoiThi cht;
	int y = wherey();
	while(true)
	{
		XoaDong(y,2); TextColor(236);
		cout<<"Nhan -1 de thoat!";
		TextColor(YELLOW);
		cout<<"\nNhap ID cau hoi: ";
		cin>>cht.ID;
		if(cht.ID==-1) return ESC;
		if(KTCHT(dscht,cht.ID)==NULL)
		{
			BaoLoi("ID nay chua co");
			continue;
		}
		break;
	}
	y = wherey();
	while(true)
	{
		XoaDong(y,3);
		TextColor(236);
		cout<<"\nNhan ESC de thoat!";
		TextColor(YELLOW);
		cout<<"\nSua MA MON HOC: ";
		nhap = NhapMa(cht.MaMH,16);
		if(nhap == ESC) return ESC;
		if(KTMaMH(dsmh,cht.MaMH)<0)
		{
			BaoLoi("Ma mon khong dung!");
			continue;
		}
		break;
	}
	TextColor(WHITE);
	cout<<"\nNhap cau hoi: ";
	fflush(stdin);
  	getline(cin,cht.ND);
	cout<<"A. ";
	fflush(stdin);
  	getline(cin,cht.A);
	cout<<"B. ";
	fflush(stdin);
  	getline(cin,cht.B);
	cout<<"C. ";
	fflush(stdin);
  	getline(cin,cht.C);
	cout<<"D. ";
	fflush(stdin);
  	getline(cin,cht.D);
  	y = wherey();
	while(true)
	{
		XoaDong(y,1);
		TextColor(YELLOW);
		cout<<"Nhap dap an: ";
		fflush(stdin);
  		getline(cin,cht.DapAn);
		if(SoSanhChuoi(cht.A,cht.DapAn)==0||SoSanhChuoi(cht.B,cht.DapAn)==0||SoSanhChuoi(cht.C,cht.DapAn)==0||SoSanhChuoi(cht.D,cht.DapAn)==0) break;
		else
		{
			BaoLoi("Khong co dap an nay! Moi nhap lai.");
			continue;
		}
	}
	
	PTRCHT kt;
	kt = KTCHT(dscht,cht.ID);
	kt->data = cht;
	return 1;
}

void TimCucTrai(PTRCHT &X, PTRCHT &Y) { 
	if (Y->left != NULL)
	{
		TimCucTrai(X, Y->left);// tìm ra node trai nhat ?
	}
	else 
	{
		X->data = Y->data;	//cap nhat du lieu vo cung trai sang con tro can xoa
		X = Y;				//cap nhat dia chi vo cung trai sang con tro can xoa
		Y = Y->right;		//ben phai cua vo cung trai dduwa leen
	}

}
void XoaCHT(PTRCHT &tree, int x)
{
	// neu nhu cây dang rong
	if (tree == NULL) return; // ket thúc hàm
	// neu nhu x nho hon node goc
	if (x < tree->data.ID)
		{
			XoaCHT(tree->left, x); // duyet sang trái
		}
	else if (x > tree->data.ID)
		{
			XoaCHT(tree->right, x); // duyet sang phai 
		}
	else 
		{
			PTRCHT p = tree; //Cho con tro tai vi tri muon xoa vao 1 con tro? tam. de lat' xoa
			if (tree->left == NULL && tree->right==NULL) //Truong hop 2 nhanh con NULL
			{
				delete tree; tree = NULL; return;
			}
			else if (tree->left == NULL && tree->right!=NULL ) //Truong hop co nhanh con ben phai
			{
				tree = tree->right;
			}
			else if (tree->left != NULL && tree->right==NULL ) //Truong hop co nhanh con ben trai
			{
				tree = tree->left;
			}
			else // node can xóa là node có 2 con
			{
				
				TimCucTrai(p, tree->right);
				delete p;
			}
		}
	
}
int XoaCauHoiThi(PTRCHT &dscht)
{
	if(dscht==NULL)
	{
		BaoLoi("Danh sach rong. Khong the xoa!");
		return ESC;
	}
	int id;
	int y = wherey();
	while(true)
	{
		XoaDong(y,2);TextColor(236);
		cout<<"Nhan -1 de thoat!";TextColor(YELLOW);
		cout<<"\nNhap ID cau hoi: ";
		cin>>id;
		if(id==-1) return ESC;
		if(KTCHT(dscht,id)==NULL)
		{
			BaoLoi("ID nay chua co");
			continue;
		}
		break;
	}
	XoaCHT(dscht,id);
	BaoLoi("Xoa thanh cong!");
	return 1;
}

//======== CAU THI - CAU SINH VIEN DA THI ===========
int randomso(int min,int max)
{
	return rand()%(max - min +1)+min;
}
void randomDapAn(CauHoiThi &cht)
{
	CauHoiThi temp=cht;
	int a[4]; int x; int i=0;
	while(i<4)
	{
		RD:	x=randomso(0,3);
		for(int j=0;j<i;j++)
		{
			if(a[j]==x) goto RD;
		}
		a[i]=x; i++;
	}
	if(a[0]==0) temp.A=cht.A;
			else if(a[0]==1) temp.A=cht.B;
			else if(a[0]==2) temp.A=cht.C;
			else temp.A=cht.D;
	if(a[1]==0) temp.B=cht.A;
			else if(a[1]==1) temp.B=cht.B;
			else if(a[1]==2) temp.B=cht.C;
			else temp.B=cht.D;
	if(a[2]==0) temp.C=cht.A;
			else if(a[2]==1) temp.C=cht.B;
			else if(a[2]==2) temp.C=cht.C;
			else temp.C=cht.D;
	if(a[3]==0) temp.D=cht.A;
		else if(a[3]==1) temp.D=cht.B;
		else if(a[3]==2) temp.D=cht.C;
		else temp.D=cht.D;
		cht=temp;
}
void TimCauHoiThi (PTRCHT dscht,PTRCHT &ds,char *ma,int &dem)
{
	if(dscht!=NULL)
	{
		if(stricmp(dscht->data.MaMH,ma)==0)
		{
			randomDapAn(dscht->data);
			ThemCauHoiThi(ds,dscht->data);
			dem++;
		}
		TimCauHoiThi(dscht->left,ds,ma,dem);
		TimCauHoiThi(dscht->right,ds,ma,dem);
	}
}
void TimMangCauHoiThi (PTRCHT dscht,int a[],int &i)
{
	if(dscht!=NULL)
	{	
		a[i]=dscht->data.ID;
		i++;
		TimMangCauHoiThi(dscht->left,a,i);
		TimMangCauHoiThi(dscht->right,a,i);
	}
}
void XoaPTMang(int a[],int &soluong, int vt)
{
	for(int i = vt; i < soluong; i++)
	{
		a[i] = a[i + 1]; 
	}
	soluong--;
}

void ThiTracNghiem(PTRCHT dsch,int a[], int chon,dsCauThi &thi,int thgian,int soluong)
{
	int dh=0;
	time_t now = time(0);
	tm *ltm = localtime(&now);
	int phut = ltm->tm_min;
	int giay = ltm->tm_sec; 
	int x=0; char key; int trangthai;
	for(int i=0;i<thi.n;i++)
	{
		thi.nodeCT[i] = new CauThi;
		x = randomso(0,soluong-1);
		thi.nodeCT[i]->id=a[x];
		XoaPTMang(a,soluong,x);
	}
	do
	{
NHAP:	clrscr();
		nhap = MenuThi(chon,phut,giay,thgian);
		dh=DH(phut,giay,thgian);
		if(dh==ESC||nhap==ESC) break;
		nhap=nhap-1;
		if(nhap==chon) 
		{
			for(int i=0;i<thi.n;i++)
			{
				if(thi.nodeCT[i]->DapAn==' ')
				{
					TextColor(4);
					gotoxy(10,wherey()+1);
					cout<<"Cau "<<i+1<<" chua lam!";
					Sleep(800);
					goto NHAP;
				}
			}
			break;
		}
		PTRCHT p=NULL;
		p=KTCHT(dsch,thi.nodeCT[nhap]->id);
			dh=DH(phut,giay,thgian);
			if(dh==ESC||nhap==ESC) break;
		if(thi.nodeCT[nhap]->DapAn==' ')
		{
			gotoxy(0,2);
			cout<<"\nCau hoi "<<nhap+1<<": "<<p->data.ND;
			cout<<"\nA. "<<p->data.A;
			cout<<"\nB. "<<p->data.B;
			cout<<"\nC. "<<p->data.C;
			cout<<"\nD. "<<p->data.D;
			thi.nodeCT[nhap]->ND=p->data.ND;
			thi.nodeCT[nhap]->A=p->data.A;
			thi.nodeCT[nhap]->B=p->data.B;
			thi.nodeCT[nhap]->C=p->data.C;
			thi.nodeCT[nhap]->D=p->data.D;
	CHON:	gotoxy(0,10);
			TextColor(YELLOW);
			cout<<"\nChon: ";
			cin>>key;
			dh=DH(phut,giay,thgian);
			if(dh==ESC || nhap==ESC) break;
			if(key=='a' || key=='A')
				{
					trangthai = SoSanhChuoi(p->data.A,p->data.DapAn);
				}
			else if(key=='b' || key=='B')
				{
					trangthai = SoSanhChuoi(p->data.B,p->data.DapAn);
				}
			else if(key=='c' || key=='C')
				{
					trangthai = SoSanhChuoi(p->data.C,p->data.DapAn);
				}
			else if(key=='d' || key=='D')
				{
					trangthai = SoSanhChuoi(p->data.D,p->data.DapAn);
				}
			else
			{
				TextColor(4);
				gotoxy(0,12);
				cout<<"KHONG PHU HOP!";
				Sleep(500);
				XoaDong(10,5);
				TextColor(WHITE);
				goto CHON;
			}
			thi.nodeCT[nhap]->DapAn=key;
			thi.nodeCT[nhap]->trangthai=trangthai;
			continue;
		}
		else
		{
			gotoxy(0,2);
			cout<<"\nCau hoi "<<nhap+1<<": "<<thi.nodeCT[nhap]->ND;
			cout<<"\nA. "<<thi.nodeCT[nhap]->A;
			cout<<"\nB. "<<thi.nodeCT[nhap]->B;
			cout<<"\nC. "<<thi.nodeCT[nhap]->C;
			cout<<"\nD. "<<thi.nodeCT[nhap]->D;
			dh=DH(phut,giay,thgian);
			if(dh==ESC||nhap==ESC) break;
			gotoxy(0,9);
			cout<<"Da Chon: "<<thi.nodeCT[nhap]->DapAn;
			TextColor(4);
			cout<<"\nNhan Space de sua. ";
			char k;
			k=getch();
			dh=DH(phut,giay,thgian);
			if(dh==ESC||nhap==ESC) break;
			if(k==SPACE)
			{
				XoaDong(10,2); goto CHON;
			 } 
			continue;
		}
	}while(nhap<chon);
	clrscr();
	BaoLoi("Ket thuc!");
}
float TinhDiem(int x,dsCauThi cauthi)
{
	float diem=0.0;
	for(int i=0;i<cauthi.n;i++)
	{
		if(cauthi.nodeCT[i]->trangthai==0)
		{
			diem=diem + (10.0/x);
		}
	}
	return diem;
}
//======== SINH VIEN ===========
int DemSinhVien(PTRSV SV)
{
	int dem = 0;
	for (PTRSV p = SV; p != NULL; p = p->next) { dem++; }
	return dem;
}
PTRSV KTSV(PTRSV First, char *masv) // kiem tra ma sinh do co trong lop khong.
{
	for(PTRSV p = First; p != NULL; p = p->next)
		if(stricmp(p->data.MaSV, masv) == 0)	return p;
	return NULL;
}
PTRSV KTSVtrongDS(dsLop dslop, char *ma) // KIEM TRA SV TRONG TOAN BO DS
{
	PTRSV p=NULL;
	for(int i=0;i<dslop.n;i++)
	{
		p = KTSV(dslop.nodelop[i]->FirstSV,ma);
		if(p!=NULL) return p;
	}
	return NULL;
}
bool KTSVDaThi(PTRSV first, char masv[])
{
	for(PTRSV p = first; p != NULL; p = p->next)
	{
		if(stricmp(p->data.MaSV,masv)==0 && DemSoMonDaThi(p->data.FirstDiem)==0) return false;
	}
	return true;
}
int NhapSV(dsLop dslop,PTRSV DSSV,SinhVien &sv)
{
	char temp[2];
	PTRSV p;
	while(true)
{
	clrscr();
	TextColor(236); 
	cout<<"Nhan ESC de thoat!";TextColor(YELLOW);
	cout<<"\nNhap Ma sinh vien: ";
	nhap =NhapMa(sv.MaSV,10);
	if(nhap == ESC) return ESC;
	if(sv.MaSV[1]<=48||sv.MaSV[1]>57)
   {
	   BaoLoi ("Ma lop chua dung");
       continue;
   }
   if(sv.MaSV[2]>=48&&sv.MaSV[2]<=57)
   {
	   BaoLoi ("Ma lop chua dung");
       continue;
   }
	VietHoa(sv.MaSV);
	if(KTSVtrongDS(dslop,sv.MaSV)!=NULL)
	{
		BaoLoi("Ma sinh vien bi trung!");
		continue;
	}
	cout<<"\nNhap Ho: ";
	nhap =NhapChuoi(sv.Ho,50);
	if(nhap==ESC) return ESC;
	VietHoa(sv.Ho);
	cout<<"\nNhap Ten: ";
	nhap =NhapChuoi(sv.Ten,10);
	if(nhap==ESC) return ESC;
	VietHoa(sv.Ten);
	cout<<"\nNhap Phai: ";
	nhap =NhapMa(sv.Phai,10);
	if(nhap==ESC) return ESC;
	VietHoa(sv.Phai);
	cout<<"\nNhap password: ";
	nhap =NhapPass(sv.Password,10);
	if(nhap==ESC) return ESC;
	return 1;
}

}
void ThemSV(PTRSV &DSSV, SinhVien sv)
{
	PTRSV p, first, last; 
	p = new dsSinhVien;
	p->data = sv;
	first = NULL;
	for (last = DSSV; last != NULL && stricmp(last->data.MaSV,sv.MaSV) < 0 ; first = last, last = last->next);
	if (last == DSSV)  // them nut vao dau danh sach lien ket
	{
		p->next = DSSV;
		DSSV = p;
	}
	else           // them nut p vao truoc nut last
	{
		p->next = last;
		first->next = p;
	}

}
void XoaDauSV(PTRSV &DSSV) 
{
	PTRSV p = DSSV;	DSSV = DSSV->next;	delete p;
}
void XoaGiuaSV(PTRSV &DSSV, char c[]) 
{
	PTRSV temp = NULL;
	for (PTRSV p = DSSV; p != NULL; p = p->next)
	{
		if (stricmp(p->data.MaSV, c) == 0)
		{
			temp->next = p->next;	delete p;	return;
		}
		temp = p; // temp luon la con tro truoc ben trai' cua con tro dang duyet
	}
}
void XoaCuoiSV(PTRSV &DSSV)
{
	PTRSV temp = NULL;
	for (PTRSV p = DSSV; p != NULL; p = p->next)
	{
		if (p->next == NULL)
		{
			temp->next = NULL;	delete p;	return;
		}
		temp = p; // temp luon la con tro truoc ben trai' cua con tro dang duyet
	}
}
void XoaSV(PTRSV &DSSV, char ma[])
{
	for (PTRSV p = DSSV; p != NULL; p = p->next)
	{
		if ((stricmp(p->data.MaSV, ma)) == 0 && p == DSSV)
		{
			XoaDauSV(DSSV);return;
		}
		if ((stricmp(p->data.MaSV, ma) == 0) && (p->next == NULL)) 
		{
			XoaCuoiSV(DSSV);return;
		}
		if (stricmp(p->data.MaSV, ma) == 0)
		{
			XoaGiuaSV(DSSV, ma);return ;
		}
	}
}
int SuaSV(dsLop dslop, PTRSV DSSV, char ma[])
{
	SinhVien sv;
	if(KTSV(DSSV,ma)==NULL)
	{
		BaoLoi("MA SINH VIEN khong dung!");
		return 0;
	}
	else if(KTSVDaThi(DSSV,ma)==true)
	{
		BaoLoi("Sinh vien da co diem. Khong the sua MA SINH VIEN!");
		DSSV = KTSV(DSSV,ma);
		TextColor(236);
		cout<<"Nhan ESC de thoat!";TextColor(WHITE);
		cout<<"\nNhap Ho: ";
		nhap =NhapChuoi(sv.Ho,50);
		if(nhap==ESC) return ESC;
		VietHoa(sv.Ho);
		cout<<"Nhap Ten: ";
		nhap =NhapChuoi(sv.Ten,10);
		VietHoa(sv.Ten);
		cout<<"Nhap Phai: ";
		nhap =NhapMa(sv.Phai,10);
		VietHoa(sv.Phai);
		cout<<"Nhap password: ";
		nhap =NhapPass(sv.Password,10);
		strcpy(DSSV->data.Ho,sv.Ho);
		strcpy(DSSV->data.Ten,sv.Ten);
		strcpy(DSSV->data.Phai,sv.Phai);
		strcpy(DSSV->data.Password,sv.Password);
		return 1;
	}
	else
	{
		XoaSV(DSSV,ma);
		nhap = NhapSV(dslop,DSSV,sv);
		if(nhap==ESC) return ESC;
		ThemSV(DSSV,sv);
		return 1;
	} 
}

int XetLop(char *x)
{
	return x[1]-48;
}
//============ LOP =================
int	 KTMaLop(dsLop ds, char c[])
{
	for (int i = 0; i < ds.n; i++)
	{
		if (stricmp(ds.nodelop[i]->MaLop, c) == 0)
		{
			return i;	// neu trung tra ve vi tri
		}
	}
	return -1;			// khong tim thay ptu tra -1
}

void XoaLop(dsLop &dslop, int i)
{
	if(i<0 || i>dslop.n || dslop.n==0 ) return;
	if(i==dslop.n)
	{
	delete dslop.nodelop[dslop.n];
		dslop.n--;
		dslop.nodelop[dslop.n]==NULL;//tranh tinh trang con tro bi treo
	}
	else
	{
		delete dslop.nodelop[i];
		for(int j = i+1;j<dslop.n;j++)
		{
			dslop.nodelop[j-1]=dslop.nodelop[j];
		}
		dslop.n--;
		dslop.nodelop[dslop.n]==NULL;//tranh tinh trang con tro bi treo
	}
}
int  NhapLop (dsLop &ds, Lop &lop)
{
while (1){
	clrscr();TextColor(236);
	cout<<"Nhap ESC de thoat!";TextColor(YELLOW);
   cout << "\nNhap ma lop : " ; 
   nhap = NhapMa (lop.MaLop,50);
   if(nhap == ESC) return ESC;
   if(lop.MaLop[1]<=48||lop.MaLop[1]>57)
   {
	   BaoLoi ("Ma lop chua dung");
       continue;
   }
   if(lop.MaLop[2]>=48&&lop.MaLop[2]<=57)
   {
	   BaoLoi ("Ma lop chua dung");
       continue;
   }
   VietHoa(lop.MaLop);
   if (KTMaLop(ds,lop.MaLop)>=0)
   {
       BaoLoi ("Ma lop bi trung");
       continue;
   }
   cout<<"\nNhap ten lop: ";
    nhap= NhapChuoi (lop.TenLop,50);
    if(nhap == ESC) 	return ESC;
    VietHoa(lop.TenLop);
	cout<<"\nNhap nien khoa: ";
    nhap = NhapChuoi (lop.NienKhoa,9); 
    if(nhap == ESC) 	return ESC;
    return 1;
}
}

int ThemLop (dsLop &ds){
	 Lop lop;
	 nhap =NhapLop(ds,lop);
	 while (ds.n <MAXLOP)
	 {  
	    if (nhap==ESC)  return ESC;
	    int i, k;
		if (ds.n ==MAXLOP )
		{
			BaoLoi ("Danh sach day"); return ESC;
		}
		for (i=0; i < ds.n && stricmp(ds.nodelop[i]->MaLop,lop.MaLop) <0  ; i++ );
		for ( k = ds.n-1; k >=i  ; k--) 
		   ds.nodelop[k+1]= ds.nodelop[k];
		ds.nodelop[i]= new Lop;
		*ds.nodelop[i]=lop; ds.n++;
		return 1;
	 }
	 if (ds.n==MAXLOP) 
	 {
	 	BaoLoi ("Danh sach day"); return ESC;
	 }
}

int SuaLop(dsLop &ds) 
{
	XoaDong(27,6);
	Lop p ;
	char ma[10],temp[2];
	int vitri;
	TextColor(236);
	cout<<"Nhan ESC de thoat!";TextColor(YELLOW);
	cout<<"\nNhap MA LOP can sua: ";
	nhap = NhapMa(ma,10);
	if(nhap == ESC) return ESC;
	vitri = KTMaLop(ds,ma);
	if(vitri<0)
	{
		BaoLoi("Ma lop khong dung!");
		return 0;
	}
	else if (ds.nodelop[vitri]->FirstSV != NULL)
	{
		Lop p;
		BaoLoi("Lop nay da co Sinh Vien khong the sua MA LOP!");
		TextColor(236);
		cout<<"Nhan ESC de thoat!";TextColor(WHITE);
		cout<<"\nNhap ten lop: ";
	    nhap= NhapChuoi (p.TenLop,50);
	    if(nhap == ESC) return ESC;
	    VietHoa(p.TenLop);
		cout<<"\nNhap nien khoa: ";
	    nhap = NhapChuoi (p.NienKhoa,9);
	    strcpy(ds.nodelop[vitri]->TenLop,p.TenLop);
	    strcpy(ds.nodelop[vitri]->NienKhoa,p.NienKhoa);
	    BaoLoi("Cap nhat thanh cong");
	    return 1;
	}
	else
	{
		XoaLop(ds,vitri);
		nhap =NhapLop(ds,p);
		if(nhap==ESC) return ESC;
		else 
		{
			int i;
			for (int i=0; i < ds.n && stricmp(ds.nodelop[i]->MaLop,p.MaLop) <0  ; i++ );
			for ( int k = ds.n-1; k >=i  ; k--) 
			   ds.nodelop[k+1]= ds.nodelop[k];
			ds.nodelop[i]= new Lop;
			*ds.nodelop[i]=p; ds.n++;
		}
		return 1;
	}
}

// ============== DOC - GHI FILE ==============
void DocFile(dsLop &ds)
{
	ifstream filein;
	string data;
	int x,somh;
	filein.open("DanhSachLop.txt",ios_base::in);
	filein >> ds.n;
	getline(filein,data);
	if(filein.fail() == true) BaoLoi("Khong doc duoc file");
	for(int i=0;i<ds.n;i++)
	{
		ds.nodelop[i]=new Lop;
		getline(filein,data,',');
		strcpy(ds.nodelop[i]->MaLop, data.c_str());
		getline(filein,data,',');
		strcpy(ds.nodelop[i]->TenLop, data.c_str());
		getline(filein,data);
		strcpy(ds.nodelop[i]->NienKhoa, data.c_str());
		ds.nodelop[i]->FirstSV = NULL;	//Khoi tao con tro dau` DSSV NULL
		filein>>x;
		getline(filein,data);
		for(int j=0;j<x;j++)
				{
					SinhVien sv;
					getline(filein,data,',');
					strcpy(sv.MaSV, data.c_str());
					getline(filein, data,',');		
					strcpy(sv.Ho, data.c_str());
					getline(filein, data,',');		
					strcpy(sv.Ten, data.c_str());
					getline(filein, data,',');		
					strcpy(sv.Phai, data.c_str());
					getline(filein, data);		
					strcpy(sv.Password, data.c_str());
					sv.FirstDiem = NULL;
					filein>>somh;
					getline(filein,data);
					for(int k=0;k<somh;k++)
					{
						DiemThi dt  ;
						getline(filein,data,',');
						strcpy(dt.MaMH, data.c_str());
						filein>>dt.Diem;
						getline(filein,data,',');
						if(data=="N") dt.bt.ct.n=0;
						else
						{
							filein>>dt.bt.Time;
							getline(filein,data,',');
							filein>>dt.bt.SoCau;
							dt.bt.ct.n=dt.bt.SoCau;
							for(int k=0;k<dt.bt.ct.n;k++)
							{
								getline(filein,data);
								dt.bt.ct.nodeCT[k]= new CauThi;
								filein>>dt.bt.ct.nodeCT[k]->id;
								getline(filein,dt.bt.ct.nodeCT[k]->ND);
								getline(filein,dt.bt.ct.nodeCT[k]->A);
								getline(filein,dt.bt.ct.nodeCT[k]->B);
								getline(filein,dt.bt.ct.nodeCT[k]->C);
								getline(filein,dt.bt.ct.nodeCT[k]->D);
								getline(filein,data,',');
								dt.bt.ct.nodeCT[k]->DapAn = data[0];
								filein>>dt.bt.ct.nodeCT[k]->trangthai;
							}
						}
						ThemMonDaThi(sv.FirstDiem,dt);
						getline(filein,data);
					}
					ThemSV(ds.nodelop[i]->FirstSV, sv);
				}
	}
	filein.close();
}

void GhiFile(dsLop &ds)
{ 
	ofstream fileout;;
	int i;
	fileout.open("DanhSachLop.txt", ios_base::out);
	fileout << ds.n << endl;
	for(i = 0; i < ds.n; ++i)
	{
		VietHoa(ds.nodelop[i]->TenLop); 
		fileout << ds.nodelop[i]->MaLop<<","<< ds.nodelop[i]->TenLop<<","<<ds.nodelop[i]->NienKhoa << endl;
		fileout<<DemSinhVien(ds.nodelop[i]->FirstSV)<<endl;
		for (PTRSV p = ds.nodelop[i]->FirstSV; p != NULL; p = p->next)
			{
				VietHoa(p->data.Ho);	VietHoa(p->data.Ten);
				VietHoa(p->data.Phai);
				fileout << p->data.MaSV <<","
					<< p->data.Ho << ","
					<< p->data.Ten << ","
					<< p->data.Phai << ","
					<< p->data.Password << endl;
					fileout<<DemSoMonDaThi(p->data.FirstDiem)<<endl;
					for(PTRDT q = p->data.FirstDiem; q != NULL ; q = q->next)
					{
						fileout<<q->data.MaMH<<","<<q->data.Diem;
						if(q->data.bt.ct.n==0) fileout<<"N,"<<endl;
						else
						{
							fileout<<","<<q->data.bt.Time<<"p,"<<q->data.bt.ct.n<<endl;
							for(int k=0;k<q->data.bt.ct.n;k++)
							{
								fileout<<q->data.bt.ct.nodeCT[k]->id<<q->data.bt.ct.nodeCT[k]->ND<<endl;
								fileout<<q->data.bt.ct.nodeCT[k]->A<<endl<<q->data.bt.ct.nodeCT[k]->B<<endl<<q->data.bt.ct.nodeCT[k]->C<<endl<<q->data.bt.ct.nodeCT[k]->D<<endl;
								fileout<<q->data.bt.ct.nodeCT[k]->DapAn<<","<<q->data.bt.ct.nodeCT[k]->trangthai<<endl;
							}
						}
					}
			}
	}
	fileout.close();
}

void DocFileMonHoc(dsMonHoc &ds)
{
	ifstream filein;
	string data;
	filein.open("DanhSachMonHoc.txt",ios_base::in);
	filein >> ds.n;
	getline(filein,data);
	if(filein.fail() == true) BaoLoi("Khong doc duoc file mon hoc");
	for(int i=0;i<ds.n;i++)
	{
		ds.nodeMH[i]=new MonHoc;
		getline(filein,data,',');
		strcpy(ds.nodeMH[i]->MaMH, data.c_str());
		getline(filein,data);
		strcpy(ds.nodeMH[i]->TenMH, data.c_str());
	}
	filein.close();
}
void GhiFileMonHoc(dsMonHoc &ds)
{
	ofstream fileout;
	int i;
	fileout.open("DanhSachMonHoc.txt", ios_base::out);
	fileout << ds.n << endl;
	for(i = 0; i < ds.n; ++i)
	{
		VietHoa(ds.nodeMH[i]->TenMH); 
		fileout << ds.nodeMH[i]->MaMH<<","<< ds.nodeMH[i]->TenMH << endl;
	}
	fileout.close();
}

void DocFileCauHoiThi(PTRCHT &dscauhoithi) 
{
	ifstream filein;
	dscauhoithi = NULL;
	string data;
	int x;
	filein.open("DanhSachCauHoiThi.txt", ios::in);
	if(filein.fail() == true) BaoLoi("Khong doc duoc file cau hoi thi");
	filein>>x;
	getline(filein, data);
	for(int i=0;i<x;i++)
	{
		CauHoiThi cht;
		filein>>cht.ID;
		getline(filein, data);
		getline(filein, data);
		strcpy(cht.MaMH, data.c_str());
		getline(filein, cht.ND);
		getline(filein, cht.A);		
		getline(filein, cht.B);	
		getline(filein, cht.C);
		getline(filein, cht.D);
		getline(filein, cht.DapAn);
		ThemCauHoiThi(dscauhoithi,cht);
	}
	filein.close();
}

void GhiFileCHT_NLR(ofstream &fileout, PTRCHT dscauhoithi)
{
	if (dscauhoithi != NULL)
	{
		fileout << dscauhoithi->data.ID << endl
			<< dscauhoithi->data.MaMH << endl
			<< dscauhoithi->data.ND << endl
			<< dscauhoithi->data.A << endl
			<< dscauhoithi->data.B << endl
			<< dscauhoithi->data.C << endl
			<< dscauhoithi->data.D << endl
			<< dscauhoithi->data.DapAn << endl;
		GhiFileCHT_NLR(fileout, dscauhoithi->left);
		GhiFileCHT_NLR(fileout, dscauhoithi->right);
	}
}
void GhiFileCauHoiThi(PTRCHT dscauhoithi)
{
	ofstream fileout;
	fileout.open("DanhSachCauHoiThi.txt", ios_base::out);
	fileout<<DemCauHoiThi(dscauhoithi)<<endl;
	GhiFileCHT_NLR(fileout,dscauhoithi);
	fileout.close();
}

// ============ XUAT ===========
void XuatDSLop(dsLop ds, char *k)
{
	TextColor(YELLOW);
	system("cls");
	int dem=0;
		for (int i = 0;  i < ds.n; i++)
		{
			if(stricmp(ds.nodelop[i]->NienKhoa,k)==0)
			{
				TextColor(12); gotoxy(6, 8 +dem); cout << (i + 1);
				TextColor(YELLOW);
				gotoxy(10, 8+dem ); cout << ds.nodelop[i]->MaLop;
				gotoxy(31, 8 +dem); cout << ds.nodelop[i]->TenLop;
				gotoxy(72, 8 +dem); cout << ds.nodelop[i]->NienKhoa;
				dem++;
			}
		}
		if(dem==0)
		{
			BaoLoi("Nien khoa nay chua co trong danh sach!"); 
			return ;
		 } 
		else 
		{
			Khung_Xuat_Lop(); 
		}
	gotoxy(0,26);
	TextColor(WHITE);
}
void XuatdsSinhVien(dsLop &ds,int &vitri)
{
	int  soluongsv = 0 ,dem=0;
	char ma[16];
	while(true)
	{
		clrscr();
		gotoxy(40,0); TextColor(236);
		cout<<"Nhan ESC de thoat!";
		gotoxy(40,1); TextColor(YELLOW);
		cout<<"Nhap MA LOP can xem: ";
		nhap=NhapMa(ma,3);
		if(nhap == ESC) return;
				nhap = KTMaLop(ds,ma);
				if(nhap == -1)
				{
					BaoLoi("Khong co ma lop nay trong danh sach lop!");
					continue;
				}
				else
				{
					soluongsv = DemSinhVien(ds.nodelop[nhap]->FirstSV);
					if (soluongsv == 0)
					{
						BaoLoi("Chua co sinh vien trong lop nay!");
						continue;
					}
					TextColor(YELLOW); clrscr(); dem=0;
					for (PTRSV p = ds.nodelop[nhap]->FirstSV; p != NULL; p = p->next)
					{
						TextColor(12); gotoxy(6, 8 + dem); cout << dem + 1;
						TextColor(YELLOW);
						gotoxy(10, 8 + dem); cout << p->data.MaSV;
						gotoxy(26, 8 + dem); cout << p->data.Ho;
						gotoxy(47, 8 + dem); cout << p->data.Ten;
						gotoxy(58, 8 + dem); cout << p->data.Phai;
						dem++;
					} 
					Khung_Xuat_SV();
					TextColor(236);
					gotoxy(43,2);
					cout<<"	    ";
					gotoxy(43,2);
					TextColor(234);
					cout<<ds.nodelop[vitri]->TenLop;
					break;
				}
	}
	gotoxy(0,26);
	TextColor(WHITE);
}
void XuatDSMonHoc(dsMonHoc ds)
{
	TextColor(YELLOW);
	system("cls");
	int dem=0;
		for (int i = 0;  i < ds.n; i++)
		{
				TextColor(12); gotoxy(6, 8 +dem); cout << (i + 1);
				TextColor(YELLOW);
				gotoxy(11, 8+dem ); cout << ds.nodeMH[i]->MaMH;
				gotoxy(32, 8 +dem); cout << ds.nodeMH[i]->TenMH;
				dem++;
		}
		Khung_Xuat_MonHoc() ;
		gotoxy(0,26);
	TextColor(WHITE);
}

void XuatDsCHT_NLR(PTRCHT dscht)
  {
  	//duyet den gtri NULL
  	if(dscht !=NULL)
  	{	TextColor(YELLOW);
  		cout<<"\nID: "<<dscht->data.ID<<" - "<<dscht->data.MaMH<<" - ";
		TextColor(WHITE);
		cout<<dscht->data.ND<<"\nA."<<dscht->data.A<<"\nB."<<dscht->data.B<<"\nC."<<dscht->data.C<<"\nD."<<dscht->data.D;
		TextColor(GREEN);
		cout<<"\nDAP AN: "<<dscht->data.DapAn;
  		XuatDsCHT_NLR(dscht->left);
  		XuatDsCHT_NLR(dscht->right);
	  }
  }

void XuatBangDiem(Lop *lop, dsMonHoc dsmh)
{
	TextColor(236);	gotoxy(20, 1);	cout << "                                             ";
	gotoxy(20, 2);	cout << "     DANH SACH DIEM             ";
	gotoxy(20, 3);	cout << "                                             ";
	TextColor(236);
	gotoxy(40,2);
	cout<<"	                 ";
	gotoxy(40,2);
	TextColor(234);
	cout<<lop->TenLop;
	TextColor(YELLOW);
	gotoxy(1,6); cout<<"STT";
	gotoxy(6,6); cout<<"MASV";
	gotoxy(13,6); cout<<"HO";
	gotoxy(26,6); cout<<"TEN";
	TextColor(12);
	dsMonHoc mh;
	mh.n=0;
	int dem;
	for(int i=0;i<dsmh.n;i++)
	{
		if(XetMon(dsmh.nodeMH[i]->MaMH)==XetLop(lop->MaLop))
		{
			mh.nodeMH[mh.n] = dsmh.nodeMH[i];
			gotoxy(36+dem,6);
			cout<<mh.nodeMH[mh.n]->MaMH;
			mh.n++;
			dem = dem+13;
		}
	}
	if(mh.n==0)
	{
		BaoLoi("Chua co mon hoc cho lop nay");
		return;
	}
	dem=0;
	int kq=0;
	PTRDT q=NULL;
	for (PTRSV p = lop->FirstSV; p != NULL; p = p->next)
	{
		TextColor(12); gotoxy(2, 8 + dem); cout << dem + 1;
		TextColor(YELLOW);
		gotoxy(6, 8 + dem); cout << p->data.MaSV;
		gotoxy(13, 8 + dem); cout << p->data.Ho;
		gotoxy(26, 8 + dem); cout << p->data.Ten;
		kq=0;
		for(int i=0;i<mh.n;i++)
		{
			int check=0;
			gotoxy(36+kq, 8 + dem);
			for(q = p->data.FirstDiem;q!=NULL;q=q->next)
			{
				if(stricmp(mh.nodeMH[i]->MaMH,q->data.MaMH)==0)
				{
					cout<<q->data.Diem;
					check=1; break;
				}
			}
			if(check==0) cout<<"Chua thi";
			kq=kq+13;
		}
		dem++;		
	}
	delete q; GPdsMonHoc(mh);
	TextColor(YELLOW);
}
void XuatBaiThi(PTRDT dt)
{
	gotoxy(5,5); TextColor(YELLOW);
	cout<<"Mon: "<<dt->data.MaMH;
	gotoxy(40,5); TextColor(236);
	cout<<"Diem: "<<dt->data.Diem;
	cout<<"\n";
	if(dt->data.bt.ct.n==0) cout<<"\tKHONG CO BAI THI";
	for(int i=0;i<dt->data.bt.ct.n;i++)
	{
			TextColor(YELLOW);
			cout<<"\nCau "<<i+1<<": ";
			TextColor(WHITE);
			cout<<dt->data.bt.ct.nodeCT[i]->ND;
			cout<<"\nA. "<<dt->data.bt.ct.nodeCT[i]->A;
			cout<<"\nB. "<<dt->data.bt.ct.nodeCT[i]->B;
			cout<<"\nC. "<<dt->data.bt.ct.nodeCT[i]->C;
			cout<<"\nD. "<<dt->data.bt.ct.nodeCT[i]->D;
			cout<<"\nSV chon: "<<dt->data.bt.ct.nodeCT[i]->DapAn;
			
			if(dt->data.bt.ct.nodeCT[i]->trangthai==0) 
			{
				TextColor(GREEN); cout<<"\n=>DUNG";
			}
			else
			{
				TextColor(RED); cout<<"\n=>SAI";
			} 
	}
}
//============ DANG NHAP ===========
int DangNhap(dsLop DSlop, PTRSV &sv)
{
	char *user = new char [10];
	char *pass = new char [8];
	int i = 0;
	PTRSV p;
	while(1)
	{
		clrscr();
		gotoxy(15,1);
		TextColor(243);
		cout<<"=======================DANG NHAP=======================";
		gotoxy(20,3);TextColor(YELLOW);
		// 1 - SINH VIEN
		//2 - GIAO VIEN
		cout<<"Ten dang nhap: ";
		i = NhapMa(user, 10);
		if(i == ESC) return 0;
		if(stricmp(user, "GV") != 0)
		{
			for(i = 0; i < DSlop.n; i++)
			{
				p = KTSV(DSlop.nodelop[i]->FirstSV, user);
				if(p != NULL)	goto NMK;
			}
			if(p == NULL)
			{
				gotoxy(20,5);
				TextColor(RED);
				cout << "Ten dang nhap khong dung! Moi nhap lai!!" ;
				Sleep(1000);
				continue;
			}
		}
NMK:	gotoxy(20,4);
		cout<<"Nhap mat khau: ";
		i = NhapPass(pass, 8);
		if(i == ESC) return 0;
		if(stricmp(user, "GV") == 0 && stricmp(pass, "GV") == 0 ) return 2;
		else if(stricmp(user, "GV") != 0 && stricmp(pass, p->data.Password) == 0)
				{
					sv=p;
					return 1;
				}
		else
				{
					gotoxy(20,6);
					TextColor(RED);
					cout << "Mat khau khong dung! Moi nhap lai!";
					Sleep(1000);
					XoaDong(4,3);
					TextColor(YELLOW);
					goto NMK;
					continue;
				}
		
	}
	delete user;
	delete pass;
}





