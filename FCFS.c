#include <stdio.h>

// Function to calculate waiting time
void calcWT(int n, int bt[], int wt[]) {
    wt[0] = 0; // First process has no waiting time
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1]; // Waiting time for the current process
    }
}

// Function to calculate turnaround time
void calcTAT(int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i]; // Turnaround time for the current process
    }
}

// Function to calculate average times and print results
void calcAvgTimes(int n, int bt[]) {
    int wt[n], tat[n];
    int total_wt = 0, total_tat = 0;

    calcWT(n, bt, wt); // Calculate waiting times
    calcTAT(n, bt, wt, tat); // Calculate turnaround times

    printf("P\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;
    printf("Avg WT = %.2f\n", avg_wt);
    printf("Avg TAT = %.2f\n", avg_tat);
}

int main() {
    int bt[] = {10, 5, 8}; // Burst times
    int n = sizeof(bt) / sizeof(bt[0]); // Number of processes

    calcAvgTimes(n, bt); // Calculate and print average times
    return 0;
}
