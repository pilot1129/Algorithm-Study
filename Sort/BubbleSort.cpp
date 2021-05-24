#include<iostream>
using namespace std;

void swap(int *first, int *second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}

void BubbleSort(int arr[], int size)
{
	int i, j;

	for (i = 0; i < size; ++i)
	{
		for (j = 0; j < size - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}
