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
	if (a == 0& b == 0&c == 0) {
		cout << "Phuong trinh vo so nghiem";
	}
	if (delta < 0&a != 0) {
		cout << "Phuong trinh vo nghiem";
	}
	if (delta == 0&a!=0) {

		float kq1 = 0.00;
			kq1= -b / 2 * a;
		cout << "Phuong trinh co nghiem duy nhat: " << kq1;
	}
	if (delta > 0& a != 0)
	{
		float kq2 = 0.00;
			kq2 = (-b + sqrt(delta)) / 2 * a;
			float kq3 = 0.00;
			kq3= (-b - sqrt(delta)) / 2 * a;
		cout << "Phuong trinh co 2 nghiem la:" << kq2 << "," << kq3;
	}
	return 0;
}
