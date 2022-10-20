// problem
// arr = 10, 20, 30, 40, 50
// combination = ?

// approach
// total = pow(2, 4)
// 1. size 1
//    1. 10
//    2. 20
//    3. 30
//    4. 40
//    5. 50
// 2. size 2
//     10 20/30/40/50
//     20 30/40/50
//     30 40/50
//     40 50
// 3. size 3
//     10 20 30/40/50
//     20 30 40/50
//     30 40 50
// 4. size 4
//     10 20 30 40/50
//     20 30 40 50


// select(arr, 2)
// size = 5 
// i = 4 times
//     j = 1 times (2 - 1)
//     k = 4 times, 3 times, 2 times, 1 times

// select(arr, 3)
// size = 5
// i = 3 times
//     j = 2 times (3 - 1)
//     k = 3 times, 2 times, 1 times
