#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
using namespace std;
void DocMangTuFile(const string& TextFile1, int a[], int n) {
    ifstream file(TextFile1);
    for (int i = 0; i < n; i++) {
        file >> a[i];
    }
    file.close();
}
void GhiMangVaoFile(const string& TextFile1, int a[], int n) {
    ofstream file(TextFile1);
    for (int i = 0; i < n; i++) {
        file << a[i] << " ";
    }
    file.close();
}
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
void interchangeSort(int a[], int n, int& sosanh, int& doi) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            sosanh++;
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
                doi++;
            }
        }
    }
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
void taoheap(int a[], int n, int i, int& sosanh, int& doi) {
    int lonnhat = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n) {
        sosanh++;
        if (a[l] > a[lonnhat])
            lonnhat = l;
    }

    if (r < n) {
        sosanh++;
        if (a[r] > a[lonnhat])
            lonnhat = r;
    }

    if (lonnhat != i) {
        swap(a[i], a[lonnhat]);
        doi++;
        taoheap(a, n, lonnhat, sosanh, doi);
    }
}

void heapSort(int a[], int n, int& sosanh, int& doi) {
    for (int i = n / 2 - 1; i >= 0; i--)
        taoheap(a, n, i, sosanh, doi);

    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        doi++;
        taoheap(a, i, 0, sosanh, doi);
    }
}

void test1() {
    srand(time(NULL));
    const int n = 30000;
    int* a = new int[n];
    int* temp = new int[n]; // Mảng tạm để sao chép dữ liệu
    clock_t start, end;
    double time;
    int sosanh = 0, doi = 0;

    // Tạo mảng ngẫu nhiên và lưu vào file
    TaoMangNgauNhien(a, n);
    GhiMangVaoFile("TextFile1.txt", a, n);

    
    DocMangTuFile("TextFile1.txt", a, n);

    // Interchange Sort
    start = clock();
    interchangeSort(a, n, sosanh, doi);
    end = clock();
    time = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "Interchange Sort: Time = " << time << " giay, so sanh = " << sosanh << ", doi = " << doi << endl;
    GhiMangVaoFile("TextFile2", a, n);
    sosanh = 0; doi = 0;

    
    DocMangTuFile("TextFile1.txt", a, n);

    // Selection Sort
    start = clock();
    selectionSort(a, n, sosanh, doi);
    end = clock();
    time = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "Selection Sort: Time = " << time << " giay, so sanh = " << sosanh << ", doi = " << doi << endl;
    GhiMangVaoFile("TextFile2", a, n);
    sosanh = 0; doi = 0;

    
    DocMangTuFile("TextFile1.txt", a, n);

    // Insertion Sort
    start = clock();
    InsertionSort(a, n, sosanh, doi);
    end = clock();
    time = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "Insertion Sort: Time = " << time << " giay, so sanh = " << sosanh << ", doi = " << doi << endl;
    GhiMangVaoFile("TextFile2", a, n);
    sosanh = 0; doi = 0;

    
    DocMangTuFile("TextFile1.txt", a, n);

    // Bubble Sort
    start = clock();
    bubbleSort(a, n, sosanh, doi);
    end = clock();
    time = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "Bubble Sort: Time = " << time << " giay, so sanh = " << sosanh << ", doi = " << doi << endl;
    GhiMangVaoFile("TextFile2", a, n);
    sosanh = 0; doi = 0;

    
    DocMangTuFile("TextFile1.txt", a, n);

    // Quick Sort
    start = clock();
    QuickSort(a, n, sosanh, doi);
    end = clock();
    time = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "Quick Sort: Time = " << time << " giay, so sanh = " << sosanh << ", doi = " << doi << endl;
    GhiMangVaoFile("TextFile2", a, n);
    sosanh = 0; doi = 0;

    // Đọc lại dữ liệu từ file
    DocMangTuFile("input.txt", a, n);

    // Merge Sort
    start = clock();
    MergeSort(a, n, sosanh, doi);
    end = clock();
    time = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "Merge Sort: Time = " << time << " giay, so sanh = " << sosanh << ", doi = " << doi << endl;
    GhiMangVaoFile("TextFile2", a, n);
    sosanh = 0; doi = 0;

    // Đọc lại dữ liệu từ file
    DocMangTuFile("TextFile1.txt", a, n);

    // Heap Sort
    start = clock();
    heapSort(a, n, sosanh, doi);
    end = clock();
    time = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "Heap Sort: Time = " << time << " giay, so sanh = " << sosanh << ", doi = " << doi << endl;
    GhiMangVaoFile("TextFile2", a, n);

    delete[] a;
    delete[] temp;
}
int main()
{
    test1();
    return 0;
}