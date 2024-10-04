#include <iostream>
void test() {
	int a, b;
	std::cin >> a >> b;
	bool isFirstBigger = a > b;
	std::cout << a * isFirstBigger + b * !isFirstBigger;
}