# Merge sort

`arr[]` = positive integers

## Test cases
```
14
// 14

4 3
// 3 4

1 10 2
// 1 2 10

8 7 6 10
// 6 7 8 10

10 5 15 20 2 30
// 2 5 10 15 20 30
```

## Divide and conquer algorithm
- merge 2 sorted array
- start from size = 1

## Code
``` java
static void mergeSort(int[] arr, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

private static void merge(int[] arr, int start, int mid, int end) {
    int x = 0;
    int y = 0;
    int k = start;
    int[] result = new int[end - start + 1];
    int[] left = new int[mid - start + 1];
    int[] right = new int[end - mid];

    // coping to left[] and right[] from arr[]
    for (int i = 0; i < left.length; i++) {
        left[i] = arr[k++];
    }

    for (int i = 0; i < right.length; i++) {
        right[i] = arr[k++];
    }

    k = 0;
    // merging 2 sorted arrays
    while (x < left.length && y < right.length) {
        result[k++] = left[x] < right[y] ? left[x++]: right[y++];
    }

    while (x < left.length) {
        result[k++] = left[x++];
    }

    while (y < right.length) {
        result[k++] = right[y++];
    }

    // coping to original array
    for (int i = 0; i < k; i++) {
        arr[start++] = result[i];
    }

}
```
if (start < len - 1) 

int[] result = new int[end - start];
int[] left = new int[mid - start];
int[] right = new int[end - mid];
```

```
You need to consider the 2 arrays as queue.
You need to make a result[] queue and enqueue the smaller front element out of 2 array(consider queue for better understanding) in to result[]

Do this until both arrays are empty.

For reference:

```