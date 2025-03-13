#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
float delta(float a, float b, float c)
{
	float delta = (pow(b, 2) - 4 * a * c);
		return delta;
}
int main()
{
	float a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;
	cout << fixed << setprecision(2);
	if (a == 0 && b !=0&& c!= 0) {
		float kq4 = ((-c) / b);
		cout << "Phuong trinh co 1 nghiem la: "<<kq4;
	}
	if (a == 0&& b == 0&& c == 0) {
		cout << "Phuong trinh vo so nghiem: ";
	}
	if (delta(a, b, c) < 0 && a != 0) {
		cout << "Phuong trinh vo nghiem";
	}
	if (delta(a, b, c) == 0 && a != 0)
	{
		float kq = (-b / (2 * a));
		if (kq > 0) {

			cout << "Phuong trinh co 2 nghiem: " << sqrt(kq) << "," << (-sqrt(kq));
		}
		if (kq < 0) {
			cout << "Phuong trinh vo nghiem";
		}


	}
	if (delta(a, b, c) > 0 && a != 0)
	{
		float max1 = 0, max2 = 0, max3 = 0, max4 = 0;
		float
			kq1 = ((- b + sqrt(delta(a, b, c))) / (2 * a));
		float
			kq2 = (-b - sqrt(delta(a, b, c)) / (2 * a));
		if (sqrt(kq1) > sqrt(kq2))
		{
			max1 = sqrt(kq1);
			max2 = sqrt(kq2);
		}
		else if (sqrt(kq2) > sqrt(kq1)){

			max1 = sqrt(kq2);
			max2 = sqrt(kq1);
		}
		if ((- sqrt(kq1)) > (- sqrt(kq2)))
		{
			max3 = (-sqrt(kq1));
			max4 = (- sqrt(kq2));
		}
		else if ((-sqrt(kq2)) > (-sqrt(kq1)))
		{
			max3 = (-sqrt(kq2));
			max4 = (-sqrt(kq1));
		}
		cout<<"Phuong trinh co 4 nghiem: " << max1 << "," << max2 << "," << max3 << "," << max4;
	}
	return 0;
}
