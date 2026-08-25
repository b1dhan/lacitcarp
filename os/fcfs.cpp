#include <stdio.h>

int main()
{
    int n, i;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n];
    float avgTAT = 0, avgWT = 0;

printf("\nEnter Arrival Time and Burst Time for each process:\n");

for(i = 0; i < n; i++)
{
    printf("P%d (AT BT): ", i + 1);
    scanf("%d %d", &at[i], &bt[i]);
}

    // FCFS Scheduling
    ct[0] = at[0] + bt[0];

    for(i = 1; i < n; i++)
    {
        if(ct[i - 1] < at[i])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i - 1] + bt[i];
    }

    // Calculate TAT and WT
    for(i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avgTAT += tat[i];
        avgWT += wt[i];
    }

    avgTAT /= n;
    avgWT /= n;

    // Display Result
    printf("\n-----------------------------------------------------------------\n");
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    printf("-----------------------------------------------------------------\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("-----------------------------------------------------------------\n");
    printf("Average Turnaround Time = %.2f\n", avgTAT);
    printf("Average Waiting Time    = %.2f\n", avgWT);

    return 0;
}
