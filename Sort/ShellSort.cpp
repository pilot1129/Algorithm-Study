#include<iostream>
using namespace std;

void ShellSort(int arr[], int size)
{
	int interval, i, j; // ����(interval)
	int temp;
	for (interval = size / 2; interval > 0; interval /= 2) // ���� ������ ������ �ٿ����鼭 sort
	{
		for (i = interval; i < size; ++i)
		{
			temp = arr[i];
			for (j = i; j >= interval && arr[j - interval] > temp; j -= interval) // interval ��ŭ ������ ���� arr�� ����
				arr[j] = arr[j - interval]; // ��ü
			arr[j] = temp;
		}
	}
}