#include <stdio.h>

int main() {
    int m, n, q;
    scanf("%d%d", &m, &n);

    int matrix[m][n], result[m][n];
    for (int i= 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        int acc = 0;
        for (int j = 0; j < n; j++) {
            result[i][j] = acc + (i == 0 ? 0 : result[i - 1][j]) + matrix[i][j];
            acc += matrix[i][j];
        }
    }

    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int x, y;
        scanf("%d%d", &x, &y);

        printf("%d\n", result[x - 1][y - 1]);
    }

    return 0;
}
