#include <iostream>

using namespace std;

void towerOfHanoi(int n, int source, int destination, int temp) {
    if(n == 1) {
        cout << "move disk 1 from rod " << source << " to rod " << destination << endl;
        return;
    }
    towerOfHanoi(n-1, source, temp, destination);
    cout << "move disk " << n << " from rod " << source << " to rod " << destination << endl;
    towerOfHanoi(n-1, temp, destination, source);
}

int main() {
	towerOfHanoi(3, 1, 3, 2);
	return 0;
}
