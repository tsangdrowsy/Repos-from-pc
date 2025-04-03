#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

typedef struct
{
	char MaSo[11];
	char Ho[11];
	char Ten[51];
	int Phai;
	int ThamNien;
}NhanVien;
typedef struct {
	NhanVien aNhanVien[100];  
	int SoLuong;              
} PhongBan;
void NhapPhongBan(PhongBan* pb) {
	printf("Nhap so luong nhan vien: ");
	scanf("%d", &pb->SoLuong);
    for (int i = 0; i < pb->SoLuong; i++) {
        printf("Nhap thong tin nhan vien thu %d:\n", i + 1);
        printf("Ma so: ");
        scanf("%s", pb->aNhanVien[i].MaSo);
        printf("Ho: ");
        scanf("%s", pb->aNhanVien[i].Ho);
        printf("Ten: ");
        scanf("%s", pb->aNhanVien[i].Ten);
        printf("Phai (0: Nu, 1: Nam): ");
        scanf(" %d", &pb->aNhanVien[i].Phai);
        printf("Tham nien: ");
        scanf("%d", &pb->aNhanVien[i].ThamNien);
    }
}
void XuatPhongBan(PhongBan pb) {
    printf("\nDanh sach nhan vien:\n");
    for (int i = 0; i < pb.SoLuong; i++) {
        printf("Ma so: %s, Ho: %s, Ten: %s, Phai: %s, Tham nien: %d\n",
            pb.aNhanVien[i].MaSo,
            pb.aNhanVien[i].Ho,
            pb.aNhanVien[i].Ten,
            pb.aNhanVien[i].Phai == 0 ? "Nu" : "Nam",
            pb.aNhanVien[i].ThamNien);
    }
}
void DemSiSo(PhongBan pb, int* sonam, int* sonu) {
    *sonam = 0;
    *sonu = 0;

    for (int i = 0; i < pb.SoLuong; i++) {
        if (pb.aNhanVien[i].Phai == 1) {
            (*sonam)++;
        }
        else {
            (*sonu)++;
        }
    }
}
void SapXepTangTheoThamNien(PhongBan* pb) {
    for (int i = 0; i < pb->SoLuong - 1; i++) {
        for (int j = i + 1; j < pb->SoLuong; j++) {
            if (pb->aNhanVien[i].ThamNien > pb->aNhanVien[j].ThamNien) {
                NhanVien temp = pb->aNhanVien[i];
                pb->aNhanVien[i] = pb->aNhanVien[j];
                pb->aNhanVien[j] = temp;
            }
        }
    }
}
int main() 
{
    PhongBan pb;
    int sonam, sonu;
    NhapPhongBan(&pb);
    DemSiSo(pb, &sonam, &sonu);
    printf("\nSo luong nhan vien nam: %d\n", sonam);
    printf("So luong nhan vien nu: %d\n", sonu);
    SapXepTangTheoThamNien(&pb);
    XuatPhongBan(pb);
    return 0;
}