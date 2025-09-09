#include <stdio.h>
struct rr {
int pid, bt, at, wt, tat, ct, rt, rem_t;
}p[10];
void main() {
  int tq, n, time_exec = 0, completed = 0;
  float avg_wt = 0, avg_tat = 0;
  printf("Enter the number of processes: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
	printf("Enter arrival time and burst time of process %d: ", i + 1);
	scanf("%d %d", &p[i].at, &p[i].bt);
	p[i].pid = i + 1;
	p[i].rem_t = p[i].bt;
  }
  for (int i = 0; i < n - 1; i++) {
	for (int j = 0; j < n - i - 1; j++) {
  	if (p[j].at > p[j + 1].at) {
    	struct rr temp = p[j];
    	p[j] = p[j + 1];
    	p[j + 1] = temp;	}}}
  printf("Enter the time quantum: ");
  scanf("%d", &tq);
  int k = 0;
  while (completed < n) {
	int executed = 0;
	for (int i = 0; i < n; i++) {
  	if (p[i].at <= time_exec && p[i].rem_t > 0) {
    	executed = 1;
    	if (p[i].rem_t <= tq) {
      	time_exec += p[i].rem_t;
      	p[i].rem_t = 0;
      	p[i].ct = time_exec;
      	completed++;
    	} else {
      	time_exec += tq;
      	p[i].rem_t -= tq; }
  	}}
	if (!executed) {
  	time_exec++;  }
}
  for (int i = 0; i < n; i++) {
	p[i].tat = p[i].ct - p[i].at;
	p[i].wt = p[i].tat - p[i].bt;
	avg_wt += p[i].wt;
	avg_tat += p[i].tat;
}
  printf("\nPID\tAT\tBT\tCT\tWT\tTAT");
  for (int i = 0; i < n; i++) {
  printf("\n%d\t%d\t%d\t%d\t%d\t%d", p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].wt,p[i].tat);
}
  printf("\nAverage waiting time: %.2f\n", avg_wt/n);
printf("Average turnaround time: %.2f\n", avg_tat/n);
}

