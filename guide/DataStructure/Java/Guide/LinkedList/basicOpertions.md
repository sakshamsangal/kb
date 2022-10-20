# LinkedList

## Note
```
Memory created at runtime which are connected to each other is called a linked list. So in Java object gets memory at runtime so you can consider linkedlist as an object which will get memory at run time. So linked list consists of two things one is data and the second thing is next. Data consists of the value which the node will hold for example it will contain integer type value or a string type value and, the next field member of the class is of Node type and will contain the reference of the next node. So this is all about the designing of a node in a linked list. So there are various operations in linked list like we can insert at the start or at the end, we can delete at the start or at the end, we can insert or delete at a given index and finally we can traverse the linked list. 

Moreover in singular linked list we can traverse in one direction only while in doubly linked list we have two-way traversing. In circular linked list we also have a tail pointer which will reference to the last node of the linked list and the last node of the linked list is connected to the first node i.e. head. Now the question is how to insert an item at the end of the linked list so you need to consider some scenarios while programming this operation first scenario is what will happen when the list is empty, what will happen when the list contains only a single element and what will happen if a list contain more than one element. So in this way you need to think in order to develop code for this. So if the list is empty means head is equal to null then you have to replace this null with the newly created node. And if the list is not empty means it contains at least one item then you first need to reach the end of the list and get the hold of the last node and once you get the whole of the last node you need to make its next to the newly created node. In the similar way you can develop code for other operations of linked list.
```

## Linkedlist class
```
class LinkedList { }
```

## Field
```
static Node head;
```

## Node class
```
static class Node {
    int data;
    Node next;

    public Node(int data) {
        this.data = data;
    }
}
```

## Add at end
```
static void addAtEnd(int k) {
    if (head == null) { // if list is empty
        head = new Node(k);
        return;
    }

    // if list is not empty
    // get hold of last node.
    Node temp = head;
    while (temp.next != null) {
        temp = temp.next;
    }

    // insert the node
    temp.next = new Node(k);
}
```


## Add at given index
```
static void addAtGivenIndex(int k, int index) {

    Node temp;
    if (head == null || index == 1) {
        temp = head;
        head = new Node(k);
        head.next = temp;
        return;
    }

    int count = 1;
    temp = head;
    while (count != index && temp.next != null) {
        count++;
        temp = temp.next;
    }

    Node x = temp.next;
    temp.next = new Node(k);
    temp.next.next = x;
}
```

## Traverse
```
private static void traverse() {
    // copy head in temp
    Node temp = head;

    // iterate over the list
    while (temp != null) {
        System.out.print(temp.data + " ");
        temp = temp.next;
    }
    System.out.println();
}
```

## Delete node at given index
```
// For this, we hold the previous node to be deleted and
// will connect to node which is after the deleted node.
static void deleteNodeAtGivenIndex(int index, int size) {
    // if list does not exist or size < index
    if (size < index || head == null) return;

    // if we want to delete at start
    if (index == 1) {
        head = head.next;
        return;
    }

    // if more than 1 node is there
    Node temp = head;
    for (int i = 0; i < index - 2; i++) {
        temp = temp.next;
    }
    temp.next = temp.next.next;

}
```
## Reverse
```
// iterative solution
// we will traverse the list, and while traversing we keep changing pointers
// using the current node and previous node.
private static void reverse() {
    Node prev = null; // declaring previous of head
    Node current = head; // storing head in current
    while (current != null) { // traversing the list
        Node next = current.next; // getting hold of next of current
        current.next = prev; // making current next as previous
        prev = current; // new prev
        current = next; // new current
    }
    head = prev; // since curr is null so prev is head now
}
```


## Main
```
static class Main {
    public static void main(String[] args) {
        LinkedList.head = new Node(12);
        LinkedList.addAtEnd(34);
        LinkedList.addAtEnd(45);
        LinkedList.addAtEnd(78);
        LinkedList.traverse();
        LinkedList.reverse();
        LinkedList.traverse();
    }
}
```