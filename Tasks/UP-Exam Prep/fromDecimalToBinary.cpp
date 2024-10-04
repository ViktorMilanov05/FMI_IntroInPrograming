int fromDecimalToBinary(unsigned n) {
	int res = 0;
	int mult = 1;
	while (n != 0) {
		if (n % 2 == 1) {
			res += mult;
		}
		mult *= 10;
		n /= 2;
	}
	return res;
}