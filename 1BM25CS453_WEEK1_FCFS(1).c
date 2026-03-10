#include <stdio.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

int main() {
    int n, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];


    for(i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("\nProcess %d\n", i + 1);

        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival_time);

        printf("Burst Time: ");
        scanf("%d", &p[i].burst_time);
    }

    p[0].completion_time = p[0].arrival_time + p[0].burst_time;

    for(i = 1; i < n; i++) {
        if(p[i].arrival_time > p[i-1].completion_time)
            p[i].completion_time = p[i].arrival_time + p[i].burst_time;
        else
            p[i].completion_time = p[i-1].completion_time + p[i].burst_time;
    }


    for(i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
    }


    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].arrival_time,
               p[i].burst_time,
               p[i].completion_time,
               p[i].turnaround_time,
               p[i].waiting_time);
    }

    return 0;
}
