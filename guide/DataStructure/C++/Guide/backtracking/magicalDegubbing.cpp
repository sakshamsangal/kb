#include <iostream>
#include <math.h>

using namespace std;

const int size = 9;
int grid[size][size];
const int subGridSize = sqrt(size);

bool isSafe(int x, int y, int item) {
//	cout << "x = " << x << " y = " << y << endl;
	int i, j;
	// checking for row and column
	for (i = 0; i < size; ++i)
		if (grid[x][i] == item || grid[i][y] == item) return false;


	// checking for sub grid
//	cout << "x = " << x << " y = " << y << endl;
	int rs = x - (x % subGridSize);
	int cs = y - (y % subGridSize);

//	cout << subGridSize << endl;
//	cout << "rs = " << rs << " cs = " << cs << endl;
	for (i = rs; i < rs + subGridSize; ++i)
		for (j = cs ; j < cs + subGridSize; ++j)
			if (grid[i][j] == item) return false;

	return true;

}
void printMatrix() {
	int c = subGridSize - 1;
	int d;
	for (int i = 0; i < size; ++i) {
		d = subGridSize - 1;;
		for (int j = 0; j < size; ++j) {
			if(0 < grid[i][j] && grid[i][j] < 10) cout << "0";
			cout << grid[i][j] << " ";
			if(j == d ) {
				d = d + subGridSize;
				cout << " | ";
			}
		}
		if(i == c) {
			c = c + subGridSize;
			cout << endl;
		}

		cout << endl;
	}
	cout << endl;
}
//int count = 0;
bool fillCell() {
//	count ++;
//	if (count == 2) return true;
	int m, n, a;
	bool allFilled = true;

	// check for empty cell
	for (m = 0; (m < size) && allFilled; m++)
		for (n = 0; (n < size) && allFilled; n++)
			if (grid[m][n] == 0) {
//				cout << "m = " << m << " n = " << n << endl;
				allFilled = false;
			}



	if (allFilled) return true; // we are done. we have placed all numbers.

	// we need to insert numbers
//	printMatrix();
	m--;n--;
	for (a = 1; a <= size; a++) {
//		cout << "a = " << a << endl;
//		cout << "m = " << m << " n = " << n << endl;
		if (isSafe(m, n, a)) {
			grid[m][n] = a;
			if (fillCell()) return true;
			grid[m][n] = 0;
		}
	}


	return false;
}


int main() {
	int i, j;
	for (i = 0; i < size; ++i)
		for (j = 0; j < size; ++j)
			grid[i][j] = 0;

	fillCell();
	printMatrix();
	return 0;
}
