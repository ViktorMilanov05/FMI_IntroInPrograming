int binarySearch(const int arr[], size_t len, int el) {
	int left = 0;
	int right = len - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] > el) {
			left = mid + 1;
		}
		else if(arr[mid] < el) {
			right = mid - 1;
		}
		else{
			return mid;
		}
	}
	return -1;
}