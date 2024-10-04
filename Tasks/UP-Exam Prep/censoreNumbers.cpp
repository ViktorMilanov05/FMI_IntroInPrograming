unsigned myLen(const char* str) {
	if (!str)
		return 0;
	unsigned count = 0;
	while (*str) {
		count++;
		str++;
	}
	return count;
}
bool isDigit(char ch) {
	return ch >= '0' && ch <= '9';
}
unsigned getDigitCount(const char* str) {
	if (!str)
		return 0;
	unsigned count = 0;
	while (*str) {
		if (isDigit(*str)) {
			count++;
		}
		str++;
	}
	return count;
}
unsigned getNumbersCount(const char* str) {
	if (!str)
		return 0;
	unsigned count = 0;
	while (*str) {
		if (isDigit(*str) && !isDigit(*(str + 1))) {
			count++;
		}
		str++;
	}
	return count;
}

char* censore(const char* str) {
	if (!str)
		return nullptr;
	size_t size = myLen(str) - getDigitCount(str) + getNumbersCount(str);
	char* res = new char[size + 1];
	res[size] = '\0';
	int curr = 0;
	while (*str) {
		if (!isDigit(*str)) {
			res[curr++] = *str;
		}
		else if (!isDigit(*(str + 1))) {
			res[curr++] = '*';
		}
		str++;
	}
	return res;
}