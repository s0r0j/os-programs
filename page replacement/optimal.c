#include <stdio.h>
int findOptimal(int pages[], int frames[], int
no_of_frames, int no_of_pages, int current_index) {
int i, j, farthest = current_index, pos = -1;
for (i = 0; i < no_of_frames; i++) {
int found = 0;
for (j = current_index + 1; j < no_of_pages;
j++) {
if (frames[i] == pages[j]) {
if (j > farthest) {
farthest = j;
pos = i;
}
found = 1;
break;
}
}
if (found == 0) {
return i;
}
}
return (pos == -1) ? 0 : pos;
}
int main() {
int no_of_pages, no_of_frames, pages[100],
frames[10];
int i, j, page_faults = 0;
printf("Enter the number of pages: ");
scanf("%d", &no_of_pages);
printf("Enter the reference string(space-separated):\n");
for (i = 0; i < no_of_pages; i++) {
scanf("%d", &pages[i]);
}
printf("Enter the number of frames: ");
scanf("%d", &no_of_frames);
for (i = 0; i < no_of_frames; i++) {
frames[i] = -1;
}
printf("\nPage Replacement Process:\n");
for (i = 0; i < no_of_pages; i++) {
int flag = 0;
for (j = 0; j < no_of_frames; j++) {
if (frames[j] == pages[i]) {
flag = 1;
break;
}
}
if (flag == 0) {
if (i < no_of_frames) {
frames[i] = pages[i];
} else {
int pos = findOptimal(pages, frames,
no_of_frames, no_of_pages, i);
frames[pos] = pages[i];
}
page_faults++;
for (int k = 0; k < no_of_frames; k++)
if (frames[k] != -1) {
printf("%d ", frames[k]);
} else {
printf("- ");
}
}
printf(" (Page fault)\n");
} else {
printf("No page fault for %d\n", pages[i]);
}
}
printf("\nTotal Page Faults: %d\n", page_faults);
return 0;
}

