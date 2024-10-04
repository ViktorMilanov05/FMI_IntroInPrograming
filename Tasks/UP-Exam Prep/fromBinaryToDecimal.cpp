int fromBinaryToDecimal(unsigned n) {
	unsigned res = 0;
	unsigned multiplier = 1;
	while (n != 0)
	{
		res += (n % 10) * multiplier;
		multiplier *= 2;
		n /= 10;
	}
	return res;
}