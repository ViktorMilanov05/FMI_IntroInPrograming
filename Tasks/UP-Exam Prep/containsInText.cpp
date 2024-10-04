#include <iostream>
bool isPrefix1(const char* text, const char* pattern) {
	if (!(*pattern))
		return true;
	return *text == *pattern && isPrefix1(text + 1, pattern + 1);
}
bool findInText(const char* text, size_t size1, const char* pattern, size_t size2) {
	if (size1 < size2)
		return false;
	return isPrefix1(text, pattern) || findInText(text + 1, size1 - 1, pattern, size2);
}
bool findInText(const char* text, const char* pattern) {
	return findInText(text, strlen(text), pattern, strlen(pattern));
}