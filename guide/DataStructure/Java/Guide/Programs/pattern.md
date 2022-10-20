import java.util.Scanner;

public class Source {
    static String x = "";

    public static void func(int n) {
        if (1 < n) func(n - 1);
        for (int i = 0; i < n; i++) {
            System.out.print("*");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        func(n);
    }
}