Fibbonacci means next element in series is the sum of previous 2 numbers // 0 1
Tribonacci means next element in series is the sum of previous 3 numbers // 0 0 1
N-bonacci means next element in series is the sum of previous n numbers // 0 0 0 .. n - 1 times zero then 1


Since fibonacci sequence is the sum of the previous two numbers.
F(n) = F(n - 1) + F(n - 2) // 2 recursive calls

Let n = 4
T(4) = time required to compute 4th fibonacci number // T(n)
T(3) = time required to compute 3rd fibonacci number // T(n - 1)
T(2) = time required to compute 2nd fibonacci number // T(n - 2)

T(n) = T(n - 1) + T(n - 2) + some constant work
T(n) = T(n - 1) + T(n - 2) + 1 // we can replace constant with 1


static void solve(Scanner scanner) {
    System.out.println(fibonacci(1)); // 1st term = 0
    System.out.println(fibonacci(2)); // 2nd term = 1
    System.out.println(fibonacci(3)); // 3rd term = 1
    System.out.println(fibonacci(4)); // 4th term = 2
    System.out.println(fibonacci(5)); // 5th term = 3
}

private static int fibonacci(int num) {
    if (num == 1) return 0;
    if (num == 2) return 1;
    return fibonacci(num - 1) + fibonacci(num - 2);
}

private static void fibonacciSeries(int num) {
    int a = 0;
    int b = 1;

    for (int i = 0; i < num; i++) {
        System.out.print(a + " ");
        int c = a + b;
        a = b;
        b = c;
    }
}
