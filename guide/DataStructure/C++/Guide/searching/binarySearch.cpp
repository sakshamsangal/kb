#include <iostream>

using namespace std;

int main() {
	int arr[] = { 10, 20, 30, 40, 50, 60, 70, 80 };
	int size = 8;

	int item = 68; // 5
	int start = 0, end = size - 1;
	int mid = (start + end) /  2;

	while(start < end) {
		if(item == arr[mid]) break;
		item < arr[mid] ? end = mid - 1 : start = mid + 1;
		mid = (start + end) / 2 ;
	}

	if (arr[mid] != item) mid = -1;
	cout << mid << " ";

	return 0;
}

