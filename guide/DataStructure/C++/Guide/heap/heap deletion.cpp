// 1. binary tree
// 2. complete tree 
// 3. if minHeap
//    1. parent is minimum from children
// 4. if maxHeap
//    1. parent is maximum from children


// minHeap deletion
// deleteKey()
//     decreaseKey()
//     extractMin()
//     minHeapify()
    
// decreaseKey(pos) replace node(pos) with -infinity and fix it 
// extractMin() 
//     root = last node
//     delete last node 
// minHeapify() fix root 
// getMin() return smallest element
#include <iostream>

using namespace std;

void print(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void maxHeapify(int arr[], int size) {
	int parent = 0;
	bool isDisturbed = true;
	while (isDisturbed) {
		int left = (2 * parent) + 1;
		int right = (2 * parent) + 2;

		int max = parent;
		if (left < size && arr[left] > arr[max]) {
			max = left;
		}
		if (right < size && arr[right] > arr[max]) {
			max = right;
		}

		if (arr[max] == arr[parent]) {
			isDisturbed = false;
		} else {
			swap(arr[parent], arr[max]);
			parent = max;
		}


	}

}
void deleteInMaxHeap(int arr[], int *size) {

	arr[0] = arr[*size - 1];
	*size = *size - 1;

	maxHeapify(arr, * size);

}

int main() {

	int *size = new int(5);
	int arr[] = { 10, 5, 3, 2, 4 };
	deleteInMaxHeap(arr, size);

	print(arr, *size);
	return 0;
}
// 5 4 3 2 
