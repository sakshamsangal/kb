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
	int size = 8, i, item, end, gap = size / 2;

	while (gap > 0) {
		i = gap;
		while (i < size) {
			item = arr[i];
			end = i - gap;
			while (arr[end] > item && end > -1) {
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = item;
			i++;
		}
		gap /= 2;

	}

	print(arr, size);
	return 0;
}

