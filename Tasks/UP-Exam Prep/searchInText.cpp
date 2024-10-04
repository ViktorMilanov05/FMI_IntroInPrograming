unsigned myStrlen(const char* str) {
	if (!str) {
		return 0;
	}
	unsigned res = 0;
	while (*str) {
		res++;
		str++;
	}
	return res;
}
bool isPrefix(const char* text, const char* pattern) {
	if (!text || !pattern) {
		return false;
	}
	while (*text && *pattern) {
		if (*text != *pattern)
			return false;
		text++;
		pattern++;
	}
	return *pattern == '\0';
}
bool contains(const char* text, const char* pattern) {
	if (!text || !pattern) {
		return false;
	}
	unsigned textLen = myStrlen(text);
	unsigned patternLen = myStrlen(pattern);
	while (patternLen <= textLen) {
		if (isPrefix(text, pattern)) {
			return true;
		}
		textLen--;
		text++;
	}
	return false;
}