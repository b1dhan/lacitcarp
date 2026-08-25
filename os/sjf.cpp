#include <stdio.h>

int main() {
    int n, i, completed = 0, time = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n], done[n];

    printf("\nEnter AT and BT:\n");
    for(i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        done[i] = 0;
    }

    while(completed < n) {
        int idx = -1;
        int minBT = 9999;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && !done[i] && bt[i] < minBT) {
                minBT = bt[i];
                idx = i;
            }
        }

        if(idx == -1) {
            time++;
        } else {
            time += bt[idx];
            ct[idx] = time;
            done[idx] = 1;
            completed++;
        }
    }

    float avgTAT = 0, avgWT = 0;

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avgTAT += tat[i];
        avgWT += wt[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage TAT = %.2f", avgTAT/n);
    printf("\nAverage WT  = %.2f", avgWT/n);

    return 0;
}
