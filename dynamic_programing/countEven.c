#include <stdio.h>
#include <string.h>

int isEven(char c) {
	return c % 2 == 0 ? 1 : 0;
}

int main() {
	char string[20000];
	scanf("%s", string);
	
	int n = (int)strlen(string);
	int mem[n];
	int res = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (isEven(string[i])) {
			res++;
		}
		
		mem[i] = res;
	}
	
	for (int i = 0; i < n; i++) {
		printf("%d ", mem[i]);
	}
	
	return 0;
}
