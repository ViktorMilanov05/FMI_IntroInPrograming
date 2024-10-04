#include <iostream>
void mark(int arr[], int len, int el) {
	int toMark = el + el;
	while (toMark < len) {
		arr[toMark] = true;
		toMark += el;
	}
}
void sieveEratosten(int arr[], int len) {
	for (size_t i = 2; i <= len; i++)
	{
		if (!arr[i]) {
			std::cout << i;
			mark(arr, len, i);
		}
	}
}