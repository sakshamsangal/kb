#include <iostream>

using namespace std;
void print(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int getLoc(int arr[], int start, int size) {
	int loc = start, i;
	for (i = loc + 1; i < size; i++) {
		if (arr[loc] > arr[i]) {
			loc = i;
		}
	}
	return loc;
}
int main() {
	int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
	int size = 8, start = 0;

	while (start < size) {
		swap(arr[start], arr[getLoc(arr, start, size)]);
		start++;
	}

	print(arr, size);
	return 0;
}

