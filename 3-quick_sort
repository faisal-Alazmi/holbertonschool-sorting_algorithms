#include "sort.h"

/* Helper function to swap two elements */
static void swap(int *a, int *b, int *array, size_t size)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    print_array(array, size);
}

/* Lomuto partition scheme */
static int partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high], i = low - 1;
    int j;

    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            if (i != j)
                swap(&array[i], &array[j], array, size);
        }
    }
    if (i + 1 != high)
        swap(&array[i + 1], &array[high], array, size);
    return i + 1;
}

/* Recursive quicksort */
static void quick_sort_rec(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pi = partition(array, low, high, size);
        quick_sort_rec(array, low, pi - 1, size);
        quick_sort_rec(array, pi + 1, high, size);
    }
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: number of elements
 */
void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;
    quick_sort_rec(array, 0, size - 1, size);
}
