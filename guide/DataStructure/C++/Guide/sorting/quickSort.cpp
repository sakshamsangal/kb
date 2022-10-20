#include <iostream>

using namespace std;
int partition(int arr[], int start, int end) {
	int pivot = start;
	bool left = true;
	while (true) {
		if (left) {
			if (arr[pivot] < arr[end]) {
				end--;
			} else if (arr[pivot] > arr[end]) {
				swap(arr[pivot], arr[end]);
				start = pivot + 1;
				pivot = end;
				left = false;
			} else {
				return pivot;
			}
		} else {
			if (arr[start] < arr[pivot]) {
				start++;
			} else if (arr[start] > arr[pivot]) {
				swap(arr[start], arr[pivot]);
				end = pivot - 1;
				pivot = start;
				left = true;
			} else {
				return pivot;
			}
		}
	}
}
void print(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = { 2, 3, 1, 5, 4, 45, 23 };
	int size = 7;
	int lowerStack[size];
	int upperStack[size];
	int start = 0;
	int end = size - 1;
	int top = 0;
	lowerStack[top] = 0;
	upperStack[top] = end;

	while (top > -1) {
		start = lowerStack[top];
		end = upperStack[top];
		top--;

		int loc = partition(arr, start, end);
		if (start < loc - 1) {
			top++;
			lowerStack[top] = start;
			upperStack[top] = loc - 1;
		}
		if (loc + 1 < end) {
			top++;
			lowerStack[top] = loc + 1;
			upperStack[top] = end;
		}
	}
	print(arr, size);
	return 0;
}
