```
// queue using stack
import java.util.Stack;

class Queue {
    Stack<Integer> main =  new Stack<>();
    Stack<Integer> temp =  new Stack<>();

    public void enqueue(int item) {
        while (!main.empty()) {
            temp.add(main.pop());
        }

        main.add(item);
        while (!temp.empty()) {
            main.add(temp.pop());
        }
        temp.clear();
    }

    int dequeue() {
        return main.pop();
    }

    int getFront() {
        if (main.size() == 0) return -1;
        return main.peek();
    }

}

class Demo {

    public static void main(String[] args) {
        Queue queue = new Queue();

        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);


        // 10 20 30
        System.out.println(queue.dequeue()); // 10
        System.out.println(queue.dequeue()); // 20

        queue.enqueue(40); // 30 40
        System.out.println(queue.dequeue()); // 30

        queue.enqueue(50);
        queue.enqueue(60);

        System.out.println(queue.dequeue()); // 40
        System.out.println(queue.getFront()); // 50
    }
}

```
