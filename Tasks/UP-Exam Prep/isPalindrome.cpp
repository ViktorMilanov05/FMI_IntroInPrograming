#include <iostream>
bool isPalindrome(const char* str, size_t len) {
	if (len == 1) {
		return true;
	}
	return str[0] == str[len - 1] && isPalindrome(str + 1, len - 2);
}
bool isPalindrome(const char* str) {
	return isPalindrome(str, strlen(str));
}