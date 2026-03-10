#include <stdio.h>

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int executionTime;
};

int main() {
    int n, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for(i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("\nProcess P%d\n", p[i].pid);
        printf("Arrival Time: ");
        scanf("%d", &p[i].arrivalTime);
        printf("Burst Time: ");
        scanf("%d", &p[i].burstTime);
        printf("Completion Time:");
        scanf("%d", &p[i].completionTime);

        p[i].executionTime = p[i].burstTime;
    }

    printf("\nStored Process Details:\n");
    printf("PID\tAT\tBT\tET\tCT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].arrivalTime,
               p[i].burstTime,
               p[i].executionTime,
               p[i].completionTime);
    }

    return 0;
}
