#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareProcesses(const vector<int>& p1, const vector<int>& p2) {
    return p1[2] < p2[2]; // Compare remaining times
}

void srtf(vector<vector<int>>& processes) {
    int time = 0;
    vector<int> timeline;

    while (!processes.empty()) {
        // Check for arriving processes
        for (auto it = processes.begin(); it != processes.end();) {
            if ((*it)[1] <= time) {
                timeline.push_back((*it)[0]); // Process ID
                it = processes.erase(it);
            } else {
                ++it;
            }
        }

        // Sort remaining processes by remaining time
        sort(processes.begin(), processes.end(), compareProcesses);

        // Execute the current process for one unit of time
        if (!processes.empty()) {
            processes[0][2]--;

            // If the current process is completed, remove it
            if (processes[0][2] == 0) {
                processes.erase(processes.begin());
            }
        }

        time++;
    }

    // Display timeline
    cout << "Timeline: ";
    for (int id : timeline) {
        cout << id << " ";
    }
    cout << endl;
}

int main() {
    // Each process is represented as a vector [ID, Arrival Time, Burst Time, Remaining Time]
    vector<vector<int>> processes = {
        {1, 0, 6, 6},
        {2, 2, 4, 4},
        {3, 4, 3, 3},
        {4, 6, 8, 8}
    };

    srtf(processes);

    return 0;
}
