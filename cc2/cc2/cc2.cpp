#include <iostream>
#include<iomanip>
#include<math.h>

using namespace std;
int main()
{
	float a = 0.00;
	float b = 0.00;
	float c = 0.00;
	cin >> a;
	cin >> b;
	cin >> c;
	int delta = pow(b, 2) - 4 * a * c;
	cout << fixed << setprecision(2);
	if (a == 0 && b != 0 && c != 0) {
		float kq = -c / b;
		cout << "Phuong tirnh co 1 nghiem la: " << kq;
	}
	if (a == 0 && b == 0 && c == 0) {
		cout << "Phuong trinh vo so nghiem";
	}
	if (delta < 0 && a != 0) {
		cout << "Phuong trinh vo nghiem";
	}
	if (delta == 0 && a != 0) {

		float kq1 = 0.00;
		kq1 = -b / 2 * a;
		cout << "Phuong trinh co nghiem duy nhat: " << kq1;
	}
	if (delta > 0 && a != 0)
	{
		float kq2 = 0.00;
		kq2 = (-b + sqrt(delta)) / 2 * a;
		float kq3 = 0.00;
		kq3 = (-b - sqrt(delta)) / 2 * a;
		int max1 = 0,max2=0;
			if (kq2 > kq3) {
				max1 = kq2;
				max2 = kq3;
			}
			else {
				max1 = kq3;
				max2 = kq2;
			}
		cout << "Phuong trinh co 2 nghiem la:" << max2 << "," << max1;
	}
	return 0;
}