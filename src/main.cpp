#include <iostream>
#include <ctime>
#include <functional>
#include <iomanip>
#include "BubbleSort.hpp"
#include "InsertionSort.hpp"
#include "SelectionSort.hpp"
#include "MergeSort.hpp"
#include "QuickSort.hpp"
#include "CountingSort.hpp"
#include "RadixSort.hpp"
#include "RandomNumberGenerator.hpp"
#include "cpp-text-table/TextTable.h"

using namespace std;

void copyValues(int arr2[], int arr[], size_t arraySize)
{
    for (size_t i = 0; i < arraySize; i++)
        arr2[i] = arr[i];
}

double elapsedTime(function<void(int[], size_t, size_t)> func, int arr[], size_t lowerBound, size_t upperBound)
{
    double elapsedTime;
    clock_t startTime = clock();
    func(arr, lowerBound, upperBound);
    elapsedTime = static_cast<double>(clock() - startTime) / CLOCKS_PER_SEC;
    return elapsedTime;
}

double elapsedTime(function<void(int[], size_t)> func, int arr[], size_t arraySize)
{
    double elapsedTime;
    clock_t startTime = clock();
    func(arr, arraySize);
    elapsedTime = static_cast<double>(clock() - startTime) / CLOCKS_PER_SEC;
    return elapsedTime;
}

void initializeArrayWithRandomValues(int arr[], size_t arraySize)
{
    for (size_t i = 0; i < arraySize; i++)
        arr[i] = generateRandomNumber(0, 100);
}

int main()
{
    int N;
    cout << "Please enter size of array: ";
    cin >> N;
    int arr[N];
    initializeArrayWithRandomValues(arr, N);

    TextTable table('-', '|', '+');
    table.add("Algorithm");
    table.add("Time1");
    table.add("Time2");
    table.endOfRow();

    int temp[N];
    double time1;
    double time2;

    // Print results
    table.add("Bubble Sort");
    copyValues(temp, arr, N);
    time1 = elapsedTime(bubbleSort, temp, sizeof(temp) / sizeof(temp[0]));
    time2 = elapsedTime(bubbleSort, temp, sizeof(temp) / sizeof(temp[0]));
    table.add(to_string(time1) + 's');
    table.add(to_string(time2) + 's');
    table.endOfRow();

    table.add("Insertion Sort");
    copyValues(temp, arr, N);
    time1 = elapsedTime(insertionSort, temp, sizeof(temp) / sizeof(temp[0]));
    time2 = elapsedTime(insertionSort, temp, sizeof(temp) / sizeof(temp[0]));
    table.add(to_string(time1) + 's');
    table.add(to_string(time2) + 's');
    table.endOfRow();

    table.add("Selection Sort");
    copeValues(temp, arr, N);
    time1 = elapsedTime(selectionSort, temp, sizeof(temp) / sizeof(temp[0]));
    time2 = elapsedTime(selectionSort, temp, sizeof(temp) / sizeof(temp[0]));
    table.add(to_string(time1) + 's');
    table.add(to_string(time2) + 's');
    table.endOfRow();

    table.add("Merge Sort");
    copeValues(arr, temp, N);
    time1 = elapsedTime(mergeSort, temp, 0, sizeof(temp) / sizeof(temp[0]) - 1);
    time2 = elapsedTime(mergeSort, temp, 0, sizeof(temp) / sizeof(temp[0]) - 1);
    table.add(to_string(time1) + 's');
    table.add(to_string(time2) + 's');
    table.endOfRow();

    table.add("Quick Sort");
    copeValues(arr, temp, N);
    time1 = elapsedTime(quickSort, temp, 0, sizeof(temp) / sizeof(temp[0]) - 1);
    time2 = elapsedTime(quickSort, temp, 0, sizeof(temp) / sizeof(temp[0]) - 1);
    table.add(to_string(time1) + 's');
    table.add(to_string(time2) + 's');
    table.endOfRow();

    table.add("Counting Sort");
    copeValues(temp, arr, N);
    time1 = elapsedTime(countingSort, temp, sizeof(temp) / sizeof(temp[0]));
    time2 = elapsedTime(countingSort, temp, sizeof(temp) / sizeof(temp[0]));
    table.add(to_string(time1) + 's');
    table.add(to_string(time2) + 's');
    table.endOfRow();

    table.add("Radix Sort");
    copeValues(temp, arr, N);
    time1 = elapsedTime(radixSort, temp, sizeof(temp) / sizeof(temp[0]));
    time2 = elapsedTime(radixSort, temp, sizeof(temp) / sizeof(temp[0]));
    table.add(to_string(time1) + 's');
    table.add(to_string(time2) + 's');
    table.endOfRow();

    cout << table;
    return 0;
}