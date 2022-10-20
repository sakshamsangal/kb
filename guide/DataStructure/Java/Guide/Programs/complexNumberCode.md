```
Hi Asutosh, Thanks for reaching out to us.

 

real number = any number without the imaginary part.
imaginary number = real number + number with iota square root(-1)
purely imaginary number = number with an iota (square root(-1)) only

 

The trick is if the number is purely imaginary then you have to display only imaginary part e.g. i23

Refer to the code for reference:

public void checkPurelyImaginaryNumber() {
    if (real == 0 && imaginary != 0) {
        System.out.println("i" + imaginary);
        System.out.println("The number is purely imaginary");
    } else {
        System.out.println(real + "+i" + imaginary);
        System.out.println("The number is not purely imaginary");
    }
}
Testcase #4 : when real = 8.2 and imaginary = 0
Input
8.2
0

Output
0.0
The given number is real
8.2+i0.0
The number is not purely imaginary


Testcase #2 (sample): when real = 0 and imaginary = 0
Input
0
0

Output
0.0
The given number is real
0.0+i0.0
The number is not purely imaginary

 

Testcase #1 (sample) when real = 5 and imaginary = 1.6
Input
5
1.6

Output
1.6
The given number is complex
5.0+i1.6
The number is not purely imaginary


Testcase #3 (sample) when real = 0 and imaginary = 8
Input
0
8

Output
8.0
The given number is complex
i8.0
The number is purely imaginary


Thanks & Regards,
upGrad Tech Support
Happy Learning!
```