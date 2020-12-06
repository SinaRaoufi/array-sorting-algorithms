cmake_minimum_required(VERSION 3.0)
project(sorting_algorithmes)
add_executable(app src/main.cpp
  src/BubbleSort.cpp
  src/InsertionSort.cpp
  src/SelectionSort.cpp
  src/MergeSort.cpp
  src/QuickSort.cpp
  src/RandomNumberGenerator)
include_directories(include)