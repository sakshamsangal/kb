```
int getBinarySearchUnsuccessfulComparisonCount(int[] arr, int key) {
    start = 0
    end = size - 1
    count = 0
    while(start <= end) {
        mid = (start + end) / 2
        if (key == arr[mid]) return count

        count ++

        if (key < arr[mid]) end = mid - 1
        else start = mid + 1

    }
    return count 
}
```