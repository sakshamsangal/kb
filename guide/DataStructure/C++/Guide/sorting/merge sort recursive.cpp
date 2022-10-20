#include <iostream>
#define size 11

using namespace std;

int arr[] = {5, 4, 3, 2, 1, 4, 7, 8, 9, 2, 4};

void merge(int start, int middle, int end) {

	int left[size], right[size], i, j, k, x = 0, y = 0;

	for (i = start, j = 0; i <= middle; i++, j++) left[j] = arr[i];
	for (i = middle + 1, k = 0; i <= end; i++, k++) right[k] = arr[i];

	while(x < j && y < k) {
		if(left[x] < right[y]) arr[start++] = left[x++];
		else arr[start++] = right[y++];
	}

	while(x < j) arr[start++] = left[x++];
	while(y < k) arr[start++] = right[y++];
}

void mergeSort(int start, int end) {
	if(start >= end) return;

	int middle = start + (end - start) / 2;

	mergeSort(start, middle);
	mergeSort(middle + 1, end);

	merge(start, middle, end);
}

void print() {
	int i;
	for (i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	mergeSort(0, size - 1);
	print();
	return 0;
}
