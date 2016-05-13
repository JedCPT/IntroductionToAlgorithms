#include "stdio.h"
#include "stdlib.h"


uint32_t recursive_fib(int n) {
	if (n <= 2) {
		return 1;
	}
	return recursive_fib(n - 1) + recursive_fib(n - 2);
}

uint32_t dp_fib(int n) {
	if (n==1) {
		return 1;
	}
	int* a = malloc(sizeof(uint32_t) * n);
	a[0] = 1;
	a[1] = 1;
	for (size_t i = 2; i < n; i++) {
		a[i] = a[i-1] + a[i-2];
	}
	uint32_t to_return = a[n-1];
	free(a);
	return to_return;
}
