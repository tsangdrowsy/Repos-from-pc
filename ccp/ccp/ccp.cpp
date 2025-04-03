#include <iostream>
#include <math.h>
using namespace std;

void NhapMang(int a[], int n)
{

	for (int i = 1; i < n; i++) {
		cout << "Nhap phan tu thu " << i + 1 << ":";

		cin >> a[i];
	}
}
void GTLN(int a[], int n, int& max)
{
	max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
}
int tongso(int n) {
	int x = 0;
	while (n != 0)
	{
		x = x + n / 10;
		n = n / 10;
	}
	return x;
}
int g(int a[], int n) {
	int s = 0;
	for (int i = 0; i < n; i++) {
		s = s + tongso(a[i]);
	}
	return s;
}
void SapXepMang(int a[], int n) //Hàm sắp xếp mảng (Bubble Sort)
	{
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < n - i - 1; j++)
			{
				if (a[j] > a[j + 1])
				{
					int tamthoi = a[j];
					a[j] = a[j + 1];
					a[j + 1] = tamthoi;

				}
			}
		}
	}
int main()
{
	int n;
	cout << "Nhap so phan tu trong mang: " << endl;
	cin >> n;
	int a[100];
	NhapMang(a, n);
	int max;
	GTLN(a, n, max);
	cout << "Gia tri lon nhat la: " << max << endl;

	SapXepMang(a, n);
	cout << "Mang sau khi sap xep tang la: ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " " << endl;
	}
	cout << "Tong la: " << g;
	return 0;
}
