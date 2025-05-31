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


void FCFS(vector<Process>& processes) {
    
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.arrival_time < b.arrival_time;
        });

    vector<int> waiting_time(processes.size());
    vector<int> turnaround_time(processes.size());

   
    waiting_time[0] = 0;
    for (size_t i = 1; i < processes.size(); i++) {
        waiting_time[i] = max(0, processes[i - 1].burst_time + waiting_time[i - 1]
            - (processes[i].arrival_time - processes[i - 1].arrival_time));
    }

  
    for (size_t i = 0; i < processes.size(); i++) {
        turnaround_time[i] = processes[i].burst_time + waiting_time[i];
    }

    writeResults("output.txt", processes, waiting_time, turnaround_time);
}

int main() {
   
    vector<Process> processes = readProcesses("input.txt");

  
    FCFS(processes);

    cout << "Da hoan thanh. Ket qua da duoc ghi vao file output" << endl;

    return 0;
}