private static int power(int base, int exponent) {
    if (exponent == 0) return 1;
    return base * power(base, exponent - 1);
}

static void solve(Scanner scanner) {
    System.out.println(power(7, 3)); // 343
}