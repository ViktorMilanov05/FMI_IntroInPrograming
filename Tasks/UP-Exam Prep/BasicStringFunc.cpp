unsigned myStrLen(const char* str) {
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
void myStrCpy(const char* from, char* to) {
	if (!from || !to) {
		return;
	}
	while (*from) {
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';
}
int myStrCmp(const char* first, const char* second) {
	if (!first || !second) {
		return 0;
	}
	while (*first && *second && (*first == *second)) {
		first++;
		second++;
	}
	return (*first - *second);
}
void myStrCat(char* to, const char* from) {
	if (!from || !to) {
		return;
	}
	int len = myStrLen(to);
	to += len;
	myStrCpy(from, to);
}