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
