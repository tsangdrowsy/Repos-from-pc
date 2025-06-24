#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <unordered_map>
#include <iomanip>

using namespace std;

void readPageReplacementInput(const string& filename, vector<int>& pages, int& frameCount) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Khong the mo file " << filename << endl;
        exit(1);
    }

    int pageCount;
    file >> frameCount >> pageCount;

    pages.resize(pageCount);
    for (int i = 0; i < pageCount; i++) {
        file >> pages[i];
    }
}

void writePageReplacementOutput(const string& filename, const vector<int>& pageFaults,
    const string& algorithm, int frameCount, const vector<vector<int>>& framesState) {
    ofstream out(filename);
    if (!out.is_open()) {
        cerr << "Khong the tao file " << filename << endl;
        return;
    }

    out << "Ket qua thay the trang theo " << algorithm << " (Frame: " << frameCount << "):\n";
    out << "Tong so page fault: " << pageFaults.size() << "\n";
    out << "Cac vi tri xay ra page fault: ";

    for (size_t i = 0; i < pageFaults.size(); i++) {
        out << pageFaults[i];
        if (i != pageFaults.size() - 1) {
            out << ", ";
        }
    }
    out << "\n\nBang thay the trang:\n";

    out << "Buoc\t";
    for (int i = 0; i < frameCount; i++) {
        out << "Frame " << i << "\t";
    }
    out << "Page Fault\n";

    for (size_t i = 0; i < framesState.size(); i++) {
        out << i + 1 << "\t";
        for (int j = 0; j < frameCount; j++) {
            if (j < framesState[i].size()) {
                out << framesState[i][j] << "\t";
            }
            else {
                out << "-\t";
            }
        }
        bool isFault = find(pageFaults.begin(), pageFaults.end(), i) != pageFaults.end();
        out << (isFault ? "x" : "") << "\n";
    }
}

vector<int> fifoPageReplacement(const vector<int>& pages, int frameCount, vector<vector<int>>& framesState) {
    unordered_set<int> frames;
    queue<int> indexes;
    vector<int> pageFaults;

    for (size_t i = 0; i < pages.size(); i++) {
        vector<int> currentState;
        if (frames.size() < frameCount) {
            if (frames.find(pages[i]) == frames.end()) {
                frames.insert(pages[i]);
                indexes.push(pages[i]);
                pageFaults.push_back(i);
            }
        }
        else {
            if (frames.find(pages[i]) == frames.end()) {
                int val = indexes.front();
                indexes.pop();
                frames.erase(val);
                frames.insert(pages[i]);
                indexes.push(pages[i]);
                pageFaults.push_back(i);
            }
        }

        queue<int> temp = indexes;
        while (!temp.empty()) {
            currentState.push_back(temp.front());
            temp.pop();
        }
        framesState.push_back(currentState);
    }
    return pageFaults;
}

vector<int> lruPageReplacement(const vector<int>& pages, int frameCount, vector<vector<int>>& framesState) {
    unordered_set<int> frames;
    unordered_map<int, int> indexes;
    vector<int> pageFaults;
    int time = 0;

    for (size_t i = 0; i < pages.size(); i++) {
        vector<int> currentState;
        if (frames.size() < frameCount) {
            if (frames.find(pages[i]) == frames.end()) {
                frames.insert(pages[i]);
                pageFaults.push_back(i);
            }
            indexes[pages[i]] = time++;
        }
        else {
            if (frames.find(pages[i]) == frames.end()) {
                int lru = INT_MAX, val;
                for (auto it = frames.begin(); it != frames.end(); it++) {
                    if (indexes[*it] < lru) {
                        lru = indexes[*it];
                        val = *it;
                    }
                }
                frames.erase(val);
                frames.insert(pages[i]);
                pageFaults.push_back(i);
            }
            indexes[pages[i]] = time++;
        }

        vector<pair<int, int>> sortedFrames;
        for (auto page : frames) {
            sortedFrames.push_back({ indexes[page], page });
        }
        sort(sortedFrames.begin(), sortedFrames.end());

        for (auto& p : sortedFrames) {
            currentState.push_back(p.second);
        }
        framesState.push_back(currentState);
    }
    return pageFaults;
}

void pageReplacement() {
    vector<int> pages;
    int frameCount;

    readPageReplacementInput("input.txt", pages, frameCount);

    vector<vector<int>> fifoFramesState;
    vector<int> fifoFaults = fifoPageReplacement(pages, frameCount, fifoFramesState);
    writePageReplacementOutput("fifo_output.txt", fifoFaults, "FIFO", frameCount, fifoFramesState);

    vector<vector<int>> lruFramesState;
    vector<int> lruFaults = lruPageReplacement(pages, frameCount, lruFramesState);
    writePageReplacementOutput("lru_output.txt", lruFaults, "LRU", frameCount, lruFramesState);
}

int main() {
    pageReplacement();
    cout << "Da hoan thanh viec thay the trang." << endl;
    return 0;
}
