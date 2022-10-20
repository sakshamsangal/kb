import java.util.Arrays;

class SegmentTree {
    int[] arr;
    int[] tree;

    public SegmentTree(int[] arr) {
        this.arr = arr;
        int height = (int) (Math.ceil(Math.log(arr.length) / Math.log(2)));
        int totalNodes = 2 * (int) Math.pow(2, height) - 1;
        tree = new int[totalNodes];

        Arrays.fill(tree, -1);
    }

    int getSum(int start, int end) {

        return 1;
    }

    void update(int start, int end) {

    }

    int create(int start, int end, int index) {
        if (start == end) {
            tree[index] = arr[start];
        } else {
            int mid = (start + end) / 2;
            tree[index] = create(start, mid, 2 * index + 1) + create(mid + 1, end, 2 * index + 2);
        }
        return tree[index];
    }

}

class Main {
    public static void main(String[] args) {
        int[] arr = new int[]{10, 20, 30, 40, 50, 60};
        SegmentTree segmentTree = new SegmentTree(arr);
        segmentTree.create(0, arr.length - 1, 0);
        System.out.println(Arrays.toString(segmentTree.tree));


        // [210, 60, 150, 30, 30, 90, 60, 10, 20, -1, -1, 40, 50, -1, -1]

    }
}