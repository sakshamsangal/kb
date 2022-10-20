```java
import java.util.Scanner;
class CodeChef{
	static void solve(Scanner scanner) {
        int size = scanner.nextInt();
        int[] arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = scanner.nextInt();
        }
    }
}
class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int test = scanner.nextInt();

        while (test != 0) {
            CodeChef.solve(scanner);
            test --;
        }
    }
}
```

```java
// fast io
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class CodeChef {
    static void solve(BufferedReader bufferedReader) throws IOException {
        int size = Integer.parseInt(bufferedReader.readLine());
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());

        int[] arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = Integer.parseInt(stringTokenizer.nextToken());
        }
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
```

