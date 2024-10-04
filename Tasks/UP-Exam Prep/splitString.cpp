#include <iostream>
using namespace std;

void print(char** words) {
	for (size_t i = 0; words[i] != nullptr; i++)
	{
		cout << words[i] << endl;
	}
}
void free(char** words) {
	for (size_t i = 0; words[i] != nullptr; i++)
	{
		delete[] words[i];
	}
	delete[] words;
}
unsigned getChar(const char* str, char separator) {
	if (!str)
		return 0;
	int count = 0;
	while (*str) {
		if (*str == separator)
			count++;
		str++;
	}
	return count;
}

int getSepInd(const char* str, char separator) {
	if (!str)
		return -1;
	for (size_t i = 0;; i++)
	{
		if (*str == '\0' || *str == separator)
			return i;
	}
}
void copyN(const char* from, char* to, int count) {
	for (size_t i = 0; i < count; i++)
	{
		to[i] = from[i];
	}
}
char** split(const char* words, char separator) {
	int size = getChar(words, separator) + 2;
	char** res = new char* [size];
	res[size - 1] = nullptr;
	int wordInd = 0;
	while (*words) {
		int sepInd = getSepInd(words, separator);
		char* word = new char[sepInd + 1];
		word[sepInd] = '\0';
		copyN(words, word, sepInd);
		res[wordInd++] = word;
		words += sepInd;
		if (*words == separator) {
			words++;
		}
	}
	return res;
}
void test2() {
	char** words = split("hello!how!are!you", '!');
	print(words);
	free(words);
}