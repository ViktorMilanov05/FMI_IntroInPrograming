#include <iostream>
int myMax(int a, int b) {
	return a >= b ? a : b;
}
int maxInArr(int* arr, unsigned size) {
	if (size == 0)
		return INT_MIN;
	return myMax(arr[0], maxInArr(arr + 1, size - 1));
}
int maxInArr2(int* arr, unsigned size) {
	if (size == 0)
		return INT_MIN;
	if (size == 1)
		return arr[0];
	int mid = size / 2;
	return myMax(maxInArr2(arr, mid), maxInArr2(arr + mid, size - mid));
}