import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Point {
    private long x;
    private long y;

    public long getX() {
        return x;
    }

    public void setX(long x) {
        this.x = x;
    }

    public long getY() {
        return y;
    }

    public void setY(long y) {
        this.y = y;
    }

    @Override
    public String toString() {
        return "Point{" +
                "x=" + x +
                ", y=" + y +
                '}';
    }
}
class CodeChef {

    static List<Set<Long>> listOfSetList = new ArrayList<>();
    static LinkedList<List<Point>> listOfPointList = new LinkedList<>();
    static List<Integer> sizes = new ArrayList<>();



    static void solve(BufferedReader bufferedReader) throws IOException {
        int rectangle = Integer.parseInt(bufferedReader.readLine());

        for (int i = 0; i < 4 * rectangle - 1; i++) {
            StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            long x = Integer.parseInt(stringTokenizer.nextToken());
            long y = Integer.parseInt(stringTokenizer.nextToken());

            Point point = new Point();
            point.setX(x);
            point.setY(y);

            int index = getIndex(x,y);



            if(index == listOfSetList.size()) {
                listOfPointList.add(new ArrayList<>());
                listOfSetList.add(new HashSet<>());
                sizes.add(1);
            }
            listOfPointList.get(index).add(point);
            listOfSetList.get(index).add(x);
            listOfSetList.get(index).add(y);

            sizes.set(index, listOfPointList.get(index).size());
        }

        System.out.println(listOfSetList);
        System.out.println(listOfPointList);
        System.out.println(sizes);
    }

    private static int getIndex(long x, long y) {
        for (int i = 0; i < listOfSetList.size(); i++) {
            if (listOfSetList.get(i).contains(x) || listOfSetList.get(i).contains(y)) return i;
        }
        return listOfSetList.size();
    }


}

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int test = Integer.parseInt(bufferedReader.readLine());

        while (test != 0) {
            CodeChef.solve(bufferedReader);
            test--;
        }
    }
}

