#include <stdio.h>

int main() {
    int n, time=0, completed=0, i;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    int at[n], bt[n], rt[n], pr[n];
    int ct[n], tat[n], wt[n];

    printf("\nEnter AT BT Priority:\n");

    for(i=0;i<n;i++) {
        printf("P%d: ",i+1);
        scanf("%d %d %d",&at[i],&bt[i],&pr[i]);

        rt[i]=bt[i];
    }

    while(completed<n) {
        int idx=-1;
        int high=9999;

        for(i=0;i<n;i++) {
            if(at[i]<=time && rt[i]>0 && pr[i]<high) {
                high=pr[i];
                idx=i;
            }
        }

        if(idx==-1) {
            time++;
            continue;
        }

        rt[idx]--;
        time++;

        if(rt[idx]==0) {
            ct[idx]=time;
            completed++;
        }
    }

    float avgTAT=0, avgWT=0;

    printf("\nProcess\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++) {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];

        avgTAT+=tat[i];
        avgWT+=wt[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);
    }

    printf("\nAverage TAT = %.2f",avgTAT/n);
    printf("\nAverage WT  = %.2f",avgWT/n);

    return 0;
}
