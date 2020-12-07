#include "RadixSort.hpp"

void countingSort(int arr[], size_t arraySize, int exp)
{
    // Create new array for counting values stored in the array
    int countingArray[10];
    for (size_t i = 0; i < 10; i++)
        countingArray[i] = 0;

    // Count each value
    for (size_t i = 0; i < arraySize; i++)
        countingArray[(arr[i] / exp) % 10]++;

    // Calculate cumulative sum of elements
    for (size_t i = 1; i < 10; i++)
        countingArray[i] += countingArray[i - 1];

    int temp[arraySize];
    for (int i = arraySize - 1; i >= 0; i--)
    {
        temp[countingArray[(arr[i] / exp) % 10] - 1] = arr[i];
        countingArray[(arr[i] / exp) % 10]--;
    }

    // Copy all values from temp array to main array
    for (size_t i = 0; i < arraySize; i++)
        arr[i] = temp[i];
}

void radixSort(int arr[], size_t arraySize)
{
    // Find maximum value in the array
    int max = arr[0];
    for (size_t i = 1; i < arraySize; i++)
        if (arr[i] > max)
            max = arr[i];

    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, arraySize, exp);
}
