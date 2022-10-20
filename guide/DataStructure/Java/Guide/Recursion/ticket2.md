import java.util.Scanner;

class CodeChef {
    public static int sum(int n, int space) {
        for (int i = 0; i < space; i++) {
            System.out.print(" ");
        }
        System.out.println("According to sum(" + n + ")");

        for (int i = 0; i < space + 4; i++) {
            System.out.print(" ");
        }
        System.out.println("if(" + n + " > 9)");
        if (n > 9) {
            int last = n % 10;

            for (int i = 0; i < space + 8; i++) {
                System.out.print(" ");
            }
            System.out.println("last = " + last);

            for (int i = 0; i < space + 8; i++) {
                System.out.print(" ");
            }
            System.out.println("return " + last + " + call sum(" + n + " / 10)");
            return last + sum(n / 10, space + 8);
        } else {
            for (int i = 0; i < space + 4; i++) {
                System.out.print(" ");
            }
            System.out.println("else");
            for (int i = 0; i < space + 8; i++) {
                System.out.print(" ");
            }
            System.out.println("return " + n);
            return n;
        }
    }

    static void solve(Scanner scanner) {
        sum(25, 0);
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
