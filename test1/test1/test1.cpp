#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

void TaoMangNgauNhien(int a[], int n) {
    for (int i = 0; i < n; i++)
        a[i] = rand() % 10000;
}

void InMang(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int a[], int n, int& sosanh, int& doi) {
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            sosanh++;
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                doi++;
            }
        }
    }
}

void selectionSort(int a[], int n, int& sosanh, int& doi) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            sosanh++;
            if (a[j] < a[min])
                min = j;
        }
        if (min != i) {
            swap(a[i], a[min]);
            doi++;
        }
    }
}

void InsertionSort(int a[], int n, int& sosanh, int& doi) {
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int x = a[i];
        bool cont = true;
        while ((j >= 0) && cont) {
            sosanh++;
            if (a[j] > x) {
                a[j + 1] = a[j];
                j--;
                doi++;
            }
            else {
                cont = false;
            }
        }
        a[j + 1] = x;
    }
}

void Partition(int a[], int p, int q, int& sosanh, int& doi) {
    int x = a[(p + q) / 2];
    int i = p;
    int j = q;
    do {
        while (a[i] < x) { i++; sosanh++; }
        while (a[j] > x) { j--; sosanh++; }
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
            doi++;
        }
    } while (i <= j);
    if (p < j)
        Partition(a, p, j, sosanh, doi);
    if (i < q)
        Partition(a, i, q, sosanh, doi);
}

void QuickSort(int a[], int n, int& sosanh, int& doi) {
    Partition(a, 0, n - 1, sosanh, doi);
}

void Merge(int a[], int temp[], int p, int t, int q, int& sosanh, int& doi) {
    int i = p;
    int k = t - 1;
    int dem = 0;
    while ((p <= k) && (t <= q)) {
        sosanh++;
        if (a[p] < a[t]) {
            temp[dem] = a[p];
            p++;
        }
        else {
            temp[dem] = a[t];
            t++;
        }
        dem++;
    }
    while (p <= k) {
        temp[dem] = a[p];
        dem++;
        p++;
    }
    while (t <= q) {
        temp[dem] = a[t];
        dem++;
        t++;
    }
    for (int j = 0; j < dem; j++) {
        a[i + j] = temp[j];
        doi++;
    }
}

void RecMergeSort(int a[], int temp[], int p, int q, int& sosanh, int& doi) {
    if (p < q) {
        int k = (p + q) / 2;
        RecMergeSort(a, temp, p, k, sosanh, doi);
        RecMergeSort(a, temp, k + 1, q, sosanh, doi);
        Merge(a, temp, p, k + 1, q, sosanh, doi);
    }
}

void MergeSort(int a[], int n, int& sosanh, int& doi) {
    int* temp = new int[n];
    RecMergeSort(a, temp, 0, n - 1, sosanh, doi);
    delete[] temp;
}

void test1() {
    srand(time(NULL));
    int z[] = { 10, 100, 200, 500, 1000, 2000, 5000, 10000 };
    int t = 5; // số lần chạy là 5
    for (int i = 0; i < sizeof(z) / sizeof(z[0]); i++) {
        int n = z[i];
        int* a = new int[n];
        clock_t start, end;
        double time;
        cout << "n = " << n << endl;

        for (int j = 0; j < t; j++) {
            int sosanh = 0, doi = 0;

            TaoMangNgauNhien(a, n);

            start = clock();
            bubbleSort(a, n, sosanh, doi);
            end = clock();
            time = ((double)(end - start)) / CLOCKS_PER_SEC;
            cout << "bubbleSort: Time = " << time << " giay, so sanh = " << sosanh << ", doi = " << doi << endl;
            sosanh = 0; doi = 0;

            TaoMangNgauNhien(a, n);
            start = clock();
            selectionSort(a, n, sosanh, doi);
            end = clock();
            time = ((double)(end - start)) / CLOCKS_PER_SEC;
            cout << "selectionSort: Time = " << time << " giay, so sanh = " << sosanh << ", doi = " << doi << endl;
            sosanh = 0; doi = 0;

            TaoMangNgauNhien(a, n);
            start = clock();
            InsertionSort(a, n, sosanh, doi);
            end = clock();
            time = ((double)(end - start)) / CLOCKS_PER_SEC;
            cout << "InsertionSort: Time = " << time << " giay, so sanh = " << sosanh << ", doi = " << doi << endl;
            sosanh = 0; doi = 0;

            TaoMangNgauNhien(a, n);
            start = clock();
            QuickSort(a, n, sosanh, doi);
            end = clock();
            time = ((double)(end - start)) / CLOCKS_PER_SEC;
            cout << "QuickSort: Time = " << time << " giay, so sanh = " << sosanh << ", doi = " << doi << endl;
            sosanh = 0; doi = 0;

            TaoMangNgauNhien(a, n);
            start = clock();
            MergeSort(a, n, sosanh, doi);
            end = clock();
            time = ((double)(end - start)) / CLOCKS_PER_SEC;
            cout << "MergeSort: Time = " << time << " giay, so sanh = " << sosanh << ", doi = " << doi << endl;
            cout << endl;
        }

        delete[] a;
    }
}

int main() {
    test1();
    return 0;
}