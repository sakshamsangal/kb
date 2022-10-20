// 1. bst
// 2. every node = red/black
// 3. root = black
// 5. black node accepts everything
// 6. red node does not accepts red on top and bottom
// 7. path from root to null must have same no of black
// 8. null node are black

// x = red
// if x == root then x = black
// if uncle == red
//     toggle parent, uncle and grandParent
// if uncle == black 
//     if triangle then move triangle up
//     if line then move parent up and swap grandParent and parent color


