**Hi Vipul, Thanks for reaching out to us.**

**You** van apply simple logic to get index of max element.

Algorithm:

```
mostVotes(votesPerUser[]) {
    return index of the max element(on FCFS basis if multiple max exist).
}
```



Program to find max element index:

```
int getMaxElementIndex(arr[]) {
    let maxIndex = 0;
    for(int i = 1; i < arr.length; i++) {
        if(arr[maxIndex] < arr[i]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}
```

I hope it helps.

![]()













