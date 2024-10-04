int sumArr(const int* arr, int size) {
	if (size == 0)
		return 0;
	return arr[0] + sumArr(arr + 1, size - 1);
;
}