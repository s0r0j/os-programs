#include <stdio.h>
void main() {
int bsize[20], psize[20], bno, pno, allocation[20],
i, j, temp, lowest;
static int barray[20], parray[20];
printf("Best Fit\n");
for (i = 0; i < 20; i++) {
allocation[i] = -1;
barray[i] = 0;
parray[i] = -1;
}
printf("Enter number of blocks: ");
scanf("%d", &bno);
printf("Enter size of each block:\n");
for (i = 0; i < bno; i++) {
scanf("%d", &bsize[i]);
}
printf("Enter number of processes: ");
scanf("%d", &pno);
printf("Enter size of each process:\n");
for (i = 0; i < pno; i++) {
scanf("%d", &psize[i]);
}
for (i = 0; i < pno; i++) {
lowest = 9999;
for (j = 0; j < bno; j++) {
if (barray[j] == 0) {
temp = bsize[j] - psize[i];
if (temp >= 0 && temp < lowest) {
parray[i] = j;
lowest = temp;
}
}
}
if (parray[i] != -1) {
allocation[i] = parray[i];
barray[parray[i]] = 1;
}
}
printf("\nProcess No.\tProcess
Size\tAllocation\n");
for (i = 0; i < pno; i++) {
printf("%d\t\t%d\t\t", i + 1, psize[i]);
if (allocation[i] != -1)
printf("%d\n", allocation[i] + 1);
else
printf("Not Allocated\n");
}
}

