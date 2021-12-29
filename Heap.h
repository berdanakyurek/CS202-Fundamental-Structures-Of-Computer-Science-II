/*
* Title: Heaps
* Author: Berdan Akyurek
* ID: 21600904
* Section: 2
* Assignment: 3
* Description: header file of Heap class
*/

#ifndef HEAP_H
#define HEAP_H
#include "Node.h"

using namespace std;
class Heap 
{
private:
    Node* head;
    int size;

public:
    Heap();
    ~Heap();
    Node* getHead();
    bool add(int idA, int priorityA, int comingTimeA, int processTimeA);
    bool add(Process p);
    bool remove();
    bool isEmpty();
    Process getHeadProcess();
    void preorderTraverse();
    int getSize();
};

#endif