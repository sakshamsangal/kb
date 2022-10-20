// problem
// 1. value = 60 100 120
// 2. weight = 10 20 30
// 3. capacity = 50
// 4. max value = ?

// solution 
// 1. list combination of weight
//    1. 10
//    2. 20
//    3. 30
//    4. 10 20
//    5. 20 30
//    6. 10 30
//    7. 10 20 30
// 2. select those only which <= 50
//    1. 10
//    2. 20
//    3. 30
//    4. 10 20 = 30
//    5. 20 30 = 50
//    6. 10 30 = 40
// 3. find value of every combination
//    1. 60
//    2. 100
//    3. 120
//    4. 60 100 = 160
//    5. 100 120 = 120
//    6. 60 120 = 180
// 4. find max value
//    1. 180

// programming approach
// 1. make array of vectors
// 2. make another array of vectors which <= 50 
// 3. make vectors which store the sum of individual vector of step 2
// 4. get max of vector of step 3


