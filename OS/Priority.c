#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, n, temp, temp1, temp2;
    int *p, *at, *bt, *wt, *tat;
    int sum = 0;
    float avg;

    printf("Enter number of processes:\n");
    scanf("%d", &n);

    // Memory allocation
    p = (int *)calloc(n, sizeof(int));
    at = (int *)calloc(n, sizeof(int));
    bt = (int *)calloc(n, sizeof(int));
    wt = (int *)calloc(n, sizeof(int));
    tat = (int *)calloc(n, sizeof(int));

    // Input
    printf("Enter priorities:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);

    printf("Enter arrival times:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &at[i]);

    printf("Enter burst times:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    // Sort by priority (ascending)
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (p[j + 1] < p[j]) {
                // Swap priorities
                temp = p[j]; p[j] = p[j + 1]; p[j + 1] = temp;
                // Swap arrival times
                temp1 = at[j]; at[j] = at[j + 1]; at[j + 1] = temp1;
                // Swap burst times
                temp2 = bt[j]; bt[j] = bt[j + 1]; bt[j + 1] = temp2;
            }
        }
    }

    // Calculate waiting and turnaround times
    wt[0] = 0;
    tat[0] = bt[0];

    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
    }

    // Output
    printf("Priorities\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], wt[i], tat[i]);
    }

    // Average waiting time
    for (i = 0; i < n; i++)
        sum += wt[i];
    avg = (float)sum / n;

    printf("\nAverage Waiting Time = %.2f\nTotal Waiting Time = %d\n", avg, sum);

    // Free memory unwanted
    free(p);
    free(at);
    free(bt);
    free(wt);
    free(tat);

    return 0;
}
