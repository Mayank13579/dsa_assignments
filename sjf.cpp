#include<bits/stdc++.h>
using namespace std;

void sjf(int bt[], int n, int rem[], int at[], int tat[], int wt[]) {
    for (int i = 0; i < n; i++) {
        rem[i] = bt[i];
    }

    int complete = 0, time = 0;
    while (complete != n) {
        int min = INT_MAX, shortest = -1;
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rem[i] <= min && rem[i] > 0) {
                min = rem[i];
                shortest = i;
            }
        }
        if (shortest == -1) {
            time++;
            continue;
        }
        rem[shortest]--;
        if (rem[shortest] == 0) {
            complete++;
            int finish = time + 1;
            wt[shortest] = finish - at[shortest] - bt[shortest];
            if (wt[shortest] < 0) {
                wt[shortest] = 0;
            }
            tat[shortest] = wt[shortest] + bt[shortest];
        }
        time++;
    }
    cout << "Wt" << " " << "TAT" << endl;
    for (int i = 0; i < n; i++) {
        cout << wt[i] << " " << tat[i] << endl;
    }
}

int main() {
    int bt[] = {6, 2, 8, 3, 4};
    int at[] = {2, 5, 1, 0, 4};
    int rem[5], tat[5], wt[5];
    sjf(bt, 5, rem, at, tat, wt);
    return 0;
}
