#include <iostream>
unsigned addBit(unsigned n, int ind) {
	int mask = 1 << ind;
	return n |= mask;
}
unsigned removeBit(unsigned n, int ind) {
	int mask = ~(1 << ind);
	return n & mask;
}
bool checkBit(unsigned n, int ind) {
	int mask = 1 << ind;
	return mask & n;
}
unsigned toggleBit(unsigned n, int ind) {
	int mask = 1 << ind;
	return n ^ mask;
}
bool isEven(unsigned n) {
	return !(1 & n);
}
unsigned powerOfTwo(unsigned n) {
	if (n > 31)
		return 0;
	return 1 << n;
}
int firstMissing(const int arr[], int size) {
	int res = 0;
	for (size_t i = 0; i < size; i++)
	{
		res ^= arr[i];
	}
	return res;
}
void printSubset(const int arr[], int size, int mask) {
	for (size_t i = size - 1; i >= 0; i--)
	{
		if (mask % 2 == 1) {
			std::cout << arr[i];
		}
		mask /= 2;
	}
}
void generateSubsets(const int arr[], int size) {
	int pt = powerOfTwo(size);
	for (size_t i = 0; i < pt; i++)
	{
		printSubset(arr, size, i);
	}
}