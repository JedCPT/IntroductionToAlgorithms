// Something to say.

#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include "stdlib.h"

#ifndef T
#define T int
#endif

#define CHECK_BOUNDS(index) if (index >= v->length) {\
								perror("ERROR: Vector index out of bounds.");\
								exit(EXIT_FAILURE);\
							}

typedef struct Vector Vector;
typedef T (*Func) (T a);

struct Vector {
	size_t array_length;
	size_t length;
	T * array;
};

void v_init(Vector * v, size_t init_array_length);

void v_add(Vector * v, T value);

T v_get(Vector * v, size_t index);

void v_replace(Vector * v, T value, size_t index);

//void v_swap(Vector * v, size_t a, size_t b);

void v_delete(Vector * v, size_t index);

void v_foreach(Vector * v, Func func);

void v_free(Vector * v);
	
#endif
