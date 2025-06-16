#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <numeric>

using namespace std;

struct Process {
    int id;
    int burst_time;
    int arrival_time;
    int priority;
    int start_time = -1;
    int finish_time = -1;
    int remaining_time;
};

vector<Process> readProcesses(const string& filename) {
    ifstream file(filename);
    vector<Process> processes;

    if (!file.is_open()) {
        cerr << "Khong the mo file " << filename << endl;
        exit(1);
    }

    Process p;
    while (file >> p.id >> p.burst_time >> p.arrival_time >> p.priority) {
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

    out << "KET QUA DIEU PHOI CPU THEO PRIORITY (PREEMPTIVE)\n";
    out << "================================================\n\n";

    out << "Bang thong tin:\n";
    out << "+-----+----------+------------+----------+---------+--------------+\n";
    out << "| ID  | Burst    | Arrival    | Priority | Waiting | Turnaround   |\n";
    out << "+-----+----------+------------+----------+---------+--------------+\n";

    for (size_t i = 0; i < processes.size(); i++) {
        out << "| " << setw(3) << processes[i].id << " "
            << "| " << setw(8) << processes[i].burst_time << " "
            << "| " << setw(10) << processes[i].arrival_time << " "
            << "| " << setw(8) << processes[i].priority << " "
            << "| " << setw(7) << waiting_time[i] << " "
            << "| " << setw(12) << turnaround_time[i] << " |\n";
    }
    out << "+-----+----------+------------+----------+---------+--------------+\n\n";

    out << fixed << setprecision(2);
    out << "Thoi gian cho trung binh: " << avg_waiting << "\n";
    out << "Thoi gian hoan thanh trung binh: " << avg_turnaround << "\n\n";

    writeGanttChart(out, gantt);
}

void PriorityScheduling(vector<Process> processes) {
    int n = processes.size();
    vector<int> waiting_time(n, 0);
    vector<int> turnaround_time(n, 0);
    vector<bool> completed(n, false);
    vector<pair<int, int>> gantt; 

    int current_time = 0;
    int completed_count = 0;
    int last_process = -1;

    while (completed_count < n) {
        int highest_priority = INT_MAX;
        int selected = -1;

        
        for (int i = 0; i < n; i++) {
            if (!completed[i] && processes[i].arrival_time <= current_time &&
                processes[i].priority < highest_priority && processes[i].remaining_time > 0) {
                highest_priority = processes[i].priority;
                selected = i;
            }
        }

        if (selected == -1) {
            current_time++;
            continue;
        }

        
        if (processes[selected].start_time == -1) {
            processes[selected].start_time = current_time;
        }

       
        processes[selected].remaining_time--;
        current_time++;

       
        if (last_process != selected) {
            gantt.emplace_back(processes[selected].id, current_time);
            last_process = selected;
        }
        else {
            gantt.back().second = current_time;
        }

        
        if (processes[selected].remaining_time == 0) {
            processes[selected].finish_time = current_time;
            turnaround_time[selected] = processes[selected].finish_time - processes[selected].arrival_time;
            waiting_time[selected] = turnaround_time[selected] - processes[selected].burst_time;
            completed[selected] = true;
            completed_count++;
        }
    }

    
    float total_waiting = accumulate(waiting_time.begin(), waiting_time.end(), 0);
    float total_turnaround = accumulate(turnaround_time.begin(), turnaround_time.end(), 0);
    float avg_waiting = total_waiting / n;
    float avg_turnaround = total_turnaround / n;

   
    writeResults("output_priority_preemptive.txt", processes, waiting_time,
        turnaround_time, avg_waiting, avg_turnaround, gantt);
}

int main() {
    try {
        vector<Process> processes = readProcesses("input_priority.txt");
        PriorityScheduling(processes);
        cout << "Da hoan thanh. Ket qua da duoc ghi vao file output_priority_preemptive.txt" << endl;
    }
    catch (const exception& e) {
        cerr << "Co loi xay ra: " << e.what() << endl;
        return 1;
    }
    return 0;
}