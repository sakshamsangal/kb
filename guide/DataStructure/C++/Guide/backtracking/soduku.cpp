#include <iostream>
#include <math.h>

using namespace std;

const int size = 4;
int grid[size][size] = {
		{1, 0, 3, 0},
		{0, 0, 2, 1},
		{0, 1, 0, 2},
		{2, 4, 0, 0}
};

bool isSafe(int x, int y, int item) {

	// checking for row and column
	for (int i = 0; i < size; ++i) {
		if(grid[x][i] == item || grid[i][y] == item) {
			return false;
		}
	}

	// checking for sub grid
	int subGridSize = sqrt(size);
	int rs = x - (x % subGridSize);
	int cs = y - (y % subGridSize);

	for (int i = rs; i < rs + subGridSize; ++i) {
		for (int j = cs; j < cs + subGridSize; ++j) {
			if(grid[i][j] == item) {
				return false;
			}
		}
	}

	return true;

}


bool checkForEmptyCell() {

	int i, j;
	bool isNoEmptyCell = true;

	// check for empty cell
	for (i = 0; i < size && isNoEmptyCell; ++i) {
		for (j = 0; j < size && isNoEmptyCell; ++j) {
			if(grid[i][j] == 0) isNoEmptyCell = false;
		}
	}


	if(isNoEmptyCell) { // we are done. we have placed all numbers.
		return true;
	} 
	
	// we need to insert numbers
	i--,j--;
	for (int a = 1; a <= size; a++) {
		if(isSafe(i, j, a)) {
			grid[i][j] = a;
			if(checkForEmptyCell()) return true;
			grid[i][j] = 0;
		}
	}
	return false;

}
void printMatrix() {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	checkForEmptyCell();
	printMatrix();
	return 0;

}
// 1 2 3 4 
// 4 3 2 1 
// 3 1 4 2 
// 2 4 1 3 