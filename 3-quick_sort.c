#include "sort.h"

/**
 * lomuto_partition - selects a pivot and sort it using the lomuto scheme
 *
 * @array: array to parition
 * @lo: lowest index in the array
 * @hi: highest index in the array
 * @size: size of the array
 *
 * Return: the pivot after being paritioned
 */
int lomuto_partition(int *array, int lo, int hi, size_t size)
{
int pivot = array[hi], i = lo, j = lo, temp = 0;

if (lo >= hi || lo < 0)
return (-1);

for (; j < hi; j++)
{
if (array[j] < pivot)
{
if (i < j)
{
temp = array[i];
array[i] = array[j];
array[j] = temp;
print_array(array, size);
}
i += 1;
}
}

if (array[i] > pivot)
{
temp = array[i];
array[i] = array[hi];
array[hi] = temp;
print_array(array, size);
}
return (i);
}

/**
 * quick_sort_rec -  the recursive utility of the quick sort function
 *
 * @array: array to sort
 * @lo: lowest index in the array
 * @hi: highest index in the array
 * @size: the size of the array
 *
 * Return: void
 */
void quick_sort_rec(int *array, int lo, int hi, size_t size)
{
int p = -1;

if (lo >= hi || lo < 0)
return;

p = lomuto_partition(array, lo, hi, size);
if (p == -1)
return;

quick_sort_rec(array, lo, p - 1, size);
quick_sort_rec(array, p + 1, hi, size);
}

/**
 * quick_sort - sorts an array of integers using the quick sort algorithm
 *
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
if (size <= 0)
return;

quick_sort_rec(array, 0, size - 1, size);
}
