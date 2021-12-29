/*
* Title: Algorithm Efficiency and Sorting
* Author: Berdan Akyürek
* ID: 21600904
* Section: 1
* Assignment: 1
* Description: This is the collection of sorting algoritms used in this assignment. Some of them are taken from lecture slides.
*/

#include "auxArrayFunctions.h"
#include <iostream>
#include <ctime>
#include <iomanip> 

using namespace std;

const int MAX_SIZE = 30000;

void swap( int &a, int& b, int& moveCount )
{
    int temp = a;
    a = b;
    b = temp;
    moveCount += 3;
}

void insertionSort(int *arr, int size, int &compCount, int &moveCount)
{
    compCount = 0;
    moveCount = 0;

    for (int unsorted = 1; unsorted < size; ++unsorted) {

        int nextItem = arr[unsorted];
        moveCount ++;

        int loc = unsorted;

        for (  ;(loc > 0) && (arr[loc-1] > nextItem); --loc)
        {
            arr[loc] = arr[loc-1];
            moveCount ++;
            compCount ++;
        }
        compCount ++;

        arr[loc] = nextItem;
        moveCount ++;
    }
}

void partition( int theArray[], int first, int last, int &pivotIndex, int& compCount, int &moveCount) 
{
    int pivot = theArray[first]; // copy pivot
    moveCount ++;

    // initially, everything but pivot is in unknown
    int lastS1 = first;           // index of last item in S1
    int firstUnknown = first + 1; // index of first item in unknown
    
        // move one item at a time until unknown region is empty
    for (  ; firstUnknown <= last; ++firstUnknown) {
        // Invariant: theArray[first+1..lastS1] < pivot
        //            theArray[lastS1+1..firstUnknown-1] >= pivot

        // move item from unknown to proper region
        compCount ++;
        if (theArray[firstUnknown] < pivot) {  	// belongs to S1
            ++lastS1;
            swap(theArray[firstUnknown], theArray[lastS1], moveCount);
        }	// else belongs to S2
    }
    // place pivot in proper position and mark its location
    swap(theArray[first], theArray[lastS1], moveCount);
    pivotIndex = lastS1;
}
void quickSort2(int theArray[], int first, int last, int& compCount, int &moveCount) {

    int pivotIndex;

    if (first < last) {

        // create the partition: S1, pivot, S2
        partition(theArray, first, last, pivotIndex, compCount, moveCount);

        // sort regions S1 and S2
        quickSort2(theArray, first, pivotIndex-1, compCount, moveCount);
        quickSort2(theArray, pivotIndex+1, last, compCount, moveCount);
   }
}

void quickSort(int *arr, int size, int &compCount, int &moveCount)
{
    quickSort2( arr, 0, size - 1, compCount, moveCount);
}

void merge( int theArray[], int first, int mid, int last, int &compCount, int &moveCount ) 
{
   
    int tempArray[MAX_SIZE]; 	// temporary array
   
    int first1 = first; 	// beginning of first subarray
    int last1 = mid; 		// end of first subarray
    int first2 = mid + 1;	// beginning of second subarray
    int last2 = last;		// end of second subarray
    int index = first1; // next available location in tempArray

    for ( ; (first1 <= last1) && (first2 <= last2); ++index) {

        compCount ++;
        if (theArray[first1] < theArray[first2]) {  
            tempArray[index] = theArray[first1];
            ++first1;
            moveCount ++;
        }
        else {  
            tempArray[index] = theArray[first2];
            ++first2;
            moveCount ++;
        }
    }
    // finish off the first subarray, if necessary
    for (; first1 <= last1; ++first1, ++index)
    {
        tempArray[index] = theArray[first1];
        moveCount ++;
    }

    // finish off the second subarray, if necessary
    for (; first2 <= last2; ++first2, ++index)
    {
        tempArray[index] = theArray[first2];
        moveCount ++;
    }

    // copy the result back into the original array
    for (index = first; index <= last; ++index)
    {
        theArray[index] = tempArray[index];
        moveCount ++;
    }

}  
void mergeSort2(int theArray[], int first, int last, int& compCount, int& moveCount)
{
    if (first < last) {

        int mid = (first + last)/2; 	// index of midpoint

        mergeSort2(theArray, first, mid, compCount, moveCount);

        mergeSort2(theArray, mid+1, last, compCount, moveCount);

        // merge the two halves
        merge(theArray, first, mid, last, compCount, moveCount);
   }
}

void mergeSort(int *arr, int size, int &compCount, int &moveCount)
{
    mergeSort2(arr, 0, size-1, compCount, moveCount);
}

void performanceAnalysis()
{
    int K = 100;
    int sizes[6] = {5000, 10000, 15000, 20000, 25000, 30000};
    int N;
    int *arr1, *arr2, *arr3;
    int compCount1, compCount2, compCount3;
    int moveCount1, moveCount2, moveCount3;

    double duration1, duration2, duration3;
    clock_t startTime;

    int results[3][3][6]; //results[insertion, merge, quick][time, comp, move][input size]

    for( int i = 0; i< 6; i ++ )
    {
        compCount1 = 0;
        compCount2 = 0;
        compCount3 = 0;
        moveCount1 = 0;
        moveCount2 = 0;
        moveCount3 = 0;

        N = sizes[i];
        createNearlySortedArrays(arr1, arr2, arr3, N, 1000);

        startTime = clock();
        insertionSort(arr1, N, compCount1, moveCount1);
        duration1 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

        startTime = clock();
        mergeSort(arr2, N, compCount2, moveCount2);
        duration2 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

        startTime = clock();
        quickSort(arr3, N, compCount3, moveCount3);
        duration3 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

        results[0][0][i] = duration1;
        results[0][1][i] = compCount1;
        results[0][2][i] = moveCount1;

        results[1][0][i] = duration2;
        results[1][1][i] = compCount2;
        results[1][2][i] = moveCount2;

        results[2][0][i] = duration3;
        results[2][1][i] = compCount3;
        results[2][2][i] = moveCount3;
    }
    cout << "Nearly sorted array K = 1000" << endl;
    for( int i = 0 ; i < 3 ; i ++ )
    {
        cout << "-----------------------------------------------------" << endl;
        cout << "Part c - Time analysis of ";
        if(i == 0)
            cout << "Insertion Sort" << endl;
        else if(i == 1)
            cout << "Merge Sort" << endl;
        else
            cout << "Quick Sort" << endl;
        
        cout << setw(20) << left << "Array Size" << setw(20) << left << "Time Elapsed" << setw(20) << left << "compCount"<< setw(20) << left << "moveCount" << endl;
        
        for( int j = 0 ; j < 6 ; j++ )
        {
            cout << setw(20) << left << sizes[j];
            for (int k = 0; k < 3; k++)
            {
                cout << setw(20) << left << results[i][k][j];
            }
            cout << endl;
            
        }
    }
    
}

