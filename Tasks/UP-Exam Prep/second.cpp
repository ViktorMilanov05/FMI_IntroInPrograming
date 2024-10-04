#include <iostream>
bool isDigit2(char ch) {
	return ch <= '9' && ch >= '0';
}

unsigned getMaxNumberCount(const char* str, unsigned final = 0, unsigned curr = 0) {
	std::max(final, curr);
	if (!(*str))
		return final;
	if (isDigit2(*str))
		curr++;
	else {
		curr = 0;
	}
	return getMaxNumberCount(str + 1, final, curr);
}