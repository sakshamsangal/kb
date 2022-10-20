// for lower
// means lower + primary diaognal has value
// put 0 above primary diagonal

// vice versa for upper
#include <iostream>

using namespace std;

void printMatrix(int arr[][3], int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
int main() {
	int size = 3;
	int arr[][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };

	for (int i = 0; i < size; ++i) {
		for (int j = i + 1; j < size; ++j) {
			arr[i][j] = 0;
		}
	}
	printMatrix(arr, 3);
	return 0;
}
// lower
// 1 0 0 
// 4 5 0 
// 7 8 9 
#include <iostream>

using namespace std;

void printMatrix(int arr[][3], int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
int main() {
	int size = 3;
	int arr[][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < i; ++j) {
			arr[i][j] = 0;
		}
	}
	printMatrix(arr, 3);
	return 0;
}
// upper
// 1 2 3 
// 0 5 6 
// 0 0 9 
