import java.util.*;


class CodeChef{

    static void solve(Scanner scanner) {
        String main = scanner.next();
        String pattern = scanner.next();

        LinkedList<Character> list = new LinkedList<>();
        for (int i = 0; i < main.length(); i++) {
            list.add(main.charAt(i));
        }


        Collections.sort(list);
        int index = smallestKMP(list, pattern);

        StringBuilder sb = new StringBuilder();
        for (Character ch : list) sb.append(ch);
        main = sb.toString();

        System.out.println(main.substring(0, index + 1) + pattern.substring(1) + main.substring(index + 1));

    }

    private static int smallestKMP(LinkedList<Character> list, String pattern) {
        for (int i = 1; i < pattern.length(); i++) {
            int index = Collections.binarySearch(list, pattern.charAt(i));
            list.remove(index);
        }
        return list.lastIndexOf(pattern.charAt(0));
    }

}
class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int test = Integer.parseInt(scanner.next());

        while (test != 0) {
            CodeChef.solve(scanner);
            test --;
        }
    }
}

```
aaakaeekmnnry
abohotypsu

aabadawyehhorst

Expected
aaakaeekmnnry
abohotypsu
aabadawyehhorst

```