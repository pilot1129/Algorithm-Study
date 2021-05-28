#include<iostream>
using namespace std;

void ShellSort(int arr[], int size)
{
	int interval, i, j; // 간격(interval)
	int temp;
	for (interval = size / 2; interval > 0; interval /= 2) // 점차 간격을 반으로 줄여가면서 sort
	{
		for (i = interval; i < size; ++i)
		{
			temp = arr[i];
			for (j = i; j >= interval && arr[j - interval] > temp; j -= interval) // interval 만큼 간격을 가진 arr들 정렬
				arr[j] = arr[j - interval]; // 교체
			arr[j] = temp;
		}
	}
}