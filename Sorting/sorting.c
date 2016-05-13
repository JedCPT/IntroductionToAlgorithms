//#include "bin.h"
#include "stdlib.h"

void swap(int *  a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void insertionSort(int * array, int length) {
	size_t j;
	for (size_t i = 1; i < length; ++i) {
		j = i + 1;
		// The first condition makes sure j is not zero before accessing
		// array[j-1].
		while ( --j  && array[j] < array[j-1]) {
			swap(&array[j], &array[j-1]);
		}
	}
}

// Sort an array assuming the sub array on either side of the middle
// index is sorted. 
void merge (int * a, int middle, int length) {
	size_t i = 0;
	size_t j = middle;
	int * temp = malloc(sizeof(int) * length);
	for (size_t k = 0; k < length; ++k) {
			// If i >= middle then add remaining values from the second half.
			// Otherwise check if j still points to a valid location. 
			// Finally see if the value at the front of the left or right
			// hand side is smaller and then add that to the temp array.
			if ((j < length && a[j] < a[i]) || i >= middle ) {
			temp[k] = a[j];
			j++;
		}
		else {
			temp[k] = a[i];
			i++;
		}
	}
	for (size_t k = 0; k < length; ++k) {
			a[k] = temp[k];
	}
	free(temp);
}


void mergeSort (int * array, int length) {
	if (length > 1) {
		size_t middle = length / 2;
		size_t rh = length - middle;
		mergeSort(array, middle);
		mergeSort(&array[middle], rh);
		merge(array, middle, length);
	}
}

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


