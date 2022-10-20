```java
import java.util.*;

class Solution {

    static Map<Integer, List<Integer>> map = new HashMap<>();

    static List<Integer> list = new ArrayList<>();
    static void fun(int num) {

        if (num < 1) {
            return;
        }
        List<Integer> temp = new ArrayList<>();


        for (Integer item: list){
            temp.add(num - item);
            fun(num - item);
        }

        map.put(num, temp);

    }


    static LinkedList<Integer> path = new LinkedList<>();


    static void allPath(int dest)
    {

        path.add(dest);

        if (dest < 1) {
            System.out.println(path.toString());
            return;
        }


        for (Integer item : map.get(dest)) {
            allPath(item);
            path.removeLast();
        }
    }
    public static void main(String[] args) {

        list.add(12);
        list.add(11);
        list.add(13);

        fun(23);

        // System.out.println(map.toString());
        allPath(23);
    }
}
```