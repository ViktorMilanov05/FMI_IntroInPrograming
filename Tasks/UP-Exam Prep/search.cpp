bool linearSearch(const int* arr, size_t size, int el) {
	if (size == 0)
		return false;
	return arr[0] == el || linearSearch(arr + 1, size - 1, el);
}