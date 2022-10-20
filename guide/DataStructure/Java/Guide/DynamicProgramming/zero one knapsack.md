# zero one knapsack

```
// find maximum value of the bag
int knapsack(int capacity, int[] weight, int[] value) {

}

```

## Test cases
```
capacity = 5
w = 5
v = 10
// 10

capacity = 5
w = 10 
v = 45
// 0

capacity = 10
w = 5 4 3
v = 20 10 50
// 60

capacity = 10
w = 5 4 6 3
v = 10 40 30 50
// 90

capacity = 50
w = 10 20 30 
v = 60 100 120
// 220
```

## Branch and bound algorithm
- pick and ignore item

## Code
``` java
static int knapsack(int capacity, int[] weight, int[] value, int end) {
    if(-1 < end && weight[end] <= capacity) {
        return Math.max(value[end] + knapsack(capacity - weight[end], weight, value, end - 1), knapsack(capacity, weight, value, end - 1));
    }
    return 0;
}

```

## algorithm
```
knapsack(capacity, weight[], value, end) {
    if(-1 < end && weight[end] <= capacity) {
        return Math.max(value[end] + knapsack(capacity - weight[end], weight, value, end - 1), knapsack(capacity, weight, value, end - 1));
    }
    return 0;
}
```