#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <unordered_map>

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
    const string& algorithm, int frameCount) {
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
    out << "\n";
}

vector<int> fifoPageReplacement(const vector<int>& pages, int frameCount) {
    unordered_set<int> frames;
    queue<int> indexes;
    vector<int> pageFaults;

    for (size_t i = 0; i < pages.size(); i++) {
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
    }
    return pageFaults;
}

vector<int> lruPageReplacement(const vector<int>& pages, int frameCount) {
    unordered_set<int> frames;
    unordered_map<int, int> indexes;
    vector<int> pageFaults;
    int time = 0;

    for (size_t i = 0; i < pages.size(); i++) {
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
    }
    return pageFaults;
}

void pageReplacement() {
    vector<int> pages;
    int frameCount;

    readPageReplacementInput("input.txt", pages, frameCount);

    vector<int> fifoFaults = fifoPageReplacement(pages, frameCount);
    writePageReplacementOutput("fifo_output.txt", fifoFaults, "FIFO", frameCount);

    vector<int> lruFaults = lruPageReplacement(pages, frameCount);
    writePageReplacementOutput("lru_output.txt", lruFaults, "LRU", frameCount);
}

int main() {
	pageReplacement();
	cout << "Da hoan thanh viec thay the trang." << endl;
	return 0;
}