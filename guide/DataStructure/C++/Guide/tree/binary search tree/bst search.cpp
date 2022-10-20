// searchInBST(item) {
//     if parent == NULL
//         if stack empty  
//             return 0 
//         else    
//             parent = top->right; pop 
//     else 
//         if parent->data == item 
//             return 1
//         else
//             push(parent)
//             parent = parent->left 


// }

#include <iostream>
#include <stack>
using namespace std;

struct node {
	int data;
	node *left, *right;
	node(int data) {
		this->left = NULL;
		this->data = data;
		this->right = NULL;
	}
};
node *root = new node(50);

void insert(node *item) {
	node *parent = root;
	bool isNotInserted = true;

	while (isNotInserted) {
		if (item->data < parent->data) {
			if (parent->left == NULL) {
				parent->left = item;
				isNotInserted = false;
			} else {
				parent = parent->left;
			}
		} else {
			if (parent->right == NULL) {
				parent->right = item;
				isNotInserted = false;
			} else {
				parent = parent->right;
			}
		}
	}
}

void Inorder(node *root) {
	if (root == NULL)
		return;
	else {
		Inorder(root->left);
		cout << root->data << " ";
		Inorder(root->right);
	}
}

// void inorder() {
// 	stack<node*> stk;
// 	node *parent = root;
// 	stk.push(parent);
// 	parent = parent->left;
// 	bool isNotCompleted = true;

// 	while (isNotCompleted) {
// 		if (parent != NULL) {
// 			stk.push(parent);
// 			parent = parent->left;
// 		}
// 		if (parent == NULL) {
// 			if (stk.empty()) {
// 				isNotCompleted = false;
// 			} else {
// 				parent = stk.top();
// 				stk.pop();
// 				cout << parent->data << " ";
// 				parent = parent->right;
// 			}
// 		}
// 	}
// }

int searchInBST(int item) {
	stack<node*> stk;
	node *parent = root;
	while (true) {
		if (parent == NULL) {
			if (stk.empty())
				return 0;
			else {
				parent = stk.top();
				parent = parent->right;
				stk.pop();
			}

		} else {
			if (parent->data == item)
				return 1;
			else {
				stk.push(parent);
				parent = parent->left;

			}
		}

	}
}
int main() {

	insert(new node(33));
	insert(new node(24));
	insert(new node(47));
	insert(new node(12));
	insert(new node(12));
	insert(new node(78));
	insert(new node(25));
	insert(new node(89));
	insert(new node(24));
	insert(new node(69));
	cout << searchInBST(89);
	return 0;
}
// 12 12 24 24 25 33 47 50 69 78 89
