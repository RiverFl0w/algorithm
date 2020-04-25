#include <stdio.h>
#include <stdlib.h>
#define MAX 100001

int main() {
    freopen("./graph/input", "r", stdin);
    int testCase;
    scanf("%d", &testCase);
    for (int i = 0; i < testCase; i++) {
        int link, map[MAX];
        scanf("%d", &link);

        for (int i = 0; i < MAX; i++) {
            map[i] = 0;
        }

        int count = 0;
        for (int i = 0; i < link; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            if (map[a] == 0) {
                count++;
                map[a] = 1;
            }
            if (map[b] == 0) {
                count++;
                map[b] = 1;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}
