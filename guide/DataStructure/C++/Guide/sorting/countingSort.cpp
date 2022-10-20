#include <iostream>
#include <algorithm>
using namespace std;
void print(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = { 6, 7, 6, 8, 2, 1, 4, 3 };
	int size = 8, i;
	int output[size];

	int rankSize = *max_element(arr, arr + size) + 1;
	int *rank = (int*) calloc(rankSize, 4);

	for (i = 0; i < size; i++) {
		rank[arr[i]]++;
	}
	for (i = 1; i < rankSize; i++) {
		rank[i] += rank[i - 1];
	}

	for (i = 0; i < size; i++) {
		output[rank[arr[i]] - 1] = arr[i];
		rank[arr[i]] --;
	}

	print(output, size);
	return 0;
}

