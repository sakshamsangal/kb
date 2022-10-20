// all permutation of string

#include <iostream>

using namespace std;

void permute(string str, int start, int end) {

	// if len = 1
	if(start == end) {
		 cout << str << endl;
		 return;
	}
	for (int i = start; i <= end; ++i) {

		// make choice
		swap(str[start], str[i]);

		// fill next element
		permute(str, start + 1, end);

		// undo
		swap(str[start], str[i]);
	}
}

int main() {
	permute("abc", 0, 2);
	return 0;
}


// abc
// acb
// bac
// bca
// cba
// cab