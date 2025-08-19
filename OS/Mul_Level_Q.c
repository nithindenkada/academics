#include <stdio.h>

int main()
{
    int p_id[20], bt[20], priority[20], wt[20], tat[20], i, k, n, temp;
    float wtavg, tatavg;

    // Input number of processes with validation
    do
    {
        printf("Enter the number of processes (1-20): ");
        scanf("%d", &n);
        if (n < 1 || n > 20)
            printf("❌ Invalid input! Please enter a number between 1 and 20.\n");
    } while (n < 1 || n > 20);

    // Input burst times and process types with validation
    for (i = 0; i < n; i++)
    {
        p_id[i] = i + 1;

        // Validate burst time
        do
        {
            printf("Enter the burst time of process %d (must be > 0): ", i + 1);
            scanf("%d", &bt[i]);
            if (bt[i] <= 0)
                printf("❌ Invalid burst time! Please enter a positive value.\n");
        } while (bt[i] <= 0);

        // Validate process type
        do
        {
            printf("System/User process (0=System, 1=User): ");
            scanf("%d", &priority[i]);
            if (priority[i] != 0 && priority[i] != 1)
                printf("❌ Invalid input! Enter 0 for System or 1 for User.\n");
        } while (priority[i] != 0 && priority[i] != 1);
    }

    // Sorting processes by system/user type (0 < 1)
    for (i = 0; i < n - 1; i++)
    {
        for (k = i + 1; k < n; k++)
        {
            if (priority[i] > priority[k])
            {
                // Swap processes
                temp = p_id[i];
                p_id[i] = p_id[k];
                p_id[k] = temp;

                // Swap burst times
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;

                // Swap system/user types
                temp = priority[i];
                priority[i] = priority[k];
                priority[k] = temp;
            }
        }
    }

    // Initialize waiting time and turnaround time for the first process
    wt[0] = 0;
    tat[0] = bt[0];
    wtavg = 0;
    tatavg = bt[0];

    // Calculate waiting times and turnaround times
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    // Display the results
    printf("\nProcess\tSystem/User\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%s\t\t%d\t\t%d\t\t%d\n",
               p_id[i],
               (priority[i] == 0) ? "System" : "User",
               bt[i], wt[i], tat[i]);
    }

    // Calculate and display average waiting time and turnaround time
    printf("\nAverage Waiting Time: %.2f", wtavg / n);
    printf("\nAverage Turnaround Time: %.2f\n", tatavg / n);

    return 0;
}
