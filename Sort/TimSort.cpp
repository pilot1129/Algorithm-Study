#include<iostream>
#include<algorithm>
using namespace std;
const int CUT = 32; // 32, 64, 128...

void insertionSort(int arr[], int left, int right)
{
	for (int i = left + 1; i <= right; i++)
	{
		int pivot = arr[i];
		for (int j = i - 1; j >= left; --j)
		{
			if (arr[j] > pivot)
				arr[j + 1] = arr[j];
			else
				break;
		}
		arr[j + 1] = pivot;
	}
}

void merge(int arr[], int l, int m, int r)
{
	int len1 = m - l + 1, len2 = r - m;
	int* left = new int[len1];
	int* right = new int[len2];
	for (int i = 0; i < len1; i++)
		left[i] = arr[l + i];
	for (int i = 0; i < len2; i++)
		right[i] = arr[m + 1 + i];

	int i = 0;
	int j = 0;
	int k = l;

	while (i < len1 && j < len2)
	{
		if (left[i] <= right[j])
		{
			arr[k] = left[i];
			i++;
		}
		else
		{
			arr[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < len1)
	{
		arr[k] = left[i];
		k++;
		i++;
	}

	while (j < len2)
	{
		arr[k] = right[j];
		k++;
		j++;
	}
	delete left;
	delete right;
}

void timSort(int arr[], int n)
{
	for (int i = 0; i < n; i += CUT)
		insertionSort(arr, i, min((i + CUT - 1),
		(n - 1)));

	for (int size = CUT; size < n; size = 2 * size)
	{
		for (int left = 0; left < n; left += 2 * size)
		{
			int mid = left + size - 1;
			int right = min((left + 2 * size - 1), (n - 1));
			if (mid < right)
				merge(arr, left, mid, right);
		}
	}
}
