#include <stdio.h>
struct sjf {
int wtime, btime, ttime, pid, atime, ctime;
} p[10];
void main() {
int i, n, j, completed = 0, currentTime = 0;
float tttime = 0, twtime = 0;
int executing[30];
printf("SJF Scheduling");
printf("\nEnter number of processes: ");
scanf("%d", &n);
for (i = 0; i < n; i++) {
printf("Enter burst time of process %d: ", i + 1);
scanf("%d", &p[i].btime);
printf("Enter arrival time of process %d: ", i + 1);
scanf("%d", &p[i].atime);
p[i].pid = i + 1;
}
for (i = 0; i < n - 1; i++) {
for (j = 0; j < n - i - 1; j++) {
if (p[j].atime > p[j + 1].atime) {
struct sjf temp = p[j];
p[j] = p[j + 1];
p[j + 1] = temp;    }}}
j=0;
while (completed < n) {
int idx = -1;
int minBurst = 9999;

for (i = 0; i < n; i++) {
if (p[i].atime <= currentTime && p[i].btime < minBurst && p[i].ttime == 0) {
minBurst = p[i].btime;
idx = i;
}
}

if (idx == -1) {
currentTime++;
} else {
p[idx].wtime = currentTime - p[idx].atime;
p[idx].ttime = p[idx].wtime + p[idx].btime;
p[idx].ctime = currentTime + p[idx].btime;
currentTime += p[idx].btime;
completed++;
executing[j]=idx;
twtime += p[idx].wtime;
tttime += p[idx].ttime;
}
j++;
}
printf("\nPID\tAT\tBT\tWT\tTAT");
for (i = 0; i < n; i++) {
int ind = executing[i];
printf("\n%d\t%d\t%d\t%d\t%d", p[ind].pid, p[ind].atime, p[ind].btime, p[ind].wtime, p[ind].ttime);
}
printf("\n\nTotal waiting time: %.2f", twtime);
printf("\nTotal turnaround time: %.2f", tttime);
printf("\nAverage waiting time: %.2f", twtime / n);
printf("\nAverage turnaround time: %.2f\n",tttime/n);
}

