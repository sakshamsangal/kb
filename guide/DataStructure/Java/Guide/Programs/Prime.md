```java
class Prime {
    boolean checkPrime(int n) {

        if (n <= 1) return false;

        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;

        int i = 5;

        while (i <= n) {
            if (n % i == 0 && n % (i+2) == 0) return false;
            i += 6;
        }
        return true;
    }
}

class Main {
    public static void main(String[] args) {
        Prime prime = new Prime();
        System.out.println(prime.checkPrime(-1)); // false
        System.out.println(prime.checkPrime(2)); // true
        System.out.println(prime.checkPrime(15)); // false
        System.out.println(prime.checkPrime(13)); // true
        System.out.println(prime.checkPrime(17)); // true
        System.out.println(prime.checkPrime(38)); // false
    }
}
```