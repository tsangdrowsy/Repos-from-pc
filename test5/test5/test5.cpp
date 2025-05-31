#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

void readFile(int*& a, int& n, string& s, string& x, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Khong the mo file " << filename << endl;
        a = nullptr;
        n = 0;
        return;
    }

    file >> n;
    a = new int[n];
    for (int i = 0; i < n; i++) {
        file >> a[i];
    }

    file.ignore();
    getline(file, s);
    getline(file, x);
    file.close();
}

bool ktSNT(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void sapXepMang(int* a, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void xepMangTheoSNT(int* a, int n) {
    if (n <= 0) return;

    int* temp = new int[n];
    int soLuongSNT = 0;
    int soLuongKhongSNT = 0;

    for (int i = 0; i < n; i++) {
        if (ktSNT(a[i])) {
            soLuongSNT++;
        }
    }
    soLuongKhongSNT = n - soLuongSNT;

    int* mangSNT = new int[soLuongSNT];
    int* mangKhongSNT = new int[soLuongKhongSNT];
    int indexSNT = 0, indexKhongSNT = 0;

    for (int i = 0; i < n; i++) {
        if (ktSNT(a[i])) {
            mangSNT[indexSNT++] = a[i];
        }
        else {
            mangKhongSNT[indexKhongSNT++] = a[i];
        }
    }

    sapXepMang(mangSNT, soLuongSNT);
    sapXepMang(mangKhongSNT, soLuongKhongSNT);

    int index = 0;
    for (int i = 0; i < soLuongSNT; i++) {
        temp[index++] = mangSNT[i];
    }
    for (int i = 0; i < soLuongKhongSNT; i++) {
        temp[index++] = mangKhongSNT[i];
    }

   
    for (int i = 0; i < n; i++) {
        a[i] = temp[i];
    }

   
    delete[] mangSNT;
    delete[] mangKhongSNT;
    delete[] temp;
}

int demXuatHien(const string& s, const string& x) {
    if (x.empty() || s.empty()) return 0;

    int count = 0;
    size_t pos = 0;
    while ((pos = s.find(x, pos)) != string::npos) {
        count++;
        pos += x.length();
        if (pos >= s.length()) break;
    }
    return count;
}

string timTuDaiNhat(const string& s) {
    if (s.empty()) return "";

    string TuDaiNhat;
    string TuHT;
    for (char ch : s) {
        if (ch == ' ') {
            if (TuHT.length() > TuDaiNhat.length()) {
                TuDaiNhat = TuHT;
            }
            TuHT.clear();
        }
        else {
            TuHT += ch;
        }
    }
    if (TuHT.length() > TuDaiNhat.length()) {
        TuDaiNhat = TuHT;
    }
    return TuDaiNhat;
}

void writeFile(const int* a, int n, int count, const string& longestWord, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Khong the mo file " << filename << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        file << a[i] << " ";
    }
    file << endl;

    file << count << endl;
    file << longestWord << endl;
    file.close();
}

int main()
{
    int* a = nullptr;
    int n = 0;
    string s, x;
    const string inputFile = "DE03.INP";
    const string outputFile = "DE03.OUT";

    readFile(a, n, s, x, inputFile);
    if (a == nullptr) {
        return 1;
    }
    


    cout << "Mang a: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\nChuoi s: " << s << "\nChuoi x: " << x << endl;

    xepMangTheoSNT(a, n);
    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    int count = demXuatHien(s, x);
    cout << "So lan xuat hien cua x trong s: " << count << endl;

    string tuDaiNhat = timTuDaiNhat(s);
    cout << "Tu dai nhat trong s: " << tuDaiNhat << endl;

    writeFile(a, n, count, tuDaiNhat, outputFile);

    delete[] a;
    return 0;
}

