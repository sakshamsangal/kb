```java
class Demo {
    int getCount(int[] arr, int size, int sum) {
        if (sum == 0) return 1;
        if (size == 0) return 0;
        int result = getCount(arr, size - 1, sum);
        if (arr[size - 1] <= sum) result += getCount(arr, size, sum - arr[size - 1]);
        return result;
    }
}


class Source {
    public static void main(String[] args) {
        int[] arr = {1,5,7,10};
        Demo demo = new Demo();
        System.out.println(demo.getCount(arr, arr.length, 20));
    }
}
```


