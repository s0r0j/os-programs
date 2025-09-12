#include <stdio.h>

struct Process {
    int id, arrival_time, burst_time, completion_time, turnaround_time, waiting_time, remaining_time;
};

void sortByArrival(struct Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].arrival_time > p[j + 1].arrival_time) {
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void fcfsScheduling(struct Process p[], int n) {
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        if (current_time < p[i].arrival_time) {
            current_time = p[i].arrival_time;  
        }
        p[i].completion_time = current_time + p[i].burst_time;
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
        current_time = p[i].completion_time;
    }
}


void roundRobinScheduling(struct Process p[], int n, int time_quantum) {
    int completed = 0, current_time = 0;
    
    while (completed < n) {
        int all_idle = 1;
        for (int i = 0; i < n; i++) {
            if (p[i].remaining_time > 0 && p[i].arrival_time <= current_time) {
                all_idle = 0;
                if (p[i].remaining_time > time_quantum) {
                    current_time += time_quantum;
                    p[i].remaining_time -= time_quantum;
                } else {
                    current_time += p[i].remaining_time;
                    p[i].completion_time = current_time;
                    p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
                    p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
                    p[i].remaining_time = 0;
                    completed++;
                }
            }
        }
        if (all_idle) {
            current_time++;
        }
    }
}

float displayProcesses(struct Process p[], int n) {
    float total_wt = 0, total_tat = 0;

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].arrival_time, p[i].burst_time, 
               p[i].completion_time, p[i].turnaround_time, p[i].waiting_time);

        total_tat += p[i].turnaround_time;
        total_wt += p[i].waiting_time;
    }

    printf("\nAverage Turnaround Time: %.2f", total_tat / n);
    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);

    return total_wt / n;  
}


void main() {
    int n, choice, time_quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    printf("Enter Arrival Time and Burst Time:\n");
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
        p[i].remaining_time = p[i].burst_time;
    }

    sortByArrival(p, n);

  
    while(1){
    printf("\nChoose Scheduling Algorithm:\n1. FCFS\n2. Round Robin\n3.Exit\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1: 
          fcfsScheduling(p, n);
          displayProcesses(p, n);
          break;
        case 2:
          printf("Enter Time Quantum: ");
          scanf("%d", &time_quantum);
          roundRobinScheduling(p, n, time_quantum);
          displayProcesses(p, n);
            break;
        case 3:
            return;
        default: 
            printf("Invalid choice!"); 
          } }}
