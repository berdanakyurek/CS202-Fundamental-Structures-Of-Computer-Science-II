/*
* Title: Sorting and Algorithm Efficiency
* Author: Berdan Akyurek
* ID: 21600904
* Section: 2
* Assignment: 1
* Description: main of the project
*/

#include "sorting.h"

int main()
{
    int arrS = 16;

    int arr[] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    int* arr1 = new int[arrS];
    int* arr2 = new int[arrS];
    int* arr3 = new int[arrS];
    int* arr4 = new int[arrS];
    
    for(int i = 0; i < arrS; i++ )
    {
        arr1[i] = arr[i];
        arr2[i] = arr[i];
        arr3[i] = arr[i];
        arr4[i] = arr[i];
    }

    int cc1, mc1, cc2, mc2, cc3, mc3;
    
    
    cout << "Before sorting" << endl;
    displayArray(arr1, arrS);
    
    // Sort
    selectionSort(arr1, arrS, cc1, mc1);
    mergeSort(arr2, arrS, cc2, mc2);
    quickSort(arr3, arrS, cc3, mc3);
    radixSort(arr4, arrS);

    cout << "-------------------------" << endl;
    cout << "After selection sort" << endl;
    displayArray(arr1, arrS);
    cout << "compCount: " << cc1 << endl;
    cout << "moveCount: " << mc1 << endl;
    cout << "-------------------------" << endl;
    cout << "After merge sort" << endl;
    displayArray(arr2, arrS);
    cout << "compCount: " << cc2 << endl;
    cout << "moveCount: " << mc2 << endl;
    cout << "-------------------------" << endl;
    cout << "After quick sort" << endl;
    displayArray(arr3, arrS);
    cout << "compCount: " << cc3 << endl;
    cout << "moveCount: " << mc3 << endl;
    cout << "-------------------------" << endl;
    cout << "After radix sort" << endl;
    displayArray(arr4, arrS);
    cout << "-------------------------" << endl;

    cout << "-------------------------" << endl;
    int a,b;
    swap(a,b);
    performanceAnalysis();
    return 0;
}