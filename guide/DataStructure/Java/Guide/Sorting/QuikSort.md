# Quick sort

## quickSort
```
private static void quickSort(int[] arr, int start, int end) {

    // more than 1 element
    // sorting needs
    if (start < end) {
        int pi = partition(arr, start, end);
        quickSort(arr, start, pi - 1);
        quickSort(arr, pi + 1, end);

    }
}
```

## partition
```
private static int partition(int[] arr, int start, int end) {
    int item = arr[start];
    int lastSmaller = start;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] < item) {
            lastSmaller++;
            swap(arr, i, lastSmaller);
        }
    }

    swap(arr, lastSmaller, start);
    return lastSmaller;
}
```

## swap
```
private static void swap(int[] arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
```

