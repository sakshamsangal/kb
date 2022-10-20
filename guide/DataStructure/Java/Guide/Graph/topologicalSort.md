# Topological sort DFS

## topologicalSortDFSUtil
```
void topologicalSortDFSUtil(int v, boolean[] visited, Stack<Integer> stack) {
    visited[v] = true;
    Integer i;
    for (Integer integer : adjacencyList.get(v)) {
        i = integer;
        if (!visited[i]) topologicalSortDFSUtil(i, visited, stack);
    }
    stack.push(v);
}

## topologicalSortDFS
void topologicalSortDFS() {
    Stack<Integer> stack = new Stack<Integer>();

    boolean[] visited = new boolean[size];
    for (int i = 0; i < size; i++)
        visited[i] = false;

    for (int i = 0; i < size; i++)
        if (!visited[i])
            topologicalSortDFSUtil(i, visited, stack);

    while (!stack.empty())
        System.out.print(stack.pop() + " ");
}

## Main
graph.addEdge(5, 2);
graph.addEdge(5, 0);
graph.addEdge(4, 0);
graph.addEdge(4, 1);
graph.addEdge(2, 3);
graph.addEdge(3, 1);

graph.topologicalSortDFS();

// 5 4 2 3 1 0 
```

BFS based algorithm(Kahn algorithm):

Store the indegree of every vertex.
Create a queue
Add vertex to queue whose indegree = 0
while(queue is not empty) {
    dequeue
    print dequeued
    for every adjacent item of dequeued
        reduce the indegree by 1
        if indegree == 0 then add item to the queue
}
```
// Kahn's Algo
public void topologicalSortBFS() {
    int[] inDegree = new int[size];
    for (int i = 0; i < size; i++) {
        for (int node : adjacencyList.get(i)) {
            inDegree[node]++;
        }
    }
    System.out.println(Arrays.toString(inDegree));

    // Create a queue and enqueue all vertices with inDegree 0
    Queue<Integer> queue = new LinkedList<>();
    for (int i = 0; i < size; i++) {

        if (inDegree[i] == 0) {
            queue.add(i);
            System.out.println(queue.peek());
        }
    }


    int count = 0;
    List<Integer> result = new ArrayList<>();
    while (!queue.isEmpty()) {

        System.out.println(queue);
        // Extract front of queue (or perform dequeue) and add it to topological order
        int deleted = queue.poll();
        result.add(deleted);

        // Iterate through all its neighbouring of deleted nodes
        // and decrease their in-degree by 1
        for (Integer node : adjacencyList.get(deleted)) {
            // If in-degree becomes zero, add it to queue
            if (--inDegree[node] == 0) queue.add(node);
        }
        count++;
    }

    // Check if there was a cycle
    if (count != size) {
        System.out.println("There exists a cycle in the graph");
        return;
    }

    // Print topological order
    for (Integer item : result) {
        System.out.print(item + " ");
    }
}
```