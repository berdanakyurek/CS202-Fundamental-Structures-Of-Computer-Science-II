/*
* Title: Algorithm Efficiency and Sorting
* Author: Berdan Akyürek
* ID: 21600904
* Section: 1
* Assignment: 1
* Description: This is the experiment code to invoke functions written.
*/

#include <iostream>

#include "sorting.h"
#include "auxArrayFunctions.h"

using namespace std;

int main()
{
    
    //Insertion sort
    int array[16] = {9, 5, 8, 15, 16, 6, 3, 11, 18, 0, 14, 17, 2, 9, 11, 7};
    int compCount = 0;
    int moveCount = 0;

    insertionSort(array, 16, compCount, moveCount);
    cout << "Results For Insertion Sort:\nComparison Count: " << compCount << "\nMove Count: " << moveCount << endl;
    displayArray( array, 16 );

    // Merge Sort
    int array2[16] = {9, 5, 8, 15, 16, 6, 3, 11, 18, 0, 14, 17, 2, 9, 11, 7};
    compCount = 0;
    moveCount = 0;

    mergeSort(array2, 16, compCount, moveCount);
    cout << "Results For Merge Sort:\nComparison Count: " << compCount << "\nMove Count: " << moveCount << endl;
    displayArray( array2, 16 );

    // Quick Sort
    int array3[16] = {9, 5, 8, 15, 16, 6, 3, 11, 18, 0, 14, 17, 2, 9, 11, 7};
    compCount = 0;
    moveCount = 0;

    quickSort(array3, 16, compCount, moveCount);
    cout << "Results For Quick Sort:\nComparison Count: " << compCount << "\nMove Count: " << moveCount << endl;
    displayArray( array3, 16 );
    
    
    //performanceAnalysis();

    return 0;
}