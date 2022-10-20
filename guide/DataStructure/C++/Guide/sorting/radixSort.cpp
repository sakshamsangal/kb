#include <algorithm>
#include <iostream>
#include <vector>
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
	int temp[size];
	int m = *max_element(arr, arr + size);
	int place = 1;
	vector<pair<int, int> > v1;
	while (m > 0) {
		for (i = 0; i < size; i++) {
			temp[i] = (temp[i] / place) % 10;
		}

		for (i = 0; i < size; i++) {
			v1.push_back(make_pair(temp[i], arr[i]));
		}
		sort(v1. begin(), v1.end());
		for (i = 0; i < size; i ++) {
			arr[i] = v1[i].second;
		}
		m /= 10;
		place *= 10;
		v1.clear();
	}

	print(arr, size);
	return 0;
}

