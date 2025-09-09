#include <stdio.h>
struct process{
int pid,bt,at,wt,tat,ct,priority,rt,check;
};
struct process p[30];
int main(){
int
n,count=0,currTime=0,index=-1,min_index,max_ind
ex;
float tot_wt,tot_tat;
printf("Enter the no. of processes: ");
scanf("%d",&n);
printf("Priority Scheduling Preemptive...\n");
for(int i=0;i<n;i++){
printf("Enter the AT,BT, and Priority of process
%d: ",i+1);
scanf("%d %d
%d",&p[i].at,&p[i].bt,&p[i].priority);
p[i].pid = i+1;
p[i].rt = p[i].bt;
p[i].check=0;}
for(int i=0;i<n-1;i++){
for(int j=0;j<n-i-1;j++){
if(p[j].at>p[j+1].at){
struct process temp = p[j];
p[j] = p[j+1];
p[j+1] = temp;}}}
min_index = 0;
while(count!=n){
int MAX = 9999;
for(int i=0;i<n;i++){
if(p[i].at<=currTime && p[i].priority<MAX &&
!p[i].check){
max_index = i;
MAX = p[i].priority;
index = i;}
if(p[i].priority==MAX){
min_index = i;}
if(p[i].at<p[min_index].at && !p[i].check){
min_index = i;}
if(p[i].priority==MAX && !p[i].check &&
p[max_index].at>p[min_index].at){
index = i;
min_index = i;}}
if(p[index].rt>0){
currTime++;
p[index].rt--;
continue;}
if(p[index].rt==0){
p[index].ct = currTime;
p[index].tat = p[index].ct - p[index].at;
p[index].wt = p[index].tat - p[index].bt;
p[index].check=1;
tot_wt += p[index].wt;
tot_tat += p[index].tat;
count++;}}
printf("PID\tAT\tBT\tCT\tWT\tTAT\n");
for(int i=0;i<n;i++){
printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[
i].bt,p[i].
ct,p[i].wt,p[i].tat);}
printf("Average waiting time: %.2f\n",tot_wt/n);
printf("Average turnaround time:
%.2f\n",tot_tat/n);
}

