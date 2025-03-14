#include <iostream>
using namespace std;
const int MAX_SIZE = 100;

void sapXepGiamDan(int mang[][2], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (mang[i][0] < mang[j][0]) {
                // Đổi chỗ giá trị
                swap(mang[i][0], mang[j][0]);
                // Đổi chỗ chỉ số
                swap(mang[i][1], mang[j][1]);
            }
        }
    }
}

void timViTriKPhanTuLonNhat(int mang[], int ketQua[], int k, int kichThuoc) {
    // Tạo mảng chứa cặp giá trị và chỉ số
    int mangCoChiSo[MAX_SIZE][2];
    for (int i = 0; i < kichThuoc; ++i) {
        mangCoChiSo[i][0] = mang[i]; // Giá trị
        mangCoChiSo[i][1] = i;       // Chỉ số
    }

    // Sắp xếp giảm dần theo giá trị
    sapXepGiamDan(mangCoChiSo, kichThuoc);

    // Lấy chỉ số của k phần tử lớn nhất
    for (int i = 0; i < k && i < kichThuoc; ++i) {
        ketQua[i] = mangCoChiSo[i][1];
    }
}
int tinhTongChuSo(int so) {
    int tong = 0;
    while (so != 0) {
        tong += abs(so % 10); // Lấy chữ số cuối cùng và cộng vào tổng
        so /= 10; // Loại bỏ chữ số cuối cùng
    }
    return tong;
}
void sapXepTheoTongChuSo(int mang[], int kichThuoc) {
    for (int i = 0; i < kichThuoc - 1; ++i) {
        for (int j = i + 1; j < kichThuoc; ++j) {
            if (tinhTongChuSo(mang[i]) > tinhTongChuSo(mang[j])) {
                swap(mang[i], mang[j]); // Đổi chỗ nếu tổng chữ số của phần tử trước lớn hơn
            }
        }
    }

}
bool laSoNguyenTo(int so) {
    if (so < 2) return false; // Số nhỏ hơn 2 không phải số nguyên tố
    for (int i = 2; i * i <= so; ++i) {
        if (so % i == 0) return false; // Nếu chia hết cho số khác, không phải số nguyên tố
    }
    return true;
}
void xoaSoNguyenTo(int mang[], int& kichThuoc) {
    int j = 0; // Vị trí mới trong mảng sau khi xóa
    for (int i = 0; i < kichThuoc; ++i) {
        if (!laSoNguyenTo(mang[i])) {
            mang[j] = mang[i]; // Giữ lại phần tử không phải số nguyên tố
            j++;
        }
    }
    kichThuoc = j; // Cập nhật kích thước mảng sau khi xóa
}



void test1()
{
    int n = 9;
    int mang[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5 };

    int k = 3;
    int ketQua[MAX_SIZE];


    timViTriKPhanTuLonNhat(mang, ketQua, k, n);


    cout << "Vi tri cua " << k << " phan tu lon nhat la: ";
    for (int i = 0; i < k; ++i) {
        cout << ketQua[i] << " ";
    }
    cout << endl;
}
void test2()
{
    int n = 10;
    int mang[] = { 33, 11, 41, 21, 52, 90, 12, 26, 5,10 };

    int k = 4;
    int ketQua[MAX_SIZE]; // Mảng để lưu kết quả

    // Gọi hàm tìm vị trí của k phần tử lớn nhất
    timViTriKPhanTuLonNhat(mang, ketQua, k, n);

    // In kết quả
    cout << "Vi tri cua " << k << " phan tu lon nhat la: ";
    for (int i = 0; i < k; ++i) {
        cout << ketQua[i] << " ";
    }
    cout << endl;
    sapXepTheoTongChuSo(mang, n);
    cout << "Mang sau khi sap xep theo tong cac chu so: ";
    for (int i = 0; i < n; ++i) {
        cout << mang[i] << " ";
    }
    cout << endl;
    xoaSoNguyenTo(mang, n);
    cout << "Mang sau khi xoa cac so nguyen to: ";
    for (int i = 0; i < n; ++i) {
        cout << mang[i] << " ";
    }
    cout << endl;
}


int main()
{
    test1();
    test2();

    return 0;
}