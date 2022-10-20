```java
public class LIS {

    // the subsequence has to be end with any element
    // i am finding every subsequence ending with arr[i]
    // i = 0, 1, . . . , end
    // i am actually finding max length of subsequence ending with arr[]
    
    // driver
    public static void main(String[] args) {
        
        // given an array
        int[] arr = new int[]{
                10, 22, 9, 33, 21, 50, 41, 60, 80
        };
        
        // make maxLength[]
        int[] maxLength = new int[arr.length];
        
        // make maxLength[0] = 1;
        maxLength[0] = 1;

        // find max of maxLength for else part
        int max = maxLength[0];
        
        // iterate over arr[] from 1
        for (int i = 1; i < arr.length; i++) {


            // if arr[] is greater to previous it will contribute to LIS
            if (arr[i - 1] < arr[i]) {


                // so make length[i] = just previous length + 1
                maxLength[i] = maxLength[i - 1] + 1;

            }

            // arr[] is smaller than previous
            // it will not contribute to LIS
            else {

                // maxLength will be the maximum of previous maxLength
                maxLength[i] = max;
            }

            // finding max in maxLength
            if (max < maxLength[i]) {
                max = maxLength[i];
            }
        }

        System.out.println(max);
    }
}
```
```java
import java.util.Scanner;

class CodeChef {


    private static int lis(int[] arr) {

        int[] lisArr = new int[arr.length];
        lisArr[0] = 1;

        for (int i = 1; i < arr.length; i++) {

            int temp = 1;

            // ending with arr[i]
            for (int j = 0; j < i; j++) {

                if (arr[j] < arr[i]) {
                    temp = Math.max(lisArr[j] + 1, temp);
                }

            }
            lisArr[i] = temp;
        }

        int max = 1;
        for (int i = 1; i < arr.length; i++) {
            max = Math.max(lisArr[i], max);
        }

        return max;
    }

    static void answer(Scanner scanner) {
        int[] arr = {10, 22, 9, 33, 21, 50, 41, 60, 80};
        int lis = lis(arr);
        System.out.println(lis);
    }
}

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int test = scanner.nextInt();

        while (test != 0) {
            CodeChef.answer(scanner);
            test--;
        }
    }
}
```
