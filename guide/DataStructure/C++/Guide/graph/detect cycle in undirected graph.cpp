// for dfs, graph should be undirected.

#include <iostream>
#include <vector>
using namespace std;

class Graph {

	int size;
	vector<int> * arr;

public:
	Graph(int size) {
		this->size = size;
		this->arr = new vector<int>[size];
	}

	void addEdge(int v1, int v2) {
		arr[v1].push_back(v2);
		arr[v2].push_back(v1);
	}

	void printAdjacencyList() {
		for (int i = 0; i < size; ++i) {
			cout << i << " -> ";
			for (unsigned int j = 0; j < arr[i].size(); ++j) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
	}


	bool isCyclePresent(int vertex, bool visited[], int parent) {

		visited[vertex] = true;

		for(int x: arr[vertex])
			if((!visited[x] && isCyclePresent(x, visited, vertex)) || x != parent)
				return true;

		return false;
	}

	bool detectCycle() {
		// initialized visited array to false
		bool visited[size];

		for (int i = 0; i < size; ++i) visited[i] = false;

		for (int i = 0; i < size; ++i)
			if(!visited[i] && isCyclePresent(i, visited , -1)) return true;


		return false;

	}


};
int main() {

	Graph graph(5);

	graph.addEdge(1, 0);
	graph.addEdge(0, 2);
	graph.addEdge(2, 1);
	graph.addEdge(0, 3);
	graph.addEdge(3, 4);

	graph.printAdjacencyList();

	graph.detectCycle() ? cout << "yes": cout << "no";

	return 0;
}
