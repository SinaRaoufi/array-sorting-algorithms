/*
Worst and Average Case Time Complexity: O(n*2).
    Worst case occurs when array is reverse sorted.

Best Case Time Complexity: O(n).
    Best case occurs when array is already sorted.

Auxiliary Space: O(1)

Boundary Cases: Bubble sort takes minimum time (Order of n) when elements are already sorted.
*/

#include "BubbleSort.hpp"

using namespace std;

void notOptimizedBubbleSort(int arr[], size_t arraySize)
{
    for (size_t i = 0; i < arraySize; i++)
        for (size_t j = 1; j < arraySize; j++)
            if (arr[j] < arr[j - 1])
                swap(arr[j], arr[j - 1]);
}

void optimizedBubbleSort(int arr[], size_t arraySize)
{
    bool isSorted;
    for (size_t i = 0; i < arraySize; i++)
    {
        isSorted = true;
        for (size_t j = 1; j < arraySize; j++)
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
                isSorted = false;
            }
        if (isSorted)
            return;
    }
}

void mostOptimizedBubbleSort(int arr[], size_t arraySize)
{
    bool isSorted;
    for (size_t i = 0; i < arraySize; i++)
    {
        isSorted = true;
        for (size_t j = 1; j < arraySize - i; j++)
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
                isSorted = false;
            }
        if (isSorted)
            return;
    }
}