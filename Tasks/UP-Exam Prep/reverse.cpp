void swap(int& el1, int& el2) {
	int temp = el1;
	el1 = el2;
	el2 = temp;
}
void reverse(int arr[], int size) {
	for (size_t i = 0; i < size / 2; i++)
	{
		swap(arr[i], arr[size - i - 1]);
	}
}