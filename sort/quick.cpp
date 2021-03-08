#include <iostream>
using namespace std;
void quick_sort(int arr[], int size) {
	int pivot = arr[0];
	int cursor = 0;
	for (int i=1;i<size;i++) {
		if (pivot > arr[i]) {
			cursor++;
			swap(arr[cursor], arr[i]);	
		}
	}
	swap(arr[0], arr[cursor]);
	if (cursor > 0) quick_sort(arr, cursor);
	if (cursor+1 < size-1) quick_sort(arr+cursor+1, size-cursor-1);
}

int main() {
	int arr[] = {3, 7, 8, 1, 5, 9, 6, 10, 2, 4};
	int size = sizeof(arr)/sizeof(arr[0]);
	quick_sort(arr, size);
	for (int i=0;i<size;i++) cout<<arr[i]<<' ';
	cout<<'\n';
	return 0;
}