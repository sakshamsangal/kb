#include <iostream>

using namespace std;
void print(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void merge(int arr[], int start, int q1[], int s1, int q2[], int s2) {
	int i = 0, j = 0;
	while (i < s1 && j < s2) {
		q1[i] < q2[j] ? arr[start++] = q1[i++] : arr[start++] = q2[j++];
	}
	while (i < s1) {
		arr[start++] = q1[i++];
	}
	while (j < s2) {
		arr[start++] = q2[j++];
	}
}
int main() {
	int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 11, 15, 13};
	int size = 13;
	int q1[size], q2[size];
	int a, b, c, i, j, k, queueSize = 1;
	while (queueSize < size) {
		a = 0;
		b = a + queueSize;
		c = b + queueSize;
		while (a < size && b < size) {
			j = 0;
			k = 0;
			for (i = a; i < b; i++) {
				q1[j++] = arr[i];
			}
			if (c >= size) {
				c = size;
			}
			for (i = b; i < c; i++) {
				q2[k++] = arr[i];
			}
			merge(arr, a, q1, j, q2, k);
			a = c;
			b = a + queueSize;
			c = b + queueSize;
		}
		queueSize *= 2;
	}

	print(arr, size);
	return 0;
}
