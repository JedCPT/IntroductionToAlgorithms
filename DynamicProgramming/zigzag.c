// A sequence of numbers is called a zig-zag sequence if the differences between successive 
// numbers strictly alternate between positive and negative. The first difference (if one exists) 
// may be either positive or negative. A sequence with fewer than two elements is trivially a 
// zig-zag sequence.
//
// For example, 1,7,4,9,2,5 is a zig-zag sequence because the differences (6,-3,5,-7,3) are 
// alternately positive and negative. In contrast, 1,4,7,2,5 and 1,7,4,5,5 are not zig-zag sequences, 
// the first because its first two differences are positive and the second because its last difference 
// is zero.
//
// Given a sequence of integers, sequence, return the length of the longest subsequence of sequence 
// that is a zig-zag sequence. A subsequence is obtained by deleting some number of elements 
// (possibly zero) from the original sequence, leaving the remaining elements in their original order.

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

void zigzag (int a[], int n) {
	// The sign of m[i] determines if the next element of the array must be bigger or smaller.
	int* mem = malloc(sizeof(int) * n);
	memset(mem, 0, sizeof(int) * n);
	int max_, overall_max = 0;
	for (int i = n - 1; i >= 0; i--) {
		max_ = 0;
		for (size_t j = i + 1; j < n; j++) {
			// Check if a[i] can follow a[j] in the sequence. 
			// Then check if it is the longest of such sequences.
			if ( mem[j] < 0 && a[i] > a[j] && max_ < abs(mem[j]) ) {
				mem[i] = -1 * (mem[j] - 1);
				max_ = abs(mem[j]);
			} 
			else if ( mem[j] > 0 && a[i] < a[j] && max_ < abs(mem[j]) ) {
				mem[i] = -1 * (mem[j] + 1);
				max_ = abs(mem[j]);
			}
			// When i == n - 2 then the second last element makes a sequence with the last element.
			// The sequence must be of length 1 but we must determine the sign.
			else if ( mem[j] == 0 && i == n - 2 ) {
				mem[i] = (a[i] < a[j]) ? -1: 1;
			}
		}
		overall_max = (overall_max < abs(mem[i])) ? abs(mem[i]) : overall_max;
	}
	printf("%d\n", overall_max + 1);
}

int main(void) {
	int a [] = { 1, 7, 4, 9, 2, 5 };
	int n_a = sizeof(a) / sizeof(int);
	zigzag(a, n_a);

	int b [] = { 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 };
	int n_b = sizeof(b) / sizeof(int);
	zigzag(b, n_b);
	
	int c [] = { 44 };
	int n_c = sizeof(c) / sizeof(int);
	zigzag(c, n_c);


	int d [] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int n_d = sizeof(d) / sizeof(int);
	zigzag(d, n_d);

	int e [] = { 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 };
	int n_e = sizeof(e) / sizeof(int);
	zigzag(e, n_e);

	
	int f [] = { 374, 40, 854, 203, 203, 156, 362, 279, 812, 955, 
	600, 947, 978, 46, 100, 953, 670, 862, 568, 188, 
	67, 669, 810, 704, 52, 861, 49, 640, 370, 908, 
	477, 245, 413, 109, 659, 401, 483, 308, 609, 120, 
	249, 22, 176, 279, 23, 22, 617, 462, 459, 244 };
	int n_f = sizeof(f) / sizeof(int);
	zigzag(f, n_f);

	return 0;
}
