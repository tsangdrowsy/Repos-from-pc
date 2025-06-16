#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Process {
    int id;
    int burst_time;
    int arrival_time;
    int start_time;
    int finish_time;
};

vector<Process> readProcesses(const string& filename) {
    ifstream file(filename);
    vector<Process> processes;

    if (!file.is_open()) {
        cerr << "Khong the mo file " << filename << endl;
        exit(1);
    }

    Process p;
    while (file >> p.id >> p.burst_time >> p.arrival_time) {
        processes.push_back(p);
    }

    if (processes.empty()) {
        cerr << "File rong hoac khong dung dinh dang" << endl;
        exit(1);
    }

    return processes;
}

void writeGanttChart(ofstream& out, const vector<Process>& processes) {
    out << "\nBieu do Gantt:\n";
    out << "+";
    for (const auto& p : processes) {
        for (int i = 0; i < p.burst_time; i++) out << "--";
        out << "+";
    }

    out << "\n|";
    for (const auto& p : processes) {
        int spaces = p.burst_time - 1;
        out << "P" << p.id;
        for (int i = 0; i < spaces; i++) out << "  ";
        out << "|";
    }

    out << "\n+";
    for (const auto& p : processes) {
        for (int i = 0; i < p.burst_time; i++) out << "--";
        out << "+";
    }

    out << "\n";
    out << processes[0].start_time;
    for (const auto& p : processes) {
        out << "  " << p.finish_time;
    }
    out << "\n";
}

void writeResults(const string& filename, const vector<Process>& processes,
    const vector<int>& waiting_time, const vector<int>& turnaround_time,
    float avg_waiting, float avg_turnaround) {
    ofstream out(filename);

    if (!out.is_open()) {
        cerr << "Khong the tao file " << filename << endl;
        return;
    }

    out << "KET QUA DIEU PHOI CPU THEO FCFS\n";
    out << "================================\n\n";

    out << "Bang thong tin:\n";
    out << "+-----+----------+------------+---------+--------------+\n";
    out << "| ID  | Burst    | Arrival    | Waiting | Turnaround   |\n";
    out << "+-----+----------+------------+---------+--------------+\n";

    for (size_t i = 0; i < processes.size(); i++) {
        out << "| " << setw(3) << processes[i].id << " "
            << "| " << setw(8) << processes[i].burst_time << " "
            << "| " << setw(10) << processes[i].arrival_time << " "
            << "| " << setw(7) << waiting_time[i] << " "
            << "| " << setw(12) << turnaround_time[i] << " |\n";
    }
    

    
    out << fixed << setprecision(2);
    out << "Thoi gian cho trung binh: " << avg_waiting << "\n";
    out << "Thoi gian hoan thanh trung binh: " << avg_turnaround << "\n\n";

   
    writeGanttChart(out, processes);

    
}

void FCFS(vector<Process>& processes) {
    if (processes.empty()) {
        cerr << "Khong co tien trinh nao de xu ly" << endl;
        return;
    }

    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.arrival_time < b.arrival_time;
        });

    vector<int> waiting_time(processes.size());
    vector<int> turnaround_time(processes.size());
    float total_waiting = 0, total_turnaround = 0;

    
    processes[0].start_time = processes[0].arrival_time;
    processes[0].finish_time = processes[0].start_time + processes[0].burst_time;
    waiting_time[0] = 0;
    turnaround_time[0] = processes[0].burst_time;

    
    for (size_t i = 1; i < processes.size(); i++) {
        processes[i].start_time = max(processes[i - 1].finish_time, processes[i].arrival_time);
        processes[i].finish_time = processes[i].start_time + processes[i].burst_time;

        waiting_time[i] = processes[i].start_time - processes[i].arrival_time;
        turnaround_time[i] = processes[i].finish_time - processes[i].arrival_time;
    }

   
    for (size_t i = 0; i < processes.size(); i++) {
        total_waiting += waiting_time[i];
        total_turnaround += turnaround_time[i];
    }
    float avg_waiting = total_waiting / processes.size();
    float avg_turnaround = total_turnaround / processes.size();

    
    writeResults("output.txt", processes, waiting_time, turnaround_time, avg_waiting, avg_turnaround);
}

int main() {
    try {
        vector<Process> processes = readProcesses("input.txt");
        FCFS(processes);
        cout << "Da hoan thanh. Ket qua da duoc ghi vao file output.txt" << endl;
    }
    catch (const exception& e) {
        cerr << "Co loi xay ra: " << e.what() << endl;
        return 1;
    }
    return 0;
}