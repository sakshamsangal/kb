```java
public class DisjointSet {
    int[] arr;
    int[] parent;
    int size;

    public DisjointSet(int size) {
        this.size = size;
        arr = new int[size];
        parent = new int[size];
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    int find(int n) {
        if (n == parent[n]) return n;
        return find(parent[n]);
    }
    void union(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;
        parent[a] = b;
    }
}

public class Main {
    public static void main(String[] args) {

        DisjointSet disjointSet = new DisjointSet(5);

        // 0 is a friend of 2
        disjointSet.union(0, 2);

        // 4 is a friend of 2
        disjointSet.union(4, 2);

        // 3 is a friend of 1
        disjointSet.union(3, 1);

        if (disjointSet.find(4) == disjointSet.find(0))
            System.out.println("Yes");
        else
            System.out.println("No");

        // Check if 1 is a friend of 0
        if (disjointSet.find(1) == disjointSet.find(0))
            System.out.println("Yes");
        else
            System.out.println("No");
    }
}
```