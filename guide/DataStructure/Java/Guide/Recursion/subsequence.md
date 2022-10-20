```java
import java.util.*;

class Solution {

    static Map<Integer, List<Integer>> map = new HashMap<>();

    static List<Integer> list = new ArrayList<>();
    static LinkedList<Integer> path = new LinkedList<>();


    static void recur(int end, LinkedList<Integer> result) {


        if (end == -1) {
            System.out.println(result.toString());
            return;
        }

        List<Integer> temp = new ArrayList<>();

        temp.add(end - 1);
        result.add(list.get(end));
        recur(end - 1, result);
        result.removeLast();

        temp.add(end - 1);
        recur(end - 1, result);
        // result.removeLast();


        map.put(end, temp);
    }
    static void allPath(int dest)
    {

        path.add(dest);

        if (dest == 0) {
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


        list.add(10);
        list.add(20);
        list.add(30);
        list.add(40);

        recur(list.size() - 1, new LinkedList<>());
        System.out.println(map.toString());
        allPath(3);
    }
}
```