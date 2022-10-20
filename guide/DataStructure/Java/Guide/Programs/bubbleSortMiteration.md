```
Hi Sambath, Thanks for reaching out to us.

 

For example, if M = 0, the bubble sort program will perform 0 swaps in 0 iterations.
It means the number of iterations is zero. So the program will not perform any swaps and hence output as 0

 

In bubble sort, an iteration is defined as the total number of times the outer loop runs. Assume that:
There are 2 loops in bubble sort in iterative solution, here it is talking about 1st loop. He is saying that M is the count of iteration of the outer loop.
We also need to assume something like:

 

1) M <= the array size and // if array size is 10 then M ranges from 0 to 10 both inclusive.
2) the program sorts in descending order. // the bubble sort will sort the elements in descending order.

 

The code should ask the user to input the values for M, the array size, and finally the elements of the array. So, there will be three types of inputs — 

Input 1: The value of M
Input 2: The size of the array
Input 3: The elements inside the array

 

Sample Input: 
2 // count of outer loop
4 // size of array
1 // arr[0]
2 // arr[1] 
3 // arr[2]
4 // arr[3]

Sample Output:
5 //  total swaps till M iteration 

 

arr = [1 2 3 4] // given array 
1st iteration:
2 3 4 1 // 3 swaps done (1, 2) (1, 3) (1, 4)

2nd iteration:
3 4 2 1 // 2 swaps done (2, 3) (2, 4)

 

Thanks & Regards,
upGrad Tech Support

```