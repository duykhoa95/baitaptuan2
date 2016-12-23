#include "sinhvien.h"
#include "iostream"
#include "stdio.h"
#include "conio.h"
#include <fstream> 
#include <string>
#include <vector>
#include <math.h> 
#include <iomanip>
using namespace std;
sinhvien::sinhvien()
{
}


sinhvien::~sinhvien()
{
}
void sinhvien::vSwap(Sinhvien *sv1, Sinhvien *sv2)
{
	Sinhvien *p = new Sinhvien();
	p->sHoten = sv2->sHoten;
	p->sSbd = sv2->sSbd;
	p->sDiachi = sv2->sDiachi;
	p->sGT = sv2->sGT;
	p->dDiem.fToan = sv2->dDiem.fToan;
	p->dDiem.fly = sv2->dDiem.fly;
	p->dDiem.fhoa = sv2->dDiem.fhoa;

	sv2->sHoten = sv1->sHoten;
	sv2->sSbd = sv1->sSbd;
	sv2->sDiachi = sv1->sDiachi;
	sv2->sGT = sv1->sGT;
	sv2->dDiem.fToan = sv1->dDiem.fToan;
	sv2->dDiem.fly = sv1->dDiem.fly;
	sv2->dDiem.fhoa = sv1->dDiem.fhoa;

	sv1->sHoten = p->sHoten;
	sv1->sSbd = p->sSbd;
	sv1->sDiachi = p->sDiachi;
	sv1->sGT = p->sGT;
	sv1->dDiem.fToan = p->dDiem.fToan;
	sv1->dDiem.fly = p->dDiem.fly;
	sv1->dDiem.fhoa = p->dDiem.fhoa;
}
bool sinhvien::bKiemtra(float kt)
{
	if (kt > 10 || kt < 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
void sinhvien::vXuatFile(Sinhvien *xuat)
{
	fstream f;
	f.open("xuat.txt", ios::out);

	// 3. Ghi d? li?u vào file, tru?ng h?p này ta có data là d? li?u
	f << xuat->sHoten << "#" << xuat->sSbd << "#" << xuat->sDiachi << "#" << xuat->sGT << "#"
		<< xuat->dDiem.fToan << "#" << xuat->dDiem.fly << "#" << xuat->dDiem.fhoa << "\n";

	// 4. Ðóng file
	f.close();
}
void sinhvien::vHienthi(Sinhvien *pdau)
{
	Sinhvien *pchay, *p;
	pchay = pdau;
	if (pdau == NULL)
	{
		cout << "Chua co thong tin de hien thi " << endl; system("pause");
	}
	else
	{
		cout << "------Hien thi thong tin sinh vien-------" << endl;
		cout << "SBD" << setw(10) << "Ho va ten" << setw(10) << "Dia chi"
			<< setw(10) << "Gioi tinh" << setw(10) << "Diem Toan" << setw(10) << "Diem ly"
			<< setw(10) << "Diem Hoa" << setw(10) << endl;
		while (pchay != NULL)
		{
			cout << pchay->sSbd << setw(10) << pchay->sHoten << setw(10) << pchay->sDiachi << setw(10)
				<< pchay->sGT << setw(10) << pchay->dDiem.fToan << setw(10)
				<< pchay->dDiem.fly << setw(10) << pchay->dDiem.fhoa << setw(10) << endl;
			pchay = pchay->next;
		}
	}
	system("pause");
}
void sinhvien::vThKTonggt25(Sinhvien *pdau)
{
	Sinhvien *pchay;
	int dem = 0;
	pchay = pdau;
	if (pdau == NULL)
	{
		cout << "chua co danh sach";
	}
	else
	{
		while (pchay != NULL)
		{
			if (fTongDiem(pchay->dDiem.fToan, pchay->dDiem.fly, pchay->dDiem.fhoa) > 25)
			{
				dem++;
			}
			pchay = pchay->next;
		}
	}
	if (dem > 0)
	{
		cout << "Tong so thi sinh co diem lon hon 25 trong danh sach la : " << dem << endl;
		system("pause");
	}
	else
	{
		cout << "khong co nguoi nao nhu the ca";
		system("pause");
	}
}
void sinhvien::vThKTongbetwen20to25(Sinhvien *pdau)
{
	Sinhvien *pchay;
	int dem = 0;
	pchay = pdau;
	if (pdau == NULL)
	{
		cout << "chua co danh sach";
	}
	else
	{
		while (pchay != NULL)
		{
			if (fTongDiem(pchay->dDiem.fToan, pchay->dDiem.fly, pchay->dDiem.fhoa) > 20 && fTongDiem(pchay->dDiem.fToan, pchay->dDiem.fly, pchay->dDiem.fhoa) < 25)
			{
				dem++;
			}
			pchay = pchay->next;
		}
	}
	if (dem > 0)
	{
		cout << "Tong so thi sinh co diem lon hon 20 va nho hon 25 trong danh sach la : " << dem << endl;
		system("pause");
	}
	else
	{
		cout << "khong co nguoi nao nhu the ca";
		system("pause");
	}
}
void sinhvien::vThKTongbetwen15to20(Sinhvien *pdau)
{
	Sinhvien *pchay;
	int dem = 0;
	pchay = pdau;
	if (pdau == NULL)
	{
		cout << "chua co danh sach";
	}
	else
	{
		while (pchay != NULL)
		{
			if (fTongDiem(pchay->dDiem.fToan, pchay->dDiem.fly, pchay->dDiem.fhoa) > 15 && fTongDiem(pchay->dDiem.fToan, pchay->dDiem.fly, pchay->dDiem.fhoa) < 20)
			{
				dem++;
			}
			pchay = pchay->next;
		}
	}
	if (dem > 0)
	{
		cout << "Tong so thi sinh co diem lon hon 15 va nho hon 20 trong danh sach la : " << dem << endl;
		system("pause");
	}
	else
	{
		cout << "khong co nguoi nao nhu the";
		system("pause");
	}
}
void sinhvien::vThKTonglt15(Sinhvien *pdau)
{
	Sinhvien *pchay;
	int dem = 0;
	pchay = pdau;
	if (pdau == NULL)
	{
		cout << "chua co danh sach";
	}
	else
	{
		while (pchay != NULL)
		{
			if (fTongDiem(pchay->dDiem.fToan, pchay->dDiem.fly, pchay->dDiem.fhoa) > 15)
			{
				dem++;
			}
			pchay = pchay->next;
		}
	}
	if (dem > 0)
	{
		cout << "Tong so thi sinh co diem lon hon 15 trong danh sach la : " << dem << endl;
		system("pause");
	}
	else
	{
		cout << "khong co nguoi nao nhu the ca";
		system("pause");
	}

}
void sinhvien::vThKTongThSinh(Sinhvien *pdau)
{
	Sinhvien *pchay;
	int dem = 0;
	pchay = pdau;
	if (pdau == NULL)
	{
		cout << "chua co danh sach";
	}
	else
	{
		while (pchay != NULL)
		{
			dem++;
			pchay = pchay->next;
		}
	}
	if (dem > 0)
	{
		cout << "Tong so thi sinh co trong danh sach la : " << dem << endl;
		system("pause");
	}
	else
	{
		cout << "khong co nguoi nhu the";
		system("pause");
	}

}
void sinhvien::vTkSbd(Sinhvien *pdau)
{
	bool error_detected, flag = false;
	Sinhvien *pchay;
	pchay = pdau;
	string sbd;
	string kq;
	if (pdau == NULL)
	{
		cout << "chua co du lieu";
		return;
	}
	cout << "Nhap sbd ban muon tim kiem : " << endl;
	cin >> sbd;
	cout << "Ho ten" << setw(10) << "sbd" << setw(10) << " diachi" << setw(10)
		<< "gt" << setw(10) << "toan" << setw(10) << "ly" << setw(10) << "hoa" << endl;
	while (pchay != NULL)
	{
		if (pchay->sSbd == sbd)
		{
			cout << pchay->sHoten << setw(10) << pchay->sSbd << setw(10) << pchay->sDiachi
				<< setw(10) << pchay->sGT << setw(10) << pchay->dDiem.fToan
				<< setw(10) << pchay->dDiem.fly << setw(10) << pchay->dDiem.fhoa;
			vXuatFile(pchay);
			flag = true;
		}
		pchay = pchay->next;
	}
	if (!flag)
	{
		cout << "khong co du lieu can tim";
	}
	system("pause");
}
void sinhvien::vTkHoTen(Sinhvien *pdau)
{
	bool error_detected, flag = false;
	Sinhvien *pchay;
	pchay = pdau;
	string hoten;
	string kq;
	if (pdau == NULL)
	{
		cout << "chua co du lieu";
		return;
	}
	cout << "Nhap sbd ban muon tim kiem : " << endl;
	cin >> hoten;
	cout << "Ho ten" << setw(10) << "sbd" << setw(10) << " diachi" << setw(10)
		<< "gt" << setw(10) << "toan" << setw(10) << "ly" << setw(10) << "hoa" << endl;
	while (pchay != NULL)
	{
		if (pchay->sHoten == hoten)
		{
			cout << pchay->sHoten << setw(10) << pchay->sSbd << setw(10) << pchay->sDiachi
				<< setw(10) << pchay->sGT << setw(10) << pchay->dDiem.fToan
				<< setw(10) << pchay->dDiem.fly << setw(10) << pchay->dDiem.fhoa;
			vXuatFile(pchay);
			flag = true;
		}
		pchay = pchay->next;
	}
	if (!flag)
	{
		cout << "khong co du lieu can tim";
	}
	system("pause");
}
void sinhvien::vTkTongDiem(Sinhvien *pdau)
{
	bool error_detected, flag = false;
	Sinhvien *pchay;
	pchay = pdau;
	float tongdiem;
	string kq;
	if (pdau == NULL)
	{
		cout << "chua co du lieu";
		return;
	}
tt1:
	cout << "Nhap tong diem ban muon tim kiem : " << endl;
	cin >> tongdiem;
	if (cin.fail())
	{
		cout << "\n Dinh lua anh ah, nhap so de : )\n"; system("pause");
		cin.clear();
		cin.ignore(numeric_limits< float >::max(), '\n');
		error_detected = true;
		goto tt1;
	}
	else
	{
		error_detected = false;
	}
	cout << "Ho ten" << setw(10) << "sbd" << setw(10) << " diachi" << setw(10)
		<< "gt" << setw(10) << "toan" << setw(10) << "ly" << setw(10) << "hoa" << endl;
	while (pchay != NULL)
	{
		if (fTongDiem(pchay->dDiem.fToan, pchay->dDiem.fly, pchay->dDiem.fhoa) == tongdiem)
		{
			cout << pchay->sHoten << setw(10) << pchay->sSbd << setw(10) << pchay->sDiachi
				<< setw(10) << pchay->sGT << setw(10) << pchay->dDiem.fToan
				<< setw(10) << pchay->dDiem.fly << setw(10) << pchay->dDiem.fhoa;
			vXuatFile(pchay);
			flag = true;
		}
		pchay = pchay->next;
	}
	if (!flag)
	{
		cout << "khong co du lieu can tim";
	}
	system("pause");
}
void sinhvien::vSsSbd(Sinhvien *pdau)
{
	Sinhvien *pchay, *p;
	pchay = pdau;
	if (pdau != NULL)
	{
		p = pchay;
		pchay = pchay->next;
		while (pchay != NULL)
		{
			if (p->sSbd > pchay->sSbd)
			{
				vSwap(p, pchay);
			}
			p = pchay;
			pchay = pchay->next;
		}
	}
	vHienthi(pdau);
}
void sinhvien::vSsIncTongDiem(Sinhvien *pdau)
{
	Sinhvien *pchay, *p;
	pchay = pdau;

	if (pdau != NULL)
	{
		p = pchay;
		pchay = pchay->next;
		while (pchay != NULL)
		{
			if (fTongDiem(p->dDiem.fToan, p->dDiem.fly, p->dDiem.fhoa) > fTongDiem(pchay->dDiem.fToan, pchay->dDiem.fly, pchay->dDiem.fhoa))
			{
				vSwap(p, pchay);
			}
			p = pchay;
			pchay = pchay->next;
		}
	}
	vHienthi(pdau);
}
void sinhvien::vSsIncAnpha(Sinhvien *pdau)
{
	Sinhvien *pchay, *p;
	pchay = pdau;

	if (pdau != NULL)
	{
		p = pchay;
		pchay = pchay->next;
		while (pchay != NULL)
		{
			if (p->sHoten > pchay->sHoten)
			{
				vSwap(p, pchay);
			}
			p = pchay;
			pchay = pchay->next;
		}
	}
	vHienthi(pdau);
}

Sinhvien *sinhvien::vNhapSVfile( Sinhvien *pdau)
{
	fstream f;
	Sinhvien *pchay = NULL, *p;
	pchay = pdau;
	if (pdau != NULL)
	{

		while (!pchay->next == NULL)
		{
			pchay = pchay->next;
		}
	}
	vector<string> SS;
	cout << "nhap duong dan : " << endl;
	fflush(stdin);
	string a;
	getline(cin, a);
	f.open(a, ios::in);
	if (f.fail())
	{
		cout << " Duong dan ko ton tai :D, nhap lai";
		system("pause");
		return pdau;
	}

	// 3. doc du lieu tu file vao data
	string Str;

	// *** doc tung dong vao data
	string line;
	while (!f.eof())
	{
		getline(f, line);
		Str = line;
		vector<string> SS;
		while (!Str.empty())
		{
			SS.push_back(Str.substr(0, Str.find("#")));// add word to vector 
			if (Str.find("#") > Str.size()) //Check if found " " (Space) 
			{
				break;
			}
			else
			{
				Str.erase(0, Str.find("#") + 1); // Update string 
			}
		}

		float diemtoan = stof(SS[4]);
		float diemly = stof(SS[5]);
		float diemhoa = stof(SS[6]);

		if (pdau == NULL)
		{
			p = new Sinhvien();
			p->sHoten = SS[0];
			p->sSbd = SS[1];
			p->sDiachi = SS[2];
			p->sGT = SS[3];
			p->dDiem.fToan = diemtoan;
			p->dDiem.fly = diemly;
			p->dDiem.fhoa = diemhoa;
			pdau = pchay = p;
			p->next = NULL;
			p->prev = NULL;
		}
		else
		{
			p = new Sinhvien();
			p->sHoten = SS[0];
			p->sSbd = SS[1];
			p->sDiachi = SS[2];
			p->sGT = SS[3];
			p->dDiem.fToan = diemtoan;
			p->dDiem.fly = diemly;
			p->dDiem.fhoa = diemhoa;
			pchay->next = p;
			p->prev = pchay;
			pchay = p;
			p->next = NULL;
		}
	}
	cout << "Nhap file hoan thanh :)" << endl;
	system("pause");
	// 4. Ðóng file
	f.close();
	return pdau;
}
float sinhvien::fTongDiem(float diem1, float diem2, float diem3)
{
	return diem1 + diem2 + diem3;
}
Sinhvien *sinhvien::XoaSV(Sinhvien *pdau)
{
	Sinhvien *pchay;
	pchay = pdau;
	string sbd;
	cout << "SBD sinh vien ban muon xoa la : ";
	fflush(stdin);
	getline(cin, sbd);
	if (pdau == NULL)
	{
		cout << "Chua co danh sach nen ko the xoa " << endl;
	}
	else
	{
		while (pchay != NULL)
		{
			if (pdau->sSbd == sbd)
			{
				pdau = pdau->next;
				pdau->prev = NULL;
				return pdau;
			}
			else
			{
				if (pchay->sSbd == sbd)
				{
					if (pchay->next == NULL)
					{

						pchay->prev->next = NULL;
						delete pchay;
						return pdau;
					}
					else
					{
						pchay->prev->next = pchay->next;
						pchay->next->prev = pchay->prev;
						delete pchay;
						return pdau;
					}
				}
			}
			pchay = pchay->next;
		}
	}
}
Sinhvien *sinhvien::vThemSV(Sinhvien *pdau)
{
	string ten;
	Sinhvien *pchay, *p;
	pchay = pdau;
	cout << "ban muon them truoc sinh vien ten la : ";
	fflush(stdin);
	getline(cin, ten);
	if (pchay == NULL)
	{
		cout << "chua co danh sanh sinh vien de them" << endl;
	}
	else
	{
		while (pchay != NULL)
		{
			if (pdau->sHoten == ten)
			{
				p = new Sinhvien();
				fflush(stdin);
				cout << "Nhap Ho ten sinh vien :" << endl;
				getline(cin, p->sHoten);
				cout << "Nhap so bao danh :" << endl;
				getline(cin, p->sSbd);
				cout << "Nhap dia chi : " << endl;
				getline(cin, p->sDiachi);
				cout << "Nhap gioi tinh :" << endl;
				getline(cin, p->sGT);
				bool error_detected = false;
			tt1:
				fflush(stdin);
				cout << "Nhap diem toan : " << endl;
				cin >> p->dDiem.fToan;
				if (cin.fail())
				{
					cout << "\n Dinh lua anh ah, nhap so de : )\n"; system("pause");
					cin.clear();
					cin.ignore(numeric_limits< float >::max(), '\n');
					error_detected = true;
					goto tt1;
				}
				else
				{
					error_detected = false;
				}
				if (!bKiemtra(p->dDiem.fToan))
				{
					cout << "nhap dung diem ho cai to qua : )\n";
					goto tt1;
				}
			tt2:
				fflush(stdin);
				cout << "Nhap diem ly :" << endl;
				cin >> p->dDiem.fly;
				if (cin.fail())
				{
					cout << "\n Dinh lua anh ah, nhap so de : )\n"; system("pause");
					cin.clear();
					cin.ignore(numeric_limits< float >::max(), '\n');
					error_detected = true;
					goto tt2;
				}
				else
				{
					error_detected = false;
				}
				if (!bKiemtra(p->dDiem.fly))
				{
					cout << "nhap dung diem ho cai to qua : )\n";
					goto tt2;
				}
			tt3:
				fflush(stdin);
				cout << "nhap diem hoa :" << endl;
				cin >> p->dDiem.fhoa;
				if (cin.fail())
				{
					cout << "\n Dinh lua anh ah, nhap so de : )\n"; system("pause");
					cin.clear();
					cin.ignore(numeric_limits< float >::max(), '\n');
					error_detected = true;
					goto tt3;
				}
				else
				{
					error_detected = false;
				}
				if (!bKiemtra(p->dDiem.fhoa))
				{
					cout << "nhap dung diem ho cai to qua : )\n";
					goto tt3;
				}
				p->next = pdau;
				pdau->prev = p;
				p->prev = NULL;
				pdau = p;
				return pdau;
			}
			else
			{
				if (pchay->sHoten == ten)
				{
					p = new Sinhvien();
					fflush(stdin);
					cout << "Nhap Ho ten sinh vien :" << endl;
					getline(cin, p->sHoten);
					cout << "Nhap so bao danh :" << endl;
					getline(cin, p->sSbd);
					cout << "Nhap dia chi : " << endl;
					getline(cin, p->sDiachi);
					cout << "Nhap gioi tinh :" << endl;
					getline(cin, p->sGT);
					bool error_detected = false;
				tt11:
					fflush(stdin);
					cout << "Nhap diem toan : " << endl;
					cin >> p->dDiem.fToan;
					if (cin.fail())
					{
						cout << "\n Dinh lua anh ah, nhap so de : )\n"; system("pause");
						cin.clear();
						cin.ignore(numeric_limits< float >::max(), '\n');
						error_detected = true;
						goto tt11;
					}
					else
					{
						error_detected = false;
					}
					if (!bKiemtra(p->dDiem.fToan))
					{
						cout << "nhap dung diem ho cai to qua : )\n";
						goto tt11;
					}
				tt22:
					fflush(stdin);
					cout << "Nhap diem ly :" << endl;
					cin >> p->dDiem.fly;
					if (cin.fail())
					{
						cout << "\n Dinh lua anh ah, nhap so de : )\n"; system("pause");
						cin.clear();
						cin.ignore(numeric_limits< float >::max(), '\n');
						error_detected = true;
						goto tt22;
					}
					else
					{
						error_detected = false;
					}
					if (!bKiemtra(p->dDiem.fly))
					{
						cout << "nhap dung diem ho cai to qua : )\n";
						goto tt22;
					}
				tt33:
					fflush(stdin);
					cout << "nhap diem hoa :" << endl;
					cin >> p->dDiem.fhoa;
					if (cin.fail())
					{
						cout << "\n Dinh lua anh ah, nhap so de : )\n"; system("pause");
						cin.clear();
						cin.ignore(numeric_limits< float >::max(), '\n');
						error_detected = true;
						goto tt33;
					}
					else
					{
						error_detected = false;
					}
					if (!bKiemtra(p->dDiem.fhoa))
					{
						cout << "nhap dung diem ho cai to qua : )\n";
						goto tt33;
					}
					p->next = pchay;
					p->prev = pchay->prev;
					pchay->prev->next = p;
					pchay->prev = p;
					return pdau;
				}
				pchay = pchay->next;
			}
		}
	}

}
void sinhvien::vSuaSV(Sinhvien *pdau)
{
	Sinhvien *pchay, *p;
	bool flag = false;
	pchay = pdau;
	string sbd;
	cout << "Nhap so sbd cua sinh vien can sua :";
	fflush(stdin);
	getline(cin, sbd);
	if (pdau == NULL)
	{
		cout << "Chua co sinh vien nao de sua :)";
	}
	else
	{
		while (pchay != NULL)
		{
			if (pchay->sSbd == sbd)
			{
				fflush(stdin);
				cout << "Nhap Ho ten sinh vien :" << endl;
				getline(cin, pchay->sHoten);
				cout << "Nhap so bao danh :" << endl;
				getline(cin, pchay->sSbd);
				cout << "Nhap dia chi : " << endl;
				getline(cin, pchay->sDiachi);
				cout << "Nhap gioi tinh :" << endl;
				getline(cin, pchay->sGT);
				bool error_detected = false;
			tt1:
				cout << "Nhap diem toan : " << endl;
				cin >> pchay->dDiem.fToan;
				if (cin.fail())
				{
					cout << "\n Dinh lua anh ah, nhap so de : )\n"; system("pause");
					cin.clear();
					cin.ignore(numeric_limits< float >::max(), '\n');
					error_detected = true;
					goto tt1;
				}
				else
				{
					error_detected = false;
				}
				if (!bKiemtra(pchay->dDiem.fToan))
				{
					cout << "nhap dung diem ho cai to qua : )\n";
					goto tt1;
				}
			tt2:
				cout << "Nhap diem ly :" << endl;
				cin >> pchay->dDiem.fly;
				if (cin.fail())
				{
					cout << "\n Dinh lua anh ah, nhap so de : )\n"; system("pause");
					cin.clear();
					cin.ignore(numeric_limits< float >::max(), '\n');
					error_detected = true;
					goto tt2;
				}
				else
				{
					error_detected = false;
				}
				if (!bKiemtra(pchay->dDiem.fly))
				{
					cout << "nhap dung diem ho cai to qua : )\n";
					goto tt2;
				}
			tt3:
				cout << "nhap diem hoa :" << endl;
				cin >> pchay->dDiem.fhoa;
				if (cin.fail())
				{
					cout << "\n Dinh lua anh ah, nhap so de : )\n"; system("pause");
					cin.clear();
					cin.ignore(numeric_limits< float >::max(), '\n');
					error_detected = true;
					goto tt3;
				}
				else
				{
					error_detected = false;
				}
				if (!bKiemtra(pchay->dDiem.fhoa))
				{
					cout << "nhap dung diem ho cai to qua : )\n";
					goto tt3;
				}
				cout << "Da sua xong :)" << endl;
				flag = true;
			}
			pchay = pchay->next;
		}
		if (!flag)
		{
			cout << "Chiu, tim ko thay thong tin nguoi can sua";
		}
	}

	system("pause");
}

Sinhvien *sinhvien::vNhapSVbanphim( Sinhvien *pdau)
{
	Sinhvien *pchay = NULL, *p;
	if (pdau != NULL)
	{
		while (pchay->next != NULL)
		{
			pchay = pchay->next;
		}
	}
	char a = '1';
	do
	{
		if (pdau == NULL)
		{
			p = new Sinhvien();
			fflush(stdin);
			cout << "Nhap Ho ten sinh vien :" << endl;
			getline(cin, p->sHoten);
			cout << "Nhap so bao danh :" << endl;
			getline(cin, p->sSbd);
			cout << "Nhap dia chi : " << endl;
			getline(cin, p->sDiachi);
			cout << "Nhap gioi tinh :" << endl;
			getline(cin, p->sGT);
			bool error_detected = false;
		tt1:
			fflush(stdin);
			cout << "Nhap diem toan : " << endl;
			cin >> p->dDiem.fToan;
			if (cin.fail())
			{
				cout << "\n Dinh lua anh ah, nhap so de : )\n"; system("pause");
				cin.clear();
				cin.ignore(numeric_limits< float >::max(), '\n');
				error_detected = true;
				goto tt1;
			}
			else
			{
				error_detected = false;
			}
			if (!bKiemtra(p->dDiem.fToan))
			{
				cout << "nhap dung diem ho cai to qua : )\n";
				goto tt1;
			}
		tt2:
			fflush(stdin);
			cout << "Nhap diem ly :" << endl;
			cin >> p->dDiem.fly;
			if (cin.fail())
			{
				cout << "\n Dinh lua anh ah, nhap so de : )\n"; system("pause");
				cin.clear();
				cin.ignore(numeric_limits< float >::max(), '\n');
				error_detected = true;
				goto tt2;
			}
			else
			{
				error_detected = false;
			}
			if (!bKiemtra(p->dDiem.fly))
			{
				cout << "nhap dung diem ho cai to qua : )\n";
				goto tt2;
			}
		tt3:
			fflush(stdin);
			cout << "nhap diem hoa :" << endl;
			cin >> p->dDiem.fhoa;
			if (cin.fail())
			{
				cout << "\n Dinh lua anh ah, nhap so de : )\n"; system("pause");
				cin.clear();
				cin.ignore(numeric_limits< float >::max(), '\n');
				error_detected = true;
				goto tt3;
			}
			else
			{
				error_detected = false;
			}
			if (!bKiemtra(p->dDiem.fhoa))
			{
				cout << "nhap dung diem ho cai to qua : )\n";
				goto tt3;
			}
			 pdau = pchay = p;
			p->next = NULL;
			p->prev = NULL;
		}
		else
		{
			p = new Sinhvien();
			system("cls");
			fflush(stdin);
			cout << "Nhap Ho ten sinh vien :" << endl;
			getline(cin, p->sHoten);
			cout << "Nhap so bao danh :" << endl;
			getline(cin, p->sSbd);
			cout << "Nhap dia chi : " << endl;
			getline(cin, p->sDiachi);
			cout << "Nhap gioi tinh :" << endl;
			getline(cin, p->sGT);
			bool error_detected = false;
		tt4:
			fflush(stdin);
			cout << "Nhap diem toan : " << endl;
			cin >> p->dDiem.fToan;
			if (cin.fail())
			{
				cout << "\n Dinh lua anh ah, nhap so de : )\n"; system("pause");
				cin.clear();
				cin.ignore(numeric_limits< float >::max(), '\n');
				error_detected = true;
				goto tt4;
			}
			else
			{
				error_detected = false;
			}
			if (!bKiemtra(p->dDiem.fToan))
			{
				cout << "nhap dung diem ho cai to qua : )\n";
				goto tt4;
			}
		tt5:
			fflush(stdin);
			cout << "Nhap diem ly :" << endl;
			cin >> p->dDiem.fly;
			if (cin.fail())
			{
				cout << "\n Dinh lua anh ah, nhap so de : )\n"; system("pause");
				cin.clear();
				cin.ignore(numeric_limits< float >::max(), '\n');
				error_detected = true;
				goto tt5;
			}
			else
			{
				error_detected = false;
			}
			if (!bKiemtra(p->dDiem.fly))
			{
				cout << "nhap dung diem ho cai to qua : )\n";
				goto tt5;
			}
		tt6:
			fflush(stdin);
			cout << "nhap diem hoa :" << endl;
			cin >> p->dDiem.fhoa;
			if (cin.fail())
			{
				cout << "\n Dinh lua anh ah, nhap so de : )\n"; system("pause");
				cin.clear();
				cin.ignore(numeric_limits< float >::max(), '\n');
				error_detected = true;
				goto tt6;
			}
			else
			{
				error_detected = false;
			}
			if (!bKiemtra(p->dDiem.fhoa))
			{
				cout << "nhap dung diem ho cai to qua : )\n";
				goto tt6;
			}
			pchay->next = p;
			p->prev = pchay;
			pchay = p;
			
			p->next = NULL;
		}
		cout << "Ban co muon nhap tiep ko ? ( nhan esc de thoat)" << endl;
		a = _getch();
	} while (a != 27);
	return pdau;
}
