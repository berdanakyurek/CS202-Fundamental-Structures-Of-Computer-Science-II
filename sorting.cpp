/*
* Title: Sorting and Algorithm Efficiency
* Author: Berdan Akyurek
* ID: 21600904
* Section: 2
* Assignment: 1
* Description: implementations of functions defined in sorting.h
*/

#include // "sorting.h"

// void swap(int &x, int &y)
// {
//     int temp = x;
//     x = y;
//     y = temp;
// }
// int indexOfLargest(const int *theArray, int size, int &compCount)
// {
//     int indexSoFar = 0;
//     for (int currentIndex = 1; currentIndex < size; ++currentIndex)
//     {
//         if (theArray[currentIndex] > theArray[indexSoFar])
//             indexSoFar = currentIndex;
//         compCount ++;
    }
    return indexSoFar;


}

void selectionSort(int *arr, const int size, int &compCount, int &moveCount)
{
    compCount = 0;
    moveCount = 0;
    for (int last = size - 1; last >= 1; --last)
    {
        int largest = indexOfLargest(arr, last + 1, compCount);
        swap(arr[largest], arr[last]);
        moveCount += 3;
    }
}

const int MAX_SIZE = 100000;
void merge(int *theArray, int first, int mid, int last, int &compCount, int &moveCount )
{

    int tempArray[MAX_SIZE]; // temporary array

    int first1 = first;   // beginning of first subarray
    int last1 = mid;      // end of first subarray
    int first2 = mid + 1; // beginning of second subarray
    int last2 = last;     // end of second subarray
    int index = first1;   // next available location in tempArray

    for (; (first1 <= last1) && (first2 <= last2); ++index)
    {
        compCount ++;
        if (theArray[first1] < theArray[first2])
        {
            moveCount ++;
            tempArray[index] = theArray[first1];
            ++first1;
        }
        else
        {
            moveCount ++;
            tempArray[index] = theArray[first2];
            ++first2;
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

void mergesort(int *theArray, int first, int last, int &compCount, int &moveCount) {

    if (first < last)
    {

        int mid = (first + last) / 2; // index of midpoint

        mergesort(theArray, first, mid, compCount, moveCount);

        mergesort(theArray, mid + 1, last, compCount, moveCount);

        // merge the two halves
        merge(theArray, first, mid, last, compCount, moveCount);
    }
}

void mergeSort(int *arr, const int size, int &compCount, int &moveCount)
{
    moveCount = 0;
    compCount = 0;

    mergesort(arr, 0, size - 1, compCount, moveCount);
}

void partition(int theArray[], int first, int last, int &pivotIndex, int &compCount, int &moveCount)
{

    // place pivot in theArray[first]
    //choosePivot(theArray, first, last);

    moveCount ++;
    int pivot = theArray[first]; // copy pivot

    // initially, everything but pivot is in unknown
    int lastS1 = first;           // index of last item in S1
    int firstUnknown = first + 1; // index of first item in unknown

    // move one item at a time until unknown region is empty
    for (; firstUnknown <= last; ++firstUnknown) {
        // Invariant: theArray[first+1..lastS1] < pivot
        //            theArray[lastS1+1..firstUnknown-1] >= pivot

        // move item from unknown to proper region
        compCount ++;
        if (theArray[firstUnknown] < pivot) { // belongs to S1
        ++lastS1;
        swap(theArray[firstUnknown], theArray[lastS1]);
        moveCount += 3;
        } // else belongs to S2
    }
    // place pivot in proper position and mark its location
    swap(theArray[first], theArray[lastS1]);
    moveCount += 3;
    pivotIndex = lastS1;
}

void quicksort(int *theArray, int first, int last, int &compCount, int &moveCount) {

    int pivotIndex;

    if (first < last) {

        // create the partition: S1, pivot, S2
        partition(theArray, first, last, pivotIndex, moveCount, compCount);

        // sort regions S1 and S2
        quicksort(theArray, first, pivotIndex - 1, compCount, moveCount);
        quicksort(theArray, pivotIndex + 1, last, compCount, moveCount);
    }
}

void quickSort(int *arr, const int size, int &compCount, int &moveCount)
{
    moveCount = 0;
    compCount = 0;
    quicksort(arr, 0, size - 1, moveCount, compCount);
}

void radixSort(int *arr, const int size)
{
    int max;
    for(int i = 0; i < size; i++)
    {
        if(i == 0 || arr[i] > max)
            max = arr[i];
    }
    for(int i = 1; max/i > 0; i *= 10)
    {
        int count[10] = { 0 };
        asd

          asdasdasdas
        int result[size];
        for(int j = 0; j < size; j ++)
            count[(arr[j] / i) % 10]++;

        for(int j = 1; j < 10; j ++ )
            count[j] += count[j - 1];
        for (int j = size - 1; j >= 0; j--)
        {
            result[count[(arr[j] / i) % 10] - 1] = arr[j];
            count[(arr[j] / i) % 10]--;
        }
        for (int j = 0; j < size; j++)
            arr[j] = result[j];
    }
}

void displayArray(const int *arr, const int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size)
{
    int max = 100;
    int min = 1;

    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];
    srand(time(nullptr));

    for (int i = 0; i < size; i++)
    {
        int randomNumber = rand() % (max - min + 1) + min;

        arr1[i] = randomNumber;
        arr2[i] = randomNumber;
        arr3[i] = randomNumber;
        arr4[i] = randomNumber;
        // cout << randomNumber << endl;
    }
}

void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size) // artan
{
    int compCount, moveCount;
    createRandomArrays(arr1, arr2, arr3, arr4, size);
    quickSort(arr1, size, compCount, moveCount);
    quickSort(arr2, size, compCount, moveCount);
    quickSort(arr3, size, compCount, moveCount);
    quickSort(arr4, size, compCount, moveCount);


}

void reverse(int* arr, int size)
{
    int* temp = new int[size];

    for(int i = 0; i < size; i++)
        temp[i] = arr[i];

    for(int i = 0; i < size; i++)
        arr[i] = temp[size-i-1];
    delete[] temp;

}

void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size)
{
    createAscendingArrays(arr1, arr2, arr3, arr4, size);
    reverse(arr1, size);
    reverse(arr2, size);
    reverse(arr3, size);
    reverse(arr4, size);
}

void performanceAnalysis()
{
    cout << "Performance Analysis" << endl;
    cout << "--------------------------" << endl;
    cout << "--------------------------" << endl;
    int lenArrSizes = 7;
    int arraySizes[] = {6000, 10000, 14000, 18000, 22000, 26000, 30000};

    // Random
    cout << "Random" << endl;
    for(int i = 0; i < 4; i ++)
    {
        if(i == 0)
            cout << "-----------------------------------------------------\nAnalysis of Selection Sort" << endl;
        else if(i == 1)
            cout << "-----------------------------------------------------\nAnalysis of Merge Sort" << endl;
        else if(i == 2)
            cout << "-----------------------------------------------------\nAnalysis of Quick Sort" << endl;
        else
            cout << "-----------------------------------------------------\nAnalysis of Radix Sort" << endl;

        if( i < 3 )
            cout << "Array Size\tElapsed time\tcompCount\tmoveCount" << endl;
        else
            cout << "Array Size\tElapsed time" << endl;

        for(int j = 0; j < lenArrSizes; j ++)
        {
            int* arr1, *arr2, *arr3, *arr4, cc, mc;
            int tme;
            createRandomArrays(arr1, arr2, arr3, arr4, arraySizes[j]);

            if(i == 0)
            {
                const clock_t begin_time = clock();
                selectionSort(arr1, arraySizes[j], cc, mc);
                tme = float( clock () - begin_time ) /  (float(CLOCKS_PER_SEC)/1000);
            }
            else if(i == 1)
            {
                const clock_t begin_time = clock();
                mergeSort(arr1, arraySizes[j], cc, mc);
                tme = float( clock () - begin_time ) /  (float(CLOCKS_PER_SEC)/1000);
            }
            else if(i == 2)
            {
                const clock_t begin_time = clock();
                quickSort(arr1, arraySizes[j], cc, mc);
                tme = float( clock () - begin_time ) /  (float(CLOCKS_PER_SEC)/1000);
            }
            else
            {
                const clock_t begin_time = clock();
                radixSort(arr1, arraySizes[j]);
                tme = float( clock () - begin_time ) /  (float(CLOCKS_PER_SEC)/1000);
            }

            if(i < 3)
            {
                cout << arraySizes[j] << "\t\t" << tme << " ms\t\t" << cc << "\t";
                if (cc < 10000000)
                    cout << "\t";
                cout << mc << endl;
            }
            else
                cout << arraySizes[j] << "\t\t" << tme << " ms\t\t" << endl;

        }
    }

    // Ascending
    cout << "Ascending" << endl;
    for(int i = 0; i < 4; i ++)
    {
        if(i == 0)
            cout << "-----------------------------------------------------\nAnalysis of Selection Sort" << endl;
        else if(i == 1)
            cout << "-----------------------------------------------------\nAnalysis of Merge Sort" << endl;
        else if(i == 2)
            cout << "-----------------------------------------------------\nAnalysis of Quick Sort" << endl;
        else
            cout << "-----------------------------------------------------\nAnalysis of Radix Sort" << endl;

        if( i < 3 )
            cout << "Array Size\tElapsed time\tcompCount\tmoveCount" << endl;
        else
            cout << "Array Size\tElapsed time" << endl;

        for(int j = 0; j < lenArrSizes; j ++)
        {
            int* arr1, *arr2, *arr3, *arr4, cc, mc;
            int tme;
            createAscendingArrays(arr1, arr2, arr3, arr4, arraySizes[j]);

            if(i == 0)
            {
                const clock_t begin_time = clock();
                selectionSort(arr1, arraySizes[j], cc, mc);
                tme = float( clock () - begin_time ) /  (float(CLOCKS_PER_SEC)/1000);
            }
            else if(i == 1)
            {
                const clock_t begin_time = clock();
                mergeSort(arr1, arraySizes[j], cc, mc);
                tme = float( clock () - begin_time ) /  (float(CLOCKS_PER_SEC)/1000);
            }
            else if(i == 2)
            {
                const clock_t begin_time = clock();
                quickSort(arr1, arraySizes[j], cc, mc);
                tme = float( clock () - begin_time ) /  (float(CLOCKS_PER_SEC)/1000);
            }
            else
            {
                const clock_t begin_time = clock();
                radixSort(arr1, arraySizes[j]);
                tme = float( clock () - begin_time ) /  (float(CLOCKS_PER_SEC)/1000);
            }

            if(i < 3)
            {
                cout << arraySizes[j] << "\t\t" << tme << " ms\t\t" << cc << "\t";
                if (cc < 10000000)
                    cout << "\t";
                cout << mc << endl;
            }
            else
                cout << arraySizes[j] << "\t\t" << tme << " ms\t\t" << endl;

        }
    }

    // Descending
    cout << "Descending" << endl;
    for(int i = 0; i < 4; i ++)
    {
        if(i == 0)
            cout << "-----------------------------------------------------\nAnalysis of Selection Sort" << endl;
        else if(i == 1)
            cout << "-----------------------------------------------------\nAnalysis of Merge Sort" << endl;
        else if(i == 2)
            cout << "-----------------------------------------------------\nAnalysis of Quick Sort" << endl;
        else
            cout << "-----------------------------------------------------\nAnalysis of Radix Sort" << endl;

        if( i < 3 )
            cout << "Array Size\tElapsed time\tcompCount\tmoveCount" << endl;
        else
            cout << "Array Size\tElapsed time" << endl;

        for(int j = 0; j < lenArrSizes; j ++)
        {
            int* arr1, *arr2, *arr3, *arr4, cc, mc;
            int tme;
            createDescendingArrays(arr1, arr2, arr3, arr4, arraySizes[j]);

            if(i == 0)
            {
                const clock_t begin_time = clock();
                selectionSort(arr1, arraySizes[j], cc, mc);
                tme = float( clock () - begin_time ) /  (float(CLOCKS_PER_SEC)/1000);
            }
            else if(i == 1)
            {
                const clock_t begin_time = clock();
                mergeSort(arr1, arraySizes[j], cc, mc);
                tme = float( clock () - begin_time ) /  (float(CLOCKS_PER_SEC)/1000);
            }
            else if(i == 2)
            {
                const clock_t begin_time = clock();
                quickSort(arr1, arraySizes[j], cc, mc);
                tme = float( clock () - begin_time ) /  (float(CLOCKS_PER_SEC)/1000);
            }
            else
            {
                const clock_t begin_time = clock();
                radixSort(arr1, arraySizes[j]);
                tme = float( clock () - begin_time ) /  (float(CLOCKS_PER_SEC)/1000);
            }

            if(i < 3)
            {
                cout << arraySizes[j] << "\t\t" << tme << " ms\t\t" << cc << "\t";
                if (cc < 10000000)
                    cout << "\t";
                cout << mc << endl;
            }
            else
                cout << arraySizes[j] << "\t\t" << tme << " ms\t\t" << endl;

        }
    }

}
