#include <stdio.h>

long C(int i, int j) {
    if (i == j || j == 0) return 1;
    return C(i, j - 1) * (i - j + 1) / j;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%ld ", C(i, j));
        }
        printf("\n");
    }

    return 0;
}
