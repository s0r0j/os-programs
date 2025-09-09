#include <stdio.h>
#include <stdlib.h>

void scanDiskScheduling(int requests[], int n, int head, int disk_size, int d) {
    int totalHeadMovement = 0;
    int sortedRequests[n + 1];  // Include boundaries (0 and disk_size - 1)
    int i, j, pos = 0;

    // Copy requests and add disk boundaries
    for (i = 0; i < n; i++)
        sortedRequests[i] = requests[i];
    if(d == 1)
        sortedRequests[n++] = disk_size - 1;
    else
        sortedRequests[n++] = 0;
    

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (sortedRequests[i] > sortedRequests[j]) {
                int temp = sortedRequests[i];
                sortedRequests[i] = sortedRequests[j];
                sortedRequests[j] = temp;
            }
        }
    }

    // Find head position in the sorted array
    for (i = 0; i < n; i++) {
        if (sortedRequests[i] >= head) {
            pos = i;
            break;
        }
    }

    printf("\nHead Movement Sequence: %d", head);

    if (d == 1) {  // Move Right
        for (i = pos; i < n; i++) {
            printf(" -> %d", sortedRequests[i]);
            totalHeadMovement += abs(sortedRequests[i] - head);
            head = sortedRequests[i];
        }
        for (i = pos - 1; i >= 0; i--) {
            printf(" -> %d", sortedRequests[i]);
            totalHeadMovement += abs(sortedRequests[i] - head);
            head = sortedRequests[i];
        }
    } else {  // Move Left (Fixed logic)
        for (i = pos - 1; i >= 0; i--) {   // Move left first
            printf(" -> %d", sortedRequests[i]);
            totalHeadMovement += abs(sortedRequests[i] - head);
            head = sortedRequests[i];
        }
        for (i = pos; i < n; i++) {        // Then move right
            printf(" -> %d", sortedRequests[i]);
            totalHeadMovement += abs(sortedRequests[i] - head);
            head = sortedRequests[i];
        }
    }

    printf("\nTotal Head Movement: %d\n", totalHeadMovement);
}

void main() {
    int n, head, disk_size, d;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int requests[n];

    printf("Enter the disk request queue: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the total disk size: ");
    scanf("%d", &disk_size);

    printf("Enter direction (1 for right, 0 for left): ");
    scanf("%d", &d);

    scanDiskScheduling(requests, n, head, disk_size, d);
}

