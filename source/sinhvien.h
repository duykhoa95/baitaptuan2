#pragma once
#include "iostream"
#include "stdio.h"
#include "conio.h"
#include <fstream> 
#include <string>
#include <vector>
#include <math.h> 
#include <iomanip>
using namespace std;
typedef struct diem
{
	float fToan, fly, fhoa;
};
typedef struct Sinhvien
{
	string sHoten;
	string sSbd;
	string sDiachi;
	string sGT;
	diem dDiem;
	Sinhvien *next;
	Sinhvien *prev;
};
class sinhvien
{
public:
	sinhvien();
	~sinhvien();
	// them sinh vien
	Sinhvien *vThemSV(Sinhvien *);
	// Nhap sinh vien
	Sinhvien *vNhapSVbanphim( Sinhvien *);
	Sinhvien *vNhapSVfile( Sinhvien *);
	// sua sinh vien
	void vSuaSV(Sinhvien *);
	// xoa sinh vien
	Sinhvien *XoaSV(Sinhvien *);
	// tim kiem sinh vien
	void vTkTongDiem(Sinhvien *);
	void vTkSbd(Sinhvien *);
	void vTkHoTen(Sinhvien *);
	void vTkDiemToan(Sinhvien *);
	// sap xep sinh vien
	void vSsIncAnpha(Sinhvien *);
	void vSsIncTongDiem(Sinhvien *);
	// thong ke thi sinh
	void vThKTongThSinh(Sinhvien *);
	void vThKTonglt15(Sinhvien *);
	void vThKTongbetwen15to20(Sinhvien *);
	void vThKTongbetwen20to25(Sinhvien *);
	void vThKTonggt25(Sinhvien *);
	// tinh tong diem
	float fTongDiem(float, float, float);
	// kiem tra diem
	bool bKiemtra(float);
	// hien thi thong tin sinh vien
	void vHienthi(Sinhvien *);
	//hoan doi
	void vSwap(Sinhvien *, Sinhvien *);
	// xuat file
	void vXuatFile(Sinhvien *);
	void vSsSbd(Sinhvien *);
};

