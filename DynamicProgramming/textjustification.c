#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "time.h"
#include "limits.h"

// Define these as as global variable just so that they don't have to be passed as arguments 
// to each function. 
extern const int max_line_length = 10;
extern const int n_words = 11;
int word_sizes [n_words] = {5,1,4,2,5,3,1,6,2,1,1};
int mem [n_words] = {0};
int b [n_words] = {0};

int cost(int i, int j) {
	int total = 0;
	for (size_t k = i; k <= j; k++) {
		total += word_sizes[k];
	}
	return total <= max_line_length ? max_line_length - total : 10000;
}

int min_cost(int i) {
	int min_ = cost(i, n_words - 1);
	int temp;
	int min_k = i;
	for (size_t k = i + 1; k < n_words; k++) {
		temp = mem[k] + cost(i, k - 1);
		[>min_ = (temp < min_) ? temp : min_; <]
		if (temp < min_) {
			min_ = temp;
			min_k = k + 1;
		}
	}
	b[i] = min_k;
	return min_;
}



int dp (void) {
	[>mem[n_words - 1] = max_line_length - word_sizes[n_words - 1];<]
	for (int i = n_words - 1; i >= 0 ; i--) {
		mem[i] = min_cost(i);
	}
	printf("%d\n", mem[0]);
	return 0;
}


int main(void) {
	dp();
	return 0;
}









