#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int ranks[n];
    int maxRank = 0;
    for (int i = 0; i < n; i++) {
        int rank;
        scanf("%d", &rank);
        ranks[i] = rank;
        if (maxRank < rank) maxRank = rank;
    }

    int rankSet[maxRank + 1];
    for (int i = 0; i < maxRank + 1; i++) {
        rankSet[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        rankSet[ranks[i]]++;
    }

    int sum = 2;
    for (int i = 1; i <= maxRank - 2; i++) {
        sum += rankSet[i + 2] * i;
    }

    if (rankSet[1] == sum) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}
