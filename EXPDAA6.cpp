#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char id;
    int deadline;
    int profit;
} Job;

int compare(const void *a, const void *b) {
    return ((Job *)b)->profit - ((Job *)a)->profit;
}


int min(int a, int b) {
    return (a < b) ? a : b;
}


void jobSequencing(Job jobs[], int n) {

    qsort(jobs, n, sizeof(Job), compare);

    
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    char jobSequence[maxDeadline];
    for (int i = 0; i < maxDeadline; i++) {
        jobSequence[i] = '\0'; 
    }

    int totalProfit = 0;

  
    for (int i = 0; i < n; i++) {
        for (int j = min(jobs[i].deadline - 1, maxDeadline - 1); j >= 0; j--) {
            if (jobSequence[j] == '\0') {
                jobSequence[j] = jobs[i].id; 
                totalProfit += jobs[i].profit; 
                break;
            }
        }
    }

    
    printf("Selected jobs for maximum profit: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (jobSequence[i] != '\0') {
            printf("%c ", jobSequence[i]);
        }
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}
int main() {
    
    Job jobs[] = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(jobs) / sizeof(jobs[0]);

    
    jobSequencing(jobs, n);

    return 0;
}

