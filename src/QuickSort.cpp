#include "QuickSort.hpp"
#include <iostream>

using namespace std;

int partition(int arr[], int lowerBound, int upperBound)
{
    int pivot = arr[upperBound]; // Set last element of array as pivot
    int i = -1;
    for (size_t j = 0; j < upperBound; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i + 1], arr[upperBound]);
    return i + 1;
}

void quickSort(int arr[], int lowerBound, int upperBound)
{
    if (lowerBound < upperBound)
    {
        int p = partition(arr, lowerBound, upperBound);
        quickSort(arr, lowerBound, p - 1);
        quickSort(arr, p + 1, upperBound);
    }
}
