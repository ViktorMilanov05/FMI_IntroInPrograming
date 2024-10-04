void minAndMaxDigit(unsigned n, unsigned& min, unsigned& max) {
	min = 9;
	max = 0;
	while (n != 0) {
		int last = n % 10;
		if (last > max) {
			max = last;
		}
		if (last < min)
			min = last;
		n /= 10;
	}
}