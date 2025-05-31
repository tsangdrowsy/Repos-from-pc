#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// Hàm nhập mảng 2 chiều
void NhapMang(int a[][100], int x, int y) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << "Nhap phan tu A[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }
}

// Hàm kiểm tra số chính phương
bool SCP(int so) {
    int canso = (int)sqrt(so);
    return (canso * canso == so);
}

// Hàm tính tổng số chính phương
int TongCP(int a[][100], int x, int y) {
    int ketqua = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (SCP(a[i][j])) {
                ketqua = ketqua + a[i][j];
            }
        }
    }
    return ketqua;
}

// Hàm tìm giá trị nhỏ nhất mỗi cột
vector<int> GTNhoNhatMoiCot(int a[][100], int x, int y) {
    vector<int> GTNN(y, INT_MAX);
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (a[j][i] < GTNN[i]) {
                GTNN[i] = a[j][i];
            }
        }
    }
    return GTNN;
}

// Hàm tính tổng các giá trị trên cột thứ n
int TongCotN(int a[][100], int x, int n) {
    int kq = 0;
    for (int hang = 0; hang < x; hang++) {
        kq = kq + a[hang][n];
    }
    return kq;
}

// Hàm tìm GTLN trong số GTNN của mỗi cột
int GTLNtrongcacGTNNmoicot(const vector<int>& GTNN) {
    int GTLN = INT_MIN;
    for (int GT : GTNN) {
        if (GT > GTLN) {
            GTLN = GT;
        }
    }
    return GTLN;
}

int main() {
    int x, y;
    cout << "Nhap so dong x: ";
    cin >> x;
    cout << "Nhap so cot y: ";
    cin >> y;
    int a[100][100];
    NhapMang(a, x, y);

    // Câu a
    int tong = TongCP(a, x, y);
    cout << "Tong cac so CP la: " << tong << endl;

    // Câu b
    vector<int> GTNN = GTNhoNhatMoiCot(a, x, y);
    cout << "GTNN cua moi cot: ";
    for (int GT : GTNN) {
        cout << GT << " ";
    }
    cout << endl;

    // Câu c
    int n;
    cout << "Nhap so n (cot muon tinh tong): ";
    cin >> n;
    if (n >= 0 && n < y) {
        int kq = TongCotN(a, x, n);
        cout << "Tong cac GT tren cot " << n << " : " << kq << endl;
    }
    else {
        cout << "Chi so cot n khong dung" << endl;
    }

    // Câu d
    int kq = GTLNtrongcacGTNNmoicot(GTNN);
    cout << "GTLN trong cac GTNN moi cot la: " << kq << endl;

    return 0;
}
