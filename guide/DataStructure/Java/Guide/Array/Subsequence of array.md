# Non-empty power set of array

`arr[]` = positive integers

## Test cases

```
1
// 1

1 2 
//
1
2
1 2

1 2 3 4
//
1 
2 
1 2 
3 
1 3 
2 3 
1 2 3 
4 
1 4 
2 4 
1 2 4 
3 4 
1 3 4 
2 3 4 
1 2 3 4
```

## Bit manipulation algorithm

**Step 1:** find total subsets

**Step 2:** for counter = 5, takes it binary 101 and print only set bits

**Step 3:** do this for counter =  1 to totalSubset

```java
static void powerSet(int[] arr, int size) {
    int totalSubset = (int) Math.pow(2, size); // total set

    for (int i = 1; i < totalSubset; i++) {
        for (int j = 0; j < size; j++) {

            if ((i & (1 << j)) > 0) { // go inside if bit is set
                System.out.print(arr[j]+" ");
            }
        }
        System.out.println();
    }
} 


static LinkedList<Character> result = new LinkedList<>();
private static void subsequence(String arr, int end) {
    if (end < 0) {
        System.out.println(result);
        return;
    }
    result.add(arr.charAt(end));
    subsequence(arr, end - 1);

    result.removeLast();
    subsequence(arr, end - 1);
}
```
