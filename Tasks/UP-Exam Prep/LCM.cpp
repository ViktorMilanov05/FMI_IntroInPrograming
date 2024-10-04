#include <iostream>
using namespace std;

void LCM() {
	int n, m;
	cin >> n >> m;
	int max = n >= m ? n : m;
	int lcmCandidate = max;
	while (lcmCandidate % n != 0 || lcmCandidate % m != 0)
		lcmCandidate += max;
	cout << lcmCandidate;
}