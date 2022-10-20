// n queen problem
#include <iostream>

using namespace std;

const int row = 4, col = 4;
int mat[row][col];

bool isSafe(int x, int y) {
	int i = x;
	int j = y;
	// checking for upper diagonal
	while (i > -1 && j > -1) {
		if (mat[i--][j--] == 1)
			return false;
	}

	j = y;
	// checking for row
	while (j > -1) {
		if (mat[x][j--] == 1)
			return false;
	}

	i = x;
	j = y;
	// checking for lower diagonal
	while (i < row && j > -1) {
		if (mat[i++][j--] == 1)
			return false;
	}

	return true;
}

bool solveRec(int j) {
	if (j == col)
		return true;
	else {
		for (int i = 0; i < row; i++) {
			if (isSafe(i, j)) {
				mat[i][j] = 1;
				if (solveRec(j + 1))
					return true;
				mat[i][j] = 0;
			}
		}
		return false;
	}
}

void printMatrix() {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}



int main() {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			mat[i][j] = 0;

		}
	}
	if(solveRec(0)) {
		printMatrix();
	} else {
		cout << "no solution possible\n";
	}
	return 0;
}


// 0 0 1 0 
// 1 0 0 0 
// 0 0 0 1 
// 0 1 0 0 


// // n queen problem
// #include <iostream>

// using namespace std;

// const int N = 4;
// int board[N][N] = {
// 		{0,0,0,0},
// 		{0,0,0,0},
// 		{0,0,0,0},
// 		{0,0,0,0}
// };

// void printMatrix() {
// 	for (int i = 0; i < N; ++i) {
// 		for (int j = 0; j < N; ++j) {
// 			cout << board[i][j] << " ";
// 		}
// 		cout << endl;
// 	}
// }

// bool isSafe(int x, int y) {
// 	int i, j;

// 	// check upper diagonal
// 	for (i = x - 1, j = y - 1; i > -1 && j > - 1 ; i --, j--) {
// 		if(board[i][j] == 1) return false;
// 	}

// 	// check row
// 	for (i = y - 1; i > -1; i--) {
// 		if(board[x][i] == 1) return false;
// 	}

// 	// check for lower diagonal
// 	for (i = x + 1, j = y - 1; i < N && j > - 1 ; i ++, j--) {
// 			if(board[i][j] == 1) return false;
// 	}

// 	return true;
// }

// bool hasSolution(int col) {
// 	if(col == N) return true;
// 	for (int i = 0; i < N; ++i) {
// 		if(isSafe(i, col)) {
// 			board[i][col] = 1;
// 			if(hasSolution(col + 1)) return true;
// 			board[i][col] = 0;
// 		}
// 	}
// 	return false;
// }

// int main() {
// 	if(hasSolution(0)) {
// 		printMatrix();
// 	} else {
// 		cout << "no solution\n";
// 	}
// 	return 0;
// }
