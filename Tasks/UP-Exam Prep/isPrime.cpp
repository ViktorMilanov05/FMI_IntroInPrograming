#include <iostream>
using namespace std;

void isPrime() {
	int n;
	cin >> n;
	if (n <= 1) {
		cout << "Not prime";
	}
	int sqrtN = sqrt(n);
	bool isPrime = true;
	for (size_t i = 0; i <= sqrtN; i++)
	{
		if (n % i == 0)
			isPrime = false;
	}
	if (isPrime)
		std::cout << "Prime";
	else {
		std::cout << "Not Prime";
	}
}