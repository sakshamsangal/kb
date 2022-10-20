// inorder left parent right
// 1. if null
//    1. pop
//    2. print poped
// 2. else
//    1. push parent
//    2. move left
//    3. goto 1

// void inorder(Node * parent) {
//     if(parent == NULL) return;
//     inorder(parent->left);
//     cout << parent->data << " ";
//     inorder(parent->right);
// }