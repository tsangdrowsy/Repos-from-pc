#include<iostream>
#include<math.h>
using namespace std;

void nhapMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

//Sap xep s? d?ng bubble sort

void Sapxep(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                temp = a[j + 1];
            }
        }
    }
}
int TimChung(int x[], int y[], int z[], int a, int b, int c, int kq[]) {
    int i = 0, j = 0, k = 0, slc = 0;

    while (i < a && j < b && k < c) {
        if (x[i] == y[j] && y[j] == z[k]) {
            if (slc == 0 || x[i] != kq[slc - 1]) {
                kq[slc++] = x[i];
            }
            i++, j++, k++;
        }
        else if (x[i] < x[j]) {
            i++;
        }
        else if (y[j] < z[k]) {
            j++;
        }
        else {
            k++;
        }
    }
    return slc;
}

int main()
{
    int a, b, c;
    int kq[10000];
    cin >> a;
    if (a > 1000) {
        cout << "loi";
        return 0;
    }
    int x[10000];
    nhapMang(x, a);
    cin >> b;
    if (b > 1000) {
        cout << "loi";
        return 0;
    }
    int y[10000];
    nhapMang(y, b);
    cin >> c;
    if (c > 1000) {
        cout << "loi";
        return 0;
    }
    int z[10000];
    nhapMang(z, c);
    Sapxep(x, a);
    Sapxep(y, b);
    Sapxep(z, c);

    int SL = TimChung(x, y, z, a, b, c, kq);
    cout << SL << endl;
    for (int i = 0; i < SL; i++) {
        cout << kq[i] << " ";
    }
    cout << endl;

    return 0;
}
