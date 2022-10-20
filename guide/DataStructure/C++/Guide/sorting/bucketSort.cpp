#include <iostream>
#include <vector>
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
	float arr[] = { 0.52, 0.51, 0.310, 0.12, 0.11, 0.34 };
	unsigned int size = 6, i, j;
	vector<float> bucket[10];

	for (i = 0; i < size; i++) {
		j = arr[i] * 10;
		bucket[j].push_back(arr[i]);
	}

	for (i = 0; i < size; i++) {
		sort(bucket[i].begin(), bucket[i].end());
		for (j = 0; j < bucket[i].size(); j ++) {
			cout << bucket[i].at(j) << " ";
		}
	}

	return 0;
}

