#include <iostream>
# define vertex 5

using namespace std;

void printGraph(int arr[][vertex]) {
	cout << "  ";
	for (int i = 0; i < vertex; ++i) {
		cout << i << " ";
	}
	cout << endl;
	for (int i = 0; i < vertex; ++i) {
		cout << i << " ";
		for (int j = 0; j < vertex; ++j) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void connect(int arr[][vertex], int source, int destination) {
	arr[source][destination] = 1;
	arr[destination][source] = 1;
}

int main() {

	int arr[vertex][vertex];

	for (int i = 0; i < vertex; ++i) {
		for (int j = 0; j < vertex; ++j) {
			arr[i][j] = 0;
		}
	}

	connect(arr, 0, 1);
	connect(arr, 0, 4);
	connect(arr, 1, 2);
	connect(arr, 1, 3);
	connect(arr, 1, 4);
	connect(arr, 2, 3);
	connect(arr, 3, 4);

	printGraph(arr);
	return 0;
}


//   0 1 2 3 4 
// 0 0 1 0 0 1 
// 1 1 0 1 1 1 
// 2 0 1 0 1 0 
// 3 0 1 1 0 1 
// 4 1 1 0 1 0 
