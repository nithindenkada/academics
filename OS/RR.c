#include <stdio.h>
#include <string.h>

int main()
{
    char p[20][5];        // Increased size to hold new processes from splitting
    int et[20], wt[20], timer = 3, count, pt[20], rt, i, j, totwt = 0, n = 5, found = 0, m;
    float avgwt;

    // Input process details
    for (i = 0; i < n; i++)
    {
        printf("Enter the process name: ");
        scanf("%s", p[i]);         // Removed & because p[i] is already an array (string)
        printf("Enter the processing time: ");
        scanf("%d", &pt[i]);
    }

    m = n;         // Save original process count
    wt[0] = 0;
    i = 0;

    // Round Robin scheduling loop
    do
    {
        if (pt[i] > timer)
        {
            rt = pt[i] - timer;         // Remaining time
            strcpy(p[n], p[i]);         // Copy process name to new slot
            pt[n] = rt;                 // Assign remaining time to new process
            et[i] = timer;              // Execution time in this round
            pt[i] = timer;              // Adjust current process burst time to quantum (important fix)
            n++;                        // Increment total number of processes
        }
        else
        {
            et[i] = pt[i];              // Execution time is remaining burst time
        }

        i++;
        wt[i] = wt[i - 1] + et[i - 1];  // Waiting time for next process
    } while (i < n);

    // Adjust waiting time for original processes after splitting
    count = 0;
    for (i = 0; i < m; i++)
    {
        found = 0;
        count = 0;
        for (j = i + 1; j < n; j++)      // Changed <= to < to avoid out-of-bound error
        {
            if (strcmp(p[i], p[j]) == 0)
            {
                count++;
                found = j;
            }
        }
        if (found != 0)
        {
            wt[i] = wt[found] - (count * timer);
        }
    }

    // Calculate total and average waiting time
    for (i = 0; i < m; i++)
    {
        totwt += wt[i];
    }
    avgwt = (float)totwt / m;

    // Output results
    printf("\nProcess\tBurst Time\tWaiting Time\n");
    for (i = 0; i < m; i++)
    {
        printf("%s\t%d\t\t%d\n", p[i], pt[i], wt[i]);
    }
    printf("\nTotal Waiting Time: %d\n", totwt);
    printf("Average Waiting Time: %.2f\n", avgwt);

    return 0;
}








Absolutely! Let's go step-by-step and show you the **full process execution table** for the same example:

---

### 🧪 **Given Inputs**

* **Processes**: P1 = 5, P2 = 3, P3 = 7
* **Time quantum**: 3

---

## ✅ WITH `pt[i] = timer;`

Each `pt[i]` represents the **actual execution time** per slice.

### 📋 Process List After Scheduling:

| Index | Process | Executed Time (`pt[i]`) | Waiting Time (`wt[i]`) |
| ----- | ------- | ----------------------- | ---------------------- |
| 0     | P1      | 3                       | 0                      |
| 1     | P2      | 3                       | 3                      |
| 2     | P3      | 3                       | 6                      |
| 3     | P1      | 2                       | 9                      |
| 4     | P3      | 3                       | 11                     |
| 5     | P3      | 1                       | 14                     |

### 🧮 Adjusted Waiting Time for original processes:

We care about the original 3: P1, P2, P3

| Process | Original Burst | Final Waiting Time Calculation                 | Waiting Time |
| ------- | -------------- | ---------------------------------------------- | ------------ |
| P1      | 5              | From last P1 (index 3): `wt[3] - 1×3 = 9 - 3`  | 6            |
| P2      | 3              | No split → `wt[1]`                             | 3            |
| P3      | 7              | From last P3 (index 5): `wt[5] - 2×3 = 14 - 6` | 8            |

### ✅ Final Table (WITH `pt[i] = timer;`)

| Process | Burst Time | Waiting Time |
| ------- | ---------- | ------------ |
| P1      | 5          | 6            |
| P2      | 3          | 3            |
| P3      | 7          | 8            |

---

## 🚫 WITHOUT `pt[i] = timer;`

Now the first entries keep **original burst times**, not just the quantum.

### 📋 Process List After Scheduling:

| Index | Process | Executed Time (`pt[i]`) | Waiting Time (`wt[i]`) |
| ----- | ------- | ----------------------- | ---------------------- |
| 0     | P1      | 5 ❌                     | 0                      |
| 1     | P2      | 3                       | 3                      |
| 2     | P3      | 7 ❌                     | 6                      |
| 3     | P1      | 2                       | 9                      |
| 4     | P3      | 4                       | 11                     |
| 5     | P3      | 1                       | 14                     |

### 🔍 Problems:

* P1 and P3's first entries still show 5 and 7 — this **doesn't reflect their slice (3)**.
* Confuses output if you display `pt[i]` for each slice.

---

### 🧮 Adjusted Waiting Time for original processes:

| Process | Original Burst | Final Waiting Time Calculation                 | Waiting Time |
| ------- | -------------- | ---------------------------------------------- | ------------ |
| P1      | 5              | From last P1 (index 3): `wt[3] - 1×3 = 9 - 3`  | 6            |
| P2      | 3              | No split → `wt[1]`                             | 3            |
| P3      | 7              | From last P3 (index 5): `wt[5] - 2×3 = 14 - 6` | 8            |

✅ The **waiting times are the same**.

---

### 🚫 Final Table (WITHOUT `pt[i] = timer;`)

| Process | Burst Time | Waiting Time |
| ------- | ---------- | ------------ |
| P1      | 5          | 6            |
| P2      | 3          | 3            |
| P3      | 7          | 8            |

---

## ✅ Conclusion

| Feature                | With `pt[i] = timer;` | Without `pt[i] = timer;`                     |
| ---------------------- | --------------------- | -------------------------------------------- |
| Waiting time accuracy  | ✅ Correct             | ✅ Correct                                    |
| Output clarity         | ✅ Easy to understand  | ❌ Confusing (wrong execution time per slice) |
| Display per slice info | ✅ Accurate            | ❌ Misleading                                 |

So, **functionally**, your logic works **without** `pt[i] = timer;`, but **for clarity and correctness in reporting each slice**, it’s better to **include it**.

---

Would you like me to help visualize this as a Gantt chart too?

