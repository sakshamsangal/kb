// 1. bst
// 2. every node = red/black
// 3. root = black
// 5. black node accepts everything
// 6. red node does not accepts red on top and bottom
// 7. path from root to null must have same no of black
// 8. null node are black

// delete x
// replace with inorder predeccessor
//     inorder predeccessor == red then do nothing
//     inorder predeccessor == black then make null doubleBlack

// resovle doubleBlack 
// if root == doubleBlack then make black
// if doubleBlack sibling == red 
//     swap sibling and parent color
//     move sibling up 
// if doubleBlack sibling == black 
//     if both child == black
//          doubleBlack node = black
//          sibling = red
//          if parent == red 
//              parent = black 
//          else 
//              parent = doubleBlack
//     if triangle child == red and line child == black 
//          swap sibling and triangle childcolor
//          move triangle child up 
//     if line child == red
//          doubleBlack node = black
//          line child = black
//          swap sibling and parent color
//          move sibling up



