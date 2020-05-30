#include <stdio.h>

typedef struct {
    int a;
    int b;
    int cost;
} DuongSat;

void merge(DuongSat arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    DuongSat L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1+ j];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i].cost <= R[j].cost) {
            arr[k++] = L[i++];
        } else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(DuongSat arr[], int l, int r){
    if (l >= r) return;
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
}

void makeNullSet(int set[], int n) {
    for (int i = 0; i < n; i++) {
        set[i] = -1;
    }
}

int find(int set[], int a) {
    if (set[a] < 0) return a;
    return find(set, set[a]);

}
int unionSet(int set[], int a, int b) {
    int pa = find(set, a);
    int pb = find(set, b);
    if (pa == pb) return 0;

    if (pb < pa) {
        set[pb] += set[pa];
        set[pa] = pb;
    } else {
        set[pa] += set[pb];
        set[pb] = pa;
    }

    return 1;
}

void findCost(const char* input) {
    freopen(input, "r", stdin);
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    DuongSat duongSat[m];
    int set[m + 1];

    makeNullSet(set, m + 1);

    for (int i = 0; i < m; i++) {
        scanf("%d", &duongSat[i].a);
        scanf("%d", &duongSat[i].b);
        scanf("%d", &duongSat[i].cost);
    }

    mergeSort(duongSat, 0, m - 1);

    long result = 0;
    for (int i = 0; i < m; i++) {
        if (unionSet(set, duongSat[i].a, duongSat[i].b)) {
            result += duongSat[i].cost;
        }
    }

    printf("%ld", result);

}

int main() {
    findCost("/home/riverflow/Desktop/Input/Kruskal/kruskal02.inp");
}
