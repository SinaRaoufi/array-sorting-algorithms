#include <iostream>
#include "BubbleSort.hpp"
#include "InsertionSort.hpp"
#include "SelectionSort.hpp"
#include <ctime>
#include <functional>
#include <iomanip>

using namespace std;

struct Result
{
    long long int numberOfOperations;
    double elapsedTime;
};

void printResult(function<void(int[], size_t)> func, int arr[], size_t arraySize)
{
    cout << "Before sorting:" << endl;
    for (size_t i = 0; i < arraySize; i++)
        cout << arr[i] << " ";
    cout << endl;

    struct Result result = {0, 0};
    clock_t startTime = clock();
    func(arr, arraySize);
    result.elapsedTime = static_cast<double>(clock() - startTime) / CLOCKS_PER_SEC;

    cout << "After sorting:" << endl;
    for (size_t i = 0; i < arraySize; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << fixed << "Elapsed time: " << result.elapsedTime << 's' << endl;
    cout << "-------------------------" << endl;
}

int main()
{
    int integersArray[] = {9, 3, 5, 2, 1, 2, 23, 45, 0, -4, 99, 12};
    // int integersArray2[] = {9, 3, 5, 2, 1, 2, 23, 45, 0, -4, 99, 12};
    // int integersArray3[] = {9, 3, 5, 2, 1, 2, 23, 45, 0, -4, 99, 12};

    // printResult(notOptimizedBubbleSort, integersArray, sizeof(integersArray) / sizeof(integersArray[0]));
    // printResult(optimizedBubbleSort, integersArray2, sizeof(integersArray) / sizeof(integersArray[0]));
    // printResult(mostOptimizedBubbleSort, integersArray3, sizeof(integersArray) / sizeof(integersArray[0]));

    printResult(selectionSort, integersArray, sizeof(integersArray) / sizeof(integersArray[0]));
    return 0;
}