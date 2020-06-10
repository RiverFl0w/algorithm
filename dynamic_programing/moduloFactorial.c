#include <stdio.h>
#define NUM 1000000007

int main() {
    int t;
    scanf("%d", &t);

    int arr[t];

    int max = 0;
    for (int i = 0; i < t; i++) {
        scanf("%d", &arr[i]);
        if (max < arr[i]) {
            max = arr[i];
        }
    }

    long results[max + 1];
    results[0] = 1;

    long acc = 1;
    for (int i = 1; i <= max; i++) {
        acc = (acc * i) % NUM;
        results[i] = acc;
    }

    for(int i = 0; i < t; i++) {
        printf("%ld\n", results[arr[i]]);
    }

    return 0;
}
