```
static boolean linearSearch(int[] arr, int key) {
    for (Integer item : arr) {
        if (item == key) return true;
    }
    return false;
}


// reverse order 
static int linearSearch(int[] arr, int key) {
    for (int i = arr.length - 1; i > -1; i--) {
        if (arr[i] == key) return arr.length - 1 - i;
    }
    return -1;
}

// reverse traversal
static boolean linearSearch(int[] arr, int key) {
    for(int i = arr.length - 1; i > -1; i--) {
        if (arr[i] == key) return true;
    }
    return false;
}

```