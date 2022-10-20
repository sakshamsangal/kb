#include <iostream>

using namespace std;

const int row = 5;
const int col = 10;

int maze[row][col] = { {1,1,1,1,1,1,1,1,1,1},
		{1,1,1,0,0,1,1,1,1,1},
		{1,1,1,1,1,1,0,0,0,0},
		{1,1,0,0,0,1,1,1,1,1},
		{1,1,0,0,0,0,0,0,0,1}};
int solutionMaze[row][col];
bool canMove(int x, int y) {
	if (x == row - 1 && y == col - 1) {
		solutionMaze[x][y] = 1;
		return true;
	} else {
		// can move down
		if (x < row && maze[x + 1][y] == 1) {
			solutionMaze[x + 1][y] = 1;
			if (canMove(x + 1, y))
				return true;
			else
				solutionMaze[x + 1][y] = 0;

		}
        // can move right
		if (y < col && maze[x][y + 1] == 1) {
			solutionMaze[x][y + 1] = 1;
			if (canMove(x, y + 1))
				return true;
			else
				solutionMaze[x][y + 1] = 0;
		}
        
        // cannot move anywhere
		return false;
	}
}

void printMatrix(int arr[row][col]) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			solutionMaze[i][j] = 0;
		}
	}
	printMatrix(maze);
	cout << endl;
	solutionMaze[0][0] = 1;
	if (canMove(0, 0)) {
		printMatrix(solutionMaze);
	} else {
		cout << "no solution of maze\n";
	}

	return 0;
}

// 1 1 1 1 1 1 1 1 1 1 
// 1 1 1 0 0 1 1 1 1 1 
// 1 1 1 1 1 1 0 0 0 0 
// 1 1 0 0 0 1 1 1 1 1 
// 1 1 0 0 0 0 0 0 0 1 

// 1 0 0 0 0 0 0 0 0 0 
// 1 0 0 0 0 0 0 0 0 0 
// 1 1 1 1 1 1 0 0 0 0 
// 0 0 0 0 0 1 1 1 1 1 
// 0 0 0 0 0 0 0 0 0 1 

// another approach
// #include <iostream>

// using namespace std;
// const int row = 5;
// const int col = 10;

// int maze[row][col] = { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 0, 0, 1, 1,
// 		1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 }, { 1, 1, 0, 0, 0, 1, 1, 1,
// 		1, 1 }, { 1, 1, 0, 0, 0, 0, 0, 0, 0, 1 } };
// int sMaze[row][col];

// bool isSafe(int i, int j) {
// 	return i < row && j < col && maze[i][j] == 1;
// }

// bool isPathExist(int x, int y) {
// 	if (x == row - 1 && y == col - 1) {
// 		sMaze[x][y] = 1;
// 		return true;
// 	} else {
// 		if (isSafe(x, y)) {
// 			sMaze[x][y] = 1;
// 			if (isPathExist(x + 1, y))
// 				return true;
// 			if (isPathExist(x, y + 1))
// 				return true;
// 			sMaze[x][y] = 0;
// 		}
// 	}
// 	return false;
// }
// void printMatrix(int arr[row][col]) {
// 	for (int i = 0; i < row; ++i) {
// 		for (int j = 0; j < col; ++j) {
// 			cout << arr[i][j] << " ";
// 		}
// 		cout << endl;
// 	}
// }

// int main() {
// 	for (int i = 0; i < row; ++i) {
// 		for (int j = 0; j < col; ++j) {
// 			sMaze[i][j] = 0;
// 		}
// 	}
// 	isPathExist(0, 0);
// 	printMatrix(sMaze);
// 	return 0;
// }



