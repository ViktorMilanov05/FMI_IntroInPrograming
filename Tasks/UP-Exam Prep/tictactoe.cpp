#include <iostream>
using namespace std;

const unsigned N = 3;
const unsigned LINE = 3;
const unsigned PLAYERS = 2;
const char EMPTY = ' ';

void fill(char board[][N], char ch) {
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			board[i][j] = ch;
		}
	}
}
bool isValid(int row, int col) {
	return row >= 0 && col >= 0 && row < N && col < N;
}
void input(char matrix[][N], int& row, int& col) {
	do {
		cin >> row >> col;
	} while (!isValid(row, col));
}
unsigned getCount(char matrix[][N], int row, int col, int rowMove, int colMove) {
	int count = 0;
	char ch = matrix[row][col];
	while (isValid(row, col) && matrix[row][col] == ch) {
		count++;
		row += rowMove;
		col += colMove;
	}
	return count;
}
unsigned getRepeatingCount(char matrix[][N], int row, int col, int rowMove, int colMove) {
	return getCount(matrix, row, col, rowMove, colMove) + getCount(matrix, row, col, -rowMove, -colMove) - 1;
}
bool isItWin(char matrix[][N], int row, int col) {
	return getRepeatingCount(matrix, row, col, 1, 0) >= LINE ||
		getRepeatingCount(matrix, row, col, 0, 1) >= LINE ||
		getRepeatingCount(matrix, row, col, 1, 1) >= LINE ||
		getRepeatingCount(matrix, row, col, 1, -1) >= LINE;
}
void tictactoe(){
	char board[N][N];
	fill(board, EMPTY);
	bool haveWinner = false;
	for (int i = 0, curr = 0; i < (N * N) || !haveWinner; i++, (++curr) %= PLAYERS) {
		int row, col;
		input(board, row, col);
		board[row][col] = 'A' + curr;
		haveWinner = isItWin(board, row, col);
	}
	cout << haveWinner ? "Winner!" : "Draw";
}