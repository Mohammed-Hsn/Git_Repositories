#include <stdio.h>

struct process {
    int allocation[3];
    int max[3];
    int need[3];
    int finish;
} p[10];

int main() {
    int avail[3], work[3], sequence[10], n, count = 0;

    printf("Enter the total number of processes: ");
    scanf("%d", &n);

    printf("Enter the available resources: ");
    scanf("%d%d%d", &avail[0], &avail[1], &avail[2]);

    for (int i = 0; i < n; i++) {
        printf("Enter allocated resources for process %d: ", i);
        scanf("%d%d%d", &p[i].allocation[0], &p[i].allocation[1], &p[i].allocation[2]);
        printf("Enter maximum resources for process %d: ", i);
        scanf("%d%d%d", &p[i].max[0], &p[i].max[1], &p[i].max[2]);

        p[i].finish = 0;

        for (int j = 0; j < 3; j++) {
            p[i].need[j] = p[i].max[j] - p[i].allocation[j];
        }
    }

    // Initialize work array with available resources
    for (int i = 0; i < 3; i++) {
        work[i] = avail[i];
    }

    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (p[i].finish == 0) {
                int flag = 1;
                for (int j = 0; j < 3; j++) {
                    if (p[i].need[j] > work[j]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 1) {
                    for (int j = 0; j < 3; j++) {
                        work[j] += p[i].allocation[j];
                    }
                    sequence[count++] = i;
                    p[i].finish = 1;
                    found = 1;
                }
            }
        }
        if (found == 0) {
            printf("System is in an unsafe state!\n");
            return 0;
        }
    }

    printf("Safe sequence is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", sequence[i]);
    }
    printf("\n");

    return 0;
}
