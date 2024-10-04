bool isLower(char ch) {
	return ch >= 'a' && ch <= 'z';
}
bool isUpper(char ch) {
	return ch >= 'A' && ch <= 'Z';
}
void getLowerAndUpperCount(const char* str, unsigned& lowerCount, unsigned& upperCount) {
	if (!str) {
		return;
	}
	lowerCount = upperCount = 0;
	while (*str) {
		if (isLower(*str)) {
			lowerCount++;
		}
		else if (isUpper(*str)) {
			upperCount++;
		}
		str++;
	}
}

void getLowerAndUpper(const char* str, char*& lower, char*& upper) {
	if (!str) {
		return;
	}
	unsigned lowerCount = 0;
	unsigned upperCount = 0;
	getLowerAndUpperCount(str, lowerCount, upperCount);
	lower = new char[lowerCount + 1];
	upper = new char[upperCount + 1];
	lower[lowerCount] = upper[upperCount] = '\0';
	unsigned lowerCur = 0;
	unsigned upperCur = 0;
	while (*str) {
		if (isLower(*str))
			lower[lowerCur++] = *str;
		else if (isUpper(*str)) {
			upper[upperCur++] = *str;
		}
		str++;
	}
}