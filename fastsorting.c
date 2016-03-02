#include "stdlib.h"
#include "bin.h"
#define K 10000


// TODO need to implement radix sort.



void count_sort(int * array, int k, int length) {
	int * count_array = malloc(sizeof(int) * k);
	for (size_t i = 0; i < k; i++) {
		count_array[i] = 0;	
	}
	for (size_t i = 0; i <length; i++) {
		count_array[array[i]]++;
	}
	for (size_t i = 0, count = 0; i < k; i++) {
		for (size_t j = 0; j < count_array[i]; j++) {
			array[count] = i;
			count++;
		}
	}
	free(count_array);
}

int mm(const void * x, const void * y) {
	int a = *((int*)x);
	int b = *((int*)y);
	if (a == b) {
		return 0;	
	}
	if (a < b ) {
		return -1;
	}
	return 1;
}

int main(void) {
	size_t length = 100;
	int * a = malloc(sizeof(int) * length);
	genRandomArray(a, length, K);
	printArray(a, length);
	count_sort(a, K, length);
	printf("\n");
	/*qsort(a, length, sizeof(int), mm);*/
	printArray(a, length);
	return 0;
}
