// 1. binary tree
// 2. complete tree 
// 3. if minHeap
//    1. parent is minimum from children
// 4. if maxHeap
//    1. parent is maximum from children

// minHeap insertion operation 
// insert() insert node at end and fix it if needed

// heap insertion
#include <iostream>

using namespace std;

void print(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void insertMaxHeap(int arr[], int *size, int item) {
	arr[*size] = item;

	// fix heap
	int child = *size;
	int parent = (child - 1) / 2;
	while (arr[child] > arr[parent]) {
		swap(arr[child], arr[parent]);
		child = parent;
		parent = (child - 1) / 2;
	}
	*size = *size + 1;
}

int main() {
	int *size = new int(5);
	int arr[] = { 10, 5, 3, 2, 4 };
	insertMaxHeap(arr, size, 15);
	print(arr, *size);
	return 0;
}



// 15 5 10 2 4 3 



// recursive

// #include <iostream>

// using namespace std;
// void print(int arr[], int size) {
// 	int i;
// 	for (i = 0; i < size; i++) {
// 		cout << arr[i] << " ";
// 	}
// 	cout << endl;
// }

// void fixLastInMaxHeap(int arr[], int parent, int child) {
// 	if (arr[parent] >= arr[child]) return;
// 	else{
// 		swap(arr[parent], arr[child]);
// 		fixLastInMaxHeap(arr, (parent - 1) / 2, parent);
// 	}
// }

// void insert(int arr[], int &size, int item) {
// 	arr[size] = item;
// 	fixLastInMaxHeap(arr, (size - 1) / 2, size);
// 	size ++;
// }

// int main() {
// 	int arr[] = { 10, 5, 3, 2, 4 }, size = 5;
// 	insert(arr, size, 15);
// 	print(arr, size);
// 	return 0;
// }







