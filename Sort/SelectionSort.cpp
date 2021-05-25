#include<iostream>
using namespace std;

void swap(int *first, int *second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}


void SelectionSort(int arr[], int size)
{
	int i, j, min;
	for (i = 0; i < size; ++i)
	{
		min = i; // pivot
		for (j = i + 1; j < size; ++j)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}
		swap(arr[i], arr[min]);
	}
}