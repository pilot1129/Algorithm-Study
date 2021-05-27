void quicksort(int arr[], int start, int end)
{
	if (start >= end)
		return;
	int pivot = arr[(start + end) / 2]; // Pivot을 중앙으로 선택
	int left = start;
	int right = end;

	while (right >= left)
	{
		while (arr[left] < pivot)
			++left;
		while (arr[right] > pivot)
			--right;
		if (right >= left)
		{
			swap(arr[left], arr[right]);
			++left;
			--right;
		}
	}
	quicksort(arr,start,right);
	quicksort(arr,left, end);

}