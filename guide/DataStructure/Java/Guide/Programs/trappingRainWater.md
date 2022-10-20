```
import sun.plugin.javascript.navig.Array;

import java.util.Arrays;
import java.util.Scanner;
class CodeChef{
    static void solve(Scanner scanner) {
        int size = scanner.nextInt();
        int[] arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = scanner.nextInt();
        }
        trappingRainWater(arr, size);
    }

    private static void trappingRainWater(int[] arr, int size) {
        int[] left = new int[size];
        int[] right = new int[size];
        leftExtreme(arr, left);
        rightExtreme(arr, right);

        System.out.println(Arrays.toString(left));
        System.out.println(Arrays.toString(right));
    }

    private static void rightExtreme(int[] arr, int[] right) {
        right[arr.length - 1] = arr[arr.length - 1];
        for (int i = arr.length - 2; i > -1; i--) {
            right[i] = Math.max(right[i + 1], arr[i]);
        }

    }

    private static void leftExtreme(int[] arr, int[] left) {
        left[0] = arr[0];
        for (int i = 1; i < arr.length; i++) {
            left[i] = Math.max(left[i - 1], arr[i]);
        }
    }


}
class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int test = scanner.nextInt();

        while (test != 0) {
            CodeChef.solve(scanner);
            test --;
        }
    }
}
```