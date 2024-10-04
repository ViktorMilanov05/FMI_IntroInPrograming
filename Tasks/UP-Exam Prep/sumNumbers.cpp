#include <iostream>
using namespace std;

bool isDigit1(char ch) {
	return ch >= '0' && ch <= '9';
}
int sum(const char* str, int curr = 0, int final = 0) {
	if (!*str) {
		final += curr;
		return final;
	}
	if (isDigit1(*str)) {
		(curr *= 10) += (*str - '0');
	}
	else{
		final += curr;
		curr = 0;
	}
	return sum(str + 1, curr, final);
}