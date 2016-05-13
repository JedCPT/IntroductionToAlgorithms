#include "stdlib.h"
#include "stdio.h"
#include "limits.h"

// This problem is from https://community.topcoder.com/stat?c=problem_statement&pm=2402&rd=5009

// Let dp[i] := the maximum donations of a sequence ending on neighbour i.
// Then dp[i] = max_{j < i-1}(dp[j]) + a[i]
void max_donations (int* a, size_t n) {
	int* dp = malloc(sizeof(int) * n);
	dp[0] = -a[0];
	
	int dp_max, max = 0;
	for (size_t i = 1; i < n; i++) {
		dp_max = 0;
		for (size_t j = 0; j < i - 1; j++) {
			dp_max = (abs(dp_max) < abs(dp[j])) ? dp[j] : dp_max; 
		}
		// Use the negative sign to indicate that the sequence includes a[0].
		dp[i] = (abs(dp_max) + a[i]) * ((dp_max < 0) ? -1: 1);
		// Keep a record of the max excluding dp[n-1] if it involves a sequence using a[0].
		if (max < abs(dp[i]) && (i != n - 1 || dp[i] > 0)) {
			max = abs(dp[i]);
		}
	}
	// Final check if dp[n-1] ends the optimal sequence.
	if (abs(dp[n-1] - a[0] > max))max = abs(dp[n-1] - a[0]);
	printf("%d\n", max);
	free(dp);
}

int main(void) {
	
	int a [] = { 10, 3, 2, 5, 7, 8 };
	max_donations(a, sizeof(a) / sizeof(int));
	
	int b [] = { 11, 15 };
	max_donations(b, sizeof(b) / sizeof(int));

	int c [] = { 7, 7, 7, 7, 7, 7, 7 };
	max_donations(c, sizeof(c) / sizeof(int));

	int d [] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
	max_donations(d, sizeof(d) / sizeof(int));

	int e [] = { 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,  
				 6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397,
				 52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 };
	max_donations(e, sizeof(e) / sizeof(int));
	return 0;
}
