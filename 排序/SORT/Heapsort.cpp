#include"Header.hpp"

void heapify(int arr[], int n, int i){
	int smallest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && arr[l] < arr[smallest])
		smallest = l;
	if (r < n && arr[r] < arr[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(arr[smallest], arr[i]);
		i = smallest;
		heapify(arr, n, i);
	}
}
void heapsort(int arr[], int n){
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}
