#include <iostream>
using namespace std;
int** createMatrix(int rows) {
	int** res = new int* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		int cols;
		cin >> cols;
		res[i] = new int[cols + 2];
		res[i][0] = cols;
	}
	return res;
}
void print(int** matrix, int rows) {
	for (size_t i = 0; i < rows; i++)
	{
		int size = matrix[i][0];
		for (size_t j = 2; j < size + 2; j++)
		{
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}
void free(int** matrix, int rows) {
	for (size_t i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}
void mySwap(int*& first, int*& second) {
	int* temp = first;
	first = second;
	second = temp;
}
void moveUpper(int** matrix, int row) {
	while (row > 0 && matrix[row][1] > matrix[row - 1][1]) {
		mySwap(matrix[row], matrix[row - 1]);
		row--;
	}
}
void addPoints(int** matrix, int row, int col, int points) {
	matrix[row][col + 2] += points;
	matrix[row][1] += points;
	moveUpper(matrix, row);
}
void test3() {
	int rows;
	cin >> rows;
	int** matrix = createMatrix(rows);
	print(matrix, rows);
	int n;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		int row, col, points;
		cin >> row >> col >> points;
		addPoints(matrix, rows, col, points);
		print(matrix, rows);
	}
	free(matrix, rows);
}