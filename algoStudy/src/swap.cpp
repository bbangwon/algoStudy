#include "swap.h"

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void swap_arr(int arr[], int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}