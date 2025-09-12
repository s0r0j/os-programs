#include <stdio.h>

struct Process {
    int id, arrival_time, burst_time, completion_time, turnaround_time, waiting_time, remaining_time;
};

// Utility function to sort processes by arrival time (FCFS order)
void sortByArrival(struct Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].arrival_time > p[j + 1].arrival_time) {
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;        }    }    }}

// **First-Come, First-Served (FCFS) Scheduling**
void fcfsScheduling(struct Process p[], int n) {
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        if (current_time < p[i].arrival_time) {
            current_time = p[i].arrival_time;  // CPU idle until process arrives
        }
        p[i].completion_time = current_time + p[i].burst_time;
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
        current_time = p[i].completion_time;
    }
}

int queue[100], front = 0, rear = 0;

void enqueue(int val) {
    queue[rear++] = val;
}

int dequeue() {
    if(front == rear) return -1;
    return queue[front++];
}

int isInQueue(int val) {
    for(int i = front; i < rear; i++) {
        if(queue[i] == val) return 1;
    }
    return 0;
}


// **Round Robin Scheduling**
void roundRobinScheduling(struct Process p[], int n, int tq) {
    int current_time = 0, completed = 0;
    int visited[n];

    for(int i = 0; i < n; i++) {
        visited[i] = 0;
        p[i]. remaining_time= p[i].burst_time;
    }

    enqueue(0);
    visited[0] = 1;

    while(completed < n) {
        int idx = dequeue();
        if(idx == -1) {
            current_time++;
            for(int i = 0; i < n; i++) {
                if(p[i].arrival_time <= current_time && !visited[i]) {
                    enqueue(i);
                    visited[i] = 1;
                }
            }
            continue;
        }

        if(p[idx]. remaining_time > tq) {
            current_time += tq;
            p[idx]. remaining_time -= tq;
        } else {
            current_time += p[idx].remaining_time;
            p[idx].remaining_time = 0;
            p[idx].completion_time= current_time;
            p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
           p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
            completed++;
        }

        for(int i = 0; i < n; i++) {
            if(p[i].arrival_time <= current_time && p[i]. remaining_time > 0 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }

        if(p[idx]. remaining_time > 0) {
            enqueue(idx);
        }
    }

front= rear = 0;
}

// **Function to Display Results and Calculate Average Waiting Time**
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

    return total_wt / n;  // Returning Average Waiting Time for Comparison
}

// **Function to Compare FCFS and Round Robin Scheduling**
void compareAlgorithms(struct Process p[], int n, int time_quantum) {
    struct Process p1[n], p2[n];

    // Copy the original process list
    for (int i = 0; i < n; i++) {
        p1[i] = p[i];
        p2[i] = p[i];
        p2[i].remaining_time = p[i].burst_time;  // Reset remaining time for Round Robin
    }

    printf("\nExecuting FCFS Scheduling:");
    fcfsScheduling(p1, n);
    float avg_wt_fcfs = displayProcesses(p1, n);

    printf("\nExecuting Round Robin Scheduling (Time Quantum = %d):", time_quantum);
    roundRobinScheduling(p2, n, time_quantum);
    float avg_wt_rr = displayProcesses(p2, n);

    printf("\nComparison:\n");
    printf("FCFS Avg Waiting Time: %.2f\n", avg_wt_fcfs);
    printf("Round Robin Avg Waiting Time: %.2f\n", avg_wt_rr);

    if (avg_wt_rr < avg_wt_fcfs) {
        printf("\nRound Robin is better as it has lower waiting time.\n");
    } else if (avg_wt_fcfs < avg_wt_rr) {
        printf("\nFCFS is better as it has lower waiting time.\n");
    } else {
        printf("\nBoth algorithms have the same waiting time.\n");
    }
}

// **Main Function**
int main() {
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

printf("enter time quantum : ");
scanf("%d",&time_quantum);

    sortByArrival(p, n);
    compareAlgorithms(p, n, time_quantum);
           
    return 0;
}

