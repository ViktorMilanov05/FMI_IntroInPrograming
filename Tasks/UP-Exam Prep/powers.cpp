unsigned power(int n, int k) {
	if (k == 0)
		return 1;
	return n * power(n, k - 1);
}
unsigned fastPower(int n, int k) {
	if (k == 0)
		return 1;
	else if (k % 2 == 0)
		return n * fastPower(n, k - 1);
	else {
		return fastPower(n * n, k / 2);
	}
}