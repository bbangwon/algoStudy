#include "minmax.h"

int max(int x, int y)
{
	if (x > y)
		return x;
	return y;
}
int min(int x, int y)
{
	if (x < y)
		return x;
	return y;
}

int max_arr(int arr[], int arr_len)
{
	int maxa = arr[0];
	for (int i = 1; i < arr_len; i++)
	{
		if (maxa < arr[i])
			maxa = arr[i];
	}
	return maxa;
}

int min_arr(int arr[], int arr_len)
{
	int mina = arr[0];
	for (int i = 1; i < arr_len; i++)
	{
		if (mina > arr[i])
			mina = arr[i];
	}
	return mina;
}