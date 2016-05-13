#include <stdio.h>
#include <stdlib.h>


typedef struct {
	char *name;
	int weight;
	int value;
} item_t;

item_t items[] = {
    {"map",                      9,   150},
    {"compass",                 13,    35},
    {"water",                  153,   200},
    {"sandwich",                50,   160},
    {"glucose",                 15,    60},
    {"tin",                     68,    45},
    {"banana",                  27,    60},
    {"apple",                   39,    40},
    {"cheese",                  23,    30},
    {"beer",                    52,    10},
    {"suntan cream",            11,    70},
    {"camera",                  32,    30},
    {"T-shirt",                 24,    15},
    {"trousers",                48,    10},
    {"umbrella",                73,    40},
    {"waterproof trousers",     42,    70},
    {"waterproof overclothes",  43,    75},
    {"note-case",               22,    80},
    {"sunglasses",               7,    20},
    {"towel",                   18,    12},
    {"socks",                    4,    50},
    {"book",                    30,    10},
};

const int n = sizeof(items) / sizeof(item_t);
const int w = 400;
// Add an additional row of zeros for the edge case.
int mem[n + 1][w] = {0}; 
// For each i  j pair store wether or not it was included. If it was include store its value too.
// This is called parent pointer becaus this can be used to back track from the optimal i j pair.
int parent_pointer [n][w] = {0}; 


// Use the parent_pointer array to retrace steps taken to get to the optimal output. 
void back_track(int i, int j) {
	printf("%-22s %5d %5d\n", "totals:", j, mem[i][j]);
	while(i != n) {
		if (parent_pointer[i][j] != 0) {
			printf("%-22s %5d %5d\n", items[i].name, items[i].weight, items[i].value);
		}
		j = j - parent_pointer[i][j];
		i = i + 1;
	}
}


void knapsack() {
	int weight, value, max_i, max_j, max = -1;
	for (int i = n - 1; i >= 0 ; i--) {
		for (int j = w - 1; j >= 0; j--) {
			weight = items[i].weight;
			value = items[i].value;

			// Determine wether adding the item or not results in a higher total value.
			if (j - weight >= 0 && mem[i + 1][j] < mem[i + 1][j - weight] + value) {
				mem[i][j] = mem[i + 1][j - weight] + value;
				parent_pointer[i][j] = weight;
			} else  {
				mem[i][j] = mem[i + 1][j];
				parent_pointer[i][j] = 0;
			}

			// Store the position of the optimal value.
			if (max <= mem[i][j]) {
				max = mem[i][j];
				max_i = i;
				max_j = j;
			}
		}
	}
	back_track(max_i, max_j);

}


int main () {
	knapsack();
	return 0;
}
