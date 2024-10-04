unsigned len(unsigned n) {
	if (n == 0)
		return 0;
	unsigned res = 0;
	while (n != 0) {
		res++;
		n /= 10;
	}
	return res;
}
char getChar(unsigned n) {
	if (n > 9) {
		return '\0';
	}
	return '0' + n;
}
void toStr(unsigned n, char* str) {
	unsigned res = len(n);
	for (int i = res - 1; i >= 0; i--)
	{
		str[i] = getChar(n % 10);
		n /= 10;
	}
	str[res] = '\0';
}