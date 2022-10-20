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
	int size = 8, i, j;
	i = 0;
	while(i < size - 1) {
		j = 0;
		while(j < size - 1 - i) {
			if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
			j ++;
		}
		i ++;
	}
	print(arr, size);
	return 0;
}

