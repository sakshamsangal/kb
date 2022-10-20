```java
import java.util.*;

public class Source {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        partitionNegativeAndPositive(n, arr);
    }

    static boolean oppositeSign(int x, int y) {
        return ((x ^ y) < 0);
    }

    static void printList(ArrayList<Integer> list) {
        String result = "";
        for (int i = 0; i < list.size(); i++) {
            result += list.get(i) + " ";
        }
        System.out.println(result);
    }

    static void partitionNegativeAndPositive(int n, int arr[]) {
        ArrayList<Integer> a = new ArrayList<Integer>();
        ArrayList<Integer> b = new ArrayList<Integer>();
        //push first element
        a.add(arr[0]);
        // Now put all elements of same sign
        // in a[] and opposite sign in b[]
        for (int i = 1; i < n; i++) {
            if (oppositeSign(a.get(0), arr[i])) {
                b.add(arr[i]);
            } else {
                a.add(arr[i]);
            }
        }

        printList(a);
        if (0 < b.size()) printList(b);

        // checking whether first element is positive or negative
        if (-1 < arr[0]) {
            // first array is positive
            if (b.size() == 0) System.out.println("Array doesn't have negative numbers");
        } else {
            if (b.size() == 0) System.out.println("Array doesn't have positive numbers");
        }
    }
}

```