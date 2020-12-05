#include "MergeSort.hpp"

using namespace std;

void merge(int arr[], size_t lowerBound, size_t middle, size_t upperBound)
{
    // Calculate size of each subarray
    size_t sizeOfLeftSubarray = middle - lowerBound + 1;
    size_t sizeOfRightSubarray = upperBound - middle;

    // Create subarrays
    int left[sizeOfLeftSubarray];
    int right[sizeOfRightSubarray];

    // Copy data to temp arrays left[] and Right[]
    for (size_t i = 0; i < sizeOfLeftSubarray; i++)
        left[i] = arr[lowerBound + i];
    for (size_t j = 0; j < sizeOfRightSubarray; j++)
        right[j] = arr[middle + 1 + j];

    int i = 0;          // Initial index of left subarray
    int j = 0;          // Initial index of right subarray
    int k = lowerBound; // Initial index of merged subarray

    // Compare elements of each subarray with eachother
    while (i < sizeOfLeftSubarray && j < sizeOfRightSubarray)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left subarray
    while (i < sizeOfLeftSubarray)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right subarray
    while (j < sizeOfRightSubarray)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], size_t lowerBound, size_t upperBound)
{
    if (lowerBound < upperBound)
    {
        size_t middle = (lowerBound + upperBound) / 2;
        mergeSort(arr, lowerBound, middle);
        mergeSort(arr, middle + 1, upperBound);
        merge(arr, lowerBound, middle, upperBound);
    }
}
