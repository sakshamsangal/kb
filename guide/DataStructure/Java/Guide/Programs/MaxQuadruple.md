```
int maxProdQuad(n, arr) {
    max = positive infinity
    min = negative infinity

    if (n < 4) return -1

    maxA = negative infinity
    maxB = negative infinity
    maxC = negative infinity
    maxD = negative infinity

    minA = positive infinity
    minB = positive infinity
    minC = positive infinity
    minD = positive infinity

    for(each item in arr) { 
        if (item > maxA) {
            maxD = maxC
            maxC = maxB
            maxB = maxA
            maxA = item
        } else if (item > maxB) {
            maxD = maxC
            maxC = maxB
            maxB = item
        } else if (item > maxC) {
            maxD = maxC
            maxC = item
        } else if (item > maxD) {
            maxD = item
        } 

        if (item < minA) {
            minD = minC
            minC = minB
            minB = minA
            minA = item
        } else if (item < minB) {
            minD = minC
            minC = minB
            minB = item
        } else if (item < minC) {
            minD = minC
            minC = item
        } else if (item < minD) {
            minD = item
        } 
        
    }

    x = maxA * maxB * maxC * maxD 
    y = minA * minB * minC * minD 
    z = minA * minB * maxA * maxB

    return maximum of x and (maximum of y and z)

}

```