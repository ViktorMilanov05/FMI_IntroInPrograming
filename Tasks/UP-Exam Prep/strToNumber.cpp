int getDigit(char ch) {
	if (ch >= '0' && ch <= '9') {
		return ch - '0';
	}
	return -1;
}

unsigned toNumberUnsigned(const char* str) {
	if (!str) {
		return 0;
	}
	unsigned res = 0;
	while (*str) {
		int digit = getDigit(*str);
		if (digit == -1)
			return 0;
		(res *= 10) += digit;
		str++;
	}
	return res;
}

int toNumber(const char* str) {
	if (!str)
		return 0;
	if (*str == '-') {
		return -1 * toNumberUnsigned(str + 1);
	}
	else {
		return toNumberUnsigned(str);
	}
}