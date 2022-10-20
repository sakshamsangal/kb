# Basic operations

## addEdge
```
public void addEdge(Integer vertex1, Integer vertex2) {
    adjacencyList.get(vertex1).add(vertex2);
}
```

## BFS traversal
```
// connected graph
public void bfs() {
    Queue<Integer> queue = new LinkedList<>();
    boolean[] visited = new boolean[size];
    queue.add(0);
    visited[0] = true;

    while (!queue.isEmpty()) {
        int deleted = queue.poll();

        System.out.print(deleted + " ");

        for (Integer item : adjacencyList.get(deleted)) {
            if (!visited[item]) {
                visited[item] = true;
                queue.add(item);
            }
        }
    }
}
```

##  DFS traversal
```
// connected graph
public void dfs(int vertex, boolean[] visited) {
    System.out.print(vertex + " ");
    visited[vertex] = true;

    for (Integer adjacent : adjacencyList.get(vertex)) {

        if (!visited[adjacent]) {
            dfs(adjacent, visited);
        }
    }
}
```