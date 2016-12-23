#include "iostream"
#include "stdio.h"
#include "conio.h"
#include <fstream> 
#include <string>
#include <vector>
#include <math.h> 
#include <iomanip>
#include "view.h";
#include "sinhvien.h"
using namespace std;


int main()
{
	Sinhvien *pdau = NULL, *pcuoi=NULL;

	Thu tn;
	
	sinhvien sv;
	int nhap = 0;
	while (nhap != 18)
	{
		tn.vMenu();
		bool error_detected = false;
		cin >> nhap;
		if (cin.fail())
		{
			cout << "\n dinh lua anh ah, nhap so de : )\n"; system("pause");
			cin.clear();
			cin.ignore(numeric_limits< int >::max(), '\n');
			error_detected = true;
			continue;
		}
		switch (nhap)
		{
			
		case 1: pdau = sv.vNhapSVbanphim(pdau); break;
		case 2: pdau = sv.vNhapSVfile(pdau); break;
		case 3: pdau = sv.vThemSV(pdau); break;
		case 4:	sv.vSuaSV(pdau); break;
		case 5: pdau = sv.XoaSV(pdau); break;
		case 6: sv.vTkTongDiem(pdau); break;
		case 7: sv.vTkSbd(pdau); break;
		case 8: sv.vTkHoTen(pdau); break;
		case 9:break;
		case 10: sv.vSsIncAnpha(pdau); break;
		case 11: sv.vSsIncTongDiem(pdau); break;
		case 12: sv.vThKTongThSinh(pdau); break;
		case 13: sv.vThKTonglt15(pdau); break;
		case 14: sv.vThKTongbetwen15to20(pdau); break;
		case 15: sv.vThKTongbetwen20to25(pdau); break;
		case 16: sv.vThKTonggt25(pdau); break;
		case 17: sv.vSsSbd(pdau); break;
		default: cout << "xin vui long nhap dung "; break;
		}

	}
	
	return 0;
}
