#include<iostream>
using namespace std;

void swap(int *first, int *second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}

void InsertionSort(int arr[], int size)
{
	int i, j, pivot;
	for (i = 1; i < size; ++i)
	{
		pivot = arr[i];
		for (j = i - 1; j >= 0; --j)
		{
			if (arr[j] > pivot)
				arr[j + 1] = arr[j];
			else
				break;
		}
		arr[j + 1] = pivot;
	}
}