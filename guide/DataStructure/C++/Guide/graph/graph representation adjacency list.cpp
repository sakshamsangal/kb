// graph print using adjacent list
// c++ 14
#include <iostream>
#include <vector>

using namespace std;

void connect(vector<int> arr[], int source, int destination) {
	arr[source].push_back(destination);
	arr[destination].push_back(source);
}

void printGraph(vector<int> arr[], int vertex) {
	for (int i = 0; i < vertex; ++i) {
		cout << i << " -> ";
		for(auto x: arr[i]) {
			cout << x << " ";
		}
		cout << endl;
	}
}

int main() {
	int vertex = 5;
	vector<int> arr[vertex];

	connect(arr, 0, 1);
	connect(arr, 0, 4);
	connect(arr, 1, 2);
	connect(arr, 1, 3);
	connect(arr, 1, 4);
	connect(arr, 2, 3);
	connect(arr, 3, 4);

	printGraph(arr, vertex);
	return 0;
}

// 0 -> 1 4 
// 1 -> 0 2 3 4 
// 2 -> 1 3 
// 3 -> 1 2 4 
// 4 -> 0 1 3 
