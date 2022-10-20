# Detect cycle directed graph

```
Use modified DFS for this.
In recursion tree, if there is a back edge then there is a cycle.
```

## Algorithm
```
DFSRecur(adj, s, visited[], recusionStack[]) {
    visited[s] = true
    recusionStack[s] = true

    for every adjacent u of s {
        if (visited[u] == false && DFSRecur(adj, u, visited, recusionStack)) return true;
        else if (recusionStack[u] == true) return true
    }

    recusion[s] = false
    return false;
}

DFS(adj, V) {
    visited[V] = {false, false, ..., false};
    recusionStack[V] = {false, false, ..., false};

    for(i = 0; i < V; i++) {
        if (visited[i] == false) {
            if(DFSRecur(adj, i, visited, recusionStack) == true) return true 
        }
    }

    return false
}

```