## Binary exponentiation
### Algorithm
we need to calculate 2 ^ 13

 Result     | Base  | Power     | Nature    | Todo
-|-|-|-|-
 1          | 2     | 13        | odd       | power-- and result *= base 
 2          | 2     | 12        | even      | power = power / 2 and base = base * base
 2          | 4     | 6         | even      | power = power / 2 and base = base * base
 2          | 16    | 3         | odd       | power-- and result *= base
 32         | 16    | 2         | even      | power = power / 2 and base = base * base
 32         | 256   | 1         | odd       | power-- and result *= base
 8192       | 256   | 0         | even      | since power is 0 so res is answer

### code
``` 
static int binaryExponentiation(int base, int power) {
    int result = 1;
    while (power != 0) {
        if ((power & 1) == 1) {
            power--;
            result *= base;
        }
        // we have even power now
        power = power >> 1; // divide by 2
        base *= base;
    }
    return result;
}
```