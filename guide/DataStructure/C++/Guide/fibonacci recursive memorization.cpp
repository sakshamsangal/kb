#include <iostream>
#define size 5

using namespace std;

int memo[size] = {-1, -1, -1, -1, -1};

// n != 0
// n 1, 2, ....
int getFibonacci(int n) {
	if(memo[n - 1] == -1) {
		if(n == 1) memo[n - 1] = 0;
		else if(n == 2) memo[n - 1] = 1;
		else memo[n - 1] = getFibonacci(n - 1) + getFibonacci(n - 2);
	}
	return memo[n - 1];
}

int main() {


	cout << getFibonacci(5) << " ";


	return 0;
}
