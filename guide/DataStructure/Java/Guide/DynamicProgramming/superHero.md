```
minJumps(n) {
    arr[1] = 0
    
    // fill the array to find the min jumps from certain distance
    for(i = 2 to <=n) {
        temp = arr[i - 1]
        if(i is divisible by 2) temp = minimum of arr[i / 2] and temp
        if(i is divisible by 3) temp = minimum of arr[i / 3] and temp
        arr[i] = temp + 1
    }
    return arr[n]
}

```