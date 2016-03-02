

#include "stdlib.h"
#include "stdio.h"
#include "time.h"

#define LENGTH 100000000

struct point {
	int i, j;
};


int * genRandomArray(int length) {
	int * to_return = malloc(sizeof(int) * length);
	int i = 0;
	for (i = 0; i < length; ++i) {
		to_return[i] = rand();
	}
	return to_return;
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

// Determine wether a point in an array is a peak.
int isPeak (int * array, int pos, int length) {
	if (pos == 0 && array[0] >= array[1]) {
		return 1;
	}
	if (pos == length - 1 && array[length-1] >= array[length-2]) {
		return 1;
	}
	if (array[pos-1] <= array[pos] && array[pos+1] <= array[pos]) {
		return 1;
	}
	return 0;
}

// Determine wether a point in a 2D array is a peak.
int isPeak2D (int** array, int i, int j, int n, int m) {
	// Each if statement checks a condition that would prevent it froming a peak. 	
	if (!(i - 1 < 0 || array[i][j] >= array[i-1][j])) {
		return 0;
	}
	if (!(i + 1 == n || array[i][j] >= array[i+1][j])) {
		return 0;
	}
	if (!(j - 1 < 0 || array[i][j] >= array[i][j-1])) {
		return 0;
	}
	if (!(j + 1 == m || array[i][j] >= array[i][j+1])) {
		return 0;
	}
	return 1;
}


// Perform a linear search for the peak a of a 1d array.
int findPeak(int * array, int length) {
	int i;
	for (i = 1; i < length - 1; ++i) {
		if (array[i - 1] <= array[i] && array[i] >= array[i + 1]) {
			return i;
		}
	}
	// Peak not found so it must be at either the end of beginning of array.
	if (array[0] >= array[1]) {
		return 0;
	}
	return length - 1;
}

// Use binary search to find a peak of 1d array.
int findPeak2 (int * array, int length) {
	int middle = length / 2;

	if (middle + 1 < length &&  array[middle] < array[middle+1]) {
		return middle + findPeak2(&array[middle+1], length - middle - 1) + 1;
	}
	else if (middle > 0 && array[middle-1] > array[middle]) {
		return findPeak2(array, middle);
	}
	else {
		return middle;
	}
}

// Perform a linear search for a peak of a 2D array.
struct point findPeak2D(int ** array, int n, int m) {
	int i = rand() % n;
	int j = rand() % m;
	while (1) {
		if (array[i][j] < array[i+1][j]) {
			i = i + 1;
			continue;
		}
		if (array[i][j] < array[i-1][j]) {
			i = i - 1;
			continue;
		}
		if (array[i][j] < array[i][j+1]) {
			j = j + 1;
			continue;
		}
		if (array[i][j] < array[i][j-1]) {
			j = j - 1;
			continue;
		}
		else{
			struct point to_return = {i, j};
			return to_return;
		}
	}
}

// Return the index of an array's maximum value.
int indexMax (int * array, int length) {
	int i;
	int max = -1;
	int max_pos = -1;
	for (i = 0; i < length; ++i) {
		if (max < array[i]) {
			max = array[i];
			max_pos = i;
		}
	}
	return max_pos;
}

struct point findPeak2D2 (int ** array, int n, int m) {
	int middle = n / 2;
	int col = indexMax(array[middle], m);
	struct point result;
	if (middle + 1 < n && array[middle][col] < array[middle+1][col])	 {
		result = findPeak2D2(&array[middle+1], n - middle - 1, m);
		result.i = middle + result.i + 1;
		return result;
	}
	if (middle > 0 && array[middle][col] < array[middle-1][col]) {
		result = findPeak2D2(array, middle, m);
		return result;
	}
	else  {
		result.i = middle;
		result.j = col;
		return result;
	}
}



int main (int argc, char *argv[]) {
	srand(time(NULL));
	/*int length = 10000;*/
	
	/*int * array = genRandomArray(length);*/

	/*int ans = findPeak(array, length);*/
	
	/*if (!isPeak(array, ans, length)) {*/
		/*printf("Error\n");*/
	/*}*/
	
	/*int ** array2d = genRandomArray2D(length, length);*/
	
	
	/*struct point ans2d = findPeak2D2(array2d, length, length)	;*/
	
	/*if (!isPeak2D(array2d, ans2d.i, ans2d.j, length, length))  {*/
		/*printf("Error\n");*/
	/*}*/

	return 0;
	

}


















