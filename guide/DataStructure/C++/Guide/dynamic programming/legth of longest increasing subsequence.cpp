#include <iostream>
#include <algorithm>

using namespace std;

int size = 7;
int arr[] = {3, 4, 2, 8, 10, 5, 1};
int lis[7];


int * getMax() {

	for (int i = 0; i < size; ++i) {

		lis[i] = 1;
		for (int j = 0; j < i; ++j)
			if(arr[j] < arr[i]) lis[i] = max(lis[i], lis[j] + 1);


	}

	return max_element(lis, lis + size);
}

int main() {
	cout << * getMax();
	return 0;
}
