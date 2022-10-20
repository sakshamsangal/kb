static void solve(Scanner scanner) {
    int size = scanner.nextInt();
    System.out.println(isPrime(size));
}

private static boolean isPrime(int num) {
    if (num == 0 || num == 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;

}