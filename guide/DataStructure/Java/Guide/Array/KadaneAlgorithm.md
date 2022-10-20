```java
// 9
// -2 1 -3 4 -1 2 1 -5 4
// sub-array with maximum sum.
// max sum that ends at ith index
// e.g. index = 3
// 4
// -3 4
// 1 -3 4
// -2 1 -3 4
// 1 2 3 4 5
// choice 1: we can start a new sub-array
// choice 2: add to existing sub-array


max[0] = arr[0] // -2
max[1] = maximum(max[0] + arr[1], arr[1]) // 1 (choice 1)
max[2] = maximum(max[1] + arr[2], arr[2]) // -2 (choice 2)
.....

ans = maximum(max[])


private static int kadaneAlgo(int[] arr, int size) {
    int[] max = new int[size];
    max[0] = arr[0];
    int maximum = max[0];
    for (int i = 1; i < size; i++) {
        max[i] = Math.max(arr[i], arr[i] + max[i - 1]);
        if (maximum < max[i]) maximum = max[i];
    }
    return maximum;
}

Test case
1
9
-2 1 -3 4 -1 2 1 -5 4
[-2, 1, -2, 4, 3, 5, 6, 1, 5]
6
```