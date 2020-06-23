#include <stdio.h>

int binarySearch2(int arr[], int n, int key) {
    int start = 0, end = n - 1;
    int i = (start + end) / 2;
    while (start != i && end != i) {
        if (arr[i] >= key) end = i;
        else start = i;

        i = (start + end) / 2;
        printf("%d %d %d\n", start, end, i);
    }

    for (i = start; i <= end; i++) {
        if (arr[i] >= key) break;
    }

    return i;
}

int main() {
    //            0  1  2  3  4  5  6  7  8  9
    int arr[] = { 1, 2, 2, 2, 4, 4, 5, 5, 5, 6 };
    int n = sizeof(arr) / sizeof(int);

    printf("%d\n", binarySearch2(arr, n, 5));

    return 0;
}
