unsigned fibb2(unsigned n, unsigned* cache) {
	if (n <= 1)
		return 1;
	if (cache[n] != 0)
		return cache[n];
	else {
		int res = fibb2(n - 1, cache) + fibb2(n - 2, cache);
		cache[n] = res;
		return cache[n];
	}
}
unsigned fibb1(unsigned n) {
	unsigned* cache = new unsigned[n + 1] {0};
	unsigned res = fibb2(n, cache);
	delete[] cache;
	return res;
}