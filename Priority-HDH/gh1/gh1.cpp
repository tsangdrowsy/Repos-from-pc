#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int id;
    int burst_time;
    int arrival_time;
    int priority;
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


void Priority(vector<Process> processes) {
    int n = processes.size();
    vector<int> remaining_time(n);
    vector<int> waiting_time(n, 0);
    vector<int> turnaround_time(n, 0);
    vector<bool> completed(n, false);

    for (int i = 0; i < n; ++i)
        remaining_time[i] = processes[i].burst_time;

    int time = 0, completed_count = 0;

    while (completed_count < n) {
        int idx = -1;
        int best_priority = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (!completed[i] && processes[i].arrival_time <= time &&
                processes[i].priority < best_priority && remaining_time[i] > 0) {
                best_priority = processes[i].priority;
                idx = i;
            }
        }

        if (idx != -1) {
            remaining_time[idx]--;
            if (remaining_time[idx] == 0) {
                completed[idx] = true;
                completed_count++;
                int finish_time = time + 1;
                turnaround_time[idx] = finish_time - processes[idx].arrival_time;
                waiting_time[idx] = turnaround_time[idx] - processes[idx].burst_time;
            }
        }

        time++;
    }

    writeResults("output_priority_preemptive.txt", processes, waiting_time, turnaround_time);
}


int main() {

    vector<Process> processes = readProcesses("input.txt");


    Priority(processes);

    cout << "Ket qua da duoc ghi vao file output" << endl;

    return 0;
}