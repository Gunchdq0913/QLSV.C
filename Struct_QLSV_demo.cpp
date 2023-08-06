#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <math.h>
#include <conio.h>
#define MAX 100

/*
	Quan ly sinh vien:
		- Danh sach sinh vien: hoTen, namSinh, diemTb;
		- Sach trong thu vien: tenSach, tenTacGia, namXuatBan, float danhGia;
	Ve cau truc du lieu:
		- Truy xuat/ truy van/ Xem thong tin
		- Them
		- Sua
		- Xoa
		- Sap xep theo hoTen, diemTb
	Hay viet chuong trinh de quan ly danh sach sinh vien, chuong trinh co cac chuc nang sau:
		1. Them mot danh sach sinh vien
		2. Hien thi danh sach sinh vien
		3. Them mot sinh vien vao cuoi
		4. Sua mot sinh vien theo ten
		5. Xoa mot sinh vien theo ten
		6. Sap xep sinh vien 
		0. Thoat chuong trinh
*/
//Dinh nghia cau truc du lieu
typedef struct
{
	char hoTen[20];
	int namSinh;
	float to, ly, ho, diemTB;
} SinhVien;
//Xay dung cac phuong thuc de thao tac voi KDL SinhVien, mang cac SinhVien[]
SinhVien nhapThongTinSinhVien()
{
	SinhVien sv;
	printf("\tNhap ho ten: ");
	fflush(stdin);
	gets(sv.hoTen);
	printf("\tNhap nam sinh: ");
	scanf("%d", &sv.namSinh);
	printf("\tNhap diem TB cac mon\n");
	printf("\t\tToan: "); scanf("%f", &sv.to);
	printf("\t\tLy: "); scanf("%f", &sv.ly);
	printf("\t\tHoa: "); scanf("%f", &sv.ho);
	sv.diemTB = (sv.to+sv.ly+sv.ho)/3;
	return sv;	
}

void hienThiSinhVienTheoDong(SinhVien sv)
{
	printf("%20s%10d%7.2f%6.2f%6.2f%9.2f", sv.hoTen, sv.namSinh, sv.to, sv.ly, sv.ho, sv.diemTB);
}

//Xay dung cac phuong thuc de thao tac mang cac SinhVien[]
void hienThiDanhSachSinhVien(SinhVien students[], int n)
{
	printf("\t\t\tDANH SACH SINH VIEN\n");
	printf("\t%5s%20s%10s%7s%6s%6s%9s\n", "STT", "HO TEN", "NAM SINH", "TOAN", "LY", "HOA", "DIEM TB");
	for(int i=0; i<n; i++)
	{
		printf("\t%5d", i+1);
		hienThiSinhVienTheoDong(students[i]);
		printf("\n");
	}
}

int themSinhVienVaoDanhSach(SinhVien students[], int n, SinhVien sv)
{
	students[n] = sv;
	return n+1;
}

int taoDanhSachSinhVien(SinhVien students[], int n)
{
	while(true)
	{
		SinhVien sv = nhapThongTinSinhVien();
		n = themSinhVienVaoDanhSach(students, n, sv);
		printf("\t\tNhap tiep? (y neu co): ");
		char chon;
		fflush(stdin);
		scanf("%c", &chon);
		if(chon!='y'&&chon!='Y')
			break;
	}
	return n;
}

int timSinhVienTheoTen(SinhVien students[], int n, char hoTenCanTim[])
{
	for(int i=0; i<n; i++)
	{
		if(strcmp(hoTenCanTim, students[i].hoTen)==0)
		{
			return i;
		}
	}
	return -1;
}

void suaSinhVienTheoTen(SinhVien students[], int n, char hoTenCanSua[])
{
	int index = timSinhVienTheoTen(students, n, hoTenCanSua);
	if(index<0)
	{
		printf("\tKhong tim thay sinh vien %s\n", hoTenCanSua);
	}
	else
	{
		printf("\tNhap thong tin moi cua sinh vien: ");
		SinhVien sv = nhapThongTinSinhVien();
		students[index] = sv;
	}
}

int xoaSinhVienTheoTen(SinhVien students[], int n, char hoTenCanXoa[])
{
	int index = timSinhVienTheoTen(students, n, hoTenCanXoa);
	if(index<0)
	{
		printf("\tKhong tim thay sinh vien %s\n", hoTenCanXoa);
		return n;
	}
	else
	{
		while(index<n-1)
		{
			students[index] = students[index+1];
			index++; 
		}
		printf("\tDa xoa xong sinh vien%s\n", hoTenCanXoa);
		return n-1;
	}
}

void hienThiMenu()
{
	printf("\t\tMENU\n");
	printf("\t1. Nhap danh sach sinh vien\n");
	printf("\t2. Hien thi danh sach sinh vien\n");
	printf("\t3. Them mot sinh vien\n");
	printf("\t4. Sua mot sinh vien theo ten\n");
	printf("\t5. Xoa mot sinh vien theo ten\n");
	printf("\t6. Sap xep danh sach sinh vien theo diem giam dan\n");
	printf("\t0. Exit\n");
	printf("\t\tVui long chon: ");
}

void sapXepSinhVienTheoDiemGiamDan(SinhVien students[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(students[i].diemTB>students[j].diemTB)
			{
				float tam = students[i].diemTB;
				students[i].diemTB = students[j].diemTB;
				students[j].diemTB = tam;
			}
		}
	}
}
int main()
{
	SinhVien students[MAX];
	int n=0;
	while(true)
	{
		hienThiMenu();
		int chon;
		scanf("%d", &chon);
		system("cls"); //Xoa man hinh console
		switch(chon)
		{
			case 1: 
				printf("\t\tBan vua chon chuc nang 1: Them mot danh sach sinh vien!\n");
				n = taoDanhSachSinhVien(students, n);
				break;
			case 2: 
				hienThiDanhSachSinhVien(students, n);
				break;
			case 3: 
				printf("\t\tBan vua chon chuc nang 3: Them mot sinh vien!\n");
				printf("\tNhap thong tin sinh vien muon them\n");
				n = themSinhVienVaoDanhSach(students, n, nhapThongTinSinhVien());
				break;
			case 4: 
				printf("\t\tBan vua chon chuc nang 4: Sua mot sinh vien!\n");
				printf("\tNhap ten sinh vien muon sua: ");
				char hoTen_1[MAX];
				fflush(stdin);
				gets(hoTen_1);
				suaSinhVienTheoTen(students, n, hoTen_1);
				break;
			case 5: 
				printf("\t\tBan vua chon chuc nang 5: Xoa mot sinh vien\n");
				printf("\tNhap ten sinh vien muon xoa: ");
				char hoTen_2[MAX];
				fflush(stdin);
				gets(hoTen_2);
				n = xoaSinhVienTheoTen(students, n, hoTen_2);
				break;
			case 6: 
				printf("\tBan da chon sap xep sinh vien theo diem giam dan!\n");
				sapXepSinhVienTheoDiemGiamDan(students, n);
				hienThiDanhSachSinhVien(students, n);
				break;
			case 0: 
				return 0;
			default: 
			{
				printf("\tChi nhap tu 0--6\n");
			}
		}
		printf("\t\tBam phim bat ky de tro ve menu\n");
		getch();
		system("cls");
	}
}
