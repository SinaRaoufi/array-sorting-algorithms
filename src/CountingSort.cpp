#include "CountingSort.hpp"

using namespace std;

void countingSort(int arr[], size_t arraySize)
{
    // Find maximum value in the array
    int max = arr[0];
    for (size_t i = 1; i < arraySize; i++)
        if (arr[i] > max)
            max = arr[i];

    // Create new array for counting values stored in the array
    int countingArray[max + 1];
    for (size_t i = 0; i < max + 1; i++)
        countingArray[i] = 0;

    // Count each value
    for (size_t i = 0; i < arraySize; i++)
        countingArray[arr[i]]++;

    // Calculate cumulative sum of elements
    for (size_t i = 1; i < max + 1; i++)
        countingArray[i] += countingArray[i - 1];

    int temp[arraySize];
    for (int i = arraySize - 1; i >= 0; i--)
    {
        temp[countingArray[arr[i]] - 1] = arr[i];
        countingArray[arr[i]]--;
    }

    // Copy all values from temp array to main array
    for (size_t i = 0; i < arraySize; i++)
        arr[i] = temp[i];
}
