#include <stdio.h>
struct fcfs {
int pid, atime, btime, wtime, ttime, ctime;
};
int main() {
int n, i;
float total_wtime = 0, total_ttime = 0;
printf("FCFS Scheduling\n");
printf("Enter number of processes: ");
scanf("%d", &n);
struct fcfs p[n];
for (i = 0; i < n; i++) {
p[i].pid = i + 1;
printf("Enter arrival time of process %d: ", p[i].pid);
scanf("%d", &p[i].atime);
printf("Enter burst time of process %d: ", p[i].pid);
scanf("%d", &p[i].btime);
}
for (i = 0; i < n - 1; i++) {
for (int j = 0; j < n - i - 1; j++) {
if (p[j].atime > p[j + 1].atime) {
struct fcfs temp = p[j];
p[j] = p[j + 1];
p[j + 1] = temp;
}
}
}
p[0].wtime = 0;
p[0].ctime = p[0].atime + p[0].btime;
p[0].ttime = p[0].ctime - p[0].atime;
total_wtime += p[0].wtime;
total_ttime += p[0].ttime;
for (i = 1; i < n; i++) {
if (p[i - 1].ctime > p[i].atime) {
p[i].wtime = p[i - 1].ctime - p[i].atime;
} else {
p[i].wtime = 0;
}
p[i].ctime = p[i - 1].ctime + p[i].btime;
p[i].ttime = p[i].ctime - p[i].atime;

total_wtime += p[i].wtime;
total_ttime += p[i].ttime;
}
printf("\nProcess\tAT\tBT\tWT\tTAT\tCT");
for (i = 0; i < n; i++) {
printf("\nP%d\t%d\t%d\t%d\t%d\t%d",
p[i].pid, p[i].atime, p[i].btime, p[i].wtime, p[i].ttime, p[i].ctime);
}
printf("\nTotal Waiting Time: %.2f", total_wtime);
printf("\nTotal Turnaround Time: %.2f", total_ttime);
printf("\nAverage Waiting Time: %.2f", total_wtime / n);
printf("\nAverage Turnaround Time: %.2f\n", total_ttime / n);
}

