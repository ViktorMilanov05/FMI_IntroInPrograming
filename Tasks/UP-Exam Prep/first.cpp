unsigned countOccurances(unsigned n, unsigned digit) {
	if (n == 0 && digit == 0)
		return 1;
	int count = 0;
	while(n != 0){
		if ((n % 10) == digit)
			count++;
		n /= 10;
	}
	return count;
}

bool isInfixOfPermutation(unsigned n, unsigned k) {
	for (size_t i = 0; i <= 9; i++)
	{
		int countN = countOccurances(n,i);
		int countK = countOccurances(k,i);
		if (countK > countN)
			return false;
	}
	return true;
}