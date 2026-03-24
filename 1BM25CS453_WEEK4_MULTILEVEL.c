#include <stdio.h>

int main() {
    int n, i;

    printf("Enter total number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], type[n];
    int ct[n], tat[n], wt[n];


    for(i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        printf("Enter Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Enter Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Enter Type (1-System / 0-User): ");
        scanf("%d", &type[i]);
        pid[i] = i + 1;
    }

    int time = 0;


    for(i = 0; i < n; i++) {
        if(type[i] == 1) {
            if(time < at[i])
                time = at[i];

            time += bt[i];
            ct[i] = time;
        }
    }


    for(i = 0; i < n; i++) {
        if(type[i] == 0) {
            if(time < at[i])
                time = at[i];

            time += bt[i];
            ct[i] = time;
        }
    }

    float total_tat = 0, total_wt = 0;

    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        total_tat += tat[i];
        total_wt += wt[i];
    }


    printf("\nPID\tAT\tBT\tType\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], type[i],
               ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", total_tat / n);
    printf("\nAverage Waiting Time = %.2f\n", total_wt / n);

    return 0;
}
