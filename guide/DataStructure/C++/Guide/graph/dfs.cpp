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


	void printVertex(int vertex, bool visited[]) {

		cout << vertex << " ";
		visited[vertex] = true;

		for(int x: arr[vertex]) {
			if(!visited[x]) {
				printVertex(x, visited);
			}
		}
	}

	void dfs(int source) {
		// initialized visited array to false
		bool visited[size];
		for (int i = 0; i < size; ++i) {
			visited[i] = false;
		}

		// print vertex
		for (int i = 0; i < size; ++i) {
			if(!visited[i]) printVertex(source, visited);
		}

	}


};
int main() {

	Graph graph(4);

	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(1, 2);
	graph.addEdge(2, 3);

	graph.printAdjacencyList();

	graph.dfs(2);

	return 0;
}
