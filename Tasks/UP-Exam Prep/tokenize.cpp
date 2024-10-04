#include <iostream>
using namespace std;

void print(char** words, size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		cout << words[i] << endl;
	}
}
void free(char** words, size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		delete[] words[i];
	}
	delete[] words;
}
bool isLetter(char ch) {
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
unsigned getWordsCount(const char* str) {
	if (!str)
		return 0;
	int count = 0;
	while (*str) {
		if (isLetter(*str) && !isLetter(*(str + 1))) {
			count++;
		}
		str++;
	}
	return count;
}
void skipInvalid(const char* str) {
	while (*str && !isLetter(*str)) {
		str++;
	}
}
char* getWord(const char* str) {
	int len = 0;
	while (isLetter(str[len])) {
		len++;
	}
	char* word = new char[len + 1];
	word[len] = '\0';
	for (size_t i = 0; i < len; i++)
	{
		word[i] = str[i];
	}
	str += len;
	return word;
}
char** tokenize(const char* str, size_t& size) {
	size = getWordsCount(str);
	char** words = new char* [size];
	int currInd = 0;
	while (*str) {
		skipInvalid(str);
		if (!(*str))
			break;
		char* word = getWord(str);
		words[currInd++] = word;
	}
	return words;
}

void test1() {
	const char* str = "Hello how are you";
	size_t size = 0;
	char** words = tokenize(str, size);
	print(words, size);
	free(words, size);
}