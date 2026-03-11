#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int profit;
    int deadline;
} Job;

int compare_jobs(const void *a, const void *b) {
    Job *j1 = (Job *)a;
    Job *j2 = (Job *)b;
    return j2->profit - j1->profit;
}

void schedule_jobs(Job jobs[], int n) {
    
    qsort(jobs, n, sizeof(Job), compare_jobs);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    int *slot = (int *)malloc((maxDeadline + 1) * sizeof(int));
    for (int i = 0; i <= maxDeadline; i++) slot[i] = -1;

    int totalProfit = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i; 
                totalProfit += jobs[i].profit;
                count++;
                break;
            }
        }
    }

    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i] != -1) {
            int jobIdx = slot[i];
            printf("Slot %d-%d: Job ID %d,Profit: %d\n", 
                    i-1, i, jobs[jobIdx].id, jobs[jobIdx].profit);
        }
    }
    printf("Total Jobs Scheduled: %d\n", count);
    printf("Maximum Profit: %d\n", totalProfit);

    free(slot);
}

int main() {
    int profits[]   = {36, 21, 28, 19, 21, 13, 28, 25, 18, 20, 27, 22, 14, 26};
    int deadlines[] = {5, 8, 3, 4, 4, 9, 12, 14, 2, 7, 5, 1, 6, 3};
    int n = sizeof(profits) / sizeof(profits[0]);

    Job jobs[n];
    for (int i = 0; i < n; i++) {
        jobs[i].id = i + 1;
        jobs[i].profit = profits[i];
        jobs[i].deadline = deadlines[i];
    }

    schedule_jobs(jobs, n);

    return 0;
}
/*
Time Complexity: O(nlog(n)), with worst time complexity being O(n^2).
This is because usually sorting is the dominant factor in time complexity, however
if max deadline is equal to the number of jobs, then the sequencing is actually the dominant factor
with O(n^2)
Space Complexity: O(m), where m is the maximum deadline, for storing each slot
This is a greedy based algorithm that involves first sorting the jobs based on the profit they have
and assigned them to each slot based on when their deadline is. If there is no possible slot, then 
the job is skipped(not included as part of the final answer).
*/