#include <iostream>
using namespace std;

void nextfit(int process[], int n, int blocksize[], int m, int aloc[]) {
    for (int i = 0; i < n; i++) {
        aloc[i] = -1; // Initialize allocation status for each process
    }

    for (int i = 0; i < n; i++) {
        int j = 0;
        while (j < m) {
            if (process[i] <= blocksize[j]) {
                aloc[i] = j;
                blocksize[j] -= process[i];
                break;
            }
            j = (j + 1) % m;
            if (j == 0 && aloc[i] == -1) {
                cout << "Cannot allocate Process " << i << endl;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << "Process " << i << " allocated to block " << aloc[i] << endl;
    }
}

int main() {
    int process[3] = {10, 20, 30};
    int block[3] = {10, 20, 5};
    int aloc[3];

    nextfit(process, 3, block, 3, aloc);

    return 0;
}