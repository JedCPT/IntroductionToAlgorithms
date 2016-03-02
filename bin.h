#include "stdio.h"
#include "stdlib.h"

void printArray2D(int ** array, int n, int m) {
    int i, j;
    for (i = 0; i < n; ++i ) {
        printf("\n");
        for (j= 0; j < m ; ++j ) {
            printf("%d,",array[i][j]);
        }
    }
}

void printArray (int * array, int length) {
    int i;
    for (i = 0; i < length; ++i) {
        printf("%d,",array[i]);
    }
}

void genRandomArray(int * array, size_t length, size_t maximum) {
    for (size_t i = 0; i < length; ++i) {
        array[i] = rand() % maximum;;
    }
}

int ** genRandomArray2D (int n, int m) {
    int ** to_return = malloc(sizeof(int*) * n);
    int i, j;
    for (i =0; i< n; ++i) {
	        to_return[i] = malloc(sizeof(int) * m);
	    }
    for (i = 0; i < n ; ++i )   {
	        for (j = 0; j < n; ++j) {
			            to_return[i][j] = rand();
			        }
	    }
    return to_return;
}

int compareArrays(int * array1, int * array2, int length) {
	int i;
	for (i = 0; i < length; ++i) {
		if (array1[i] != array2[i])	{
			return 0;
		}
	}
	return 1;
}


void swap(int *  a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int max(int a, int  b) {
	if( a < b) {
		return b;
	}
	return a;
}

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int isSorted(int * a, int length) {
	for (size_t i = 1; i < length; ++i) {
		if (a[i-1] > a[i]) { return 0; }
	}
	return 1;
}

int * ptrMin(int * a, int * b) {
	if (*a < *b) {
		return a;
	}
	return b;
}
