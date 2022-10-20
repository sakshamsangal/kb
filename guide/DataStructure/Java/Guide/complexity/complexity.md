Hi Tanvi,

Big O(n) = This is the worst we can get
Theta(n) = This is the exact value we will get. 
Omega(n) = This is the best we can get. 
====================================================================
for(int i = 0; i < 100000; i++) { // it will execute 100000 times
    System.out.println("Katrina"); // it will execute 100000 times
}
Total complexity = 100000 + 100000 = 200000 = constant
This is the exact complexity. So we can use Theta(1)

====================================================================

for(int i = 0; i < n; i++) { // it will execute n times
    System.out.println("Katrina"); // it will execute n times
}

Total complexity = n + n = 2n = linear 
The upper bound for this is n i.e. BigO(n)
The lower bound for this is 1 i.e. Omega(1)
The performance of this algo lies in range so we don't have theta for this.

====================================================================
for(int i = 0; i < 100000; i++) { // it will execute 100000 times
    for(int i = 0; i < n; i++) {  // it will execute 100000 * n times 
        System.out.println("Katrina"); // it will execute 100000 * n times 
    } 
    System.out.println("Deepika"); // it will execute 100000 times 
}

Total complexity:
= 100000 + 2(100000 * n) + 100000
= 1 + 2n + 1 
= 2 + 2n
= linear this is the worst we can get. BigO(n)
The best is 1, so omega(1), n = 0
Again the performance is in range so no theta

====================================================================
for(int i = 0; i < k; i = i / 2) { // it will execute k times 
    for(int i = 0; i < n; i++) {  // it will execute k * n times
        System.out.println("Katrina"); // it will execute k * n times 
    } 
    System.out.println("Deepika"); // it will execute k times 
}


Total complexity:
= k + 2(k * n) + k
= 2k + 2(k * n) 
= linear + quadratic 
= quadratic // we take higher degree, n^2, n , 1
= quadratic this is the worst we can get. BigO(n^2)
The best is 1, so omega(1)
====================================================================

You can refer to:

https://www.geeksforgeeks.org/analysis-of-algorithms-set-3asymptotic-notations/

And can also see ravindrababu channel for time and space complexity analysis.

I hope it helps,

# ====================================
O(1) >O(log 100) > O(100) >O(100 log 100)>O(100 square2) >O(100 cube3) >O(2power100) >O(10!) 
1 > 2 > 100 > 200 > 10000 > 1000000 > 2 power 100 > 10!

constant when there is no loop or loop size is fixed
log n when loop gets reduced by order of 2 like 16, 8 ,4, 2, 1
linear when there is only 1 loop
n log n when there are 2 nested loops, first loop runs for n times and second loop runs for logn times
n square 2 when where are 2 nested loop both run for n times.
n cude 3 when where are 3 nested loop all run for n times.

2 power n when loop gets increamented in order of 2 like 1, 2, 4, 8, 16 etc.
n ! when loop gets executed in this fashion: 5 4 3 2 1 times or 1 2 3 4 5 times
