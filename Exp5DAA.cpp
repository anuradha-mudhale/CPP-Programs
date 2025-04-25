#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;


int compare(const void *a, const void *b) {
    return ((Interval *)a)->end - ((Interval *)b)->end;
}

void intervalScheduling(Interval intervals[], int n) {
    
    qsort(intervals, n, sizeof(Interval), compare);

    printf("Selected intervals:\n");


    int last_end_time = intervals[0].end;
    printf("(%d, %d)\n", intervals[0].start, intervals[0].end);


    for (int i = 1; i < n; i++) {
        if (intervals[i].start >= last_end_time) {
            printf("(%d, %d)\n", intervals[i].start, intervals[i].end);
            last_end_time = intervals[i].end;
        }
    }
}


int main() {
    Interval intervals[] = {{1, 3}, {2, 5}, {4, 6}, {6, 8}, {5, 7}};
    int n = sizeof(intervals) / sizeof(intervals[0]);

    intervalScheduling(intervals, n);

    return 0;
}

