#include <stdio.h>

#define P 4 // Number of processes
#define R 5 // Number of resources

int main() {
    int claim[P][R], alloc[P][R], need[P][R], available[R], work[R];
    int finish[P], safe[P], count = 0;
    int i, j, k, found;

    // Input claim, allocation, and available matrices
    printf("Enter claim matrix (%dx%d):\n", P, R);
    for (i = 0; i < P; i++) {
        for (j = 0; j < R; j++) {
            scanf("%d", &claim[i][j]);
        }
    }

    printf("Enter allocation matrix (%dx%d):\n", P, R);
    for (i = 0; i < P; i++) {
        for (j = 0; j < R; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter availability vector (%d elements):\n", R);
    for (i = 0; i < R; i++) {
        scanf("%d", &available[i]);
    }

    // Calculate need matrix
    for (i = 0; i < P; i++) {
        for (j = 0; j < R; j++) {
            need[i][j] = claim[i][j] - alloc[i][j];
        }
    }

    // Initialize work and finish arrays
    for (i = 0; i < R; i++) {
        work[i] = available[i];
    }
    for (i = 0; i < P; i++) {
        finish[i] = 0;
    }

    // Banker's algorithm
    while (count < P) {
        found = 0;
        for (i = 0; i < P; i++) {
            if (finish[i] == 0) {
                int flag = 1;
                for (j = 0; j < R; j++) {
                    if (need[i][j] > work[j]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    for (j = 0; j < R; j++) {
                        work[j] += alloc[i][j];
                    }
                    finish[i] = 1;
                    safe[count++] = i;
                    found = 1;
                }
            }
        }
        if (!found) {
            break;
        }
    }

    // Check for deadlock
    if (count < P) {
        printf("System is in unsafe state. Deadlock possible.\n");
    } else {
        printf("System is in safe state. Safe sequence: ");
        for (i = 0; i < P; i++) {
            printf("P%d ", safe[i]);
        }
        printf("\n");
    }

    return 0;
}