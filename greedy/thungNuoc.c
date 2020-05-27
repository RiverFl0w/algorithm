#include <stdio.h>

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1+ j];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            arr[k++] = L[i++];
        } else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r){
    if (l >= r) return;
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
}

void solve(const char* inputFile) {
    freopen(inputFile, "r", stdin);
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int n, x;
        scanf("%d%d", &n, &x);

        int bottles[n];
        for (int j = 0; j < n; j++) {
            scanf("%d", &bottles[j]);
        }

        mergeSort(bottles, 0, n - 1);

        long acc = 0;
        int result = 0;
        for (int j = 0; acc + (long)bottles[j] <= x && j < n; j++) {
            acc += (long)bottles[j];
            result++;
        }

        printf("%d\n", result);
    }
}

int main() {
    solve("./greedy/input");
    return 0;
}
