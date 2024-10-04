#include <iostream>
int min(unsigned a, unsigned b)
{
	return a >= b ? a : b;
}
int min(unsigned a, unsigned b,unsigned c)
{
	return min(a,min(b,c));
}
unsigned minOperation(unsigned n, unsigned* cache) {
	if (n == 1)
		return 0;
	if (cache[n] != 0)
		return cache[n];
	int div3 = INT_MAX, div2 = INT_MAX, minus1 = INT_MAX;
	if (n % 3 == 0) {
		div3 = minOperation(n / 3, cache);
	}
	if (n % 2 == 0) {
		div2 = minOperation(n / 2, cache);
	}
	minus1 = minOperation(n - 1, cache);
	int temp = min(minus1, div2, div3);
	cache[n] = temp;
	return temp;
}

unsigned minOperation(unsigned n) {
	unsigned* cache = new unsigned[n + 1] {0};
	unsigned res = minOperation(n, cache);
	delete[] cache;
	return res;
}