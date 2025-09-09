#include <stdio.h>
int main() {
int no_of_pages, no_of_frames, pages[100],
frames[10], i, j, k, page_faults = 0, index = 0;
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
frames[index] = pages[i];
index = (index + 1) % no_of_frames;
page_faults++;
for (k = 0; k < no_of_frames; k++) {
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

