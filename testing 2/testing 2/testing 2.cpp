#include<iostream>

using namespace std;
int main()
{
    int tienmuon = 0;
    float laixuat = 5 / 100, phaitra = 0, b = 0;

   
    cout << "Số tiền bạn muốn vay" << endl;
    cin >> tienmuon;
    b = (tienmuon * laixuat);
    cout << "Lãi suất thành tiền mỗi tháng" << endl;

    phaitra = (b * 24) + tienmuon;
    cout << "số tiền pải trả sau 2 năm trheo hợp đồng",phaitra;

    return 0;
}
