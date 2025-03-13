#include<iostream>
#include<stdio.h>
#include<ctime>
#include<cstdio>
using namespace std;

void TaoMangNgauNhien(int a[], int n)// T?o m?ng ng?u nhiên
{
	for (int i = 0; i < n; i++)
		a[i] = rand() % 10000;
}
void InMang(int a[], int n)// In m?ng
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void swap(int*a, int* b) //interchange sort
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int a[], int n)// bubble sort
{
	for (int i = n - 1; i >= 1; i--) {
		for (int j = 0; j < i ; j++) {
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
		}
	}
}
void selectionSort(int a[], int n)// selection sort
{
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min])
				min = j;
		}
		swap(a[i], a[min]);
	}
}
void InsertionSort(int a[], int n)//Insertion Sort
{
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		int x = a[i];
		bool cont = true;
		while ((j >= 0) && cont)
			if (a[j] > x)
			{
				a[j + 1] = a[j];
				j--;
			}
			else
				cont = false;
		a[j + 1] = x;
	}
}

void Partition(int a[], int p, int q) {
	int x = a[(p + q) / 2];
	int i = p;
	int j = q;
	do {
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i <= j);  
	if (p < j)
		Partition(a, p, j);
	if (i < q)
		Partition(a, i, q);
}
void QuickSort(int a[], int n)
{
	Partition(a, 0, n - 1);
}
void Merge(int a[], int temp[], int p, int t, int q)
{
	int i = p;
	int k = t - 1;
	int dem = 0;
	while ((p <= k) && (t <= q))
	{
		if (a[p] < a[t])
		{
			temp[dem] = a[p];
			p++;
		}
		else
		{
			temp[dem] = a[t];
			t++;
		}
		dem++;
	}
	while (p <= k)
	{
		temp[dem] = a[p];
		dem++;
		p++;
	}
	while (t <= q)
	{
		temp[dem] = a[t];
		dem++;
		t++;
	}
	for (int j = 0; j < dem; j++)
		a[i + j] = temp[j];
}
void RecMergeSort(int a[], int temp[], int p, int q)
{
	if (p < q)
	{
		int k = (p + q) / 2;
		RecMergeSort(a, temp, p, k);
		RecMergeSort(a, temp, k + 1, q);
		Merge(a, temp, p, k + 1, q);
	}
}

void MergeSort(int a[], int n) {
	int* temp = new int[n];
	RecMergeSort(a, temp, 0, n - 1);
	delete[] temp; 
}

void test1() {
	srand(time(NULL));
	int z[] = { 10, 100, 200, 500, 1000, 2000, 5000, 10000 };
	int t = 5; // s? l?n ch?y là 5
	for (int i = 0; i < sizeof(z) / sizeof(z[0]); i++) {
		int n = z[i];
		int* a = new int[n];
		clock_t start, end;
		double cpu_time_used;
		cout << "n = " << n << endl;

		for (int j = 0; j < t; j++) {
			TaoMangNgauNhien(a, n); // t?o m?ng ng?u nhiên

			start = clock();
			bubbleSort(a, n); // bubble sort
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC; // th?i gian ch?y
			cout << "bubbleSort: " << cpu_time_used << " seconds" << endl;

			TaoMangNgauNhien(a, n);
			start = clock();
			selectionSort(a, n); // selection sort
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC; // th?i gian ch?y
			cout << "selectionSort: " << cpu_time_used << " seconds" << endl;

			TaoMangNgauNhien(a, n);
			start = clock();
			InsertionSort(a, n); // Insertion Sort
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC; // th?i gian ch?y
			cout << "InsertionSort: " << cpu_time_used << " seconds" << endl;

			TaoMangNgauNhien(a, n);
			start = clock();
			QuickSort(a, n); // Quick Sort
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC; // th?i gian ch?y
			cout << "QuickSort: " << cpu_time_used << " seconds" << endl;

			TaoMangNgauNhien(a, n);
			start = clock();
			MergeSort(a, n); // Merge Sort
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC; // th?i gian ch?y
			cout << "MergeSort: " << cpu_time_used << " seconds" << endl;

			cout << endl;
		}

		delete[] a; 
	}
}

int main()
{
	test1();
	return 0;
}
