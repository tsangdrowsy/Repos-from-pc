#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
typedef struct {
    char Ten[50];
    int SoLuong;
    char DVT[20];
    float DonGia;
} LoaiHoa;
typedef struct {
    LoaiHoa danhSach[20];
    int SoLuongLoai;
} DanhSachLoaiHoa;
void NhapDanhSach(DanhSachLoaiHoa* ds) {
    printf("Nhap so luong loai hoa: ");
    scanf("%d", &ds->SoLuongLoai);

    for (int i = 0; i < ds->SoLuongLoai; i++) {
        printf("Nhap thong tin loai hoa thu %d:\n", i + 1);
        printf("Ten loai: ");
        scanf("%s", ds->danhSach[i].Ten);
        printf("So luong: ");
        scanf("%d", &ds->danhSach[i].SoLuong);
        printf("Don vi tinh: ");
        scanf("%s", ds->danhSach[i].DVT);
        printf("Don gia: ");
        scanf("%f", &ds->danhSach[i].DonGia);
    }
}
void XuatDanhSach(DanhSachLoaiHoa ds) {
    printf("\nDanh sach cac loai hoa:\n");
    for (int i = 0; i < ds.SoLuongLoai; i++) {
        printf("Ten: %s, So luong: %d, DVT: %s, Don gia: %.2f VND\n",
            ds.danhSach[i].Ten,
            ds.danhSach[i].SoLuong,
            ds.danhSach[i].DVT,
            ds.danhSach[i].DonGia);
    }
}
int TimLoaiHoa(DanhSachLoaiHoa ds, char* tenloai) {
    for (int i = 0; i < ds.SoLuongLoai; i++) {
        if (strcmp(ds.danhSach[i].Ten, tenloai) == 0) {
            return i;
        }
    }
    return -1;
}
void XuLyBanHoa(DanhSachLoaiHoa* ds, char* tenloai, int soluong) {
    int vitri = TimLoaiHoa(*ds, tenloai);

    if (vitri == -1) {
        printf("Khong tim thay loai hoa \"%s\" trong danh sach.\n", tenloai);
    }
    else {
        if (ds->danhSach[vitri].SoLuong >= soluong) {
            float tongTien = soluong * ds->danhSach[vitri].DonGia;
            ds->danhSach[vitri].SoLuong -= soluong; 
            printf("Ban thanh cong SL: %d DVT: %s TenLoai: %s. Tong tien: %.2f VND\n",
                soluong, ds->danhSach[vitri].DVT, tenloai, tongTien);
        }
        else {
            printf("Khong du so luong %s de ban. So luong con lai: %d DVT: %s.\n",
                tenloai, ds->danhSach[vitri].SoLuong, ds->danhSach[vitri].DVT);
        }
    }
}
int main() {
    DanhSachLoaiHoa ds;
    char tenloai[50];
    int soluong;
    NhapDanhSach(&ds);
    XuatDanhSach(ds);
    printf("\nNhap ten loai hoa can ban: ");
    scanf("%s", tenloai);
    printf("Nhap so luong can ban: ");
    scanf("%d", &soluong);
    XuLyBanHoa(&ds, tenloai, soluong);
    XuatDanhSach(ds);
    return 0;
}