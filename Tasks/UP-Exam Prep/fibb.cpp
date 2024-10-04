unsigned fibb(unsigned n) {
	if (n == 1 || n == 0) {
		return 1;
	}
	return fibb(n - 1) + fibb(n - 2);
}