bool myisLower(char ch) {
	return ch >= 'a' && ch <= 'z';
}
unsigned getLowerCount(const char* str) {
	if (!str)
		return 0;
	unsigned count = 0;
	while (*str) {
		if (myisLower(*str))
			count++;
		str++;
	}
	return count;
}
void concatAtBack(char* str, unsigned ind, char ch, unsigned count) {
	for (size_t i = 0; i < count; i++)
	{
		str[ind + i] = ch;
	}
}
char* sortLower(const char* str) {
	unsigned size = getLowerCount(str);
	char* res = new char[size + 1];
	res[size] = '\0';
	constexpr unsigned count = 26;
	constexpr char firstLetter = 'a';
	int alphabet[count]{0};
	unsigned resInd = 0;
	while (*str) {
		if (myisLower(*str))
			alphabet[*str - firstLetter]++;
		str++;
	}
	for (size_t i = 0; i < count; i++)
	{
		concatAtBack(res, resInd, 'a' + i, alphabet[i]);
		resInd += alphabet[i];
	}
	return res;
}