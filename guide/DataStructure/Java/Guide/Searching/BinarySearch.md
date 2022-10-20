```
class Search {

    static int count = 1;

    // normal binary search program
    static boolean binarySearch(int[] arr, int item) {
        int start = 0;
        int end = arr.length - 1;
        while (start <= end) { // why are leaving one then??
            int mid = (start + end) / 2;
            if (arr[mid] == item) return true; // only this one should be taken into consideration.
            count++;
            if (item < arr[mid]) end = mid - 1;
            else start = mid + 1; // in else there is no comparisons
            // moreover your answer is also taking this as comparisons
            // Although we can write if (item > arr[mid]) start = mid + 1;
            // But its up to the programmer choice.
        }
        return false;
    }

    static class Bound {
        static int lower = 0;
        static int upper = 2;

        public static void setBound(int[] arr, int item) {
            while (arr[upper] < item) {
                lower = upper;
                upper <<= 1;
            }
        }
    }

    // when arr.length is not allowed
    static boolean binarySearchInfinityArray(int[] arr, int item) {
        Bound.setBound(arr, item);
        int start = Bound.lower;
        int end = Bound.upper;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (arr[mid] == item) return true;
            if (item < arr[mid]) end = mid - 1;
            else start = mid + 1;
        }
        return false;
    }


}

class Source {
    public static void main(String[] args) {

        int[] arr = new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
        double sum = 0;
        for (int i = 0; i < arr.length; i++) {
            Search.binarySearch(arr, arr[i]);
            System.out.println(arr[i] + " = " + Search.count);
            sum += Search.count;
            Search.count = 1;
        }
        System.out.println("Total comparison = " + sum / arr.length);


    }
}
```