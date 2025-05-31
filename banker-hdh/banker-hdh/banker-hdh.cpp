#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int P, R;
vector<int> available;
vector<vector<int>> max_matrix, allocation, need;

void docFile(const string& filename) {
    ifstream in(filename);
    if (!in.is_open()) {
        cout << "Khong the mo file input.\n";
        exit(1);
    }

    in >> P >> R;

    available.resize(R);
    for (int i = 0; i < R; ++i)
        in >> available[i];

    max_matrix.resize(P, vector<int>(R));
    for (int i = 0; i < P; ++i)
        for (int j = 0; j < R; ++j)
            in >> max_matrix[i][j];

    allocation.resize(P, vector<int>(R));
    for (int i = 0; i < P; ++i)
        for (int j = 0; j < R; ++j)
            in >> allocation[i][j];

    need.resize(P, vector<int>(R));
    for (int i = 0; i < P; ++i)
        for (int j = 0; j < R; ++j)
            need[i][j] = max_matrix[i][j] - allocation[i][j];
}

void writeResult(const string& filename, const vector<int>& chuoiantoan, bool antoan) {
    ofstream out(filename);
    if (!out.is_open()) {
        cout << "Khong the tao file output.\n";
        return;
    }

    if (antoan) {
        out << "He thong AN TOAN.\nTrinh tu an toan: ";
        for (int p : chuoiantoan)
            out << "P" << p << " ";
        out << "\n";
    }
    else {
        out << "He thong KHONG AN TOAN.\n";
    }
}

bool isSafe(vector<int>& chuoiantoan) {
    vector<int> work = available;
    vector<bool> finish(P, false);
    chuoiantoan.clear();

    int count = 0;
    while (count < P) {
        bool found = false;
        for (int i = 0; i < P; ++i) {
            if (!finish[i]) {
                bool can_allocate = true;
                for (int j = 0; j < R; ++j) {
                    if (need[i][j] > work[j]) {
                        can_allocate = false;
                        break;
                    }
                }
                if (can_allocate) {
                    for (int j = 0; j < R; ++j)
                        work[j] += allocation[i][j];
                    chuoiantoan.push_back(i);
                    finish[i] = true;
                    count++;
                    found = true;
                }
            }
        }
        if (!found)
            return false;
    }
    return true;
}

int main() {
    docFile("input.txt");

    vector<int> chuoiantoan;
    bool antoan = isSafe(chuoiantoan);

    writeResult("output.txt", chuoiantoan, antoan);

    cout << "Ket qua da ghi vao output\n";
    return 0;
}
