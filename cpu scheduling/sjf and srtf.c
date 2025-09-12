#include <stdio.h>
#include <limits.h>  // For INT_MAX

struct Process {
    int id, arrival_time, burst_time, completion_time, turnaround_time, waiting_time, remaining_time, visited;
};

// Utility function to sort processes by arrival time
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

// **Shortest Job First (SJF) - Non-Preemptive**
void sjfScheduling(struct Process p[], int n) {
    int completed = 0, current_time = 0;
    
    while (completed < n) {
        int index = -1, min_burst = INT_MAX;

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

// **Shortest Remaining Time First (SRTF) - Preemptive SJF**
void srtfScheduling(struct Process p[], int n) {
    int completed = 0, current_time = 0;
    
    while (completed < n) {
       int index = -1,  min_remaining_time = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (p[i].remaining_time > 0 && p[i].arrival_time <= current_time && p[i].remaining_time < min_remaining_time) {
                min_remaining_time = p[i].remaining_time;
                index = i;
            }
        }

        if (index == -1) {
            current_time++;
            continue;
        }

        p[index].remaining_time--;
        current_time++;

        if (p[index].remaining_time == 0) {
            p[index].completion_time = current_time;
            p[index].turnaround_time = p[index].completion_time - p[index].arrival_time;
            p[index].waiting_time = p[index].turnaround_time - p[index].burst_time;
            completed++;
        }
    }
}

// **Function to Display Results**
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

// **Function to Compare SJF vs SRTF Scheduling**
void compareAlgorithms(struct Process p[], int n) {
    struct Process p1[n], p2[n];

    // Copy the original process list
    for (int i = 0; i < n; i++) {
        p1[i] = p[i];
        p2[i] = p[i];
        p2[i].remaining_time = p[i].burst_time;  // Reset remaining time for SRTF
    }

    printf("\nExecuting SJF Scheduling:");
    sjfScheduling(p1, n);
    float avg_wt_sjf = displayProcesses(p1, n);


    printf("\nExecuting SRTF Scheduling:");
    srtfScheduling(p2, n);
    float avg_wt_srtf = displayProcesses(p2, n);

    printf("\nComparison:\n");
    printf("SJF Avg Waiting Time: %.2f\n", avg_wt_sjf);
    printf("SRTF Avg Waiting Time: %.2f\n", avg_wt_srtf);

    if (avg_wt_srtf < avg_wt_sjf) {
        printf("\nSRTF is better as it has lower waiting time.\n");
    } else if (avg_wt_sjf < avg_wt_srtf) {
        printf("\nSJF is better as it has lower waiting time.\n");
    } else {
        printf("\nBoth algorithms have the same waiting time.\n");
    }
}

// **Main Function**
int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    printf("Enter Arrival Time and Burst Time:\n");
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
        p[i].remaining_time = p[i].burst_time;
        p[i].visited = 0;
    }

    sortByArrival(p, n);
    
    compareAlgorithms(p, n);
            

    return 0;
}

