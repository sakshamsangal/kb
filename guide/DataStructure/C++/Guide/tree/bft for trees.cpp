// 2 types
// 1. breadth first traversal
//    1. level order
// 2. depth first traversal
//    1. inorder
//    2. preorder
//    3. postorder

// 1. make queue
// 2. enqueue root to queue
// 3. item = dequeue 
// 4. print item
// 5. enqueue children
// 6. goto 3 
// 7. do this until queue is not empty
// void breadthFirstTraversal() {
//     parent = root;
//     q1.enqueue(parent);
//     while(!q1.empty()) {
//         cout << q1.front();
//         if(q1.front()->left != NULL) q1.enqueue(q1.front()->left);
//         if(q1.front()->right != NULL) q1.enqueue(q1.front()->right);
//         q1.dequeue();
//     }

// }
