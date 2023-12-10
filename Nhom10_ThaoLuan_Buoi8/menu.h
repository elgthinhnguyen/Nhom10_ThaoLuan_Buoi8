#pragma once


ThietBi DSTB[MAX];
void xuatMenu() {
	cout << "\n~~~~~~~~~~~~MENU BAI TAP~~~~~~~~~~~~";
	cout << "\n1.nhap danh sach thiet bi";
	cout << "\n2.xuat danh sach thiet bi";
	cout << "\n3.tinh tong gia tien cua tat ca thiet bi";
	cout << "\n4.tim vi tri thiet bi theo ma thiet bi";
	cout << "\n5.sap xep danh sach thiet bi giam theo nam nhap neu nam nhap bang nhau tang theo ten thiet bi";
	cout << "\n6.xoa tat ca thiet bi co nam nhap x";
	
	cout << "\n7.chen thiet bi tb sau thiet bi co ma thiet bi la y cho truoc";
	cout << "\n8.in bang thong ke so thiet bi theo nam nhap";
	cout << "\n0.dung chuong trinh.";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

}

int chonMenu(int soMenu) {
	int so;
	
	cin >> so;
	return so;
}
void xuLiMenu(int so,int &n) {
	string mtb;
	string mTB;
	switch (so) {
	case 1:;
		cout << "\n1.nhap danh sach thiet bi";
		NhapDSTB(DSTB,n);
		break;
	case 2:
		cout << "\n2.xuat danh sach thiet bi";
		XuatDSTB(DSTB, n);

		break;
	case 3:

		cout << "\n3.tinh tong gia tien cua tat ca thiet bi co nam nhap trong doan [x,y]";
		int x, y;
		cout << "\nnhap nam nhap x: "; cin >> x;
		cout << "\nnhap nam nhap y: "; cin >> y;
		cout << "\n tong gia tien la: "
		<<TongGiaTien(x, y, DSTB, n);
		break;
	case 4:
		cout << "\n4.tim vi tri thiet bi theo ma thiet bi";
		
		cout << "\nnhap vao ma thiet bi can tim";
		cin >> mtb;
		cout<<XacDinhViTri(DSTB, n, mtb);
		break;
	case 5:
		cout << "\n5.sap xep danh sach thiet bi giam theo nam nhap neu nam nhap bang nhau tang theo ten thiet bi";
		XapXepThietBi(DSTB, n);
		break;
		
	case 6:
		cout << "\n6.xoa tat ca thiet bi co nam nhap x";
		int z;
		cout << "\nnhap vao nam nhap muon xoa: ";
		cin >> z;
		xoacacPTnam(z, DSTB, n);
		break;
	case 7:
		cout << "\n7.chen thiet bi tb sau thiet bi co ma thiet bi la y cho truoc";
		
		cout << "\nnhap vao ma thiet bi can doi: "; cin >> mTB;
		chenTB(mTB, n, DSTB);
		break;
	case 8:
		cout << "\n8.sap xep cac so nguyen to dau mang tang cac so con lai giam dan";
		break;
	}
}
void hamXuLy(int soMenu) {
	int so;
	int n;
	cout << "Nhap vao so thiet bi: "; cin >> n;
	do {
		
		system("cls");


		xuatMenu();
		cout << "\nnhap 1 so de chon: ";
		so = chonMenu(soMenu);
		system("cls");
		xuLiMenu(so,n);

		if (so != 0) {
			cout << "\nfress any key to continue";
			_getch();
		}
		cout << "\nprogram ended!";
	} while (so != 0);

}