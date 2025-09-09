#include <stdio.h>
#include <stdlib.h>

void lookDiskScheduling(int requests[], int n, int head, int direction) {
    int totalHeadMovement = 0;
    int sortedRequests[n];
    int i, j, pos = 0;

    // Copy requests for sorting
    for (i = 0; i < n; i++) {
        sortedRequests[i] = requests[i];
    }

    // Sort the requests
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (sortedRequests[i] > sortedRequests[j]) {
                int temp = sortedRequests[i];
                sortedRequests[i] = sortedRequests[j];
                sortedRequests[j] = temp;
            }
        }
    }

    // Find head position in sorted array
    for (i = 0; i < n; i++) {
        if (sortedRequests[i] >= head) {
            pos = i;
            break;
        }
    }

    printf("\nLOOK Head Movement Sequence: %d", head);

    if (direction == 1) {  // Move Right
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
    } else {  // Move Left
        for (i = pos - 1; i >= 0; i--) {
            printf(" -> %d", sortedRequests[i]);
            totalHeadMovement += abs(sortedRequests[i] - head);
            head = sortedRequests[i];
        }
        for (i = pos; i < n; i++) {
            printf(" -> %d", sortedRequests[i]);
            totalHeadMovement += abs(sortedRequests[i] - head);
            head = sortedRequests[i];
        }
    }

    printf("\nTotal Head Movement (LOOK): %d\n", totalHeadMovement);
}

void clookDiskScheduling(int requests[], int n, int head, int direction) {
    int totalHeadMovement = 0;
    int sortedRequests[n];
    int i, j, pos = 0;

    // Copy requests for sorting
    for (i = 0; i < n; i++) {
        sortedRequests[i] = requests[i];
    }

    // Sort the requests
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (sortedRequests[i] > sortedRequests[j]) {
                int temp = sortedRequests[i];
                sortedRequests[i] = sortedRequests[j];
                sortedRequests[j] = temp;
            }
        }
    }

    // Find head position in sorted array
    for (i = 0; i < n; i++) {
        if (sortedRequests[i] >= head) {
            pos = i;
            break;
        }
    }

    printf("\nC-LOOK Head Movement Sequence: %d", head);

    if (direction == 1) {  // Move Right (forward direction)
        for (i = pos; i < n; i++) {
            printf(" -> %d", sortedRequests[i]);
            totalHeadMovement += abs(sortedRequests[i] - head);
            head = sortedRequests[i];
        }

        // Jump back to the start
        totalHeadMovement += abs(sortedRequests[0] - head);
        head = sortedRequests[0];
        printf(" -> %d", head);

        for (i = 1; i < pos; i++) {
            printf(" -> %d", sortedRequests[i]);
            totalHeadMovement += abs(sortedRequests[i] - head);
            head = sortedRequests[i];
        }

    } else {  // Move Left (backward direction)
        for (i = pos - 1; i >= 0; i--) {
            printf(" -> %d", sortedRequests[i]);
            totalHeadMovement += abs(sortedRequests[i] - head);
            head = sortedRequests[i];
        }

        // Jump to the last request
        totalHeadMovement += abs(sortedRequests[n - 1] - head);
        head = sortedRequests[n - 1];
        printf(" -> %d", head);

        for (i = n - 2; i >= pos; i--) {
            printf(" -> %d", sortedRequests[i]);
            totalHeadMovement += abs(sortedRequests[i] - head);
            head = sortedRequests[i];
        }
    }

    printf("\nTotal Head Movement (C-LOOK): %d\n", totalHeadMovement);
}

int main() {
    int n, head, direction;

    // Input section
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int requests[n];

    printf("Enter the disk request queue: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter direction (1 for right, 0 for left): ");
    scanf("%d", &direction);

    // Execute LOOK
    lookDiskScheduling(requests, n, head, direction);

    // Execute C-LOOK
    clookDiskScheduling(requests, n, head, direction);

    return 0;
}
