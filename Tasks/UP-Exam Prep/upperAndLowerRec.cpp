bool isLower1(char ch) {
	return ch >= 'a' && ch <= 'z';
}
bool isUpper1(char ch) {
	return ch >= 'A' && ch <= 'Z';
}
void getUpperAndLowerRec(const char* str, size_t& lower, size_t& upper) {
	if (!str)
		return;
	if (isLower1(*str))
		lower++;
	else if (isUpper1(*str))
		upper++;
	getUpperAndLowerRec(str + 1, lower, upper);
}