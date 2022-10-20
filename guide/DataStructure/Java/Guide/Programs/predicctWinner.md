prev = 0
i = 0
sum[2]
traverse through the list
    if prev % 2 == 0
        x = list.pollFirst();
    else 
        x = list.pollLast();
    sum[i] += x
    i ^= 1
    prev = x