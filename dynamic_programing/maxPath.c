#include <stdio.h>
#define MIN -2147483647
#define COL 502

void makeMaxPath(int matrix[][COL], int result[][COL], int m, int n, int x, int y, int prev) {
    int newValue = prev + matrix[x][y];
    if (result[x][y] < newValue) {
        result[x][y] = newValue;
    } else return;

    if (y + 1 < n) {
        makeMaxPath(matrix, result, m, n, x, y + 1, newValue);
    }
    if (x + 1 < m) {
        makeMaxPath(matrix, result, m, n, x + 1, y, newValue);
    }
    if (x + 1 < m && y + 1 < n) {
        makeMaxPath(matrix, result, m, n, x + 1, y + 1, newValue);
    }
}

int max(int a, int b, int c) {
  if (a > b && a > c) return a;
  if (b > a && b > c) return b;
  return c;
}


int main() {
    int m, n;
    freopen("./input", "r", stdin);
    scanf("%d%d", &m, &n);

    int matrix[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int result[m][n];
    result[0][0] = matrix[0][0];

    for (int i = 1; i < m; i++) {
        result[i][0] = result[i - 1][0] + matrix[i][0];
    }

    for (int i = 1; i < n; i++) {
        result[0][i] = result[0][i - 1] + matrix[0][i];
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            int top = result[i - 1][j];
            int left = result[i][j - 1];
            int topLeft = result[i - 1][j - 1];


            result[i][j] = max(top, left, topLeft) + matrix[i][j];
        }
    }

    printf("%d", result[m - 1][n - 1]);
    return 0;
}
