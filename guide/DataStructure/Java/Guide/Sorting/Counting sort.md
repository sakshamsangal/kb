# Counting sort

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

## Algorithm
- find frequency of element in rank[]
- prefix sum of rank[]
- there are rank[i] elements before i

## Code
``` java
static void countingSort(int[] arr, int max) {
    int[] rank = new int[max + 1];

    for (int i = 0; i < arr.length; i++) {
        rank[arr[i]]++;
    }

    for (int i = 1; i < rank.length; i++) {
        rank[i] += rank[i - 1];
    }

    int[] result = new int[arr.length];
    for (int i = 0; i < arr.length; i++) {
        result[rank[arr[i]] - 1] = arr[i];
        rank[arr[i]]--;
    }

    System.out.println(Arrays.toString(result));
}
```