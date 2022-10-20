#include <iostream>

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
	node * parent = root;
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
	
	Inorder(root);
	return 0;
}
// 12 12 24 24 25 33 47 50 69 78 89 

// recursive
// #include <iostream>

// using namespace std;

// struct Node {
// 	int data;
// 	Node *left, *right;
// 	Node(int data) {
// 		this->data = data;
// 		this->left = NULL;
// 		this->right = NULL;
// 	}
// };

// Node *root = new Node(50);

// void inorder(Node *parent) {
// 	if (parent == NULL)
// 		return;
// 	inorder(parent->left);
// 	cout << parent->data << " ";
// 	inorder(parent->right);
// }

// Node* insert(Node *parent, int item) {
// 	if (parent == NULL)
// 		return new Node(item);
// 	else {
// 		if (item < parent->data)
// 			parent->left = insert(parent->left, item);
// 		else
// 			parent->right = insert(parent->right, item);
// 	}
// 	return parent;
// }

// int main() {

// 	insert(root, 33);
// 	insert(root, 24);
// 	insert(root, 47);
// 	insert(root, 12);

// 	insert(root, 12);
// 	insert(root, 78);
// 	insert(root, 25);
// 	insert(root, 89);
// 	insert(root, 24);
// 	insert(root, 69);


// 	inorder(root);
// 	return 0;
// }
