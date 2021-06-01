#include<iostream>
using namespace std;

int SequentialSearch(int arr[], int size, int findnum)
{
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == findnum)
			return i;
		else if (arr[i] > findnum)
			return -1;
	}
	return -1;
}