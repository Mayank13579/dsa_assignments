#include <iostream>
#include <algorithm>

using namespace std;

#define n 5
int arrivaltime[] = {1, 2, 3, 4, 5};
int bursttime[] = {3, 5, 1, 7, 4};
int priority[] = {3, 4, 1, 7, 8};



int wt[5], tat[5];

bool compare(int a, int b) {
    if (arrivaltime[a] == arrivaltime[b])
        return priority[a] < priority[b];
    else
        return arrivaltime[a] < arrivaltime[b];
}

void getWaitingTime() {
    int service[5];
    service[0] = arrivaltime[0];
    wt[0] = 0;

    for (int i = 1; i < n; i++) {
        service[i] = bursttime[i - 1] + service[i - 1];
        wt[i] = service[i] - arrivaltime[i];
        wt[i] = max(0, wt[i]);
    }
}

void getTurnaroundTime() {
    for (int i = 0; i < n; i++)
        tat[i] = bursttime[i] + wt[i];
}

int main() {


    int order[n];
    for (int i = 0; i < n; i++)
        order[i] = i;

    sort(order, order + n, compare);

    getWaitingTime();
    getTurnaroundTime();

    // Displaying the results directly in the main function
    cout << "Process_no\tStart_time\tComplete_time\tTurn_Around_Time\tWaiting_Time" << endl;

    double wavg = 0, tavg = 0;

   for (int i = 0; i < n; i++) {
        wavg += wt[i];
        tavg += tat[i];

        int stime, ctime;
        if (i == 0) {
            stime = arrivaltime[order[i]];
        } else {
            stime = tat[order[i - 1]] + arrivaltime[order[i]];
        }

        ctime = stime + tat[order[i]] - wt[order[i]];

        cout << order[i] + 1 << "\t\t" << stime << "\t\t" << ctime << "\t\t" << tat[order[i]] << "\t\t\t" << wt[order[i]] << endl;
    }
    cout << "Average waiting time is : " << wavg / n << endl;
    cout << "Average turnaround time : " << tavg / n << endl;

    return 0;
}
