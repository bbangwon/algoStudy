#include "rotate.h"

void right_rotate(int arr[], int s, int t)
{
	int tmp = arr[t];
	for (int n = t; n > s; n--)
	{
		arr[n] = arr[n - 1];
	}
	arr[s] = tmp;
}

void left_rotate(int arr[], int s, int t)
{
	int tmp = arr[s];
	for (int n = s; n < t; n++)
	{
		arr[n] = arr[n + 1];
	}
	arr[t] = tmp;
}

void right_rotate_k(int arr[], int s, int t, int k)
{
	int distance = t - s + 1;
	int addvalue = distance - (k % distance);
	int *arr2 = new int[distance];
	int *arr3 = new int[distance];

	for (int i = 0; i < distance; i++)
	{
		arr2[i] = (i + addvalue) % distance;
		arr3[i] = arr[i + s];
	}

	for (int i = 0; i < distance; i++)
		arr[i + s] = arr3[arr2[i]];

	delete arr3;
	delete arr2;
}