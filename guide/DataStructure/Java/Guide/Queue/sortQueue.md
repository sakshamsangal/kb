```
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

class Demo {

    public static void main(String[] args) {

        Queue<Integer> queue = new LinkedList<>();

        queue.add(20);
        queue.add(40);
        queue.add(10);
        queue.add(30);
        queue.add(50);

        sort(queue);
    }

    private static void sort(Queue<Integer> queue) {
        int[] temp = new int[queue.size()];

        int i = 0;
        while (!queue.isEmpty()) {
            int item = queue.poll();
            int end = i - 1;

            while (-1 < end && item < temp[end]) {
                temp[end + 1] = temp[end];
                end--;
            }
            temp[end + 1] = item;
            i++;
        }
        System.out.println(Arrays.toString(temp)); // [10, 20, 30, 40, 50]
    }


}
```