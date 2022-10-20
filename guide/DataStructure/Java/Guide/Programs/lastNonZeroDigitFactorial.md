```
static int lastNonZeroDigit(int n) {
    if (n == 0) return 1;
    return getLastNonZero(getLastNonZero(n) * lastNonZeroDigit(n - 1));
}

private static int getLastNonZero(int n) {
    while ((n % 10) == 0) n /= 10;
    return (n % 10);
}
```