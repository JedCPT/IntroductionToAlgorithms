/*
Author: Jedda Boyle
*/

#include "stdlib.h"
#include "string.h"

// Merge values into a sorted array, assuming that the
// values to left and right of the middle point are sorted.
void merge(int *arr, int middle, size_t len)
{
    int *temp = (int *)malloc(sizeof(int) * len);
    for (size_t i = 0, l = 0, r = middle; i < len; ++i)
    {
        // temp[i] is the smaller of a[l] and a[r] or which ever still has values left.
        if ((arr[l] < arr[r] && l < middle) || r >= len)
            temp[i] = arr[l++];
        else
            temp[i] = arr[r++];
    }
    memcpy(arr, temp, sizeof(int) * len);
    free(temp);
}

void merge_sort(int *arr, size_t len)
{
    if (len > 1)
    {
        size_t middle = len / 2;
        size_t rh = len - middle;
        merge_sort(arr, middle);
        merge_sort(&arr[middle], rh);
        merge(arr, middle, len);
    }
}