#include <stdio.h>
#include <stdlib.h>

void fcfsDiskScheduling(int requests[], int n, int head) {
    int totalHeadMovement = 0;
    printf("\nFCFS Disk Scheduling:");
    printf("\nDisk Request Sequence: ");
    
    for (int i = 0; i < n; i++) {
        printf("%d ", requests[i]);
    }

    printf("\nHead Movement Sequence: %d", head);
    
    for (int i = 0; i < n; i++) {
        totalHeadMovement += abs(requests[i] - head);
        head = requests[i];
        printf(" -> %d", head);
    }
    
    printf("\nTotal Head Movement: %d\n", totalHeadMovement);
}

int main() {
    int n, head, disk_size;

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


    // Execute FCFS
    fcfsDiskScheduling(requests, n, head);


    return 0;
}

