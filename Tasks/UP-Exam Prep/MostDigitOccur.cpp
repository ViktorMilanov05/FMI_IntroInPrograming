#include <iostream>
#include <cmath>

using namespace std;

void hey()
{
	int n;
	cin >> n;

	int maxDigit = -1;
	int maxOccur = 0;
	for (size_t i = 0; i <= 9; i++)
	{
		int temp = n;
		int currOccur = 0;
		while (temp != 0) {
			int last = temp % 10;
			if (last == i)
				currOccur++;
			temp /= 10;
		}
		if (currOccur > maxOccur) {
			maxOccur = currOccur;
			maxDigit = i;
		}
	}
	cout << maxDigit;
}
