#include <stdio.h>

void findBoundingBox(const char* input) {
    freopen(input, "r", stdin);

    int n;
    scanf("%d", &n);
    long x[n], y[n];
    for (int i = 0; i < n; i++) {
        scanf("%ld%ld", &x[i], &y[i]);
    }

    long bx = x[0], by = y[0], mx = x[0], my = y[0];
    for (int i = 1; i <n; i++) {
        if (bx < x[i]) bx = x[i];
        if (mx > x[i]) mx = x[i];
        if (by < y[i]) by = y[i];
        if (my > y[i]) my = y[i];
    }

    long a;
    if (bx - mx > by - my) a = bx - mx;
    else a = by - my;

    printf("%ld", a * a);
}

int main() {
    findBoundingBox("/home/riverflow/...");
    return 0;
}
