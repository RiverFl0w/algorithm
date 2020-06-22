// not accurate
#include <stdio.h>
#include <stdlib.h>

int max_sequence(int arr[], int n) {
    int result = -1;
    for (int i = 1; i <= n; i++) {
        int count = 1;
        int current = arr[i];
        for (int j = i + 1; j <= n; j++) {
            if (current < arr[j]) {
                current = arr[j];
                count++;
            }
        }

        if (result < count) {
            result = count;
        }
    }

    return result;
}

int main() {
    srand(1234);

    int n = 1000;
    int A[1003];
    for (int i = 1; i <= n; i++) {
        A[i] = rand()%2000 - 1000;
    }

    printf("%d", max_sequence(A, n));
    // expect 58 but got 14

    return 0;
}
