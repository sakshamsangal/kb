#include <iostream>

using namespace std;
void print(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
	int size = 8, i, item, end;
	i = 1;
	while (i < size) {
		item = arr[i];
		end = i - 1;
		while (arr[end] > item && end > -1) {
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = item;
		i++;
	}

	print(arr, size);
	return 0;
}

