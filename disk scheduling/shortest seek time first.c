#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void sstfDiskScheduling(int requests[], int n, int head) {
    int totalHeadMovement = 0;
    int visited[n];
    int i, completed = 0;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nSSTF Disk Scheduling:");
    printf("\nHead Movement Sequence: %d", head);

    while (completed < n) {
        int min_distance = INT_MAX;
        int closest_index = -1;

        for (i = 0; i < n; i++) {
            if (!visited[i]) {
                int distance = abs(requests[i] - head);
                if (distance < min_distance) {
                    min_distance = distance;
                    closest_index = i;
                }
            }
        }

        visited[closest_index] = 1;
        totalHeadMovement += abs(requests[closest_index] - head);
        head = requests[closest_index];
        printf(" -> %d", head);
        completed++;
    }

    printf("\nTotal Head Movement: %d\n", totalHeadMovement);
}

int main() {
    int n, head;

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

    // Execute SSTF
    sstfDiskScheduling(requests, n, head);

    return 0;
}

