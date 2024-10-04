int gcd(unsigned n, unsigned k) {
	if (n < k) {
		int temp = n;
		n = k;
		k = temp;
	}
	while (k != 0) {
		int mod = n % k;
		n = k;
		k = mod;
	}
	return n;
}
int gcd4(unsigned a, unsigned b, unsigned c, unsigned d) {
	return gcd(gcd(a,b), gcd(c,d));
}