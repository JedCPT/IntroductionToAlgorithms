/*
Author: Jedda Boyle
*/

#include "stdlib.h"

#ifndef SWAP
#define SWAP
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
#endif

void insertion_sort(int *arr, size_t len)
{
    for (size_t i = 1; i < len; ++i)
    {
        // Assume arr[0..i-1] is sorted.
        // Swap arr[i] into correct place.
        for (size_t j = i; j >= 1; j--)
        {
            if (arr[j - 1] < arr[j])
                break;
            swap(&arr[j], &arr[j - 1]);
        }
    }
}