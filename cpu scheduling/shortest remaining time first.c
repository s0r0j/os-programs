#include <stdio.h>
struct sjf {
int wtime, btime, ttime, pid, atime, ctime, rtime;
} p[10];
void main() {
  int i, n, completed = 0, currentTime = 0, shortest;
  float tttime = 0, twtime = 0;
  printf("SJF Preemptive Scheduling");
  printf("\nEnter number of processes: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
	printf("\nEnter burst time of process %d: ", i+1);
	scanf("%d", &p[i].btime);
	printf("Enter arrival time of process %d: ", i+1);
	scanf("%d", &p[i].atime);
	p[i].pid = i + 1;
	p[i].rtime = p[i].btime;
  }
  while (completed < n) {
	int idx = -1;
	int minRTime = 9999;
	for (i = 0; i < n; i++) {
	if (p[i].atime <= currentTime && p[i].rtime < minRTime && p[i].rtime > 0) {
  	minRTime = p[i].rtime;
  	idx = i;
	}}
	if (idx == -1) {
  	currentTime++;
  	continue;
  	}
	p[idx].rtime--;
	currentTime++;
	if (p[idx].rtime == 0) {
  	completed++;
  	p[idx].ctime = currentTime;
  	p[idx].ttime = p[idx].ctime - p[idx].atime;
  	p[idx].wtime = p[idx].ttime - p[idx].btime;
  	twtime += p[idx].wtime;
  	tttime += p[idx].ttime;}
  	}
  printf("\nPID\tAT\tBT\tCT\tWT\tTAT");
  for (i = 0; i < n; i++) {
	printf("\n%d\t%d\t%d\t%d\t%d\t%d", p[i].pid,p[i].atime,p[i].btime,p[i].ctime,p[i].wtime,p[i].ttime); }
printf("\n\nTotal waiting time: %.2f", twtime);
printf("\nTotal turnaround time: %.2f", tttime);
printf("\nAverage waiting time: %.2f", twtime / n);
printf("\nAverage turnaround time: %.2f\n", tttime /n);
}

