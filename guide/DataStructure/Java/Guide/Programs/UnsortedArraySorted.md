
void maxElements(arr1, arr2, size1, size2) {
    i = 1
    for(j = 1 to < size1 - 1) {
        if (arr1[j] < arr1[j - 1]) i = j 
    }

    max = negative infinity

    for(j = 1 to < size2) {
        if (arr2[j] >= arr1[i - 1] && arr2[j] <= arr1[i + 1]) {
            max = arr2[i]
        }
    }

    if (max == negative infinity) {
        print "Not Possible"
    } else {
        print max
    }

}