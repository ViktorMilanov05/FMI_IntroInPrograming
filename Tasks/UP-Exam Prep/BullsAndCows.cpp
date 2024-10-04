#include <iostream>
using namespace std;
int countOccur(unsigned n, unsigned digit) {
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
int digitCount(unsigned n) {
	int count = 0;
	while (n != 0) {
		count++;
		n /= 10;
	}
	return count;
}
bool allDiff(unsigned n) {
	for (size_t i = 0; i <= 9; i++)
	{
		if (countOccur(n, i) > 1)
			return false;
	}
	return true;
}
int userInput() {
	int n;
	do {
		cin >> n;
	} while ((!allDiff(n)) && digitCount(n) > 4);
	return n;
}
int getBulls(unsigned toGuess, unsigned guess) {
	int res = 0;
	while (toGuess != 0) {
		int lastN = toGuess % 10;
		int lastK = guess % 10;
		if (lastK == lastN) {
			res++;
		}
		toGuess /= 10;
		guess /= 10;
	}
	return res;
}
int getBullsAndCowsSum(unsigned n, unsigned k) {
	int sum = 0;
	while (n != 0) {
		int last = n % 10;
		if (countOccur(k, last)) {
			sum++;
		}
		n /= 10;
	}
	return sum;
}
void getBoolsAndCows(unsigned toGuess, unsigned guess, unsigned& bulls, unsigned& cows) {
	bulls = getBulls(toGuess, guess);
	cows = getBullsAndCowsSum(toGuess, guess) - bulls;
}
void bullsAndCols() {
	int n;
	n = userInput();
	unsigned bulls = 0;
	unsigned cows = 0;
	int guess;
	do {
		cin >> guess;
		getBoolsAndCows(n, guess, bulls, cows);
	} while (bulls == 4);
}