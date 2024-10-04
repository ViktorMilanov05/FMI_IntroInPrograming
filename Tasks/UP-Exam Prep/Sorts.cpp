void mySwap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void bubbleSort(int* arr, size_t size) {
	int lastSwapped = size - 1;
	for (size_t i = 0; i < size - 1; i++)
	{
		int curr = 0;
		for (size_t j = i; j < lastSwapped; j++)
		{
			if (arr[j] > arr[j + 1]) {
				mySwap(arr[j], arr[j + 1]);
				curr = j;
			}
		}
		if (curr == 0)
			break;
		lastSwapped = curr;
	}
}
void selectionSort(int* arr, size_t size) {
	for (size_t i = 0; i < size - 1; i++)
	{
		int minInd = i;
		for (size_t j = i + 1; j < size; j++)
		{
			if (arr[minInd] > arr[j])
				minInd = i;
		}
		if (minInd != i) {
			mySwap(arr[minInd], arr[i]);
		}
	}
}
void insertionSort(int* arr, size_t size) {
	for (size_t i = 1; i < size - 1; i++)
	{
		int curr = arr[i];
		int prevInd = i - 1;
		while (prevInd >= 0 && curr < arr[prevInd]) {
			arr[prevInd + 1] = arr[prevInd];
			prevInd--;
		}
		arr[prevInd + 1] = curr;
	}
}