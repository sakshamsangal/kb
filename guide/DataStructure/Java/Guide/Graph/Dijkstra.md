# Dijkstra algorithm

## Definition
```
It gives shortest distance from source node to all other nodes.
```

## Dijkstra
```
public void dijkstra(int[][] graph, int source) {

    boolean[] visited = new boolean[size];
    int[] distance = new int[size];
    int[] previous = new int[size];

    Arrays.fill(distance, Integer.MAX_VALUE);
    distance[source] = 0;
    previous[source] = source;

    for (int i = 0; i < size - 1; i++) {
        int fixedIndex = getMinimumVertex(distance, visited);
        visited[fixedIndex] = true;
        List<Integer> adjacentIndexes = getAdjacentIndex(graph, fixedIndex, visited);
        for (Integer adjacentIndex : adjacentIndexes) {
            relax(distance, fixedIndex, graph[fixedIndex][adjacentIndex], adjacentIndex, previous);
        }
    }
    System.out.println(Arrays.toString(distance));
    printPath(source, previous);
}
```

## Get minimum vertex
```
private int getMinimumVertex(int[] distance, boolean[] visited) {
    int minIndex = -1;
    for (int i = 0; i < distance.length; i++) {
        if (!visited[i] && (minIndex == -1 || distance[i] < distance[minIndex])) {
            minIndex = i;
        }
    }
    return minIndex;
}
```

## Get adjacent index
```
public List<Integer> getAdjacentIndex(int[][] graph, int fixedIndex, boolean[] visited) {
    List<Integer> adjacentIndex = new ArrayList<>();
    for (int j = 0; j < size; j++) {
        if (!visited[j] && graph[fixedIndex][j] != 0) {
            adjacentIndex.add(j);
        }
    }
    return adjacentIndex;
}
```

## Relax
```
public void relax(int[] distance, int fixedIndex, int gapBetween, int adjacentIndex, int[] previous) {
    if (distance[fixedIndex] + gapBetween < distance[adjacentIndex]) {
        distance[adjacentIndex] = distance[fixedIndex] + gapBetween;
        previous[adjacentIndex] = fixedIndex;
    }
}
```

## Print path
```
private void printPath(int source, int[] previous) {
    for (int i = 0; i < size; i++) {
        System.out.print(i + ": ");
        int temp = previous[i];
        while (temp != source) {
            System.out.print(temp + " ");
            temp = previous[temp];
        }
        System.out.println(temp + " ");
    }
}
```

## Main
```
public class Main {
    public static void main(String[] args) {
        Graph graph = new Graph(6);

        int[][] graphMatrix = new int[][] { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
        graph.dijkstra(graphMatrix, 0);
    }
}
```

