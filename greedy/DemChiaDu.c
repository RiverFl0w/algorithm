#include <stdio.h>

void countOperations(const char* input) {
    freopen(input, "r", stdin);
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    long res = 0;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        int moded = a % k;
        if (a / k == 0) {
            res += k - moded;
        } else res += moded > k / 2 ? k - moded : moded;
    }
    printf("%ld", res);
}

int main() {
    countOperations("/home/riverflow/Desktop/Input/UC/uc05New.inp");
}
