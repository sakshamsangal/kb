import java.util.Scanner;

class CodeChef {

    static void fun(int x, int space) {
        for (int i = 0; i < space; i++) {
            System.out.print(" ");
        }
        System.out.println("According to fun(" + x + ")");

        for (int i = 0; i < space + 4; i++) {
            System.out.print(" ");
        }
        System.out.println("if(" + x + " > 0)");
        if (x > 0) {
            for (int i = 0; i < space + 8; i++) {
                System.out.print(" ");
            }
            System.out.println("call fun(" + (x - 1) + ")");
            fun(--x, space + 8);

            for (int i = 0; i < space + 8; i++) {
                System.out.print(" ");
            }
            System.out.println("x = " + x);


            for (int i = 0; i < space + 8; i++) {
                System.out.print(" ");
            }
            System.out.println("call fun(" + x + ")");
            fun(x--, space + 8);

        }
    }

    static void solve(Scanner scanner) {

        fun(4, 0);
    }
}

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int test = scanner.nextInt();

        while (test != 0) {
            CodeChef.solve(scanner);
            test--;
        }
    }
}
