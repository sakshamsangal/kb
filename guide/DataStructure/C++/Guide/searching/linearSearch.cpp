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
	int size = 8, i;

	int item = 66; // 5
	for (i = 0; i < size; i ++) {
		if(arr[i] == item) break;
	}
	if(!(i < size)) i = -1;
	cout << i << endl;

	return 0;
}

