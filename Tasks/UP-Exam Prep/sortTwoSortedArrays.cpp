int getBound(const int* arr, size_t count) {
	if (!arr)
		return -1;
	for (size_t i = 0; i < count; i++)
	{
		if (arr[i] > arr[i + 1])
			return i + 1;
	}
	return -1;
}
void merge(const int* first, unsigned size1, const int* second, unsigned size2, int* result) {
	int firstInd = 0, secondInd = 0, resInd = 0;
	while (firstInd < size1 && secondInd < size2) {
		if (first[firstInd] <= second[secondInd])
			result[resInd++] = first[firstInd++];
		else
			result[resInd++] = second[secondInd++];
	}
	while(firstInd < size1)
		result[resInd++] = first[firstInd++];
	while (secondInd < size2)
		result[resInd++] = second[secondInd++];
}
void sort(int* arr, size_t count) {
	if (!arr)
		return;
	int secondArrInd = getBound(arr, count);
	if (secondArrInd == -1)
		return;
	int* temp = new int[count];
	merge(arr, secondArrInd, arr + secondArrInd, count - secondArrInd, temp);
	for (size_t i = 0; i < count; i++)
	{
		arr[i] = temp[i];
	}
	delete[] temp;
}