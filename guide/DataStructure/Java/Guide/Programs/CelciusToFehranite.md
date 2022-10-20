Hi Shubham,

When your code is verified correctly it means that it has passed the sample test cases. But when it is rejected after submission it means that there are a few hidden non-sample test cases in which your code is not passing. One reason could be that you're hardcoding the solution using the exact values given in the example. Try writing a generic code that will pass all the test cases.

And if after first submission your answer is partially correct/rejected then there is button details besides partially correct/rejected after clicking on that you can find which test cases are failed for that particular program, so you can ask for the test cases, we will provide you with the test cases than after that what can you do is this give that input in the input tab and RUN your code instead of verifying it, because if after giving your input if you will click on verify button it will automatically take sample input, so request you to click on RUN button and check the Output, match it with the expected output then you will realize what is wrong with your code.

**Below is the code.** 

```
import java.util.*;
public class Source {

   public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int C;
        float F;
        C = input.nextInt();
        F = 9 * (float)C / 5 + 32;
        System.out.println(F);
   }
}
```

Hope it helps.