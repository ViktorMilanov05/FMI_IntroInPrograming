#include <iostream>
using namespace std;

void test6() {
	int n, m;
	cin >> n >> m;
	if (n < m) {
		int temp = n;
		n = m;
		m = temp;
	}
	while (m != 0) {
		int mod = n % m;
		n = m;
		m = mod;
	}
	cout << n;
}