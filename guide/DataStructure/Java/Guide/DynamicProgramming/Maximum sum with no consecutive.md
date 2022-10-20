# Find maximum sum of array elements with no consecutive.

`arr[]` = positive integers

## Test cases
```
1 10 2
// 10

8 7 6 10
// 18 (8 + 10)

10 5 15 20 2 30
// 60 (10 + 20 + 30)
```

## Branch and bound algorithm
- find all valid subsequences
- store the sum of subsequence in sum[]
- find max in sum[] 


## Detailed code
``` java
static LinkedList<Integer> result = new LinkedList<>();
static HashSet<Integer> sum = new HashSet<>();
static int max;
static void subsequence(int[] arr, int end) {
    if(end < 0) {
        // System.out.println(result.toString());
        int s = 0;
        for (Integer item:result) {
            s += item;
        }
        sum.add(s);
        // System.out.println(sum.toString());
        max = Collections.max(sum);
        return;
    }
    result.add(arr[end]); // picked
    subsequence(arr, end - 2);

    // remove last from result
    result.removeLast();

    subsequence(arr, end - 1);// unpicked
}
```


## Simplified code
``` java
static int getMax(int[] arr, int end, int sum) {
    if(end < 0) return sum;
    return Math.max(getMax(arr, end - 2, sum + arr[end]), getMax(arr, end - 1, sum));
}
```