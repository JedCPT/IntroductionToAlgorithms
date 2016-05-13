#include "string.h"
#include "stdio.h"
#include "stdlib.h"


int find_prev(char* s, size_t k) {
	/*for (int i = k - 1; i >= 0; i--) {*/
		/*if (s[i] == s[k]) {*/
			/*[>printf("%d\n", i);<]*/
			/*return i;*/
		/*}*/
	/*}*/
	for (size_t i = 0; i < k; i++) {
		if (s[i] == s[k]) {
			return i;
		}
	}
	return -1;
}

int next_occurence(char* s, char target, size_t i) {
	while(1) {
		i++;
		if (s[i] == target) {
			return i;
		}
	}
}

int new_strip(size_t x_1, size_t x_2, int* mem) {
	for (size_t i = x_1 + 1; i < x_2; i++) {
		if (mem[x_1] > mem[i]) {
			return 1;
		}
	}
	return 0;
}

void min_strokes(char* s) {
	size_t len_s = strlen(s);
	int* mem = malloc(sizeof(int) * len_s);
	int p;
	int current_max = 0;
	for (size_t i = 0; i < len_s; i++) {
		/*p = find_prev(s, i);*/
		/*if (p == -1 || new_strip(p, i, mem)) {*/
			/*current_max++;*/
			/*mem[i] = current_max;*/
		/*}*/
		/*else {*/
			/*mem[i] = mem[p];*/
		/*}*/
		p = 0;
		while((p = next_occurence(s, s[i], p))) {
			if (p == i) {
				current_max++;
				mem[i] = current_max;
			}
			else if (!new_strip(p, i, mem)) {
				mem[i] = mem[p];
				break;
			}
		}
	}
	printf("%d\n", current_max);
}


int less_than(int* a, size_t n, int num) {
	for (size_t i = 0; i < n; i++) {
		if (a[i] <= num) {
			return 0;
		}
	}
	return 1;
}

void fun(char* str, size_t n) {
	int* mem = malloc(sizeof(int) * n);;
	mem[0] = 1;
	int total = 1;
	for (size_t i = 1; i < n; i++) {
		total++;
		mem[i] = total;
		
		for (size_t j = 0; j < i; j++) {
			if (str[j] == str[i] && 
				less_than(&mem[j+1], i - j - 1, mem[j]) && 
				mem[j] < mem[i]) {
					if (mem[i] == total) {
						total--;
					}
				   	mem[i] = mem[j];

			}
		}
		
	}
	for (size_t i = 0; i < n; i++) {
		printf("%d,", mem[i]);
	}
	printf("\n");
}

int main(void) {
	
	char a[] = "RGBGR";
	fun(a, strlen(a));
	

	char b[] = "RGRG";
	fun(b, strlen(b));

	char c[] = "ABACADA";
	fun(c, strlen(c));

	char e[] = "AABBCCDDCCBBAABBCCDD";
	fun(e, strlen(e));

	char d[] = "BECBBDDEEBABDCADEAAEABCACBDBEECDEDEACACCBEDABEDADD";
	fun(d, strlen(d));

}
