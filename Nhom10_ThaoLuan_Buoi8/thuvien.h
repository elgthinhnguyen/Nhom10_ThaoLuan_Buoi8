#pragma once
#define MAX 100

struct ThietBi {
	string MaTB;
	string TenTB;
	int NamNhap;
	int ThoigianBH;
	int Giatien;
};

// nhap danh sach thiet bi.
typedef ThietBi DSThietBi[MAX];

void NhapTB(ThietBi& TB,int i) {
	system("cls");
	cout << "NHAP THIET BI "<<i+1;
	cout << "\nNhap ma thiet bi: "; cin >> TB.MaTB; cin.ignore();
	cout << "\nNhap ten thiet bi: "; getline(cin, TB.TenTB);
	cout << "\nNhap nam nhap thiet bi: "; cin >> TB.NamNhap;
	cout << "\nNhap thoi gian bao hanh thiet bi: "; cin >> TB.ThoigianBH;
	cout << "\nNhap gia tien thiet bi: "; cin >> TB.Giatien;
}

void XuatTB(ThietBi TB) {
	
	cout<<endl << setiosflags(ios::left)
	<< setw(20)<<TB.MaTB
	<< setw(25) << TB.TenTB
	<< setw(25) << TB.NamNhap
	<< setw(30) << TB.ThoigianBH
    << setw(30)  << TB.Giatien;
}

void NhapDSTB(DSThietBi DSTB,int n) {
	
	
	for (int i = 0; i < n; i++) {
		NhapTB(DSTB[i],i);
	}
}

void XuatDSTB(DSThietBi DSTB, int n) {
	cout << endl << setiosflags(ios::left)
		<<setw(20) <<"Ma thiet bi: "
		<< setw(25) << "Ten thiet bi: "
		<< setw(25) << "Nam nhap thiet bi: "
		<< setw(30) << "Thoi gian bao hanh thiet bi: "
		<< setw(30) << "Gia tien thiet bi: ";
	for (int i = 0; i < n; i++) {
		XuatTB(DSTB[i]);

	}
}

int TongGiaTien(int x, int y, DSThietBi DSTB, int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (DSTB[i].NamNhap >= x && DSTB[i].NamNhap <= y) {
			count += DSTB[i].Giatien;
			
		}

	}
	return count;
}

int XacDinhViTri(DSThietBi DSTB, int n, string matb) {
	for (int i = 0; i < n; i++) {
		if (DSTB[i].MaTB == matb) {
			return i + 1;
		}
	}
	return 0;
}

void HoanVi(ThietBi &TB1, ThietBi &TB2) {
	string stemp ;
	int itemp ;
	// MaTB 
	stemp = TB1.MaTB;
	TB1.MaTB = TB2.MaTB;
	TB2.MaTB = stemp;

	// TenTB
	stemp = TB1.TenTB;
	TB1.TenTB = TB2.TenTB;
	TB2.TenTB = stemp;


	// NamNhap
	itemp = TB1.NamNhap;
	TB1.NamNhap = TB2.NamNhap;
	TB2.NamNhap = itemp;

	// GiaTien
	itemp = TB1.Giatien;
	TB1.Giatien = TB2.Giatien;
	TB2.Giatien = itemp;
	// Bao hanh
	itemp = TB1.ThoigianBH;
	TB1.ThoigianBH = TB2.ThoigianBH;
		TB2.ThoigianBH = itemp;
}

void XapXepThietBi(DSThietBi DSTB, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (DSTB[i].NamNhap < DSTB[j].NamNhap) {
				cout << "\ntrue";
				HoanVi(DSTB[i], DSTB[j]);
				if (DSTB[i].NamNhap == DSTB[j].NamNhap) {
					if (DSTB[i].TenTB.compare(DSTB[j].TenTB) > 0) {
						HoanVi(DSTB[i], DSTB[j]);

					}

				}
			}
		}
	}

}
void xoaphantu(int x,DSThietBi DSTB,int &n){
	
	for (int i = x; i <= n; i++) {	
			HoanVi(DSTB[i], DSTB[i+1]);
	}
	n--;
	
}
void xoacacPTnam(int x, DSThietBi DSTB, int &n) {
	for (int i = 0; i < n; i++) {
		if (DSTB[i].NamNhap == x)
			xoaphantu(i, DSTB, n);
	}
}
void chenTB(string y, int n, DSThietBi DSTB) {
	int j;
	for (j = -1; j < n; j++) {
		if (DSTB[j].MaTB == y) {
			break;
		}
	}
	
	NhapTB(DSTB[n], n);
	for (int i = n; i >j; i--) {
		HoanVi(DSTB[i], DSTB[i - 1]);
	}
}

