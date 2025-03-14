#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Cấu trúc lưu thông tin phòng thi
struct PhongThi {
    int soPhong;  // Số phòng
    char nha;     // Nhà (A-Z)
    int sucChua;  // Khả năng chứa
};

// Sắp xếp theo sức chứa giảm dần
bool soSanhSucChua(const PhongThi& a, const PhongThi& b) { return a.sucChua > b.sucChua; }
// Sắp xếp theo Nhà (A-Z), cùng nhà thì số phòng tăng dần
bool soSanhNhaVaPhong(const PhongThi& a, const PhongThi& b) { return (a.nha == b.nha) ? a.soPhong < b.soPhong : a.nha < b.nha; }
// Sắp xếp theo Nhà (A-Z), cùng nhà thì sức chứa giảm dần
bool soSanhNhaVaSucChua(const PhongThi& a, const PhongThi& b) { return (a.nha == b.nha) ? a.sucChua > b.sucChua : a.nha < b.nha; }

// Hàm QuickSort để sắp xếp danh sách phòng thi
void quickSort(vector<PhongThi>& dsPhong, int low, int high, bool (*soSanh)(const PhongThi&, const PhongThi&)) {
    if (low < high) {
        PhongThi pivot = dsPhong[high];
        int i = low - 1;
        for (int j = low; j < high; j++) if (soSanh(dsPhong[j], pivot)) swap(dsPhong[++i], dsPhong[j]);
        swap(dsPhong[i + 1], dsPhong[high]);
        quickSort(dsPhong, low, i, soSanh);
        quickSort(dsPhong, i + 2, high, soSanh);
    }
}

// Hàm in danh sách phòng thi
void inDanhSachPhong(const vector<PhongThi>& dsPhong) {
    for (const auto& p : dsPhong) cout << "Nhà " << p.nha << " - Phòng " << p.soPhong << " - Sức chứa: " << p.sucChua << endl;
    cout << endl;
}
void test1()
{
    int n;
    cout << "Nhập số lượng phòng thi: "; cin >> n;
    vector<PhongThi> dsPhong(n);
    cout << "Nhập thông tin phòng thi (Số phòng, Nhà, Khả năng chứa):\n";
    for (auto& p : dsPhong) cin >> p.soPhong >> p.nha >> p.sucChua;

    // Sắp xếp theo sức chứa giảm dần
    quickSort(dsPhong, 0, n - 1, soSanhSucChua);
    cout << "Danh sách phòng thi theo Sức chứa giảm dần:\n"; inDanhSachPhong(dsPhong);

    // Sắp xếp theo Nhà (A-Z), cùng nhà theo số phòng tăng dần
    quickSort(dsPhong, 0, n - 1, soSanhNhaVaPhong);
    cout << "Danh sách phòng thi theo Nhà (A->Z), cùng nhà theo Số phòng tăng dần:\n"; inDanhSachPhong(dsPhong);

    // Sắp xếp theo Nhà (A-Z), cùng nhà theo sức chứa giảm dần
    quickSort(dsPhong, 0, n - 1, soSanhNhaVaSucChua);
    cout << "Danh sách phòng thi theo Nhà (A->Z), cùng nhà theo Sức chứa giảm dần:\n"; inDanhSachPhong(dsPhong);
}
int main() {
    test1();
    return 0;
}