#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct MemoryBlock {
    int id;
    int size;
    bool allocated;
};

struct Process {
    int id;
    int size;
};

void readMemoryAllocationInput(const string& filename, vector<MemoryBlock>& blocks, vector<Process>& processes) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Khong the mo file " << filename << endl;
        exit(1);
    }

    int blockCount, processCount;
    file >> blockCount >> processCount;

    blocks.resize(blockCount);
    for (int i = 0; i < blockCount; i++) {
        blocks[i].id = i + 1;
        file >> blocks[i].size;
        blocks[i].allocated = false;
    }

    processes.resize(processCount);
    for (int i = 0; i < processCount; i++) {
        processes[i].id = i + 1;
        file >> processes[i].size;
    }
}

void writeMemoryAllocationOutput(const string& filename, const vector<Process>& processes,
    const vector<int>& allocation, const string& algorithm) {
    ofstream out(filename);
    if (!out.is_open()) {
        cerr << "Khong the tao file " << filename << endl;
        return;
    }

    out << "Ket qua dieu phoi bo nho theo " << algorithm << ":\n";
    out << "Process ID\tKich thuoc\tBlock duoc cap\n";

    for (size_t i = 0; i < processes.size(); i++) {
        out << processes[i].id << "\t\t" << processes[i].size << "\t\t";
        if (allocation[i] != -1) {
            out << allocation[i];
        }
        else {
            out << "Khong duoc cap phat";
        }
        out << "\n";
    }
}

vector<int> firstFit(const vector<MemoryBlock>& blocks, const vector<Process>& processes) {
    vector<int> allocation(processes.size(), -1);
    vector<MemoryBlock> tempBlocks = blocks;

    for (size_t i = 0; i < processes.size(); i++) {
        for (size_t j = 0; j < tempBlocks.size(); j++) {
            if (!tempBlocks[j].allocated && tempBlocks[j].size >= processes[i].size) {
                allocation[i] = tempBlocks[j].id;
                tempBlocks[j].allocated = true;
                break;
            }
        }
    }
    return allocation;
}

vector<int> bestFit(const vector<MemoryBlock>& blocks, const vector<Process>& processes) {
    vector<int> allocation(processes.size(), -1);
    vector<MemoryBlock> tempBlocks = blocks;

    for (size_t i = 0; i < processes.size(); i++) {
        int bestIdx = -1;
        for (size_t j = 0; j < tempBlocks.size(); j++) {
            if (!tempBlocks[j].allocated && tempBlocks[j].size >= processes[i].size) {
                if (bestIdx == -1 || tempBlocks[j].size < tempBlocks[bestIdx].size) {
                    bestIdx = j;
                }
            }
        }

        if (bestIdx != -1) {
            allocation[i] = tempBlocks[bestIdx].id;
            tempBlocks[bestIdx].allocated = true;
        }
    }
    return allocation;
}

void memoryAllocation() {
    vector<MemoryBlock> blocks;
    vector<Process> processes;

    readMemoryAllocationInput("input.txt", blocks, processes);

    vector<int> firstFitAllocation = firstFit(blocks, processes);
    writeMemoryAllocationOutput("firstfitoutput.txt", processes, firstFitAllocation, "First Fit");

    vector<int> bestFitAllocation = bestFit(blocks, processes);
    writeMemoryAllocationOutput("bestfitoutput.txt", processes, bestFitAllocation, "Best Fit");
}
int main() {
    memoryAllocation();


    return 0;
}