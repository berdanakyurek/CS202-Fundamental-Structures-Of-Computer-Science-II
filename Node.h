/*
* Title: Heaps
* Author: Berdan Akyurek
* ID: 21600904
* Section: 2
* Assignment: 3
* Description: header file of Node class
*/

#ifndef NODE_H
#define NODE_H

#include "Process.h"
#include <string>

class Node 
{

private:
    Process p;
    Node* left;
    Node* right;

public:
    Node(int idA = 0, int priorityA = 0, int comingTimeA = 0, int processTimeA = 0 );
    Node(Process pp);
    ~Node();
    int getID();
    int getPriority();
    int getComingTime();
    int getProcessTime();
    void preorderTraverse();


    Process getP();

    Node* getLeft();
    Node* getRight();
    Node* getLast();
    Node* getParentOfLast();

    bool deleteLast();
    int height();
    
    int smallestInsertableLevel();
    void insertEnd(int id, int priority, int comingTime, int processTime);
    void insertEnd(Process p);
    void add(int id, int priority, int comingTime, int processTime);
    void add(Process p);
    bool remove();
    void heapify();
};

#endif