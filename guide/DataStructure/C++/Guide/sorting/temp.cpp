#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperand(char ch) {
	return 'a' <= ch && ch <= 'z' ? true : false;
}

int getPreccedence(char ch) {
	int precedence = 0;
	if (ch == '^') {
		precedence = 3;
	} else if (ch == '*' || ch == '/') {
		precedence = 2;
	} else if (ch == '+' || ch == '-') {
		precedence = 1;
	}
	return precedence;
}
void printStack(stack<char> s) {
	while (s.empty() == false) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}

int main() {
	string infix = "a+b*(c^d-e)^(f+g*h)-i";
	stack<char> stack1;
	unsigned short i;
	for (i = 0; i < infix.length(); i++) {
		char ch = infix[i];
		if (isOperand(ch)) {
			cout << ch;
		} else {
			if (ch == '(') {
				stack1.push('(');
			} else if (ch == ')') {
				while (!stack1.empty()) {
					if (stack1.top() == '(')
						break;
					cout << stack1.top();
					stack1.pop();
				}
				stack1.pop();
			} else {

				while (!stack1.empty()
						&& getPreccedence(stack1.top()) >= getPreccedence(ch)) {
					cout << stack1.top();
					stack1.pop();
				}

				stack1.push(ch);
			}
		}
	}
	printStack(stack1);
	return 0;
}
