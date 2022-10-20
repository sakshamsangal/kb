#include <iostream>
#define size 11

using namespace std;

int arr[] = {5, 4, 3, 2, 1, 4, 7, 8, 9, 2, 4};

int partition(int start, int end) {
	int pivot = arr[end], i;
	int pi = start;
	for (i = start; i < end; ++i) {
		if(arr[i] < pivot) {
			swap(arr[i], arr[pi]);
			pi++;
		}
	}
	swap(arr[pi], arr[end]);
	return pi;

}

void quickSort(int start, int end) {
	if(start >= end) return;

	// get the pivot index
	int pi = partition(start, end);

	quickSort(start, pi - 1);
	quickSort(pi + 1, end);

}
void print() {
	int i;
	for (i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	quickSort(0, size - 1);
	print();
	return 0;
}
