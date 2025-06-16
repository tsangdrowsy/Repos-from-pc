#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <climits>

using namespace std;

struct Process {
    int id;
    int burst_time;
    int arrival_time;
    int start_time = -1;
    int finish_time = -1;
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

void writeGanttChart(ofstream& out, const vector<pair<int, pair<int, int>>>& gantt) {
    out << "\nBieu do Gantt:\n";
    out << "+";
    for (const auto& item : gantt) {
        int duration = item.second.second - item.second.first;
        for (int i = 0; i < duration; i++) out << "--";
        out << "+";
    }

    out << "\n|";
    for (const auto& item : gantt) {
        int duration = item.second.second - item.second.first;
        int spaces = duration - 1;
        out << "P" << item.first;
        for (int i = 0; i < spaces; i++) out << "  ";
        out << "|";
    }

    out << "\n+";
    for (const auto& item : gantt) {
        int duration = item.second.second - item.second.first;
        for (int i = 0; i < duration; i++) out << "--";
        out << "+";
    }

    out << "\n";
    out << gantt[0].second.first;
    for (const auto& item : gantt) {
        out << "  " << item.second.second;
    }
    out << "\n";
}

void writeResults(const string& filename, const vector<Process>& processes,
    const vector<int>& waiting_time, const vector<int>& turnaround_time,
    float avg_waiting, float avg_turnaround, const vector<pair<int, pair<int, int>>>& gantt) {
    ofstream out(filename);

    if (!out.is_open()) {
        cerr << "Khong the tao file " << filename << endl;
        return;
    }

    out << "KET QUA DIEU PHOI CPU THEO SJF (Non-preemptive)\n";
    out << "==============================================\n\n";

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

void SJF(vector<Process>& processes) {
    if (processes.empty()) {
        cerr << "Khong co tien trinh nao de xu ly" << endl;
        return;
    }

    vector<int> waiting_time(processes.size(), 0);
    vector<int> turnaround_time(processes.size(), 0);
    vector<bool> completed(processes.size(), false);
    vector<pair<int, pair<int, int>>> gantt; 

    int time = 0;
    int completed_count = 0;

    while (completed_count < processes.size()) {
        int shortest_idx = -1;
        int shortest_burst = INT_MAX;

        for (size_t i = 0; i < processes.size(); i++) {
            if (!completed[i] && processes[i].arrival_time <= time &&
                processes[i].burst_time < shortest_burst) {
                shortest_burst = processes[i].burst_time;
                shortest_idx = i;
            }
        }

        if (shortest_idx == -1) {
            time++;
            continue;
        }

        processes[shortest_idx].start_time = time;

        time += processes[shortest_idx].burst_time;

        processes[shortest_idx].finish_time = time;

        gantt.emplace_back(processes[shortest_idx].id,
            make_pair(processes[shortest_idx].start_time,
                processes[shortest_idx].finish_time));

        waiting_time[shortest_idx] = processes[shortest_idx].start_time - processes[shortest_idx].arrival_time;
        turnaround_time[shortest_idx] = processes[shortest_idx].finish_time - processes[shortest_idx].arrival_time;

        completed[shortest_idx] = true;
        completed_count++;
    }

    float total_waiting = 0, total_turnaround = 0;
    for (size_t i = 0; i < processes.size(); i++) {
        total_waiting += waiting_time[i];
        total_turnaround += turnaround_time[i];
    }
    float avg_waiting = total_waiting / processes.size();
    float avg_turnaround = total_turnaround / processes.size();

    writeResults("output.txt", processes, waiting_time, turnaround_time, avg_waiting, avg_turnaround, gantt);
}

int main() {
    try {
        vector<Process> processes = readProcesses("input.txt");
        SJF(processes);
        cout << "Da hoan thanh. Ket qua da duoc ghi vao file output.txt" << endl;
    }
    catch (const exception& e) {
        cerr << "Co loi xay ra: " << e.what() << endl;
        return 1;
    }
    return 0;
}