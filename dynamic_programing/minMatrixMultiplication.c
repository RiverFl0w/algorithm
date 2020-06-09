#include <stdio.h>
#define MAX 100
#define MAX_INT 214748364

int minMatrix(int arr[], int matrix[][MAX], int x, int y) {
	if (y - x < 0) return -1;
	if (y - x == 0) return 0;
	if (y - x == 1) return arr[x] * arr[x + 1] * arr[y + 1];
	
	int min = MAX_INT;
	for (int i = x; i < y; i++) {
		int each = matrix[x][i] + matrix[i + 1][y] + (arr[x] * arr[y + 1] * arr[i + 1]);
		if (min > each) {
			min = each;
		}
	}
	//printf("%d\n", min);
	
	return min;
}

int main() {
	int n;
	scanf("%d", &n);
	int matrix[n - 1][MAX];
	int arr[n + 1];
	for (int i = 0; i < n + 1; i++) {
	    scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n + 1; i++) {
	    printf("%d  ", arr[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			int res = minMatrix(arr, matrix, j, j + i);
			matrix[j][j + i] = res;
		}
	}
	
	printf("%d", matrix[0][n - 1]);

	
	return 0;
}
