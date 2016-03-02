
#include "stdlib.h"
#include "bin.h"

#define L(x) (2 * x) + 1 // Return index of left child
#define R(x) L(x) + 1 // Return index of right child
#define LCHILD(x) &heap->data[L(x)] // Return pointer to left child
#define RCHILD(x) &heap->data[R(x)] // Return pointer to right child

typedef struct {
	int * data;
	size_t length;
} Heap;

// Enforce the heap property at root assuming the sub tree root at each child is a heap.
void heapify (Heap * heap, size_t root) {
	if (root >= heap->length / 2) { // Check if root is a leaf.
		return;
	}
	int * root_ptr = &heap->data[root];
	// smallest points to the smallest element from the root and its children. 
	int * smallest = (R(root) < heap->length) ? 
					 ptrMin(root_ptr, ptrMin(LCHILD(root), RCHILD(root))): // ptrMin return pointer to the smaller value.
					 ptrMin(root_ptr, LCHILD(root));
	if (smallest != root_ptr) {
		swap(smallest, root_ptr);
		smallest == LCHILD(root) ? heapify(heap, L(root)) : heapify(heap, R(root));
	}
}

// Take a heap and convert it into a min heap.
void buildMinHeap (Heap * heap) {
	for (int i = heap->length / 2; i >= 0; --i) {
		heapify(heap, i);
	}
}

int popHeap (Heap * heap ) {
	swap(&heap->data[0], &heap->data[heap->length - 1]);;
	heap->length--;
	heapify(heap, 0);
	return heap->data[heap->length];
}

void heapSort(int * array, size_t length) {
	int * array_copy = malloc(sizeof(int) * length);
	for (size_t i = 0; i < length; ++i) {
		array_copy[i] = array[i];
	}
	Heap heap = {array_copy, length};
	buildMinHeap(&heap);
	for (size_t i = 0; i < length; ++i)  {;
		array[i] = popHeap(&heap);
	}
	free(array_copy);
}


int main (void) {

	return 0;



}
