#include <stdio.h>

int main() {
    int n, tq, i;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    int at[n], bt[n], rt[n];
    int ct[n], tat[n], wt[n];

    printf("\nEnter AT and BT:\n");

    for(i=0;i<n;i++) {
        printf("P%d: ",i+1);
        scanf("%d %d",&at[i],&bt[i]);

        rt[i]=bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d",&tq);

    int completed=0;
    int time=0;

    while(completed<n) {
        int found=0;

        for(i=0;i<n;i++) {

            if(at[i]<=time && rt[i]>0) {

                found=1;

                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                }
                else {
                    time += rt[i];
                    rt[i] = 0;
                    ct[i] = time;
                    completed++;
                }
            }
        }

        if(!found)
            time++;
    }

    float avgTAT=0, avgWT=0;

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++) {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];

        avgTAT+=tat[i];
        avgWT+=wt[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    printf("\nAverage TAT = %.2f",avgTAT/n);
    printf("\nAverage WT  = %.2f",avgWT/n);

    return 0;
}
