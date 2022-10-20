In delete operation of BST, we need inorder successor (or predecessor) of a node when the node to be deleted has both left and right child as non-empty. Which of the following is true about inorder successor needed in delete operation?
A Inorder Successor is always a leaf node
B Inorder successor is always either a leaf node or a node with empty left child
C Inorder successor may be an ancestor of the node
D Inorder successor is always either a leaf node or a node with empty right child

Answer B
Explanation
Let X be the node to be deleted in a tree with root as 'root'. There are three cases for deletion
1) X is a leaf node: We change left or right pointer of parent to NULL (depending upon whether X is left or right child of its parent) and we delete X
2) One child of X is empty: We copy values of non-empty child to X and delete the non-empty child
3) Both children of X are non-empty: In this case, we find inorder successor of X. Let the inorder successor be Y. We copy the contents of Y to X, and delete Y.
So we need inorder successor only when both left and right child of X are not empty. In this case, the inorder successor Y can never be an ancestor of X. In this case, the inorder successor is the leftmost node in right subtree of X. Since it is leftmost node, the left child of Y must be empty.

What is the worst case time complexity for search, insert and delete operations in a general Binary Search Tree?
A O(n) for all
B O(Logn) for all
C O(Logn) for search and insert, and O(n) for delete
D O(Logn) for search, and O(n) for insert and delete

Answer A
Explanation
In skewed Binary Search Tree (BST), all three operations can take O(n). See the following example BST and operations.

          10

        /

       20

      /

     30

    / 

   40


Search 40. 
Delete 40
Insert 50.


We are given a set of n distinct elements and an unlabeled binary tree with n nodes. In how many ways can we populate the tree with the given set so that it becomes a binary search tree? (GATE CS 2011)
A 0
B 1
C n!
D (1/(n+1)).2nCn

Answer B
Explanation
There is only one way. The minimum value has to go to the leftmost node and the maximum value to the rightmost node. Recursively, we can define for other nodes.


How many distinct binary search trees can be created out of 4 distinct keys?
A 4
B 14
C 24
D 42

Answer 14 


Suppose the numbers 7, 5, 1, 8, 3, 6, 0, 9, 4, 2 are inserted in that order into an initially empty binary search tree. The binary search tree uses the usual ordering on natural numbers. What is the in-order traversal sequence of the resultant tree?
A 7 5 1 0 3 2 4 6 8 9
B 0 2 4 3 1 6 5 9 8 7
C 0 1 2 3 4 5 6 7 8 9
D 9 8 6 4 2 3 0 1 5 7

Answer C
Explanation
In-order traversal of a BST gives elements in increasing order. So answer c is correct without any doubt.


The following numbers are inserted into an empty binary search tree in the given order: 10, 1, 3, 5, 15, 12, 16. What is the height of the binary search tree (the height is the maximum distance of a leaf node from the root)? (GATE CS 2004)
A 2
B 3
C 4
D 6

Answer B 
Explanation
Constructed binary search tree will be..
                    10

                  /     \

                 1       15

                 \      /  \

                  3    12   16

                    \

                     5

The preorder traversal sequence of a binary search tree is 30, 20, 10, 15, 25, 23, 39, 35, 42. Which one of the following is the postorder traversal sequence of the same tree?
A 10, 20, 15, 23, 25, 35, 42, 39, 30
B 15, 10, 25, 23, 20, 42, 35, 39, 30
C 15, 20, 10, 23, 25, 42, 35, 39, 30
D 15, 10, 23, 25, 20, 35, 42, 39, 30

Answer D
Explanation
The following is the constructed tree
            30

         /      \

        20       39 

       /  \     /  \

     10    25  35  42  

      \   /

      15 23

Consider the following Binary Search Tree

               10

             /    \

            5      20

           /      /  \           

          4     15    30

               /  

              11 

If we randomly search one of the keys present in above BST, what would be the expected number of comparisons?

A 2.75
B 2.25
C 2.57
D 3.25

Answer C
Explanation
Expected number of comparisons = (1*1 + 2*2 + 3*3 + 4*1)/7 = 18/7 = 2.57

Which of the following traversals is sufficient to construct BST from given traversals
1) Inorder
2) Preorder
3) Postorder

A Any one of the given three traversals is sufficient
B Either 2 or 3 is sufficient
C 2 and 3
D 1 and 3

Answer B
Explanation
When we know either preorder or postorder traversal, we can construct the BST. Note that we can always sort the given traversal and get the inorder traversal. Inorder traversal of BST is always sorted.