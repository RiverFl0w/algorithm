#include <stdio.h>

typedef struct {
    int toy;
    int box;
} ToyBox;

void merge(ToyBox arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    ToyBox L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1+ j];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i].toy > R[j].toy) {
            arr[k++] = L[i++];
        } else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(ToyBox arr[], int l, int r){
    if (l >= r) return;
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
}

int main() {
    freopen("./greedy/input", "r", stdin);
    int m, n;
    scanf("%d%d", &n, &m);

    ToyBox toyBoxs[n];

    for (int i = 0; i < n; i++) {
        int toy, box;
        scanf("%d%d", &toy, &box);
        toyBoxs[i] = (ToyBox){ toy, box };
    }

    mergeSort(toyBoxs, 0, n - 1);

    int flag[m + 1];
    for (int i = 0; i < m + 1; i++) {
        flag[i] = 1;
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        if (flag[toyBoxs[i].box]) {
            result += toyBoxs[i].toy;
            flag[toyBoxs[i].box] = 0;
        }
    }

    printf("%d\n", result);

    return 0;
}
