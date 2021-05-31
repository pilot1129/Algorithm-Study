#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int findnum)
{
	int start = 0;
	int finish = size - 1;
	int middle;
	while (start <= finish)
	{
		middle = (start + finish) / 2;
		if (arr[middle] == findnum)
			return middle;
		else if (arr[middle] > findnum)
			finish = middle - 1;
		else
			start = middle + 1;
	}
	return -1;
}