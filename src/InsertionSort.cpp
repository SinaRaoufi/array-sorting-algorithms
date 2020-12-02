/*
Worst Case Time Complexity: O(n*2).

Best Case Time Complexity: O(n).

Auxiliary Space: O(1)

Boundary Cases: Insertion sort takes maximum time to sort if elements are sorted in reverse order.
 And it takes minimum time (Order of n) when elements are already sorted.
*/

#include "InsertionSort.hpp"

using namespace std;

void insertionSort(int arr[], size_t arraySize)
{
    int current;
    for (size_t i = 1; i < arraySize; i++)
    {
        current = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > current)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}