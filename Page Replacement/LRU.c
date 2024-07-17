#include <stdio.h>

int main() {
    int frames[3] = {-1, -1, -1}, time[3] = {0, 0, 0};
    int pages[] = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2};
    int n = sizeof(pages) / sizeof(pages[0]), faults = 0, t = 0;
    printf("\nSteps taken:\n");
    for (int i = 0; i < n; i++) {
        int hit = 0, pos = 0;

        for (int j = 0; j < 3; j++) {
            if (frames[j] == pages[i]) {
                time[j] = ++t;
                hit = 1;
                break;
            }
        }

        if (!hit) {
            for (int j = 1; j < 3; j++)
                if (time[j] < time[pos]) pos = j;

            frames[pos] = pages[i];
            time[pos] = ++t;
            faults++;
        }

        printf("%d\t", pages[i]);
        for (int j = 0; j < 3; j++)
            frames[j] != -1 ? printf("%d ", frames[j]) : printf("- ");
        if (!hit) printf("--> F");
        printf("\n");
    }

    printf("\nNo of faults: %d\n", faults);
    return 0;
}