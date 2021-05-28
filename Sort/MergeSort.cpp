#include<iostream>
using namespace std;

void Merge(int arr[], int left, int mid, int right)
{
	int* result = new int[right - left + 1];
	int start = left;
	int middle = mid + 1;
	int pivot = 0;
	while (start <= mid && middle <= right)
	{
		if (arr[start] <= arr[middle])
			result[pivot++] = arr[start++];
		else
			result[pivot++] = arr[middle++];
	}
	while (start <= mid)
		result[pivot++] = arr[start++];
	while (middle <= right)
		result[pivot++] = arr[middle++];
	pivot = 0;
	for (int i = left; i <= right; ++i)
		arr[i] = result[pivot++];
	delete result;
}

void MergeSort_Recursive(int arr[], int left, int right)
{
	int mid = (left + right) / 2;
	if (left < right)
	{
		MergeSort_Recursive(arr, left, mid);
		MergeSort_Recursive(arr, mid+1, right);
		Merge(arr, left, mid, right);
	}
}

void MergeSort_NonRecursive(int arr[], int n)
{
	int size = 1;
	int low, mid, high;
	while (size <= n)
	{
		low = 0;
		while (low + size <= n)
		{
			mid = low + size - 1;
			high = mid + size;
			if (high >= n)
				high = n - 1;
			Merge(arr, low, mid, high);
			low = high + 1;
		}
		size *= 2;
	}
}