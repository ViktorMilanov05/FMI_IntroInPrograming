#include <iostream>
using namespace std;
int getDigits(int n) {
	if (n == 0)
		return 1;
	int count = 0;
	while (n != 0) {
		count++;
		n /= 10;
	}
	return count;
}
char getChar5(int n) {
	return n + '0';
}
char* getString() {
	int n;
	cin >> n;
	int size = getDigits(n);
	char* res = new char[size + 1];
	res[size] = '\0';
	while (size > 0)
	{
		unsigned lastDigit = n % 10;
		n /= 10;

		res[size - 1] = lastDigit + '0';
		--size;
	}
	return res;
}
void free(char** matrix, int n) {
	for (size_t i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}
void swap(char*& first,char*& second) {
	char* temp = first;
	first = second;
	second = temp;
}
int myStrcmp(const char* first, const char* second) {
	if (!first || !second)
		return 0;
	while (*first && *second && ((*first) == (*second))) {
		first++;
		second++;
	}
	return *first - *second;
}
void sort(char** strings, int size) {
	for (size_t i = 0; i < size - 1; i++)
	{
		int minInd = i;
		for (size_t j = i; j < size; j++)
		{
			if (myStrcmp(strings[minInd], strings[j]) > 0) {
				minInd = j;
			}
		}
		if (minInd != i)
			swap(strings[minInd], strings[i]);
	}
}
int main() {
	int n;
	cin >> n;
	char** strings = new char* [n];
	for (size_t i = 0; i < n; i++)
	{
		strings[i] = getString();
	}
	sort(strings, n);
	for (size_t i = 0; i < n; i++)
	{
		cout << strings[i] << endl;
	}
	free(strings, n);
}