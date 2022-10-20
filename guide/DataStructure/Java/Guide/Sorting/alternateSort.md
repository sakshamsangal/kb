```java 

import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Source {
    public static void alternativeSorting(int[] arr) {

        int i = 0, j = arr.length - 1, temp = 0;

        for (i = 0; i < arr.length; i++) {
            for (j = i + 1; j < arr.length; j++) {
                if (arr[i] > arr[j]) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }

        System.out.println(Arrays.toString(arr));


        int[] tempArr = new int[arr.length]; // To store modified array

        // Adding numbers from sorted array to  
        // new array accordingly 
        int ArrIndex = 0;


        // Traverse from begin and end simultaneously  
        for (i = 0, j = arr.length - 1; i <= arr.length / 2 || j > arr.length / 2;
             i++, j--) {


            if (ArrIndex < arr.length) {
                tempArr[ArrIndex] = arr[j];
                ArrIndex++;
            }

            if (ArrIndex < arr.length) {
                tempArr[ArrIndex] = arr[i];
                ArrIndex++;
            }
        }

        // Modifying original array 
        for (i = 0; i < arr.length; i++)
            arr[i] = tempArr[i];


    }

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        alternativeSorting(arr);
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
```