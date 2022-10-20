# Design pattern

## Class
```
public class Graph { }
```

## Fields
```
private int size;
public List<Set<Integer>> adjacencyList;
```

## Constructor
```
Graph(int size) {
    this.size = size;
    adjacencyList = new ArrayList<>();
    for (int i = 0; i < size; i++) {
        adjacencyList.add(new HashSet<>());
    }
}
```


## Main
```
public class Main {
    public static void main(String[] args) {
        Graph graph = new Graph(6);

        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(1, 2);
        graph.addEdge(2, 0);
        graph.addEdge(2, 3);
        graph.addEdge(3, 3);

    }
}
```