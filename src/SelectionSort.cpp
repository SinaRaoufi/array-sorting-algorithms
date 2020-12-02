/*
Time Complexity: O(n*2).

Auxiliary Space: O(1)
*/

#include "SelectionSort.hpp"

using namespace std;

void selectionSort(int arr[], size_t arraySize)
{
    int min;
    for (size_t i = 0; i < arraySize - 1; i++)
    {
        int min_index = i;
        for (size_t j = i + 1; j < arraySize; j++)
            if (arr[j] < arr[min_index])
                min_index = j;
        swap(arr[i], arr[min_index]);
    }
}