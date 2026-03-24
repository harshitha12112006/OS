#include <stdio.h>

int main()
{
    int n,i,time=0,smallest;
    int pid[20],at[20],bt[20],pr[20];
    int remaining[20];
    int ct[20],tat[20],wt[20];
    int completed=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nProcess %d\n",i+1);

        printf("Process ID: ");
        scanf("%d",&pid[i]);

        printf("Arrival Time: ");
        scanf("%d",&at[i]);

        printf("Burst Time: ");
        scanf("%d",&bt[i]);

        printf("Priority: ");
        scanf("%d",&pr[i]);

        remaining[i]=bt[i];
    }

    while(completed<n)
    {
        smallest=-1;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && remaining[i]>0)
            {
                if(smallest==-1 || pr[i]<pr[smallest])
                    smallest=i;
            }
        }

        if(smallest==-1)
        {
            time++;
            continue;
        }

        remaining[smallest]--;
        time++;

        if(remaining[smallest]==0)
        {
            completed++;
            ct[smallest]=time;
        }
    }

    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }

    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i],at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);
    }

    return 0;
}
