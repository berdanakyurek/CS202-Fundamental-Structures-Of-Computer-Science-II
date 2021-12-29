/*
* Title: Sorting and Algorithm Efficiency
* Author: Berdan Akyurek
* ID: 21600904
* Section: 2
* Assignment: 1
* Description: definitions of the required sort and test functions
*/

#ifndef SORTING_H
#define SORTING_H
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void selectionSort(int *arr, const int size, int &compCount, int &moveCount);
void mergeSort(int *arr, const int size, int &compCount, int &moveCount);
void quickSort(int *arr, const int size, int &compCount, int &moveCount);
void radixSort(int *arr, const int size);

void displayArray(const int *arr, const int size);
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);

// Additional

void swap(int &x, int &y);
int indexOfLargest(const int* theArray, int size);
void merge( int* theArray, int first, int mid, int last);
void mergesort( int* theArray, int first, int last);
void reverse(int* arr, int size);
void performanceAnalysis();

#endif