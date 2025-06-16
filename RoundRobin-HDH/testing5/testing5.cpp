#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>

using namespace std;

struct Process {
    int id;
    int burst_time;
    int arrival_time;
    int remaining_time;
    int finish_time = 0;
    int start_time = -1;
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
        p.remaining_time = p.burst_time;
        processes.push_back(p);
    }

    if (processes.empty()) {
        cerr << "File rong hoac khong dung dinh dang" << endl;
        exit(1);
    }

    return processes;
}

void writeGanttChart(ofstream& out, const vector<pair<int, int>>& gantt) {
    out << "\nBieu do Gantt:\n";
    out << "+";
    for (const auto& item : gantt) {
        out << "-----+";
    }

    out << "\n|";
    for (const auto& item : gantt) {
        out << " P" << setw(2) << item.first << " |";
    }

    out << "\n+";
    for (const auto& item : gantt) {
        out << "-----+";
    }

    out << "\n";
    out << gantt[0].second;
    for (size_t i = 1; i < gantt.size(); i++) {
        out << "    " << gantt[i].second;
    }
    out << "\n";
}

void writeResults(const string& filename, const vector<Process>& processes,
    const vector<int>& waiting_time, const vector<int>& turnaround_time,
    float avg_waiting, float avg_turnaround, const vector<pair<int, int>>& gantt) {
    ofstream out(filename);

    if (!out.is_open()) {
        cerr << "Khong the tao file " << filename << endl;
        return;
    }

    out << "KET QUA DIEU PHOI CPU THEO ROUND ROBIN\n";
    out << "======================================\n\n";

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
    out << "+-----+----------+------------+---------+--------------+\n\n";

    out << fixed << setprecision(2);
    out << "Thoi gian cho trung binh: " << avg_waiting << "\n";
    out << "Thoi gian hoan thanh trung binh: " << avg_turnaround << "\n\n";

    writeGanttChart(out, gantt);
}

void RoundRobin(vector<Process> processes, int quantum) {
    int n = processes.size();
    vector<int> waiting_time(n, 0);
    vector<int> turnaround_time(n, 0);
    vector<pair<int, int>> gantt;

    queue<int> ready_queue;
    int current_time = 0;
    int completed = 0;

    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.arrival_time < b.arrival_time;
        });

    int next_process = 0;
    while (completed < n) {
        while (next_process < n && processes[next_process].arrival_time <= current_time) {
            ready_queue.push(next_process);
            next_process++;
        }

        if (ready_queue.empty()) {
            current_time++;
            continue;
        }

        int current = ready_queue.front();
        ready_queue.pop();

        if (processes[current].start_time == -1) {
            processes[current].start_time = current_time;
        }

        int execute_time = min(quantum, processes[current].remaining_time);
        processes[current].remaining_time -= execute_time;
        current_time += execute_time;

        gantt.emplace_back(processes[current].id, current_time);

        while (next_process < n && processes[next_process].arrival_time <= current_time) {
            ready_queue.push(next_process);
            next_process++;
        }

        if (processes[current].remaining_time > 0) {
            ready_queue.push(current);
        }
        else {
            processes[current].finish_time = current_time;
            turnaround_time[current] = processes[current].finish_time - processes[current].arrival_time;
            waiting_time[current] = turnaround_time[current] - processes[current].burst_time;
            completed++;
        }
    }

    float total_waiting = 0, total_turnaround = 0;
    for (int i = 0; i < n; i++) {
        total_waiting += waiting_time[i];
        total_turnaround += turnaround_time[i];
    }
    float avg_waiting = total_waiting / n;
    float avg_turnaround = total_turnaround / n;

    writeResults("output.txt", processes, waiting_time, turnaround_time, avg_waiting, avg_turnaround, gantt);
}

int main() {
    try {
        vector<Process> processes = readProcesses("input.txt");
        int quantum = 2; 
        RoundRobin(processes, quantum);
        cout << "Da hoan thanh. Ket qua da duoc ghi vao file output.txt" << endl;
    }
    catch (const exception& e) {
        cerr << "Co loi xay ra: " << e.what() << endl;
        return 1;
    }
    return 0;
}