```
1st node  = root
leaf node = 0 child
degree = number of child a node possess
internal node = non leaf nodes


every node has atmost 2 child.
every node 3 fields - left, data, right
heap and segemented tree are implemented using array

Why binary tree?
It is practically used.

Empty tree = null

class Node {
    Node left;
    int data;
    Node right;

    public Node(int data) {
        this.data = data;
    }
}

Application
heirarical data e.g org structure, xml, oops, folder structure
BST
heap
B and B+ tree for indexing
spanning tree for bridegs
shorest path tree for router
parse tree e.g. compiler
trie for dictictiory
suffix tree for fast search in string.
binary indexed tree for query searches with in the range.
segemented tree for query searches with in the range.

```


```

import java.util.LinkedList;
import java.util.Queue;

class BinaryTree {
    public void inOrder(Node parent) {
        if (parent != null) {
            inOrder(parent.left);
            System.out.print(parent.data + " ");
            inOrder(parent.right);
        }
    }

    static class Node {
        Node left;
        int data;
        Node right;

        public Node(int data) {
            this.data = data;
        }
    }

    Node root;

    public BinaryTree(Node root) {
        this.root = root;
    }


    // empty tree height = 0
    // max number of nodes from root to leaf

    void toDLL(Node prev, Node curr) {
        if (curr != null) {
            toDLL(prev, curr.left);
            if (prev != null) {
                prev.right = curr;
                curr.left = prev;
            }
            prev = curr;
            toDLL(prev, curr.right);
        }
    }

    int height(Node parent) {
        if (parent != null) return Math.max(height(parent.left), height(parent.right)) + 1;
        return 0;
    }

    void bfs() {
        if (root != null) {

            Queue<Node> queue = new LinkedList<>();
            queue.add(root);

            // adding child of parents
            while (!queue.isEmpty()) {
                Node curr = queue.poll();
                System.out.print(curr.data + " ");
                if (curr.left != null) queue.add(curr.left);
                if (curr.right != null) queue.add(curr.right);
            }
        }
    }
}

class Main {
    public static void main(String[] args) {
        BinaryTree binaryTree = new BinaryTree(new BinaryTree.Node(10));
        binaryTree.root.left = new BinaryTree.Node(11);
        binaryTree.root.left.left = new BinaryTree.Node(7);
        binaryTree.root.right = new BinaryTree.Node(9);
        binaryTree.root.right.left = new BinaryTree.Node(15);
        binaryTree.root.right.right = new BinaryTree.Node(8);

        // binaryTree.inOrder(binaryTree.root);
        // binaryTree.bfs();
        System.out.println(binaryTree.height(binaryTree.root));
        binaryTree.toDLL(null, binaryTree.root);
        System.out.println(binaryTree.root.data);
        System.out.println(binaryTree.root.right.data);
        System.out.println(binaryTree.root.right.right.data);
    }
}

```