#include <iostream>
bool isPrime(int n) {
	if (n <= 1)
		return false;
	int temp = sqrt(n);
	for (size_t i = 0; i < temp; i++)
	{
		if (n % temp == 0)
			return false;
	}
	return true;
}
int reverse(int n) {
	int reverse = 0;
	while (n != 0)
	{
		int last = n % 10;
		(reverse *= 10) += last;
		n /= 10;
	}
	return reverse;
}
bool isPalindrome(int n) {
	return n == reverse(n);
}
bool isSuffix(unsigned n, unsigned k) {
	while (k != 0) {
		int lastN = n % 10;
		int lastK = k % 10;

		if (lastN != lastK)
			return false;
		n /= 10;
		k /= 10;
	}
	return true;
}
bool isPreffix(unsigned n, unsigned k) {
	while (n >= k) {
		if (n == k) {
			return true;
		}
		n /= 10;
	}
	return false;
}
bool isInffix(unsigned n, unsigned k) {
	while (n >= k) {
		if (isSuffix(n, k)) {
			return true;
		}
		n /= 10;
	}
	return false;
}
int myconcatDigit(unsigned a, unsigned digit) {
	if (digit > 9)
		return 0;
	(a *= 10) += digit;
}
int concatNumbers(unsigned a, unsigned b) {
	if (a == 0)
		return 0;
	if (b == 0)
		return myconcatDigit(a, 0);
	int reverseb = reverse(b);
	int result = a;
	while (reverseb != 0) {
		int last = reverseb % 10;
		myconcatDigit(result, last);
		reverseb /= 10;
	}
	while (b % 10 != 0) {
		myconcatDigit(result, 0);
		b /= 10;
	}
}
int mycountOccur(unsigned n, unsigned digit) {
	if (digit == 0 && n == 0)
		return 1;
	if (digit < 0 || digit > 9) {
		return 0;
	}
	int count = 0;
	while (n != 0) {
		int last = n % 10;
		if (digit == last)
			count++;
		n /= 10;
	}
	return count;
}
int concatAtBack(unsigned n, unsigned digit, unsigned howMany) {
	for (size_t i = 0; i < howMany; i++)
	{
		(n *= 10) += digit;
	}
	return n;
}
int sort(unsigned n) {
	int result = 0;
	for (size_t i = 0; i <= 9; i++)
	{
		int count = mycountOccur(n, i);
		result = concatAtBack(result, i, count);
	}
	return result;
};
