#include <iostream>
using namespace std;

void test7() {
	int n;
	cin >> n;
	for (size_t i = n; i > 1; i--)
	{
		bool isPrime = true;
		int temp = sqrt(i);
		for (size_t j = 2; j <= temp; j++)
		{
			if (i % j == 0)
				isPrime = false;
		}
		if (!isPrime) {
			continue;
		}
		int count = 0;
		while (n % i) {
			count++;
			n /= i;
		}
		if (count >= 1) {
			cout << i;
			if (count > 1) {
				cout << '^' << count << " ";
			}
		}
	}
}