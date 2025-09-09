#include <stdio.h>
int findLRU(int time[], int n) {
int i, minimum = time[0], pos = 0;
for (i = 1; i < n; i++) {
if (time[i] < minimum) {
minimum = time[i];
pos = i;
}
}
return pos;
}
int main() {
int no_of_frames, no_of_pages, frames[10],
pages[100], counter = 0, time[10];
int i, j, pos, page_faults = 0, flag1, flag2;
printf("Enter number of pages: ");
scanf("%d", &no_of_pages);
printf("Enter reference string:\n ");
for (i = 0; i < no_of_pages; i++) {
scanf("%d", &pages[i]);
}
printf("Enter number of frames: ");
scanf("%d", &no_of_frames);
for (i = 0; i < no_of_frames; i++) {
frames[i] = -1;
time[i] = 0;
}
printf("\nPage Replacement Process:\n");
for (i = 0; i < no_of_pages; i++) {
flag1 = flag2 = 0;
for (j = 0; j < no_of_frames; j++) {
if (frames[j] == pages[i]) {
flag1 = flag2 = 1;
time[j] = ++counter;
printf("No page fault for %d\n", pages[i]);
break;
}
}
if (flag1 == 0) {
for (j = 0; j < no_of_frames; j++) {
if (frames[j] == -1) {
frames[j] = pages[i];
time[j] = ++counter;
page_faults++;
flag2 = 1;
for (int k = 0; k < no_of_frames; k++) {
if (frames[k] != -1) {
printf("%d ", frames[k]);
} else {
printf("- ");
}
}
printf(" (Page fault)\n");
break;
}
}
}
if (flag2 == 0) {
pos = findLRU(time, no_of_frames);
frames[pos] = pages[i];
time[pos] = ++counter;
page_faults++;
for (int k = 0; k < no_of_frames; k++) {
if (frames[k] != -1) {
printf("%d ", frames[k]);
} else {
printf("- ");
}
}
printf(" (Page fault)\n");
}
}
printf("\nTotal Page Faults: %d\n", page_faults);
return 0;
}

