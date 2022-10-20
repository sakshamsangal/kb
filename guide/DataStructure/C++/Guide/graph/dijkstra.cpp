// 1. ans = 0
// 2. queue = vertex of graph
// 3. source = extractMin(queue) 
// 4. ans += item
// 5. i: destination
//    1. w = distance from source to destination
//    2. if cost[source] + w < cost[i]
//       1. cost[i] = cost[source] + w
//       2. parent[i] = source
// 6.  goto 3
// 7.  repeat this until queue is empty