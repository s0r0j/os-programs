#include <stdio.h>

struct Process {
    int id, arrival_time, burst_time, completion_time, turnaround_time, waiting_time, remaining_time, visited, priority;
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

void sjf(struct Process p[], int n) {
    int completed = 0, current_time = 0;
    
    while (completed < n) {
        int index = -1, min_burst = 9999;

        for (int i = 0; i < n; i++) {
            if (!p[i].visited && p[i].arrival_time <= current_time && p[i].burst_time < min_burst) {
                min_burst = p[i].burst_time;
                index = i;
            }
        }

        if (index == -1) {
            current_time++;
            continue;
        }

        p[index].completion_time = current_time + p[index].burst_time;
        p[index].turnaround_time = p[index].completion_time - p[index].arrival_time;
        p[index].waiting_time = p[index].turnaround_time - p[index].burst_time;
        p[index].visited = 1;

        current_time = p[index].completion_time;
        completed++;
    }
}

void priority(struct Process p[], int n) {
    int completed = 0, current_time = 0;
    
    while (completed < n) {
        int index = -1, maxpriority = 9999;

        for (int i = 0; i < n; i++) {
            if (!p[i].visited && p[i].arrival_time <= current_time && p[i].priority < maxpriority) {
                maxpriority = p[i].priority;
                index = i;
            }
        }

        if (index == -1) {
            current_time++;
            continue;
        }

        p[index].completion_time = current_time + p[index].burst_time;
        p[index].turnaround_time = p[index].completion_time - p[index].arrival_time;
        p[index].waiting_time = p[index].turnaround_time - p[index].burst_time;
        p[index].visited = 1;

        current_time = p[index].completion_time;
        completed++;
    }
}

void resetProcesses(struct Process p[], int n) {
    for (int i = 0; i < n; i++) {
        p[i].visited = 0;
        p[i].completion_time = 0;
        p[i].turnaround_time = 0;
        p[i].waiting_time = 0;
    }
}

void display(struct Process p[], int n) {
    float total_wt = 0, total_tat = 0;

    printf("\nPID\tAT\tBT\tP\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].arrival_time, p[i].burst_time, p[i].priority,
               p[i].completion_time, p[i].turnaround_time, p[i].waiting_time);

        total_tat += p[i].turnaround_time;
        total_wt += p[i].waiting_time;
    }

    printf("\nAverage Turnaround Time: %.2f", total_tat / n);
    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);

    
}

void main() {
    int n,c;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    printf("Enter Arrival Time and Burst Time and priority:\n");
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        scanf("%d%d%d", &p[i].arrival_time, &p[i].burst_time,&p[i].priority);
        p[i].visited = 0;
    }

    sortByArrival(p, n);
    
    while(1){
    printf("Choice\n1.SJF\t2.Priority\t3.Exit\n");
    scanf("%d",&c);
    
    switch(c){
      case 1:
        sjf(p,n);
        display(p,n);
        break;
      case 2:
        resetProcesses(p,n);
        priority(p,n);
        display(p,n);
        break;
      case 3:
        return;
      default:
        printf("Wrong choice");
        break;
      }
          
}
}
