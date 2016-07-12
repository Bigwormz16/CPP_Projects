#include <iostream>
#include <random>
#include "010_heap_sort.h"


enum Error
{
	ERROR_ELEMENT_NOT_FOUND = -1,
};


int linearSearch(int arr[], int target, int length)
{
	for (int index = 0; index < length; ++index)
	{
		if (arr[index] == target)
			return index;
	}

	return ERROR_ELEMENT_NOT_FOUND;
}


// We can also write this function iteratively though the amount and complexity
// of that code is almost the same and it is also less efficient.
//
// NOTE: Binary search may not return the index of the first occurence of the
// element being searched if the array contain duplicates.
int binarySearch(int arr[], int target, int iMin, int iMax)
{
	while (iMin <= iMax)
	{
		int iMiddle = (iMin + iMax) / 2;

		if (arr[iMiddle] == target)
			return iMiddle;
		else if (arr[iMiddle] < target)
			iMin = iMiddle + 1;
		else
			iMax = iMiddle - 1;
	}

	return ERROR_ELEMENT_NOT_FOUND;
}


void search(int target, int arr[], int length)
{
	int iFound = linearSearch(arr, target, length);
	if (iFound == ERROR_ELEMENT_NOT_FOUND)
		std::cout << "Linear search: " << target << " was not found\n";
	else
		std::cout << "Linear search: " << target << " was found at index " << iFound << "\n";

	iFound = binarySearch(arr, target, 0, length - 1);
	if (iFound == ERROR_ELEMENT_NOT_FOUND)
		std::cout << "Binary search: " << target << " was not found\n";
	else
		std::cout << "Binary search: " << target << " was found at index " << iFound << "\n";
}


int main()
{
	const int length = 100;
	int nArray[length] = {};
	int maxValue = 1000;

	// Use a hardware entropy source to generate a non-deterministic random number
	// operator() : advances the engine's state and returns the generated value
	std::random_device rd;

	// Seed (i.e., invoke constructor) our mersenne twister object with the random number
	// std::mt19937 : 32-bit Mersenne Twister by Matsumoto and Nishimura, 1998
	std::mt19937 marsenne(rd());

	for (int index = 0; index < length; ++index)
		nArray[index] = marsenne() % maxValue;

	heapSort(nArray, length, ascending);	// Required for binary search
	printArray(nArray, length);

	std::cout << "Enter a number between 0 and " << maxValue << ": ";
	int target;
	std::cin >> target;

	search(target, nArray, length);

	return 0;
}
