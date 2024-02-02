#include<bits/stdc++.h>
using namespace std;

void shortestjob(int bt[], int art[], int wt[], int tat[], int n) {
    int rt[n];

    for (int i = 0; i < n; ++i)
        rt[i] = bt[i];

    int complete = 0, t = 0;

    while (complete != n) {
        int shortest = -1, minm = INT_MAX;

        for (int j = 0; j < n; ++j) {
            if (art[j] <= t && rt[j] < minm && rt[j] > 0) {
                minm = rt[j];
                shortest = j;
            }
        }

        if (shortest == -1) {
            t++;
            continue;
        }

        rt[shortest]--;
        if (rt[shortest] == 0) {
            complete++;
            int finish_time = t + 1;
            wt[shortest] = finish_time - bt[shortest] - art[shortest];
            if(wt[shortest]<0) {
                wt[shortest]=0;
                } 
        }
        t++;
    }

    for (int i = 0; i < n; ++i)
        tat[i] = bt[i] + wt[i];
}

void displayResults(int bt[], int wt[], int tat[], int n) {
    cout << " P\tBT\tWT\tTAT\n";

    for (int i = 0; i < n; ++i) {
        cout << " " << i + 1 << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << endl;
    }

    float avg_wt = accumulate(wt, wt + n, 0.0) / n;
    float avg_tat = accumulate(tat, tat + n, 0.0) / n;

    cout << "\nAverage waiting time = " << avg_wt;
    cout << "\nAverage turn around time = " << avg_tat;
}

int main() {
    int bt[] = {6, 2, 8, 3, 4};
    int art[] = {2, 5, 1, 0, 4};
    int n = sizeof(bt) / sizeof(bt[0]);

    int wt[n] = {0};
    int tat[n] = {0};

    shortestjob(bt, art, wt, tat, n);
    displayResults(bt, wt, tat, n);

    return 0;
}
