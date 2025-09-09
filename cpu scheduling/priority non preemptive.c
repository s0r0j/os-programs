#include <stdio.h>
struct process {
int pid, bt, at, wt, tat, ct, priority, completed;
} p[30];
void main() {
int n, current_time = 0, completed = 0;
float total_wt = 0, total_tat = 0;
printf("Enter the number of processes: ");
scanf("%d", &n);
for (int i = 0; i < n; i++) {
printf("Enter arrival time, burst time, and
priority of process %d: ", i + 1);
scanf("%d %d %d", &p[i].at, &p[i].bt,
&p[i].priority);
p[i].pid = i + 1;
p[i].completed = 0;
}
for (int i = 0; i < n - 1; i++) {
for (int j = 0; j < n - i - 1; j++) {
if (p[j].at > p[j + 1].at) {
struct process temp = p[j];
p[j] = p[j + 1];
p[j + 1] = temp;
}
}
}
while (completed < n) {
int idx = -1, min_priority = 9999;
for (int i = 0; i < n; i++) {
if (p[i].at <= current_time && !p[i].completed
&& p[i].priority < min_priority) {
min_priority = p[i].priority;
idx = i;
}
}
if (idx == -1) {
current_time++;
continue;
}
p[idx].wt = current_time - p[idx].at;
p[idx].ct = current_time + p[idx].bt;
p[idx].tat = p[idx].ct - p[idx].at;
p[idx].completed = 1;
total_wt += p[idx].wt;
total_tat += p[idx].tat;
current_time = p[idx].ct;
completed++;
}
printf("\nPID\tAT\tBT\tPriority\tCT\tWT\tTAT");
for (int i = 0; i < n; i++) {
printf("\n%d\t%d\t%d\t%d\t\t%d\t%d\t%d",
p[i].pid, p[i].at, p[i].bt, p[i].priority, p[i].ct, p[i].wt,
p[i].tat);
}
printf("\n\nAverage Waiting Time: %.2f", total_wt
/ n);
printf("\nAverage Turnaround Time: %.2f\n",
total_tat / n);
}

