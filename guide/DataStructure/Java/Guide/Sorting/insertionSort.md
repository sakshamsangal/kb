# insertionSort
```
static void insertionSort(int[] arr, int size) {

    // for traversing array
    for (int i = 1; i < size; i++) {
        int item = arr[i];
        int end = i - 1;

        // for shifting array elements.
        while (-1 < end && item < arr[end]) {
            arr[end + 1] = arr[end--];
        }
        arr[end + 1] = item;
    }

}
```
```
static void insertionSort(String[] arr, int size) {
    // for traversing array
    for (int i = 1; i < size; i++) {
        String item = arr[i];
        int end = i - 1;

        // for shifting array elements.
        while (-1 < end && item.compareTo(arr[end]) < 0) {
            arr[end + 1] = arr[end--];
        }
        arr[end + 1] = item;
    }

}
```