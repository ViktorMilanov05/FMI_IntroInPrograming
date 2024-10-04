#include <iostream>

void divideBy(double arr[],int size, double by) {
	for (size_t i = 0; i < size; i++)
	{
		arr[i] /= by;
	}
}
void substract(double first[], double second[], double coef, int size) {
	for (size_t i = 0; i < size; i++)
	{
		first[i] -= (second[i] * coef);
	}
}
void makeAllZeros(double matrix[][3], int rows, int cols, int curr) {
	for (size_t i = 0; i < rows; i++)
	{
		if (matrix[i] != matrix[curr]) {
			substract(matrix[i], matrix[curr], matrix[i][curr], cols);
		}
	}
}
void gauss(double matrix[][3], int n, double result[]) {
	int rows = n;
	int cols = n + 1;
	for (size_t i = 0; i < rows; i++)
	{
		divideBy(matrix[i], cols, matrix[i][i]);
		makeAllZeros(matrix, rows, cols, i);
	}
	for (size_t i = 0; i < rows; i++)
	{
		result[i] = matrix[i][cols - 1];
	}
}

