#include "vector.h"

void v_init(Vector * v, size_t init_array_length) {
	v->array = (T*) malloc(init_array_length * sizeof(T));
	v->array_length = init_array_length;
	v->length = 0;
}

void v_add(Vector * v, T value) {
	v->array[v->length++] = value;

	// Resize the underlying array.
	if (v->length == v->array_length) {
		v->array_length *= 2;
		v->array = (T*) realloc(v->array, v->array_length * sizeof(T));
		
	}
}
	
T v_get(Vector * v, size_t index) {
	CHECK_BOUNDS(index);
	return v->array[index];
}

void v_replace(Vector * v, T value, size_t index) {
	CHECK_BOUNDS(index);
	v->array[index] = value;
}

/*void v_swap(Vector * v, size_t a, size_t b) {*/
	/*CHECK_BOUNDS(a);*/
	/*CHECK_BOUNDS(b);*/
	/*T temp = v_get(v, a);*/
	/*v_replace(v, v_get(v, b), a);*/
	/*v_replace(v, temp, b);*/
/*}*/

void v_delete(Vector * v, size_t index) {
	CHECK_BOUNDS(index);
	for (size_t i = index; i < v->length - 1; i++) {
		v->array[i] = v->array[i+1];
	}

	// Resize the underlying array. 
	v->length--;
	if (v->length < v->array_length / 2) {
		v->array_length /= 2;
		v->array = (T*) realloc(v->array, v->array_length * sizeof(T));
	}
}

void v_foreach(Vector * v, Func func) {
	for (size_t i = 0; i < v->length; i++) {
		v->array[i] = func(v_get(v,i));
	}
}


void v_free(Vector * v) {
	free(v->array);
}





