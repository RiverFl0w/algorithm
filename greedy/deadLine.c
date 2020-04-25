#include <stdio.h>

typedef struct {
    int value;
    int deadline;
} Task;

void merge(Task arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Task L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1+ j];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i].value >= R[j].value) {
            arr[k++] = L[i++];
        } else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(Task arr[], int l, int r){
    if (l >= r) return;
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
}

// return -1 if don't have any timeSlot
int findTimeSlot(int timeline[], int deadline) {
    int timeSlot = deadline - 1;
    while (!timeline[timeSlot] && timeSlot >= 0) {
        timeSlot--;
    };
    return timeSlot;
}

int main() {
    int n;
    scanf("%d", &n);

    Task tasks[n];
    int longestDeadline = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &tasks[i].value);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &tasks[i].deadline);
        if (longestDeadline < tasks[i].deadline) {
            longestDeadline = tasks[i].deadline;
        }
    }
    // fill timeline with 1
    int timeline[longestDeadline];
    for (int i = 0; i < longestDeadline; i++) {
        timeline[i] = 1;
    }

    mergeSort(tasks, 0, n - 1);

    long maxValue = 0;
    for (int i = 0; i < n; i++) {
        int timeSlot = findTimeSlot(timeline, tasks[i].deadline);

        if (timeSlot >= 0) {
            maxValue += tasks[i].value;
            timeline[timeSlot] = 0;
        }
    }

    printf("%ld", maxValue);

    return 0;
}
