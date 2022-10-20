```
public static void selectionSort(int[] arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = getMinIndex(arr, i);
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

private static int getMinIndex(int[] arr, int start) {
    int minIndex = start;
    for (int i = start + 1; i < arr.length; i++) {
        if (arr[i] < arr[minIndex]) minIndex = i;
    }
    return minIndex;
}
```