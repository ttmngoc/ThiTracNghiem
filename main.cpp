#include<iostream>
#include "XuLy.h" 
#include "Menu.h" 
  
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char** argv) 
{ 
	dsLop ds;        
	dsMonHoc dsmh;            
	PTRSV dssv =NULL;
	PTRDT dsdt = NULL;
	PTRCHT dscht = NULL;    
	SinhVien sv;
	char *ma = new char[16];
	char key;
	int vitri=0,soluong=0; int phut,giay, thgian;
	int x=0;
	srand(time(NULL)); // tao ra so ngau nhien theo thoi gian thuc                
	DocFile(ds);      
	DocFileMonHoc(dsmh);                                        
	DocFileCauHoiThi(dscht);
	dsCauThi thi;     
	PTRCHT dsch=NULL;
	while(1)
	{
DN:	nhap = DangNhap(ds,dssv);    
	if(nhap==1) 
	{ 
		while(true)
		{     
			clrscr();
			gotoxy(10,0);
			TextColor(YELLOW);
			cout<<"Nhap MA MON THI: ";
			nhap=NhapMa(ma,16);
			if(nhap==ESC) break;
			if(KTMaMH(dsmh,ma)<0) 
			{
				TextColor(RED);
				cout<<"\nMa mon sai!";
				Sleep(1000);
				continue;
			} 
			if(XetLop(dssv->data.MaSV)!=XetMon(ma))
			{
				TextColor(RED);
				cout<<"\nMon nay khong phu hop voi lop ban!";
				Sleep(1000);
				continue;
			}
			soluong =0;
			dsch=NULL;   
			TimCauHoiThi(dscht,dsch,ma,soluong);     
			int MangID[soluong];    
			if(dsch==NULL)
			{
				TextColor(RED);
				cout<<"\nHien tai chua co cau hoi cho mon nay!";
				Sleep(1000);
				continue;
			}
			TextColor(RED);
			cout<<"\nHien tai mon nay chi co "<<soluong<<" cau. ";
		X:	TextColor(YELLOW);  
			gotoxy(10,4);
			cout<<"Nhap so cau thi: ";
			cin>>x;
			if(x<=0)
			{ 
				TextColor(RED);
				cout<<"\nSai! Moi nhap lai!";
				Sleep(1000);
				XoaDong(4,3);
				goto X;
			}
			if(x>soluong)
			{
				TextColor(RED);
				cout<<"\nNhap qua so luong cho phep!";
				Sleep(1000);
				XoaDong(4,3); 
				goto X;
			}
	THGIAN:	gotoxy(10,5);
			TextColor(YELLOW); 
			cout<<"Nhap so phut thi: ";
			cin>>thgian;
			if(thgian<=0)   
			{
				TextColor(RED);
				cout<<"\nThoi gian chua dung!";
				Sleep(1000);
				XoaDong(5,3); 
				goto THGIAN; 
			}                   
			BaoLoi("Bat dau thi!");
			clrscr();
			soluong=0; 
			TimMangCauHoiThi(dsch,MangID,soluong);    
			thi.n=x;       
			ThiTracNghiem(dsch,MangID,x,thi,thgian,soluong);   
			GPdsCHT(dsch);
			for(dsdt =dssv->data.FirstDiem;dsdt!=NULL;dsdt =dsdt->next)
			{
				if(stricmp(dsdt->data.MaMH,ma)==0)
				{
					dsdt->data.Diem=TinhDiem(x,thi); 
					dsdt->data.bt.ct=thi;
					dsdt->data.bt.SoCau=x;
					GhiFile(ds);      
					BaoLoi("Mon nay ban da thi. Ket qua se cap nhat moi!");
					goto DN;
				}
			} 
			DiemThi dt;
			VietHoa(ma);
			strcpy(dt.MaMH,ma);
			dt.Diem = TinhDiem(x,thi);  
			dt.bt.Time=thgian;  
			dt.bt.ct=thi; 
			ThemMonDaThi(dssv->data.FirstDiem,dt);
			GhiFile(ds);
			BaoLoi("Ket qua da luu!");
			goto DN;
		}
	}
	else if(nhap==2) 
	{  
		do
		{
			int chon = MenuDong(MenuGV);
			switch(chon){
				// 1/ Nhap lop
				case 1:
				{ 
					nhap = ThemLop(ds); 
					if(nhap==ESC) break; 
					BaoLoi("Them Lop thanh cong!");
					GhiFile(ds);
					break; 
				 }  
				// 2. xem lop theo nien khoa         
				case 2: 
				{
					while(1) 
					{
						clrscr();TextColor(236);
						cout<<"Nhan ESC de thoat!";TextColor(YELLOW);
						cout<<"\nNhap nien khoa can xem: ";
						nhap = NhapChuoi(ma,9);
						if(nhap == ESC) break;
						XuatDSLop(ds,ma); 
						key=getch();
						if(key==ESC) break;
						else if(key=='1') // 1. THEM
						{
							nhap = ThemLop(ds);  
							if(nhap==ESC) break;
							GhiFile(ds);
						} 
						else if(key=='2') // 2. SUA
						{
							while(1)
							{
								nhap = SuaLop(ds);  
								if(nhap==ESC) break;
								else if(nhap==0) continue;
								GhiFile(ds); 
							}
							break;
						}
						else if(key=='3') // 3. XOA 
						{
							while(1) 
							{
								XoaDong(27,2); 
								TextColor(236);
								cout<<"Nhan ESC de thoat!";TextColor(YELLOW);
								cout<<"\nNhap ma lop can xoa: ";
								nhap = NhapMa(ma,10);
								if(nhap == ESC) break;    
								vitri = KTMaLop(ds,ma); 
								if(vitri<0)
								{
									BaoLoi("Khong co ma lop nay trong danh sach");
									continue;
								}
								else if (ds.nodelop[vitri]->FirstSV != NULL)
								{
									BaoLoi("Lop nay da co Sinh Vien khong the Xoa!");
									continue;
								}
								else
								{
									XoaLop(ds,vitri);
									BaoLoi("Xoa thanh cong!");
									GhiFile(ds);
								} 
							}                            
							break;
						}
					} 
					break;
				}
				// 3. Them Sinh vien
				case 3:
					{    
						TextColor(YELLOW);
						gotoxy(20,0);
						while(true)
						{
						
							clrscr();TextColor(236);
							cout<<"\nNhap ESC de thoat";TextColor(YELLOW);
							cout<<"\nNhap ma lop can them sinh vien: ";
							nhap = NhapMa(ma,10);
							if(nhap == ESC) break;
							vitri = KTMaLop(ds,ma);
							if(vitri<0)
							{
								BaoLoi("Ma Lop sai!");
								continue;
							}
							while(1) 
							{
								nhap = NhapSV(ds,ds.nodelop[vitri]->FirstSV,sv);
								if(nhap== ESC) break;
								ThemSV(ds.nodelop[vitri]->FirstSV,sv);
								BaoLoi("Them sinh vien moi thanh cong!");
								GhiFile(ds);
							}
							break;
						}
						break;
					}
				// 4. Xem danh sach sinh vien theo lop
				case 4:
					{
						XuatdsSinhVien(ds,vitri);
						do
						{
							key=getch();
							if(key==ESC) break;
							else if(key=='1') // Them 
							{
								while(1)
								{
									nhap = NhapSV(ds,ds.nodelop[vitri]->FirstSV,sv);
									if(nhap== ESC) break;
									ThemSV(ds.nodelop[vitri]->FirstSV,sv);
									BaoLoi("Them sinh vien moi thanh cong!");
									GhiFile(ds);
								}
								break;    
							}
							else if(key=='2') // sua
							{
								while(1)
								{
									XoaDong(27,7); TextColor(236);
									cout<<"Nhan ESC de thoat!"; TextColor(YELLOW);
									cout<<"\nNhap MA SINH VIEN can sua: ";
									nhap = NhapMa(ma,10);
									if(nhap==ESC) break;
									nhap = SuaSV(ds, ds.nodelop[vitri]->FirstSV,ma); 
									if(nhap==ESC) break;
									if(nhap==0) continue; 
									else if(nhap==1)  
									{
										BaoLoi("Cap nhat thanh cong!");
										GhiFile(ds);
										continue;
									}
								}
								break;
							}
							else if(key=='3') // xoa
							{
								while(1)
								{  
									XoaDong(27,2); TextColor(236);
									cout<<"Nhan ESC de thoat!"; TextColor(YELLOW);
									cout<<"\nNhap MA SINH VIEN can xoa: ";
									nhap = NhapMa(ma,10);
									if(nhap==ESC) break;  
									if(KTSV(ds.nodelop[vitri]->FirstSV,ma)== NULL)
									{
										BaoLoi("Ma sinh vien khong dung");
										continue;
									}  
									if(KTSVDaThi(ds.nodelop[vitri]->FirstSV,ma)==true)
									{
										BaoLoi("Sinh vien da co diem. Khong the xoa!");
										continue;
									}
									XoaSV(ds.nodelop[vitri]->FirstSV,ma);
									BaoLoi("Xoa thanh cong!");
									GhiFile(ds);
									continue;
								}
								break;
							}
						}while(key!=ESC);
						break;
					}
				// XEM MON HOC	
				case 5: 
					{
						XuatDSMonHoc(dsmh);
						do
						{
							key = getch();
							if(key=='1') // THEM  
							{
								while(1)
								{
									nhap = ThemMonHoc(dsmh);
									if(nhap==ESC) break;
									else
									{
										BaoLoi("Them thanh cong!");
										GhiFileMonHoc(dsmh);
									} 
								}
								break;
							}
							else if(key=='2') // SUA
							{  
								while(1)
								{
									nhap = SuaMonHoc(ds,dsmh,dscht);  
									if(nhap==ESC) break;
									else if(nhap==0) continue; 
									else
									{
										BaoLoi("Cap nhap thanh cong!");
										GhiFileMonHoc(dsmh);
									}
								}
								break;
							}  
							else if(key=='3') // XOA
							{
								while(1)
								{
									nhap = XoaMonHoc(ds,dsmh,dscht,vitri);
									if(nhap==ESC) break;
									else if(nhap==0) continue;
									else
									{
										BaoLoi("Xoa thanh cong!");
										GhiFileMonHoc(dsmh);  
									} 
								}
								break; 
							}
							else if(key==ESC) break;
						}while(key!=ESC);
						break;
					}
				// NHAP CAU HOI THI  
				case 6:
					{
						do{
						chon = MenuDong(MenuCHT);
						switch(chon){
							case 1: // XUAT CAU HOI THI
								{
									clrscr();
									TextColor(236);
									cout<<"Nhan ESC de thoat!";
									TextColor(GREEN);
									cout<<"\n==============DANH SACH CAU HOI THI============\n";
									XuatDsCHT_NLR(dscht);
									do{
										gotoxy(20,0);
										key = getch();
									}while(key!=ESC);
									break;
								}
							case 2: // THEM CAU HOI THI
								{
									while(true)
									{
										clrscr();
										nhap = NhapCauHoiThi(dsmh,dscht);       
										if(nhap==ESC) break;
										GhiFileCauHoiThi(dscht); 
										continue;
									}
									break;
								}
							case 3: // SUA CAU HOI THI
								{
									while(true)
									{
										clrscr(); 
										nhap = SuaCauHoiThi(dsmh,dscht);     
										if(nhap==ESC) break;
										continue;
									}
									GhiFileCauHoiThi(dscht); 
									break;
								}
							case 4: // XOA CAU HOI THI   
								{
									while(true)
									{
										clrscr();
										nhap = XoaCauHoiThi(dscht);
										if(nhap==ESC) break;
										continue;
									}
									GhiFileCauHoiThi(dscht);          
									break;
								}
							case 5: clrscr(); break;
						}
						}while(chon<5);
						break;
					}
				// THI TRAC NGHIEM
				case 7:
					{
					do{
						clrscr();
						gotoxy(10,0);
						TextColor(YELLOW);
						cout<<"Nhap MA MON THI: ";
						nhap=NhapMa(ma,16);
						if(nhap==ESC) break;
						if(KTMaMH(dsmh,ma)<0)
						{
							TextColor(RED);
							cout<<"\nMa mon sai!";
							Sleep(1000);
							continue;
						}
						soluong = 0;
						dsch=NULL;
						TimCauHoiThi(dscht,dsch,ma,soluong);
						int MangID[soluong];   
						if(dsch==NULL)
						{
							TextColor(RED);
							cout<<"\nHien tai chua co cau hoi cho mon nay!";
							Sleep(1000);
							continue;
						}
						TextColor(RED);
						cout<<"\nHien tai mon nay chi co "<<soluong<<" cau. ";
					XGV:	TextColor(YELLOW);  
						gotoxy(10,4);
						cout<<"Nhap so cau thi: ";
						cin>>x;
						if(x<=0)
						{ 
							TextColor(RED);
							cout<<"\nSai! Moi nhap lai!";
							Sleep(1000);
							XoaDong(4,3);
							goto XGV;
						}
						if(x>soluong)
						{
							TextColor(RED);
							cout<<"\nNhap qua so luong cho phep!";
							Sleep(1000);
							XoaDong(4,3); 
							goto XGV;
						}
				TIMEGV:	gotoxy(10,5);
						TextColor(YELLOW); 
						cout<<"Nhap so phut thi: ";
						cin>>thgian;
						if(thgian<=0)  
						{
							TextColor(RED);
							cout<<"\nThoi gian chua dung!";
							Sleep(1000);
							XoaDong(5,3); 
							goto TIMEGV;
						}
						BaoLoi("Bat dau thi!");
						clrscr();
						soluong=0;
						TimMangCauHoiThi(dsch,MangID,soluong);
						thi.n=x;      
						ThiTracNghiem(dsch,MangID,x,thi,thgian,soluong);
						cout<<"\nDiem: "<<TinhDiem(x,thi);
						TextColor(RED); GPdsCHT(dsch);
						cout<<"\nNhan ESC de thoat!";
						key=getch();
					}while(key!=ESC);
						break;
					}
				// IN CHI TIET BAI THI 1 MON HOC CUA SINH VIEN
				case 8:
					{
						while(1)
						{
					BD:		clrscr();
							TextColor(236);
							cout<<"Nhan ESC de thoat!";
							TextColor(WHITE);
							cout<<"\nNhap MA SINH VIEN can xem bai thi: ";
							nhap = NhapMa(ma,16);
							if(nhap==ESC) break;
							dssv = KTSVtrongDS(ds,ma);
							if(dssv == NULL)
							{
								BaoLoi("Khong co ma sinh vien nay!");
								continue;
							}
							if(DemSoMonDaThi(dssv->data.FirstDiem)==0)
							{
								BaoLoi("Sinh vien nay chua thi!");
								continue;
							}
					MON:	TextColor(RED);
							cout<<"\nSinh vien nay da thi "<<DemSoMonDaThi(dssv->data.FirstDiem)<<" mon.\n";
							TextColor(YELLOW);
							for(dsdt=dssv->data.FirstDiem;dsdt!=NULL;dsdt=dsdt->next)
							{
								cout<<dsdt->data.MaMH<<"\n";
							}
					MAMON:	TextColor(WHITE);  
							cout<<"\nNhap MA MON HOC muon xem: ";
							nhap=NhapMa(ma,16);
							if(nhap==ESC) break;
							for(dsdt=dssv->data.FirstDiem;dsdt!=NULL;dsdt=dsdt->next)
							{
								if(stricmp(dsdt->data.MaMH,ma)==0) break;
							}
							if(dsdt==NULL)
							{
								TextColor(RED);
								cout<<"\nMa mon khong dung!";
								Sleep(500);
								XoaDong(wherey()-3,4); 
								goto MAMON;
							}
							clrscr();
							gotoxy(5,0);TextColor(91);
							cout<<"====================BAI THI====================";
							gotoxy(5,2);TextColor(YELLOW);
							cout<<"Ten: "<<dssv->data.Ho<<" "<<dssv->data.Ten;
							gotoxy(5,3);
							cout<<"Ma sinh vien: "<<dssv->data.MaSV;
							XuatBaiThi(dsdt);   
							TextColor(243);
							cout<<"\n\n\tESC: Thoat\tENTER: Xem mon khac\tSPACE: Xem SV khac ";
							Normal();
							while(1)
							{
								key=getch();
								if(key==ESC) break;
								else if(key==ENTER)
								{
									clrscr(); goto MON;
								} 
								else if(key==SPACE) goto BD;
								else continue;
							}
							break;
						}
						break;
					}
				// IN BANG DIEM 1 LOP
				case 9:    
					{
						while(true)
						{
							clrscr(); TextColor(236);
							cout<<"\nNhan ESC de thoat!"; TextColor(YELLOW);
							cout<<"\nNhap ma lop can xem: ";
							nhap=NhapMa(ma,3);
							if(nhap==ESC) break;
							vitri=KTMaLop(ds,ma);
							if(vitri<0)
							{
								BaoLoi("Khong co ma lop nay!");
								continue;
							}
							nhap = DemSinhVien(ds.nodelop[vitri]->FirstSV);
							if(nhap==0)
							{
								BaoLoi("Lop nay chua co sinh vien!");
								continue;
							}
							clrscr(); 
							XuatBangDiem(ds.nodelop[vitri],dsmh);
							key=getch();
							if(key==ESC) break;
						}
						break;
					}
				// THOAT
				case 10 : goto DN;
			}
		}while(1);	
	}		
	else 
	{
		XoaDong(0,4);
		gotoxy(15,1);
		cout<<"KET THUC CHUONG TRINH...";
		delete ma;
		GPdsLop(ds);
		GPdsCHT(dscht);
		GPdsMonHoc(dsmh);
		GPdsDiem(dsdt);			
		return 0;
	}
}	/*	*/
}
