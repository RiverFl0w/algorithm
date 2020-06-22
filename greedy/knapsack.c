#include <stdio.h>

typedef struct {
    int weight;
    int value;
} Thing;

void merge(Thing arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Thing L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1+ j];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if ((float)L[i].value / L[i].weight >= (float)R[j].value / R[j].weight) {
            arr[k++] = L[i++];
        } else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(Thing arr[], int l, int r){
    if (l >= r) return;
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
}

int main() {
    freopen("/home/riverflow/Desktop/Input/Knapsack/knapsack04.inp", "r", stdin);

    int n, w;
    scanf("%d", &n);
    scanf("%d", &w);

    Thing things[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &things[i].weight);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &things[i].value);
    }

    mergeSort(things, 0, n - 1);

    int remain = w;
    double value = 0;
    for (int i = 0; i < n && remain != 0; i++) {
        if (things[i].weight > remain) {
            value += (double)remain * things[i].value / things[i].weight;
            break;
        }

        value += things[i].value;
        remain -= things[i].weight;
    }

    printf("%.4f\n", value);

    return 0;
}
