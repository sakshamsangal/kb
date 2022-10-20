// graph print using adjacent list
// c++ 14
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

class Graph {
	int vertex;
	vector<int> *arr;

	public:
	Graph(int vertex) {
		this->vertex = vertex;
		this->arr = new vector<int>[vertex];
	}
	void connect(int source, int destination) {
		arr[source].push_back(destination);
		arr[destination].push_back(source);
	}

	void printGraph() {
		for (int i = 0; i < this->vertex; ++i) {
			cout << i << " -> ";
			for(auto x: arr[i]) {
				cout << x << " ";
			}
			cout << endl;
		}
	}

	void bfs(int source) {
		bool visited[this->vertex];
		unsigned int i;
		for (int i = 0; i < this->vertex; i++) visited[i] = false;

		visited[source] = true;

		queue<int> q;
		q.push(source);

		while(!q.empty()) {
			source = q.front();
			cout << source << " "; q.pop();

			for (i = 0; i < arr[source].size(); i++) {
				if(!visited[arr[source][i]]) {
					visited[arr[source][i]] = true;
					q.push(arr[source][i]);
				}
			}

		}

	}
//	void BFS(int s)
//	{
//	    // Mark all the vertices as not visited
//	    bool *visited = new bool[vertex];
//	    for(int i = 0; i < vertex; i++)
//	        visited[i] = false;
//
//	    // Create a queue for BFS
//	    list<int> queue;
//
//	    // Mark the current node as visited and enqueue it
//	    visited[s] = true;
//	    queue.push_back(s);
//
//	    // 'i' will be used to get all adjacent
//	    // vertices of a vertex
////	    arr<int>::iterator i;
//
//	    while(!queue.empty())
//	    {
//	        // Dequeue a vertex from queue and print it
//	        s = queue.front();
//	        cout << s << " ";
//	        queue.pop_front();
//
//	        // Get all adjacent vertices of the dequeued
//	        // vertex s. If a adjacent has not been visited,
//	        // then mark it visited and enqueue it
//	        for (auto i = arr[s].begin(); i != arr[s].end(); ++i)
//	        {
//	            if (!visited[*i])
//	            {
//	                visited[*i] = true;
//	                queue.push_back(*i);
//	            }
//	        }
//	    }
//	}
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

// 0 -> 1 4
// 1 -> 0 2 3 4
// 2 -> 1 3
// 3 -> 1 2 4
// 4 -> 0 1 3
