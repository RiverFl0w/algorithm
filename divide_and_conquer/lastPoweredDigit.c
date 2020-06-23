#include <stdio.h>

int lastPoweredDigit(int res, int x, int n) {
    if (n == 1) return x % 10;

    int redun = lastPoweredDigit(res, x, n / 2);

    return (redun * redun * (n % 2 == 1 ? x : 1)) % 10;
}

int main() {

    int x, n;
    scanf("%d%d", &x, &n);
    printf("%d\n", lastPoweredDigit(x, x, n));

    return 0;
}
