#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int id;
    int burst_time;
    int arrival_time;
};


vector<Process> readProcesses(const string& filename) {
    ifstream file(filename);
    vector<Process> processes;

    if (!file.is_open()) {
        cout << "Khong the mo file " << filename << endl;
        exit(1);
    }

    Process p;
    while (file >> p.id >> p.burst_time >> p.arrival_time) {
        processes.push_back(p);
    }

    return processes;
}


void writeResults(const string& filename, const vector<Process>& processes,
    const vector<int>& waiting_time, const vector<int>& turnaround_time) {
    ofstream out(filename);

    if (!out.is_open()) {
        cout << "Khong the tao file " << filename << endl;
        return;
    }

    out << "Ket qua dieu phoi FCFS:\n";
    out << "ID\tBurst\tArrival\tWaiting\tTurnaround\n";

    for (size_t i = 0; i < processes.size(); i++) {
        out << processes[i].id << "\t"
            << processes[i].burst_time << "\t"
            << processes[i].arrival_time << "\t"
            << waiting_time[i] << "\t"
            << turnaround_time[i] << "\n";
    }
}


void RoundR(vector<Process> processes, int chuky) {
    int n = processes.size();
    vector<int> remaining_time(n);
    vector<int> waiting_time(n, 0);
    vector<int> turnaround_time(n, 0);
    for (int i = 0; i < n; i++) remaining_time[i] = processes[i].burst_time;

    int time = 0;
    bool done;

    do {
        done = true;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0 && processes[i].arrival_time <= time) {
                done = false;
                if (remaining_time[i] > chuky) {
                    time += chuky;
                    remaining_time[i] -= chuky;
                }
                else {
                    time += remaining_time[i];
                    waiting_time[i] = time - processes[i].burst_time - processes[i].arrival_time;
                    remaining_time[i] = 0;
                }
            }
            else if (processes[i].arrival_time > time) {
                time++; 
            }
        }
    } while (!done);

    for (int i = 0; i < n; i++) {
        turnaround_time[i] = processes[i].burst_time + waiting_time[i];
    }

    writeResults("output_rr.txt", processes, waiting_time, turnaround_time);
}

int main() {

    vector<Process> processes = readProcesses("Input.txt");
    RoundR(processes, 10);

    cout << "Ket qua da duoc ghi vao file output" << endl;

    return 0;
}