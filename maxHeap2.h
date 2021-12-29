#ifndef MAXHEAP1_H
#define MAXHEAP1_H

#include <iostream>

using namespace std;

class maxHeap1{

public:
    maxHeap1();
    void insert(int id, int priority, int arrivalTime, int examDuration); 
    void shift();
    int getSize();
    void goForward(int patientNum);
    void printHeap();
    int getFirstPatientsExamDuration();
    int getFirstPatientsArrivalTime();
    int getFirstPatientsId();
    void deleteHeap();

private:
    int size;
    int heapSize;
    int** heap;

};

#endif