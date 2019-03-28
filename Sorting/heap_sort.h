/*
Author: Jedda Boyle
*/

#include "stdlib.h"
#include "string.h"

#define L(x) (2 * x) + 1            // Return index of left child
#define R(x) L(x) + 1               // Return index of right child
#define LCHILD(x) &heap->data[L(x)] // Return pointer to left child
#define RCHILD(x) &heap->data[R(x)] // Return pointer to right child

typedef struct
{
    int *data;
    size_t len;
} Heap;

#ifndef SWAP
#define SWAP
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
#endif

// Return pointer to the smaller value.
int *ptr_min(int *a, int *b)
{
    return (*a < *b) ? a : b;
}

// Enforce the heap property at root assuming the sub tree root at each child is a heap.
void heapify(Heap *heap, size_t root)
{
    // Check if root is a leaf.
    if (root >= heap->len / 2)
    {
        return;
    }
    int *root_ptr = &heap->data[root];
    // smallest points to the smallest element from the root and its children.
    int *smallest = (R(root) < heap->len) ? ptr_min(root_ptr, ptr_min(LCHILD(root), RCHILD(root))) : ptr_min(root_ptr, LCHILD(root));
    if (smallest != root_ptr)
    {
        swap(smallest, root_ptr);
        smallest == LCHILD(root) ? heapify(heap, L(root)) : heapify(heap, R(root));
    }
}

// Take a heap and convert it into a min heap.
void build_min_heap(Heap *heap)
{
    for (int i = heap->len / 2; i >= 0; --i)
    {
        heapify(heap, i);
    }
}

int pop_heap(Heap *heap)
{
    swap(&heap->data[0], &heap->data[heap->len - 1]);
    heap->len--;
    heapify(heap, 0);
    return heap->data[heap->len];
}

void heap_sort(int *arr, size_t len)
{
    int *heap_data = (int *)malloc(sizeof(int) * len);
    memcpy(heap_data, arr, sizeof(int) * len);
    Heap heap = {heap_data, len};
    build_min_heap(&heap);
    for (size_t i = 0; i < len; ++i)
    {
        arr[i] = pop_heap(&heap);
    }
    free(heap_data);
}
