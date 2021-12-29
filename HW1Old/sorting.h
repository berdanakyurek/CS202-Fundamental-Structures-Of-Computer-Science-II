/*
* Title: Algorithm Efficiency and Sorting
* Author: Berdan Akyürek
* ID: 21600904
* Section: 1
* Assignment: 1
* Description: This is the header file to define sorting.cpp file.
*/

#ifndef sort
#define sort

void insertionSort(int *arr, int size, int &compCount, int &moveCount);
void quickSort(int *arr, int size, int &compCount, int &moveCount);
void mergeSort(int *arr, int size, int &compCount, int &moveCount);
void performanceAnalysis();

#endif