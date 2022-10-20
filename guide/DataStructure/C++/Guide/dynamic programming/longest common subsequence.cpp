#include <iostream>
#include<algorithm>
using namespace std;

int getMatchCount(string str1, string str2, int end1, int end2) {

	if(end1 < 0 || end2 < 0) return 0;

	if(str1[end1] == str2[end2]) return 1 + getMatchCount(str1, str2, end1 - 1, end2 - 1);
	else return max(getMatchCount(str1, str2, end1 - 1, end2), getMatchCount(str1, str2, end1, end2 - 1));

}

int main() {

	string str1 = "axyz";
	string str2 = "baz";

	cout << getMatchCount(str1, str2, str1.length() - 1, str2.length() - 1);

	return 0;
}

