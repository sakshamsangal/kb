#include <iostream>
#include <queue>
using namespace std;

class Graph {

	int vertex;
	int * * arr;

public:
	Graph(int vertex) {
		this->vertex = vertex;
		this->arr = new int*[vertex];
		for (int row = 0; row < vertex; row++) {
			arr[row] = new int[vertex];
			for (int column = 0; column < vertex; column++) {
				arr[row][column] = 0;
			}
		}
	}
	void printGraph() {
		cout << "  ";
		for (int i = 0; i < this->vertex; ++i) {
			cout << i << " ";
		}
		cout << endl;
		for (int i = 0; i < this->vertex; ++i) {
			cout << i << " ";
			for (int j = 0; j < this->vertex; ++j) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
	}

	void connect(int source, int destination) {
		this->arr[source][destination] = 1;
		this->arr[destination][source] = 1;
	}

	void bfs(int source) {
		// visited array initialized to false
		bool visited[this->vertex];
		for (int i = 0; i < this->vertex; ++i) {
			visited[i] = false;
		}



		//make queue and insert source
		queue<int> q;
		q.push(source);

		// make source visited true
		visited[source] = true;

		while(!q.empty()) {

			// change source
			source = q.front();
			cout << source << " ";

			// dequeue it
			q.pop();

			for (int i = 0; i < vertex; ++i) {
				if(arr[source][i] == 1) {
					if(!visited[i]) {
						visited[i] = true;
						q.push(i);
					}
				}
			}

		}


	}
};


int main() {
	Graph graph(5);

	graph.connect(0, 1);
	graph.connect(0, 4);
	graph.connect(1, 2);
	graph.connect(1, 3);
	graph.connect(1, 4);
	graph.connect(2, 3);
	graph.connect(3, 4);


	graph.printGraph();
	graph.bfs(0);
	return 0;
}


//   0 1 2 3 4
// 0 0 1 0 0 1
// 1 1 0 1 1 1
// 2 0 1 0 1 0
// 3 0 1 1 0 1
// 4 1 1 0 1 0
