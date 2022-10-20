```java
import java.util.*;

class Solution {

    static Map<Integer, List<Integer>> map = new HashMap<>();

    static List<Integer> input = new ArrayList<>();
    static LinkedList<Integer> path = new LinkedList<>();


    static void recur(int item) {

        List<Integer> temp = new ArrayList<>();

        if (item < 1) {
            return;
        }

        for (Integer i: input){
            temp.add(item - i);
            recur(item - i);
        }

        map.put(item, temp);
    }
    static void allPath(int dest)
    {

        path.add(dest);

        if (dest < 1) {
            System.out.println(path.toString());
            return;
        }

        /* append this node to the path array */
        // pathLen++;

        for (Integer item : map.get(dest)) {
            allPath(item);
            path.removeLast();

        }
    }
    public static void main(String[] args) {


        input.add(9);
        input.add(6);
        input.add(5);
        input.add(1);

        recur(11);

        // System.out.println(map.toString());

        allPath(11);
    }
}
```