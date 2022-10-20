#include <iostream>

using namespace std;

void permute(string str, int start, int end) {
	if (start == end) {
		cout << str << endl;
	} else {
		for (int i = start; i <= end; ++i) {
			swap(str[start], str[i]);
			if(start > 0 && str[start - 1] == 'a' && str[start] == 'b') {

			} else permute(str, start + 1, end);
			swap(str[start], str[i]);
		}

	}
}

int main() {
	string str = "abcd";
	permute(str, 0, 3);
	return 0;
}
