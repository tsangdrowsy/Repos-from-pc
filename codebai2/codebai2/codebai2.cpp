#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Định nghĩa cấu trúc lưu trữ một số hạng của dãy thức
struct Term {
    double a; // Hệ số
    int t;       // Bậc (0 <= exponent <= 100)
};

// Hàm so sánh để sắp xếp theo bậc tăng dần
bool compareTerms(const Term& a, const Term& b) {
    return a.t < b.t;
}

void test1()
{
    int n;
    cout << "Nhập số lượng số hạng của dãy: ";
    cin >> n;

    vector<Term> lienket(n);

    // Nhập các số hạng
    cout << "Nhập các số hạng (hệ số và bậc):\n";
    for (int i = 0; i < n; i++) {
        cout << "Số hạng " << i + 1 << " (hệ số, bậc): ";
        cin >> lienket[i].a >> lienket[i].t;
        if (lienket[i].t < 0 or lienket[i].t > 100) {
            cout << "Bậc phải nằm trong khoảng từ 0 đến 100. Nhập lại!\n";
            i--; // Yêu cầu nhập lại nếu bậc không hợp lệ
        }
    }

    // Sắp xếp dãy theo thứ tự tăng dần của bậc
    sort(lienket.begin(), lienket.end(), compareTerms);

    // Xuất kết quả sau khi sắp xếp
    cout << "\nDãy thức sau khi sắp xếp:\n";
    for (const auto& term : lienket) {
        cout << term.a << "x^" << term.t << " ";
    }
    cout << endl;

}
int main() {
    test1();
    return 0;
}