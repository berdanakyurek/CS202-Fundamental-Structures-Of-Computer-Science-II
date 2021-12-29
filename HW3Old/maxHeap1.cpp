#include "maxHeap1.h"

//constructor for maxHeap object
maxHeap1::maxHeap1()
{
    size = 0;

    // heap[n][0] = id of n'th patient on the heap
    // heap[n][1] = priority of n'th patient on the heap
    // heap[n][2] = arrival time of n'th patient on the heap
    // heap[n][3] = examination duration of n'th patient on the heap
    heap[2000][4];
}

//inserts an element at the end and moves it forward until it is on the right place
void maxHeap1::insert(int id, int priority, int arrivalTime, int examDuration)
{
    heap[size][0] = id;
    heap[size][1] = priority;
    heap[size][2] = arrivalTime;
    heap[size][3] = examDuration;

    size ++;

    for(int i = size-1 ; i > 0 ; i -- )
    {
        if( heap[i][1] <= heap[i-1][1] )
            break;
        
        goForward(i);
    }
}

//moves the patient one step forward

void maxHeap1:: goForward( int num)
{
    int temp[4];

    for(int i = 0; i < 4 ; i ++)
        temp[i] = heap[num][i];

    for(int i = 0; i < 4 ; i ++)
        heap[num][i] = heap[num-1][i];

    for(int i = 0; i < 4 ; i ++)
        heap[num-1][i] = temp[i];
}

//shift all array one step and removes first array item
void maxHeap1::shift()
{
    for(int i = 0 ; i < size-1 ; i ++ )
    {
        for(int j = 0; j < 4 ; j++ )
        {
            heap[i][j] = heap[i+1][j];
        }        
    }

    size --;
}

//returns size of the heap
int maxHeap1::getSize()
{
    return size;
}

//prints heap info
void maxHeap1::printHeap()
{
    for(int i = 0; i < size ; i ++)
    {
        cout << "Id:" << heap[i][0] << ", Priority: " << heap[i][1] << ", Arrival Time: " << heap[i][2] << ", Examination Duration: " << heap[i][3] << endl;
        
    }
    cout << "-------------------------------" << endl;
}

int maxHeap1::getFirstPatientsExamDuration()
{
    return heap[0][3];
}

int maxHeap1::getFirstPatientsArrivalTime()
{
    return heap[0][2];
}

int maxHeap1::getFirstPatientsId()
{
    return heap[0][0];
}

void maxHeap1::deleteHeap()
{
    //This function left blank since there is no dynamic allocation for question 1.
}