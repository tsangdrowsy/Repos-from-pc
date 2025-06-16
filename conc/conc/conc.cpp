#include <iostream>
#include <fstream>
using namespace std;

const int MAX_PROCESS = 10;
const int MAX_RESOURCE = 10;

int main() {
    int n, m;
    int available[MAX_RESOURCE];
    int max[MAX_PROCESS][MAX_RESOURCE];
    int allocation[MAX_PROCESS][MAX_RESOURCE];
    int need[MAX_PROCESS][MAX_RESOURCE];
    bool finish[MAX_PROCESS] = { false };
    int safeSequence[MAX_PROCESS];
    int work[MAX_RESOURCE];
    int workHistory[MAX_PROCESS + 1][MAX_RESOURCE]; // Lưu lịch sử work

    // Mở file input
    ifstream inputFile("TextFile2.txt");
    if (!inputFile) {
        cerr << "Khong the mo file input.txt" << endl;
        return 1;
    }

    // Mở file output
    ofstream outputFile("output.txt");
    if (!outputFile) {
        cerr << "Khong the tao file output.txt" << endl;
        return 1;
    }

    // Đọc dữ liệu từ file
    inputFile >> n >> m;

    // Đọc available
    for (int i = 0; i < m; i++) {
        inputFile >> available[i];
        work[i] = available[i]; // Khởi tạo work = available
        workHistory[0][i] = work[i]; // Lưu work ban đầu
    }

    // Đọc ma trận max
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            inputFile >> max[i][j];
        }
    }

    // Đọc ma trận allocation
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            inputFile >> allocation[i][j];
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    inputFile.close();

    // Thuật toán Banker
    int count = 0;
    while (count < n) {
        bool found = false;

        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                bool canAllocate = true;

                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }

                if (canAllocate) {
                    // Cập nhật work
                    for (int j = 0; j < m; j++) {
                        work[j] += allocation[i][j];
                    }

                    // Lưu work vào lịch sử
                    for (int j = 0; j < m; j++) {
                        workHistory[count + 1][j] = work[j];
                    }

                    safeSequence[count] = i;
                    finish[i] = true;
                    count++;
                    found = true;
                }
            }
        }

        if (!found) {
            break; // Deadlock
        }
    }

    // Ghi kết quả ra file output
    if (count == n) {
        outputFile << "He thong an toan. Thu tu an toan: ";
        for (int i = 0; i < n; i++) {
            outputFile << "P" << safeSequence[i];
            if (i != n - 1) outputFile << " -> ";
        }
        outputFile << endl << endl;

        // In bảng work
        outputFile << "Bang Work sau moi buoc:" << endl;
        outputFile << "Buoc\tWork" << endl;
        for (int i = 0; i <= n; i++) {
            outputFile << i << "\t";
            for (int j = 0; j < m; j++) {
                outputFile << workHistory[i][j] << " ";
            }
            outputFile << endl;
        }
    }
    else {
        outputFile << "He thong khong an toan (co the xay ra deadlock)" << endl;
    }
    inputFile.close();
    outputFile.close();


    return 0;
}