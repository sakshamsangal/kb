// inorder tree stack
// while isNotCompleted
//     if parent != NULL
//         push parent
//         move parent to left 
//     if parent == NULL 
//         if stack empty
//             isNotCompleted = false
//         else 
//             parent = top and pop it 
//             print parent 
//             move parent right

    

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
void printStack(stack<node*> stk) {
	while (!stk.empty()) {
		cout << stk.top()->data << " ";
		stk.pop();
	}
	cout << endl;
}
void inorder() {
	stack<node*> stk;
	node *parent = root;
	stk.push(parent);
	parent = parent->left;
	bool isNotCompleted = true;

	while (isNotCompleted) {
		if (parent != NULL) {
			stk.push(parent);
			parent = parent->left;
		}
		if (parent == NULL) {
			if (stk.empty()) {
				isNotCompleted = false;
			} else {
				parent = stk.top();
				stk.pop();
				cout << parent->data << " ";
				parent = parent->right;
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

	inorder();
	return 0;
}
// 12 12 24 24 25 33 47 50 69 78 89
