#include "math.h"

#define T int

typedef struct map map;

typedef struct {
	int hash;
	int key;
	T value;
} map_entry;

struct map {
	int used;
	map_entry* table;
	size_t table_length;
};


int int_prehash(int i) {
	return i;
}

int hash(int key, size_t m) {
	//return key % n;
	return (key * (key * 3)) % m;
}

//map_entry* new_map_entry(T value, int key, int hash) {
	//map_entry* e = (map_entry*) malloc(sizeof(map_entry));
	//e->value = value;
	//e->key = key;
	//e->hash = 0;
	//return e;
//}
//void new_map(map* m) {
	//m->used = 0;
	//m->table_length = 16;
	//map_entry* table = (map_entry*) malloc(sizeof(map_entry) * m->table_length);
//}

int try_next(int index, int m) {
	return (index + 1) % m;
}

void rehash(map* m) {
	int s = m->table_length * 4;
	
	return;
}
//float get_alpha(map* m) {
	//return m->used / m->table_length;
//}
//void h_insert(map* m,int key, T value) {
	//int h = hash(int_prehash(key);
	//map_entry* e = new_map_entry(value, key, h);
	//m->table[h] = e;
	//m->used++;

	//if (get_alpha(m) >= 0.75) {
		//resize()
	//}

	
//}
