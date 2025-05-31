#include <iostream>
using namespace std;

// H�m ki?m tra s? nguy�n t?
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int n, count = 0, num = 2;
    cout << "Nhap so luong so nguyen to can tim: ";
    cin >> n;

    while (count < n) {
        if (isPrime(num)) {
            cout << num << " ";
            count++;
        }
        num++;
    }

    return 0;
}
