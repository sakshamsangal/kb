import java.util.Scanner;

class Source {
    public static boolean palindrome(int[] num, int index) {
        if (index == 2) return true;
        if (num[index] != num[4 - index]) return false;
        return palindrome(num, index + 1);
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int num[] = new int[5];
        for(int i=0; i< 5;i++)
            num[i]=sc.nextInt();
        boolean answer =palindrome(num, 0);
        System.out.println(answer);
    }
}
