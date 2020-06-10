#include <stdio.h>

typedef struct {
    int weight;
    int value;
} Thing;

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int ti = 0; ti < t; ti++) {
        int n;
        scanf("%d", &n);

        Thing things[n];
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &things[i].value, &things[i].weight);
        }

        int maxWeight = 0;

        int g;
        scanf("%d", &g);

        int spaces[g];
        for (int i = 0; i < g; i++) {
            scanf("%d", &spaces[i]);
            if (maxWeight < spaces[i]) {
                maxWeight = spaces[i];
            }
        }

        int matrix[n + 1][maxWeight + 1];
        for (int i = 0; i < maxWeight + 1; i++) {
            matrix[0][i] = 0;
        }
        for (int i = 0; i < n + 1; i++) {
            matrix[i][0] = 0;
        }

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < maxWeight + 1; j++) {
                int a = matrix[i - 1][j];
                int b = 0;

                if (j < things[i - 1].weight) {
                    matrix[i][j] = a;
                } else {
                    b = things[i - 1].value + matrix[i - 1][j - things[i - 1].weight];
                    matrix[i][j] = max(a, b);
                }

            }
        }

        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < maxWeight + 1; j++) {
                printf("%6d", matrix[i][j]);
            }
            printf("\n");
        }


        int totalValue = 0;
        for (int i = 0; i < g; i++) {
            totalValue += matrix[n][spaces[i]];
        }

        printf("%d\n", totalValue);

    }

    return 0;
}
